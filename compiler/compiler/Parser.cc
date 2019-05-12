// A Bison parser, made by GNU Bison 3.3.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.



// First part of user prologue.
#line 13 "Parser.y" // lalr1.cc:429

    #include "AbstractSyntaxTree.h"
    Block* root_block;

    #define YY_EXCEPTIONS 0
    #define YYDEBUG 1

#line 48 "Parser.cc" // lalr1.cc:429

#include "Parser.h"


// Unqualified %code blocks.
#line 23 "Parser.y" // lalr1.cc:435

    static int yylex(Vues::Parser::semantic_type *yylval, Lexer &lexer);

#line 58 "Parser.cc" // lalr1.cc:435


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 6 "Parser.y" // lalr1.cc:510
namespace  Vues  {
#line 134 "Parser.cc" // lalr1.cc:510

  /// Build a parser object.
   Parser :: Parser  (Lexer &lexer_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      lexer (lexer_yyarg)
  {}

   Parser ::~ Parser  ()
  {}

   Parser ::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value (std::move (that.value))
  {}
#endif

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v)
    : Base (t)
    , value (YY_MOVE (v))
  {}

  template <typename Base>
  bool
   Parser ::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
  }

  // by_type.
   Parser ::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
   Parser ::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

   Parser ::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

   Parser ::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
   Parser ::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
   Parser ::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
   Parser ::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
   Parser ::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   Parser ::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   Parser ::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   Parser ::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   Parser ::symbol_number_type
   Parser ::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

   Parser ::stack_symbol_type::stack_symbol_type ()
  {}

   Parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   Parser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value))
  {
    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
   Parser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   Parser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   Parser ::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
   Parser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   Parser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::operator() ()
  {
    return parse ();
  }

  int
   Parser ::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, lexer));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 73 "Parser.y" // lalr1.cc:919
    { root_block = new Block(); }
#line 561 "Parser.cc" // lalr1.cc:919
    break;

  case 3:
#line 74 "Parser.y" // lalr1.cc:919
    { root_block = (yystack_[0].value.block); }
#line 567 "Parser.cc" // lalr1.cc:919
    break;

  case 4:
#line 79 "Parser.y" // lalr1.cc:919
    { (yylhs.value.block) = new Block(); (yylhs.value.block)->statements.push_back((yystack_[0].value.statement)); }
#line 573 "Parser.cc" // lalr1.cc:919
    break;

  case 5:
#line 80 "Parser.y" // lalr1.cc:919
    { (yystack_[1].value.block)->statements.push_back((yystack_[0].value.statement)); }
#line 579 "Parser.cc" // lalr1.cc:919
    break;

  case 6:
#line 85 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = (yystack_[0].value.statement); }
#line 585 "Parser.cc" // lalr1.cc:919
    break;

  case 7:
#line 86 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = (yystack_[0].value.statement); }
#line 591 "Parser.cc" // lalr1.cc:919
    break;

  case 8:
#line 87 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = (yystack_[0].value.statement); }
#line 597 "Parser.cc" // lalr1.cc:919
    break;

  case 9:
#line 88 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = (yystack_[0].value.statement); }
#line 603 "Parser.cc" // lalr1.cc:919
    break;

  case 10:
#line 89 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = (yystack_[0].value.statement); }
#line 609 "Parser.cc" // lalr1.cc:919
    break;

  case 11:
#line 91 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new ExpressionStatement(*(yystack_[0].value.expression)); }
#line 615 "Parser.cc" // lalr1.cc:919
    break;

  case 12:
#line 93 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new ReturnStatement(*(yystack_[0].value.expression)); }
#line 621 "Parser.cc" // lalr1.cc:919
    break;

  case 13:
#line 95 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new BlankReturnStatement(); }
#line 627 "Parser.cc" // lalr1.cc:919
    break;

  case 14:
#line 97 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new Range((yystack_[2].value.expression), (yystack_[0].value.expression), false); }
#line 633 "Parser.cc" // lalr1.cc:919
    break;

  case 15:
#line 102 "Parser.y" // lalr1.cc:919
    { (yylhs.value.block) = (yystack_[1].value.block); }
#line 639 "Parser.cc" // lalr1.cc:919
    break;

  case 16:
#line 103 "Parser.y" // lalr1.cc:919
    { (yylhs.value.block) = new Block(); }
#line 645 "Parser.cc" // lalr1.cc:919
    break;

  case 17:
