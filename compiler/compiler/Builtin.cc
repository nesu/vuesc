#include <stdarg.h>
#include <stdio.h>
#include <iostream>
#include <cstring>

#include "Builtin.h"

extern "C" __declspec(dllexport) void println(char * format)
{
    /*va_list argptr;
    va_start(argptr, format);
    vfprintf(stdout, format, argptr);
    va_end(argptr);*/
    std::cout << format << std::endl;
}