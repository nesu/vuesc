#include <iostream>
#include <fstream>

#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Debug.h"

#include "GeneratorContext.h"
#include "Lexer.h"
#include "Error.h"
#include "Utility.h"

extern Block* root_block;

int main(int argc, char* argv[])
{
    cl::opt<std::string> ifn(cl::Positional, cl::Required, cl::desc("<input file>"));
    cl::opt<std::string> ofn("o", cl::Required, cl::desc("Bitcode output file."), cl::value_desc("output file"));
    cl::opt<int> parserd("parser-debug-level", cl::desc("Debug level for parser."), cl::value_desc("int"));
    // TODO: Add alias for output argument.

    cl::ParseCommandLineOptions(argc, argv, "Compiler for Vues programming language.");
    std::cout << "Compiling " << ifn << "..." << std::endl;
    if (ofn.length() > 0) {
        std::cout << "Bitcode output will be written to " << ofn << "." << std::endl;
    }
    
    std::ifstream input(ifn);
    if (!input.good()) {
        COMPILER_ERROR << "Provided file does not exist or is unreadable.";
        exit(EXIT_FAILURE);
    }

    Lexer lexer(&input);
    Vues::Parser* parser = new Vues::Parser(lexer);
    if (parserd > 0) {
        std::cout << "Setting parser debug level to " << parserd << "." << std::endl;
        parser->set_debug_level(parserd);
    }

    int perr = parser->parse();
    if (perr != 0)
    {
        COMPILER_ERROR << "Failed to parse script. Parse returned " << perr;
        exit(EXIT_FAILURE);
    }

    GeneratorContext context;
    context.generate(*root_block);
    auto fd_ostream = make_raw_fd_ostream(ofn.getValue());
    llvm::WriteBitcodeToFile(*context.module, *fd_ostream);


    return 0;
}