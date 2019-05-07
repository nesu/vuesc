#include <iostream>
#include <fstream>

#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Debug.h"

#include "Compiler.h"
#include "GeneratorContext.h"
#include "Lexer.h"

extern Block* root_block;

int main(int argc, char* argv[])
{
    Compiler* compiler = Compiler::get();
    cl::opt<std::string> ifn(cl::Positional, cl::Required, cl::desc("<input file>"));
    cl::opt<std::string> ofn("o", cl::desc("Bitcode output file."), cl::value_desc("output file"));
    cl::opt<int> parserd("parser-debug-level", cl::desc("Debug level for parser."), cl::value_desc("int"));
    // TODO: Add alias for output argument.

    cl::ParseCommandLineOptions(argc, argv, "Compiler for Vues programming language.");
    std::cout << "Compiling " << ifn << "..." << std::endl;
    if (ofn.length() > 0) {
        std::cout << "Bitcode output will be written to " << ofn << "." << std::endl;
    }
    
    std::ifstream input(ifn);
    if (!input.good()) {
        std::cerr << "Bad input file." << std::endl;
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
        std::cerr << "Failed to parse file. Parse result: " << perr << std::endl;
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}




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

/*
int main(int argc, char* argv[])
{
    std::ifstream input("D:/vuesc/compiler/Debug/init.vs");
    if (!input.good()) {
        std::cout << "Bad file." << std::endl;
        exit(EXIT_FAILURE);
    }

    Lexer lexer(&input);
    Vues::Parser* parser = new Vues::Parser(lexer);
    parser->set_debug_level(1);

    int pr = parser->parse();
    if (pr != 0) {
        exit(EXIT_FAILURE);
    }
    
    
    GeneratorContext context;
    context.generate(*root_block);
    
    auto fd_ostream = make_raw_fd_ostream("bitcode.bc");
    llvm::WriteBitcodeToFile(*context.module, *fd_ostream);

    //context.execute();
    
    std::error_code ec;
    raw_ostream* out = new raw_fd_ostream("bitcode.bc", ec, llvm::sys::fs::OpenFlags::F_None);

    llvm::WriteBitcodeToFile(*context.module, *out);
    

    system("pause");
    return 0;
}*/

Compiler* Compiler::self = nullptr;
Compiler::Compiler() {}

Compiler* Compiler::get()
{
    if (self == nullptr) {
        self = new Compiler();
    }

    return self;
}
