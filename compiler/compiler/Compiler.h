#ifndef _COMPILER_H
#define _COMPILER_H
#include <vector>

class Compiler
{
    private:
        static Compiler* self;
        Compiler();

    public:
        static Compiler* get();

        Compiler(Compiler const&) = delete;
        void operator=(Compiler const&) = delete;
};

#endif // !_COMPILER_H
