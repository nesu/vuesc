#define DEBUG_TYPE "Generator"

#include <iostream>
#include "llvm/Support/Debug.h"

#include "Parser.h"
using Token = Vues::Parser::token::yytokentype;

#include "GeneratorContext.h"
#include "Error.h"

Value* Integer::generator(GeneratorContext& context)
{
    LLVM_DEBUG(dbgs() << "Creating constant int with value of " << value << "\n");
    return llvm::ConstantInt::get(context.i64, value, true);
}

Value* Boolean::generator(GeneratorContext& context)
{
    return llvm::ConstantInt::get(context.i1, value ? 1 : 0, false);
}

Value* String::generator(GeneratorContext& context)
{
    ArrayType* at = ArrayType::get(IntegerType::get(context.llvmc(), 8), value.size() + 1);
    GlobalVariable* var = new GlobalVariable(*context.module, at, true, GlobalValue::PrivateLinkage, 0, ".str");
    var->setAlignment(1);

    Constant* const_astr = ConstantDataArray::getString(context.llvmc(), value);
    var->setInitializer(const_astr);

    std::vector<Constant*> ptr_vec;
    ConstantInt* cint = ConstantInt::get(context.llvmc(), APInt(64, StringRef("0"), 10));
    ptr_vec.push_back(cint);
    ptr_vec.push_back(cint);

    Constant* const_ptr8 = ConstantExpr::getGetElementPtr(at, var, ptr_vec);
    return const_ptr8;
}


Value* Identifier::generator(GeneratorContext& context)
{
    if (!context.locals()->contains(named)) {
        SCRIPT_ERROR << "Identifier " << named << " does not exist";
        return nullptr;
    }

    return new LoadInst(context.locals()->get(named)->instr, "", false, context.current_block()->block);
}


Value* Assignment::generator(GeneratorContext& context)
{
    Value* value = right.generator(context);

    if (value == nullptr)
    {
        SCRIPT_ERROR << "Missing expression for identifier " << left.named;
        return nullptr;
    }

    if (!context.locals()->contains(left.named)) {
        SCRIPT_ERROR << "Undeclared variable with name " << left.named;
        return nullptr;
    }

    BlockLocal* local = context.locals()->get(left.named);
    Type* vty = local->instr->getType()->getElementType();
    if (value->getType() != vty)
    {
        if (value->getType()->isIntegerTy() && vty->isIntegerTy())
        {
            LLVM_DEBUG(dbgs() << "Attempting to cast integer type.");
            if (value->getType()->getPrimitiveSizeInBits() > vty->getPrimitiveSizeInBits())
            {
                SCRIPT_ERROR << "Cannot cast value of bigger integer to smaller.";
                return nullptr;
            }

            value = CastInst::Create(Instruction::CastOps::ZExt, value, context.i64, "result", context.current_block()->block);
            value->getType()->dump();
        }
        else
        {
            SCRIPT_ERROR << "Assigning incompatible type for variable " << left.named;
            return nullptr;
        }
    }

    if (local->immutable && local->assigned)
    {
        SCRIPT_ERROR << "Cannot assign value on immutable variable. Use \"var\" instead.";
        return nullptr;
    }

    return new StoreInst(value, local->instr, false, context.current_block()->block);
}


Value* Block::generator(GeneratorContext& context)
{
    Value* last = nullptr;
    for (auto it : statements) {
        last = it->generator(context);
    }

    return last;
}