#line 109 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new Conditional((yystack_[2].value.expression), (yystack_[0].value.block)); }
#line 651 "Parser.cc" // lalr1.cc:919
    break;

  case 18:
#line 111 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new Conditional((yystack_[4].value.expression), (yystack_[2].value.block), (yystack_[0].value.block)); }
#line 657 "Parser.cc" // lalr1.cc:919
    break;

  case 19:
#line 115 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new VariableDeclaration(*(yystack_[2].value.identifier), *(yystack_[0].value.identifier)); }
#line 663 "Parser.cc" // lalr1.cc:919
    break;

  case 20:
#line 116 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new VariableDeclaration(*(yystack_[4].value.identifier), *(yystack_[2].value.identifier), (yystack_[0].value.expression)); }
#line 669 "Parser.cc" // lalr1.cc:919
    break;

  case 21:
#line 120 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new VariableDeclaration(*(yystack_[4].value.identifier), *(yystack_[2].value.identifier), (yystack_[0].value.expression), false); }
#line 675 "Parser.cc" // lalr1.cc:919
    break;

  case 22:
#line 125 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new VariableDeclaration(*(yystack_[2].value.identifier), *(yystack_[0].value.identifier)); }
#line 681 "Parser.cc" // lalr1.cc:919
    break;

  case 23:
#line 126 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new VariableDeclaration(*(yystack_[4].value.identifier), *(yystack_[2].value.identifier), (yystack_[0].value.expression)); }
#line 687 "Parser.cc" // lalr1.cc:919
    break;

  case 24:
#line 131 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new MethodDeclaration(*(yystack_[4].value.identifier), *(yystack_[2].value.variable_vector), *(yystack_[0].value.block)); }
#line 693 "Parser.cc" // lalr1.cc:919
    break;

  case 25:
#line 132 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new MethodDeclaration(*(yystack_[6].value.identifier), *(yystack_[4].value.variable_vector), *(yystack_[1].value.identifier), *(yystack_[0].value.block)); }
#line 699 "Parser.cc" // lalr1.cc:919
    break;

  case 26:
#line 136 "Parser.y" // lalr1.cc:919
    { (yylhs.value.variable_vector) = new std::vector<VariableDeclaration*>(); }
#line 705 "Parser.cc" // lalr1.cc:919
    break;

  case 27:
#line 137 "Parser.y" // lalr1.cc:919
    { (yylhs.value.variable_vector) = new std::vector<VariableDeclaration*>(); (yylhs.value.variable_vector)->push_back((yystack_[0].value.method_arg_decl)); }
#line 711 "Parser.cc" // lalr1.cc:919
    break;

  case 28:
#line 138 "Parser.y" // lalr1.cc:919
    { (yystack_[2].value.variable_vector)->push_back((yystack_[0].value.method_arg_decl)); }
#line 717 "Parser.cc" // lalr1.cc:919
    break;

  case 29:
#line 142 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new MethodCall(*(yystack_[3].value.identifier), *(yystack_[1].value.expression_vector)); }
#line 723 "Parser.cc" // lalr1.cc:919
    break;

  case 30:
#line 146 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Assignment(*(yystack_[2].value.identifier), *(yystack_[0].value.expression)); }
#line 729 "Parser.cc" // lalr1.cc:919
    break;

  case 31:
#line 150 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = (yystack_[0].value.expression); }
#line 735 "Parser.cc" // lalr1.cc:919
    break;

  case 32:
#line 151 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = (yystack_[0].value.expression); }
#line 741 "Parser.cc" // lalr1.cc:919
    break;

  case 33:
#line 152 "Parser.y" // lalr1.cc:919
    { (yylhs.value.identifier) = (yystack_[0].value.identifier); }
#line 747 "Parser.cc" // lalr1.cc:919
    break;

  case 34:
#line 154 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Comparison((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 753 "Parser.cc" // lalr1.cc:919
    break;

  case 35:
#line 156 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Comparison((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 759 "Parser.cc" // lalr1.cc:919
    break;

  case 36:
#line 158 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Comparison((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 765 "Parser.cc" // lalr1.cc:919
    break;

  case 37:
#line 160 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Comparison((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 771 "Parser.cc" // lalr1.cc:919
    break;

  case 38:
#line 162 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Comparison((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 777 "Parser.cc" // lalr1.cc:919
    break;

  case 39:
#line 164 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Comparison((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 783 "Parser.cc" // lalr1.cc:919
    break;

  case 40:
