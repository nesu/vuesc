#include "Registry.h"



BlockLocal * LocalRegistry::get(std::string named)
{
    if (!contains(named)) {
        return nullptr;
    }

    return &_registry[named];
}

bool LocalRegistry::contains(std::string named)
{
    return _registry.find(named) != _registry.end();
}

BlockLocal * LocalRegistry::create(std::string named, AllocaInst * instr, bool immutable, bool assigned)
{
    BlockLocal locl = {};
    locl.instr = instr;
    locl.immutable = immutable;
    locl.assigned = assigned;

    _registry.insert(std::make_pair(named, locl));
    
    BlockLocal* _local = get(named);
    assert(_local != nullptr);
    assert(_local->instr == instr);
    assert(_local->immutable == immutable);
    assert(_local->assigned == assigned);

    return _local;
}
