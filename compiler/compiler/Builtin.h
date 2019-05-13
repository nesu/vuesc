#ifndef _BUILTIN_H

#include "llvm/IR/Type.h"
#include "llvm/IR/Function.h"

#ifdef _MSC_VER
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC
#endif // _MSC_VER

extern "C" __declspec(dllexport) void println(char * format);

/*
class BuiltinDefinition
{
    std::string named;
    llvm::Type* ret_type;
    std::vector<llvm::Type*> arguments;
    
    public:
        BuiltinDefinition(std::string named, llvm::Type* ret_type, std::vector<llvm::Type*> arguments)
            : named(named), ret_type(ret_type), arguments(arguments) {}

        llvm::Function* build(Generator llvm::GlobalValue::LinkageTypes linkage, bool vararg = false)
        {
            llvm::FunctionType* ft = llvm::FunctionType::get(ret_type, arguments, vararg);
            llvm::Function* fn = llvm::Function::Create(ft, linkage, named, )
        }
};*/


#endif // !_BUILTIN_H
