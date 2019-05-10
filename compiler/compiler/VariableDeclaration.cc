#include "Error.h"
#include "Parser.h"
#include "GeneratorContext.h"

VariableDeclaration::
VariableDeclaration(Identifier & identifier, const Identifier & typeof)
    : identifier(identifier), typeof(typeof)
{
    immutable = false;
    kind = VariableDeclarationKind::LOCAL;
    value = nullptr;
}

Value* 
VariableDeclaration::
generator(GeneratorContext& context)
{


    // TODO: Find out what is AddrSpace and if zero is good number here.
    /*AllocaInst* inst = new AllocaInst(context.typeof(type), 0, identifier.named.c_str(), context.current_block()->block);
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

    return inst;*/
}