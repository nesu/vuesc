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

%token <token> TFUN TVAR TVAL TRETURN
%token <token> TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TDOT TCOLON TQUOTE

%type <identifier> identifier
%type <expression> constant expression method_call_expr method_call_arg assignment_expr
%type <expression_vector> method_call_args;
%type <variable_vector> method_decl_args;
%type <block> program statements block
%type <statement> statement var_decl val_decl method_arg_decl method_decl return_statement

%left TASSIGN

%start program

%%

program 
        : /* blank */   { root_block = new Block(); }
        | statements    { root_block = $1; }
;


statements 
        : statement                 { $$ = new Block(); $$->statements.push_back($<statement>1); }
        | statements statement      { $1->statements.push_back($<statement>2); }
;


statement 
        : var_decl
        | val_decl
        | method_decl
        | method_arg_decl
        | return_statement
        | expression { $$ = new ExpressionStatement(*$1); } 
;


block 
        : TLBRACE statements TRBRACE    { $$ = $2; }
        | TLBRACE TRBRACE               { $$ = new Block(); }
;


return_statement
        : TRETURN identifier        { $$ = new ReturnStatement(*$2); }
        | TRETURN method_call_expr  { $$ = new ReturnStatement(*$2); }
        | TRETURN constant          { $$ = new ReturnStatement(*$2); }
        | TRETURN                   { $$ = new BlankReturnStatement(); }
;

var_decl 
        : TVAR identifier TCOLON identifier                     { $$ = new VariableDeclaration(*$2, *$4); }
        | TVAR identifier TCOLON identifier TASSIGN expression  { $$ = new VariableDeclaration(*$2, *$4, $6); }
;

val_decl
        : TVAL identifier TCOLON identifier TASSIGN expression { $$ = new VariableDeclaration(*$2, *$4, $6); }
;


method_arg_decl
        : identifier TCOLON identifier                      { $$ = new VariableDeclaration(*$1, *$3); }
        | identifier TCOLON identifier TASSIGN expression   { $$ = new VariableDeclaration(*$1, *$3, $5); }
;


method_decl 
        : TFUN identifier TLPAREN method_decl_args TRPAREN block                    { $$ = new MethodDeclaration(*$2, *$4, *$6); }
        | TFUN identifier TLPAREN method_decl_args TRPAREN TCOLON identifier block  { $$ = new MethodDeclaration(*$2, *$4, *$7, *$8); }
;

method_decl_args 
        :                                           { $$ = new std::vector<VariableDeclaration*>(); }
        | method_arg_decl                           { $$ = new std::vector<VariableDeclaration*>(); $$->push_back($<method_arg_decl>1); }
        | method_decl_args TCOMMA method_arg_decl   { $1->push_back($<method_arg_decl>3); }
;

method_call_expr
        : identifier TLPAREN method_call_args TRPAREN { $$ = new MethodCall(*$1, *$3); }
;

assignment_expr
        : identifier TASSIGN expression { $$ = new Assignment(*$<identifier>1, *$3); }
;

expression 
        : method_call_expr
        | assignment_expr
        | identifier { $<identifier>$ = $1; }
        | constant
;


identifier 
        : TIDENTIFIER { $$ = new Identifier(*$1); }
;

constant
        : TINTEGER  { $$ = new Integer($1); }
        | TSTRING   { $$ = new String(*$1); }
;

method_call_arg
        : identifier        { $<identifier>$ = $1; }
        | method_call_expr
        | constant
;
           
method_call_args 
        :                                               { $$ = new std::vector<Expression*>(); }
        | method_call_arg                               { $$ = new std::vector<Expression*>(); $$->push_back($1); }
        | method_call_args TCOMMA method_call_arg       { $1->push_back($3); }
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