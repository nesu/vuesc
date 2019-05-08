﻿#include <iostream>
#include "ErrorHandling.h"

ErrorHandling::ErrorHandling(int line, int flags) : flags(flags)
{
    // Error handling for errors that comes from compiler itself.
    if (flags & COMPILER)
    {
        message << "Compiler error: ";
    }
    
    // Error handling for errors that comes from input script.
    if (flags & SCRIPT)
    {   
        // TODO: Bent jau pamėginti atsekti eilutę iš kurios kyla klaida pačiame skripte.
        message << "Error: ";
    }
}

ErrorHandling::~ErrorHandling()
{
    if (!message.str().empty() && message.str().back() != '\n') {
        message << "\n";
    }

    std::cerr << message.str();
    exit(1);
}