#ifndef _HELPERS_H
#define _HELPERS_H

#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/InstIterator.h"

namespace llvm
{
    class Constant;
    class Function;
    class Type;
}

namespace vues
{
    llvm::Constant* embed_constant_ptr(const void * address, llvm::Type * type);
}

#endif // !_HELPERS_H
