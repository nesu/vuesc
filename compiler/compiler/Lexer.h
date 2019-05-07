#ifndef _LEXER_H
#define _LEXER_H

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif // !yyFlexLexerOnce

#undef  YY_DECL
#define YY_DECL int Lexer::yylex()

#include "Parser.h"

class Lexer : public yyFlexLexer
{
    int yylex();
    Vues::Parser::semantic_type *yylval;

    public:
        Lexer(std::istream* input);
        int yylex(Vues::Parser::semantic_type *lval);
};

#endif // !_LEXER_H

