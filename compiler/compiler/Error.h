#ifndef _ERROR_H
#define _ERROR_H

#include "ErrorHandling.h"

#ifndef SCRIPT_ERROR
#define SCRIPT_ERROR ErrorHandling(__LINE__, ErrorHandling::SCRIPT)
#endif // !SCRIPT_ERROR

#ifndef COMPILER_ERROR
#define COMPILER_ERROR ErrorHandling(__LINE__, ErrorHandling::COMPILER)
#endif // !COMPILER_ERROR

#endif // !_ERROR_H
