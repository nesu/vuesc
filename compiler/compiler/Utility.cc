#include "Utility.h"
#include <iostream>

std::unique_ptr<llvm::raw_fd_ostream> make_raw_fd_ostream(const std::string &filename)
{
    std::string error_string;
    std::error_code errco;
    std::unique_ptr<llvm::raw_fd_ostream> raw_out(new llvm::raw_fd_ostream(filename, errco, llvm::sys::fs::F_None));
    if (errco) {
        std::cout << errco.message() << std::endl;
    }

    return raw_out;
}