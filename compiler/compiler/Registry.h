#ifndef _REGISTRY_H
#define _REGISTRY_H

#include <map>

#include "llvm/IR/Type.h"
#include "llvm/IR/Instructions.h"
using namespace llvm;

// Description of block local.
struct BlockLocal
{
    AllocaInst * instr;
    bool immutable;
    bool assigned;
};

// Container for locals inside of a block.
class LocalRegistry
{
    std::map<std::string, BlockLocal> _registry;

    public:
        BlockLocal * get(std::string named);
        BlockLocal * create(std::string named, AllocaInst* instr, bool immutable = false, bool assigned = false);

        bool contains(std::string named);
};

#endif // !_REGISTRY_H
