#include <iostream>

#include "Lexer.h"
#include "Parser.h"

Lexer::Lexer(std::istream* input)
    : yyFlexLexer(input), yylval(nullptr) {}

int Lexer::yylex(Vues::Parser::semantic_type* lval)
{
    yylval = lval;
    return yylex();
}