Value* Comparison::generator(GeneratorContext& context)
{
    Value* vl = left->generator(context);
    Value* vr = right->generator(context);

    if (vl->getType() != vr->getType())
    {
        SCRIPT_ERROR << "Cannot compare two different types.";
        return nullptr;
    }

    // TODO: Add support for (double/float) == integer
    CmpInst::Predicate predicate = CmpInst::Predicate::BAD_ICMP_PREDICATE;
    switch (comparison_operator)
    {
        case Token::T_EQUAL:
            predicate = CmpInst::Predicate::ICMP_EQ;
            break;
        case Token::T_NOT_EQUAL:
            predicate = CmpInst::Predicate::ICMP_NE;
            break;
        case Token::T_GREATER_OR_EQUAL:
            predicate = CmpInst::Predicate::ICMP_SGE;
            break;
        case Token::T_LESS_OR_EQUAL:
            predicate = CmpInst::Predicate::ICMP_SLE;
            break;
        case Token::T_GREATER:
            predicate = CmpInst::Predicate::ICMP_SGT;
            break;
        case Token::T_LESS:
            predicate = CmpInst::Predicate::ICMP_SLT;
            break;
        default:
            // This section should not be reached at all.
            COMPILER_ERROR << "Unknown comparison operator.";
            return nullptr;
    }

    return CmpInst::Create(Instruction::ICmp, predicate, vl, vr, "result", context.current_block()->block);
}


Value* Binary::generator(GeneratorContext& context)
{
    Value* vl = left->generator(context);
    Value* vr = right->generator(context);

    Instruction::BinaryOps bo;
    switch (binary_operator)
    {
        case Token::T_AND:
            bo = Instruction::And;
            break;
        case Token::T_OR:
            bo = Instruction::Or;
            break;
        case Token::T_ADD:
            bo = Instruction::Add;
            break;
        case Token::T_SUB:
            bo = Instruction::Sub;
            break;
        case Token::T_MUL:
            bo = Instruction::Mul;
            break;
        case Token::T_DIV:
            bo = Instruction::SDiv;
            break;
        default:
            COMPILER_ERROR << "Failed to determine instruction for binary operator.";
            return nullptr;
    }

    return BinaryOperator::Create(bo, vl, vr, "bop", context.llvm_block());
}


Value* Conditional::generator(GeneratorContext& context)
{
    Value* value = comparison->generator(context);
    if (!value) {
        COMPILER_ERROR << "Comparison returned nullptr.";
    }

    Function* F = context.current_block()->block->getParent();

    BasicBlock* if_then = BasicBlock::Create(context.llvmc(), "if.then", F);
    BasicBlock* if_cont = BasicBlock::Create(context.llvmc(), "if.cont");
    BasicBlock* if_else = if_cont;

    if (else_block) {
        if_else = BasicBlock::Create(context.llvmc(), "if.else");
    }

    BranchInst::Create(if_then, if_else, value, context.current_block()->block);
    
    //
    // IF.THEN BLOCK
    //
    //context.push(if_then);
    context.current_block()->block = if_then;
    Value* if_then_v = then_block->generator(context);
    if (!if_then_v) {
        COMPILER_ERROR << "nullptr in if_then_v";
    }

    if_then = context.current_block()->block;
    //BranchInst::Create(if_cont, if_then);
    // Do not create branch instr if block ends with terminator.
    if (!context.current_block()->terminated()) {
        BranchInst::Create(if_cont, if_then);
    }

    // 
    // IF.THEN BLOCK
    //
    if (else_block)
    {
        F->getBasicBlockList().push_back(if_else);
        context.current_block()->block = if_else;
        Value * if_else_v = else_block->generator(context);
        if (!if_else_v) {
            COMPILER_ERROR << "nullptr in if_else_v";
        }

        if_else = context.current_block()->block;
        // Do not create branch instr if block ends with terminator.
        if (!context.current_block()->terminated()) {
            BranchInst::Create(if_cont, if_else);
        }
    }

    //
    // IF.CONT BLOCK
    //
    F->getBasicBlockList().push_back(if_cont);
    context.current_block()->block = if_cont;
    //context.push(if_cont);

    return if_cont;
}



Value* ExpressionStatement::generator(GeneratorContext&  context)
{
    context.current_block()->ret = expression.generator(context);
    return context.current_block()->ret;
}



