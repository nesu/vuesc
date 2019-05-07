#include <iostream>

#include "llvm/IR/IRPrintingPasses.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/IR/Verifier.h"

#include "Compiler.h"
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
    if (type.named == "int") { 
        return i64;
    }
    if (type.named == "string") {
        return i8_ptr;
    }

    return void_;
}


llvm::Value * GeneratorContext::__stdlib_registry()
{
    std::vector<Type*> argument_type_vec;
    argument_type_vec.push_back(i8_ptr);

    FunctionType* ft = FunctionType::get(i32, makeArrayRef(argument_type_vec), true);
    Function* fn = Function::Create(ft, GlobalValue::LinkageTypes::ExternalLinkage, "printf", module);
    fn->setCallingConv(CallingConv::C);

    
    
    /*ft = FunctionType::get(i32, makeArrayRef(argument_type_vec), true);
    fn = Function::Create(ft, GlobalValue::LinkageTypes::ExternalLinkage, Twine("printf"), module);
    fn->setCallingConv(CallingConv::C);*/

    /*Function::arg_iterator it = fn->arg_begin();
    Value* format = &*it++;
    format->setName("format");
    std::vector<Value*> arguments;
    arguments.push_back(format);*/

    //Constant* int_val = ConstantInt::get(i64, reinterpret_cast<uintptr_t>((void*)println), false);
    //Constant* ptr_val = ConstantExpr::getIntToPtr(int_val, ft->getPointerTo());

    //Function* fn = Function::Create(ft, GlobalValue::LinkageTypes::ExternalLinkage, Twine("println"), module);
    //fn->setCallingConv(CallingConv::C);
    //BasicBlock* block = BasicBlock::Create(getctx(), "entry", fn, 0);

    //Function::Create(ft, GlobalValue::LinkageTypes::ExternalLinkage, "println", module);

    /*push(block);
    CallInst::Create(ptr_val, ArrayRef<Value*>(), "", block);
    ReturnInst::Create(context, block);
    pop();*/

    return nullptr;
}


void GeneratorContext::generate(Block& root)
{
    /* Create entry function. */
    std::vector<Type*> arg_type_vec;
    FunctionType* ft = FunctionType::get(void_, makeArrayRef(arg_type_vec), false);
    entry_point = Function::Create(ft, GlobalValue::ExternalLinkage, "main", module);
    BasicBlock* entry_block = BasicBlock::Create(this->getctx(), "entry", entry_point, 0);

    __stdlib_registry();

    this->push(entry_block);
    root.generator(*this);
    if (current_block()->block->getTerminator() == nullptr) {
        ReturnInst::Create(this->getctx(), 0, current_block()->block);
    }

    this->pop();
#ifndef LLVM_NO_DUMP
    module->dump();
#endif // !LLVM_NO_DUMP

    if (llvm::verifyModule(*module, &outs()))
    {
        std::cout << "Verification failed" << std::endl;
        return;
    }
}