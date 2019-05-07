#ifndef _COMMANDLINE_H 
#define _COMMANDLINE_H
#include "llvm/Support/CommandLine.h"
using namespace llvm::cl;

std::string input;
bool DebugFlag;

static opt<bool, true> Debug("debug", desc("Enable debug output."), Hidden, location(DebugFlag));
static opt<std::string, true> InputFilename(Positional, Required, desc("<input file>"), location(input));

#ifdef NDEBUG
#define LLVM_DEBUG(X)
#else
#define LLVM_DEBUG(X) do { if(DebugFlag) { X; } } while (0)
#endif // !NDEBUG

#endif // !_COMMANDLINE_H 