%skeleton "lalr1.cc"
%require "3.2"

%defines
%define api.parser.class { Parser }
%define api.namespace { Vues }

%code requires {
    #include "AbstractSyntaxTree.h"
    class Lexer;
}

%{
    #include "AbstractSyntaxTree.h"
    Block* root_block;

    #define YY_EXCEPTIONS 0
    #define YYDEBUG 1
%}

%param { Lexer &lexer }

%code {
    static int yylex(Vues::Parser::semantic_type *yylval, Lexer &lexer);
}

%union {
    int token;
    long long integer;
    std::string* string;

    Node* node;
    Block* block;
    Expression* expression;
    Statement* statement;
    Identifier* identifier;
    VariableDeclaration* var_decl;
    /* Method arguments receive different format of variable declarations. */ 
    VariableDeclaration* method_arg_decl;
    std::vector<Expression*> *expression_vector;
    std::vector<VariableDeclaration*> *variable_vector;
}

%token <integer> TINTEGER
%token <string> TSTRING TIDENTIFIER

%token <token> TDEF TVAR TRETURN
%token <token> TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TDOT TCOLON TQUOTE

%type <identifier> identifier
%type <expression> numeric string_literal expression
%type <expression_vector> call_args;
%type <variable_vector> method_decl_args;
%type <block> program statements block
%type <statement> statement var_decl method_arg_decl method_decl

%left TASSIGN

%start program

%%

program 
        : /* blank */ { root_block = new Block(); }
        | statements { root_block = $1; }
;


statements 
        : statement { $$ = new Block(); $$->statements.push_back($<statement>1); }
        | statements statement { $1->statements.push_back($<statement>2); }
;


statement 
        : var_decl 
        | method_decl
        | method_arg_decl
        | expression { $$ = new ExpressionStatement(*$1); } 
        | TRETURN expression { $$ = new ReturnStatement(*$2); }
;


block 
        : TLBRACE statements TRBRACE { $$ = $2; }
        | TLBRACE TRBRACE { $$ = new Block(); }
;


var_decl 
        : TVAR identifier TCOLON identifier { $$ = new VariableDeclaration(*$2, *$4); }
        | TVAR identifier TCOLON identifier TASSIGN expression { $$ = new VariableDeclaration(*$2, *$4, $6); }
;


method_arg_decl
        : identifier TCOLON identifier { $$ = new VariableDeclaration(*$1, *$3); }
        | identifier TCOLON identifier TASSIGN expression { $$ = new VariableDeclaration(*$1, *$3, $5); }
;


method_decl 
        : TDEF identifier TLPAREN method_decl_args TRPAREN TCOLON identifier block { $$ = new MethodDeclaration(*$2, *$4, *$7, *$8); }
;

method_decl_args 
        : /*blank*/ { $$ = new std::vector<VariableDeclaration*>(); }
        | method_arg_decl { $$ = new std::vector<VariableDeclaration*>(); $$->push_back($<method_arg_decl>1); }
        | method_decl_args TCOMMA method_arg_decl { $1->push_back($<method_arg_decl>3); }
;


expression 
        : identifier TASSIGN expression { $$ = new Assignment(*$<identifier>1, *$3); }
        | identifier TLPAREN call_args TRPAREN { $$ = new MethodCall(*$1, *$3); delete $3; }
        | identifier { $<identifier>$ = $1; }
        | numeric
        | string_literal
;


identifier 
        : TIDENTIFIER { $$ = new Identifier(*$1); delete $1; }
;


numeric 
        : TINTEGER { $$ = new Integer($1); }
;


string_literal 
        : TSTRING { $$ = new String(*$1); delete $1; }
;

           
call_args 
        : /*blank*/ { $$ = new std::vector<Expression*>(); }
        | expression { $$ = new std::vector<Expression*>(); $$->push_back($1); }
        | call_args TCOMMA expression { $1->push_back($3); }
;


%%

#include "Lexer.h"

static int yylex(Vues::Parser::semantic_type *yylval, Lexer &lexer)
{
    return lexer.yylex(yylval);
}

void Vues::Parser::error(const std::string &err)
{
    std::cerr << "Error: " << err << std::endl;
}