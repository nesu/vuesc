#define DEBUG_TYPE "Generator"

#include <iostream>

#include "llvm/Support/Debug.h"

#include "GeneratorContext.h"
#include "Error.h"

Value* Integer::generator(GeneratorContext& context)
{
    return llvm::ConstantInt::get(context.i64, value, true);
}

Value* String::generator(GeneratorContext& context)
{
    ArrayType* at = ArrayType::get(IntegerType::get(context.getctx(), 8), value.size() + 1);
    GlobalVariable* var = new GlobalVariable(*context.module, at, true, GlobalValue::PrivateLinkage, 0, ".str");
    var->setAlignment(1);

    Constant* const_astr = ConstantDataArray::getString(context.getctx(), value);
    var->setInitializer(const_astr);

    std::vector<Constant*> ptr_vec;
    ConstantInt* cint = ConstantInt::get(context.getctx(), APInt(64, StringRef("0"), 10));
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
    if (value->getType() != local->instr->getType()->getElementType())
    {
        SCRIPT_ERROR << "Assigning incompatible type for variable " << left.named;
        return nullptr;
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
    BasicBlock* block = BasicBlock::Create(context.getctx(), "entry", func, 0);
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

    ReturnInst::Create(context.getctx(), context.current_block()->ret, block);
    context.pop();

    // Validation?
    return func;
}


Value* ReturnStatement::generator(GeneratorContext& context)
{
    Value* ret = expression.generator(context);
    context.current_block()->ret = ret;
    return ret;
}


Value* BlankReturnStatement::generator(GeneratorContext& context)
{
    context.current_block()->ret = 0;
    return nullptr;
}

#undef DEBUG_TYPE