#line 166 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Binary((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 789 "Parser.cc" // lalr1.cc:919
    break;

  case 41:
#line 168 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Binary((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 795 "Parser.cc" // lalr1.cc:919
    break;

  case 42:
#line 170 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Binary((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 801 "Parser.cc" // lalr1.cc:919
    break;

  case 43:
#line 172 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Binary((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 807 "Parser.cc" // lalr1.cc:919
    break;

  case 44:
#line 174 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Binary((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 813 "Parser.cc" // lalr1.cc:919
    break;

  case 45:
#line 176 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Binary((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 819 "Parser.cc" // lalr1.cc:919
    break;

  case 46:
#line 177 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = (yystack_[0].value.expression); }
#line 825 "Parser.cc" // lalr1.cc:919
    break;

  case 47:
#line 182 "Parser.y" // lalr1.cc:919
    { (yylhs.value.identifier) = new Identifier(*(yystack_[0].value.string)); }
#line 831 "Parser.cc" // lalr1.cc:919
    break;

  case 48:
#line 186 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Integer(atol((yystack_[0].value.string)->c_str())); }
#line 837 "Parser.cc" // lalr1.cc:919
    break;

  case 49:
#line 187 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new String(*(yystack_[0].value.string)); }
#line 843 "Parser.cc" // lalr1.cc:919
    break;

  case 50:
#line 188 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Boolean(true); }
#line 849 "Parser.cc" // lalr1.cc:919
    break;

  case 51:
#line 189 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Boolean(false); }
#line 855 "Parser.cc" // lalr1.cc:919
    break;

  case 52:
#line 193 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression_vector) = new std::vector<Expression*>(); }
#line 861 "Parser.cc" // lalr1.cc:919
    break;

  case 53:
#line 194 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression_vector) = new std::vector<Expression*>(); (yylhs.value.expression_vector)->push_back((yystack_[0].value.expression)); }
#line 867 "Parser.cc" // lalr1.cc:919
    break;

  case 54:
#line 195 "Parser.y" // lalr1.cc:919
    { (yystack_[2].value.expression_vector)->push_back((yystack_[0].value.expression)); }
#line 873 "Parser.cc" // lalr1.cc:919
    break;


