%{
    #include <string>
    #include "AbstractSyntaxTree.h"
    #include "Parser.h"
    #include "Lexer.h"

    #define SAVE_TOKEN yylval->string = new std::string(yytext, yyleng)
    #define TOKEN(tok) (yylval->token = tok)

    typedef Vues::Parser::token Token;
%}

%option c++
%option yyclass="Lexer"
%option noyywrap

%x STRING_LITERAL
%x COMMENT_SECTION

%%

[ \t\n]                             ;

"var"                               return TOKEN(Token::TVAR);
"val"                               return TOKEN(Token::TVAL);
"fun"                               return TOKEN(Token::TFUN);
"return;"                           return TOKEN(Token::TRETURN_VOID);
"return"                            return TOKEN(Token::TRETURN);
"if"                                return TOKEN(Token::TIF);
"else"                              return TOKEN(Token::TELSE);


\"                                  BEGIN(STRING_LITERAL);
<STRING_LITERAL>\"                  BEGIN(INITIAL);
<STRING_LITERAL>\n                  {
                                        YY_FATAL_ERROR("Unterminated string literal before newline.");
                                        yyterminate();
                                    }
<STRING_LITERAL><<EOF>>             {
                                        YY_FATAL_ERROR("Unterminated string literal before EOF.");
                                        yyterminate();
                                    }
<STRING_LITERAL>(\\.|[^"\\])*       SAVE_TOKEN; return Token::TSTRING;


"/*"                                BEGIN(COMMENT_SECTION);
<COMMENT_SECTION>[^*\n]*            /* eat anything that's not a '*' */
<COMMENT_SECTION>"*"+[^*/\n]*       /* eat up '*' not followed by '/' */
<COMMENT_SECTION>\n                 ;
<COMMENT_SECTION>"*"+"/"            BEGIN(INITIAL);


[0-9]+                              SAVE_TOKEN; return Token::TINTEGER;

<<EOF>>                             {
                                        yypop_buffer_state();
                                        if (!YY_CURRENT_BUFFER) {
                                            yyterminate();
                                        }
                                    }

"="                                 return TOKEN(Token::TASSIGN);

"("                                 return TOKEN(Token::TLPAREN);
")"                                 return TOKEN(Token::TRPAREN);
"{"                                 return TOKEN(Token::TLBRACE);
"}"                                 return TOKEN(Token::TRBRACE);

"for"                               return Token::T_FOR;
".."                                return Token::T_RANGE;

"."                                 return TOKEN(Token::TDOT);
","                                 return TOKEN(Token::TCOMMA);
":"                                 return TOKEN(Token::TCOLON);

"&&"                                return TOKEN(Token::T_AND);
"||"                                return TOKEN(Token::T_OR);
"=="                                return TOKEN(Token::T_EQUAL);
"!="                                return TOKEN(Token::T_NOT_EQUAL);
">="                                return TOKEN(Token::T_GREATER_OR_EQUAL);
"<="                                return TOKEN(Token::T_LESS_OR_EQUAL);
">"                                 return TOKEN(Token::T_GREATER);
"<"                                 return TOKEN(Token::T_LESS);
"+"                                 return TOKEN(Token::T_ADD);
"-"                                 return TOKEN(Token::T_SUB);
"*"                                 return TOKEN(Token::T_MUL);
"/"                                 return TOKEN(Token::T_DIV);

"true"                              return Token::T_TRUE;
"false"                             return Token::T_FALSE;

[a-zA-Z_][a-zA-Z0-9_]*              SAVE_TOKEN; return Token::TIDENTIFIER;
.                                   printf("Syntax error: unknown token.\n"); yyterminate();

%%