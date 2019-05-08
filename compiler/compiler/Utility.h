#ifndef _UTILITY_H
#define _UTILITY_H

#include <memory>

#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Debug.h"
#include "llvm/IR/Type.h"

#include "ErrorHandling.h"

std::unique_ptr<llvm::raw_fd_ostream> make_raw_fd_ostream(const std::string &filename);

#endif // !_UTILITY_H