#line 877 "Parser.cc" // lalr1.cc:919
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
   Parser ::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char  Parser ::yypact_ninf_ = -72;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short
   Parser ::yypact_[] =
  {
      91,   -72,   -72,   -72,    -2,    -2,    -2,    85,   -72,    -4,
     -72,   -72,    12,    91,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   118,    33,   -72,    13,    29,    34,    82,    55,
      85,   -72,   -72,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    -2,    85,    -2,
      -2,    -2,   106,   152,   152,   -72,   -72,   -72,   -72,   -72,
     -72,   134,   134,   146,   146,    82,    82,    -7,    27,    82,
     -72,    49,    52,    37,    38,    63,   -72,    85,    85,    50,
      -2,    85,    85,    11,    67,    82,    82,    -2,   -72,   -72,
      82,    82,   -72,    51,    63,    63,   -72,   -72,   -72
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       2,    48,    49,    47,     0,     0,     0,     0,    13,     0,
      50,    51,     0,     3,     4,     6,     7,     8,    10,     9,
      31,    32,    11,    33,    46,     0,     0,     0,    12,    33,
       0,     1,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,     0,     0,    26,
       0,     0,     0,    40,    41,    34,    39,    36,    38,    35,
      37,    42,    43,    45,    44,    14,    53,     0,    22,    30,
      27,     0,     0,    19,     0,     0,    29,     0,     0,     0,
       0,     0,     0,     0,    17,    54,    23,     0,    24,    28,
      20,    21,    16,     0,     0,     0,    15,    18,    25
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -72,   -72,    -1,   -12,   -71,   -72,   -72,   -72,   -38,   -72,
     -72,   -72,   -72,    -5,     0,   -72,   -72
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
      -1,    12,    13,    14,    84,    15,    16,    17,    18,    19,
      71,    20,    21,    22,    29,    24,    67
  };

  const unsigned char
   Parser ::yytable_[] =
  {
      23,    32,    28,     3,    25,    26,    27,    76,    88,    30,
      77,    70,    31,    23,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    97,    98,    52,    49,    92,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    89,    69,    10,    11,    46,    68,    50,    72,
      73,    74,    47,    51,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    79,    78,    83,    80,    96,    46,    87,
      48,    47,    85,    86,    81,    82,    90,    91,    83,    94,
      72,    32,    93,    23,    10,    11,     0,    95,     1,     2,
       3,     0,    48,    23,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,     0,     0,    10,    11,
      75,     0,     0,     0,    10,    11,     0,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,     0,     0,    45,    33,    34,    35,    36,    37,
      38,    39,    40,     0,     0,    43,    44,    33,    34,    35,
      36,    37,    38,    39,    40,    35,    36,    37,    38,    39,
      40
  };

  const signed char
   Parser ::yycheck_[] =
  {
       0,    13,     7,     5,     4,     5,     6,    14,    79,    13,
      17,    49,     0,    13,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    94,    95,    30,    13,    16,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    80,    48,    33,    34,    13,    47,    19,    49,
      50,    51,    19,    19,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    14,    37,    15,    17,    16,    13,    19,
      37,    19,    77,    78,    37,    37,    81,    82,    15,    12,
      80,    93,    83,    83,    33,    34,    -1,    87,     3,     4,
       5,    -1,    37,    93,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    33,    34,
      14,    -1,    -1,    -1,    33,    34,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    36,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    32,    21,    22,    23,
      24,    25,    26,    27,    28,    23,    24,    25,    26,    27,
      28
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      33,    34,    39,    40,    41,    43,    44,    45,    46,    47,
      49,    50,    51,    52,    53,    52,    52,    52,    51,    52,
      13,     0,    41,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    36,    13,    19,    37,    13,
      19,    19,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    54,    52,    51,
      46,    48,    52,    52,    52,    14,    14,    17,    37,    14,
      17,    37,    37,    15,    42,    51,    51,    19,    42,    46,
      51,    51,    16,    40,    12,    52,    16,    42,    42
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    38,    39,    39,    40,    40,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    42,    42,    43,    43,    44,
      44,    45,    46,    46,    47,    47,    48,    48,    48,    49,
      50,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    52,    53,    53,
      53,    53,    54,    54,    54
  };

  const unsigned char
   Parser ::yyr2_[] =
  {
       0,     2,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     3,     2,     5,     7,     4,
       6,     6,     3,     5,     6,     8,     0,     1,     3,     4,
       3,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     0,     1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "$end", "error", "$undefined", "TINTEGER", "TSTRING", "TIDENTIFIER",
  "TFUN", "TVAR", "TVAL", "TRETURN", "TRETURN_VOID", "TIF", "TELSE",
  "TLPAREN", "TRPAREN", "TLBRACE", "TRBRACE", "TCOMMA", "TDOT", "TCOLON",
  "TQUOTE", "T_AND", "T_OR", "T_EQUAL", "T_NOT_EQUAL",
  "T_GREATER_OR_EQUAL", "T_LESS_OR_EQUAL", "T_GREATER", "T_LESS", "T_ADD",
  "T_SUB", "T_MUL", "T_DIV", "T_TRUE", "T_FALSE", "T_FOR", "T_RANGE",
  "TASSIGN", "$accept", "program", "statements", "statement", "block",
  "conditional", "var_decl", "val_decl", "method_arg_decl", "method_decl",
  "method_decl_args", "method_call_expr", "assignment_expr", "expression",
  "identifier", "constant", "method_call_args", YY_NULLPTR
  };


  const unsigned char
   Parser ::yyrline_[] =
  {
       0,    73,    73,    74,    79,    80,    85,    86,    87,    88,
      89,    90,    92,    94,    96,   102,   103,   108,   110,   115,
     116,   120,   125,   126,   131,   132,   136,   137,   138,   142,
     146,   150,   151,   152,   153,   155,   157,   159,   161,   163,
     165,   167,   169,   171,   173,   175,   177,   182,   186,   187,
     188,   189,   193,   194,   195
  };

  // Print the state stack on the debug stream.
  void
   Parser ::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
   Parser ::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

   Parser ::token_number_type
   Parser ::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
    };
    const unsigned user_token_number_max_ = 292;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 6 "Parser.y" // lalr1.cc:1242
} //  Vues 
#line 1299 "Parser.cc" // lalr1.cc:1242
#line 199 "Parser.y" // lalr1.cc:1243


#include "Lexer.h"

static int yylex(Vues::Parser::semantic_type *yylval, Lexer &lexer)
{
    return lexer.yylex(yylval);
}

void Vues::Parser::error(const std::string &err)
{
    std::cerr << "Error: " << err << std::endl;
}
