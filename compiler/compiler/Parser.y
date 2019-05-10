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

%token <string> TINTEGER
%token <string> TSTRING TIDENTIFIER

%token <token> TFUN TVAR TVAL TRETURN TRETURN_VOID TIF TELSE
%token <token> TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TDOT TCOLON TQUOTE
%token <token> T_AND T_OR T_EQUAL 
%token <token> T_NOT_EQUAL T_GREATER_OR_EQUAL T_LESS_OR_EQUAL T_GREATER T_LESS 
%token <token> T_ADD T_SUB T_MUL T_DIV
%token <token> T_TRUE T_FALSE

%type <identifier> identifier
%type <expression> constant expression method_call_expr assignment_expr
%type <expression_vector> method_call_args;
%type <variable_vector> method_decl_args;
%type <block> program statements block
%type <statement> statement var_decl val_decl method_arg_decl method_decl conditional

%left TASSIGN
%left T_ADD T_SUB
%left T_MUL T_DIV
%left T_AND T_OR
%left T_NOT_EQUAL T_GREATER_OR_EQUAL T_LESS_OR_EQUAL T_GREATER T_LESS T_EQUAL

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
        : conditional
        | var_decl
        | val_decl
        | method_decl
        | method_arg_decl
        | expression 
            { $$ = new ExpressionStatement(*$1); } 
        | TRETURN expression
            { $$ = new ReturnStatement(*$2); }
        | TRETURN_VOID
            { $$ = new BlankReturnStatement(); }
;


block 
        : TLBRACE statements TRBRACE    { $$ = $2; }
        | TLBRACE TRBRACE               { $$ = new Block(); }
;


conditional
        : TIF TLPAREN expression TRPAREN block                              
            { $$ = new Conditional($3, $5); }
        | TIF TLPAREN expression TRPAREN block TELSE block  
            { $$ = new Conditional($3, $5, $7); }
;

var_decl 
        : TVAR identifier TCOLON identifier                     { $$ = new VariableDeclaration(*$2, *$4); }
        | TVAR identifier TCOLON identifier TASSIGN expression  { $$ = new VariableDeclaration(*$2, *$4, $6); }
;

val_decl
        : TVAL identifier TCOLON identifier TASSIGN expression { $$ = new VariableDeclaration(*$2, *$4, $6, false); }
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
        | expression T_EQUAL expression 
            { $$ = new Comparison($1, $3, $2); }
        | constant
;

identifier 
        : TIDENTIFIER { $$ = new Identifier(*$1); }
;

constant
        : TINTEGER  { $$ = new Integer(atol($1->c_str())); }
        | TSTRING   { $$ = new String(*$1); }
        | T_TRUE    { $$ = new Boolean(true); }
        | T_FALSE   { $$ = new Boolean(false); }
;

method_call_args 
        :                                               { $$ = new std::vector<Expression*>(); }
        | expression                                    { $$ = new std::vector<Expression*>(); $$->push_back($1); }
        | method_call_args TCOMMA expression            { $1->push_back($3); }
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