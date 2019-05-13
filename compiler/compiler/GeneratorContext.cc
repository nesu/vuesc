#include <iostream>
#include <algorithm>

#include "llvm/IR/IRPrintingPasses.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/PassManager.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/Support/TargetSelect.h"

#include "GeneratorContext.h"
#include "Builtin.h"


GeneratorContext::GeneratorContext()
{
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();

    module = new Module("vues", context);

    i1 = Type::getInt1Ty(context);
    i8 = Type::getInt8Ty(context);
    i8_ptr = Type::getInt8PtrTy(context);
    i32 = Type::getInt32Ty(context);
    i64 = Type::getInt64Ty(context);
    double_ = Type::getDoubleTy(context);
    void_ = Type::getVoidTy(context);
}

llvm::Type* GeneratorContext::typeof(const Identifier& type)
{
    std::string typen = type.named;

    std::transform(typen.begin(), typen.end(), typen.begin(), ::tolower);

    if (typen == "int") {
        return i64;
    }

    if (typen  == "string") {
        return i8_ptr;
    }

    if (typen == "bool" || typen == "boolean") {
        return i1;
    }

    return void_;
}


void GeneratorContext::internal_methods()
{
    std::vector<Type*> argument_type_vec;
    argument_type_vec.push_back(i8_ptr);

    FunctionType* ft = FunctionType::get(i32, makeArrayRef(argument_type_vec), true);
    Function* fn = Function::Create(ft, GlobalValue::LinkageTypes::ExternalLinkage, "printf", module);
    fn->setCallingConv(CallingConv::C);

    
    ft = FunctionType::get(void_, makeArrayRef(argument_type_vec), false);
    Function* bound = (Function*)module->getOrInsertFunction("println", ft);
    //bound->setCallingConv(CallingConv::C);

    //fn = Function::Create(ft, GlobalValue::LinkageTypes::ExternalLinkage, "println", module);
}


void GeneratorContext::generate(Block& root)
{
    /* Create entry function. */
    std::vector<Type*> arg_type_vec;
    FunctionType* ft = FunctionType::get(void_, makeArrayRef(arg_type_vec), false);
    entry_point = Function::Create(ft, GlobalValue::ExternalLinkage, "main", module);
    BasicBlock* entry_block = BasicBlock::Create(this->llvmc(), "entry", entry_point, 0);
    internal_methods();


    this->push(entry_block);
    root.generator(*this);
    if (current_block()->block->getTerminator() == nullptr) {
        ReturnInst::Create(this->llvmc(), 0, current_block()->block);
    }

    this->pop();
    if (DebugFlag)
    {
#ifndef LLVM_NO_DUMP
        module->dump();
#endif // !LLVM_NO_DUMP
    }

    if (llvm::verifyModule(*module, &outs()))
    {
        std::cout << "Verification failed" << std::endl;
        return;
    }
}