Value* VariableDeclaration::generator(GeneratorContext& context)
{
    // TODO: Find out what is AddrSpace and if zero is good number here.
    AllocaInst* inst = new AllocaInst(context.typeof(type), 0, identifier.named.c_str(), context.current_block()->block);
    BlockLocal* local = context.locals()->create(identifier.named, inst, !is_mutable, false);

    if (expression != nullptr)
    {
        Assignment assigment(identifier, *expression);
        Value* ret = assigment.generator(context);
        if (ret != nullptr)
        {
            local->assigned = true;
        }
    }
    else if (!is_mutable)
    {
        SCRIPT_ERROR << "Immutable variables must have assigned value.";
        return nullptr;
    }

    return inst;
}


Value* MethodCall::generator(GeneratorContext& context)
{
    Function* func = context.module->getFunction(identifier.named.c_str());

    if (func == nullptr)
    {
        SCRIPT_ERROR << "Method " << identifier.named << " is not defined.";
        return nullptr;
    }

    // Check for default arguments.
    size_t provided_argc = arguments.size();
    size_t required_argc = func->arg_size();
    
    if (provided_argc > required_argc && !func->isVarArg())
    {
        SCRIPT_ERROR << "Function " << identifier.named << " takes " << required_argc << " arguments, but " << provided_argc << " given.";
        return nullptr;
    }

    std::vector<Value*> args;
    for (auto it : arguments) {
        args.push_back(it->generator(context));
    }

    return CallInst::Create(func, makeArrayRef(args), "", context.current_block()->block);
}



Value* MethodDeclaration::generator(GeneratorContext& context)
{
    std::vector<Type*> method_decl_args;
    for (auto it : arguments) {
        method_decl_args.push_back(context.typeof(it->type));
    }

    // isVarArg true only when function takes number of arguments.
    // http://llvm.org/doxygen/Function_8h_source.html
    llvm::FunctionType* ft = FunctionType::get(context.typeof(type), makeArrayRef(method_decl_args), false);
    //
    Function* func = Function::Create(ft, GlobalValue::ExternalLinkage, identifier.named.c_str(), context.module);
    BasicBlock* block = BasicBlock::Create(context.llvmc(), "entry", func, 0);
    context.push(block);

    Function::arg_iterator rarguments = func->arg_begin();
    for (auto it : arguments)
    {
        AllocaInst* alloc = llvm::dyn_cast_or_null<AllocaInst>(it->generator(context));
        if (alloc != nullptr)
        {
            // TODO: Class usage.
            rarguments->setName(it->identifier.named);
            new StoreInst(&(*rarguments), alloc, context.current_block()->block);
        }

        rarguments++;
    }
        
    method_block.generator(context);
    llvm::Value* retty = context.current_block()->ret;
    
    // Block ended with some value.
    if (retty != NULL && context.typeof(type) != retty->getType())
    {
        SCRIPT_ERROR << "Missing return statement or type of return value does not match method signature.";
        return nullptr;
    }

    // Create void return if method return type is void and block is without terminator.
    if (retty->getType()->isVoidTy() && !context.current_block()->terminated()) {
        ReturnInst::Create(context.llvmc(), 0, context.current_block()->block);
    }

    context.pop();
    // Validation?
    return func;
}


Value* Range::generator(GeneratorContext& context)
{
    Value* vl = left->generator(context);
    Value* vr = right->generator(context);

    if (!vl->getType()->isIntegerTy() || !vr->getType()->isIntegerTy())
    {
        SCRIPT_ERROR << "Range must be specified in integer type.";
        return nullptr;
    }

    //
    // Create range start and end values.
    //
    return nullptr;
}


Value* ReturnStatement::generator(GeneratorContext& context)
{
    Value* ret = expression.generator(context);
    context.current_block()->ret = ret;
    
    return ReturnInst::Create(context.llvmc(), ret, context.current_block()->block);
}


Value* BlankReturnStatement::generator(GeneratorContext& context)
{
    context.current_block()->ret = 0;
    return ReturnInst::Create(context.llvmc(), 0, context.current_block()->block);
}

#undef DEBUG_TYPE