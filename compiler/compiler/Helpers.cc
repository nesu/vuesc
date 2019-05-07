#include "Helpers.h"

llvm::Constant * vues::embed_constant_ptr(const void * address, llvm::Type * type)
{
    if (!type)
    {
        // TODO: Error reporting.
        return nullptr;
    }

    //llvm::Constant* int_Val = llvm::Constant::get()

    return nullptr;
}