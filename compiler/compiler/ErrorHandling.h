#ifndef _ERROR_HANDLING_H
#define _ERROR_HANDLING_H

#include <sstream>

struct ErrorHandling
{
    enum 
    {
        COMPILER = 0x0001,
        SCRIPT = 0x0002
    };

    const int flags;
    std::ostringstream message;

    ErrorHandling(int line, int flags);
    ~ErrorHandling();

    template<typename T>
    ErrorHandling &operator<<(const T &x)
    {
        message << x;
        return *this;
    }
};

#endif // !_ERROR_HANDLIG_H
