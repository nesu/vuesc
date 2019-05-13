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
#line 74 "Parser.y" // lalr1.cc:919
    { root_block = new Block(); }
#line 561 "Parser.cc" // lalr1.cc:919
    break;

  case 3:
#line 76 "Parser.y" // lalr1.cc:919
    { root_block = (yystack_[0].value.block); }
#line 567 "Parser.cc" // lalr1.cc:919
    break;

  case 4:
#line 82 "Parser.y" // lalr1.cc:919
    { (yylhs.value.block) = new Block(); (yylhs.value.block)->statements.push_back((yystack_[0].value.statement)); }
#line 573 "Parser.cc" // lalr1.cc:919
    break;

  case 5:
#line 84 "Parser.y" // lalr1.cc:919
    { (yystack_[1].value.block)->statements.push_back((yystack_[0].value.statement)); }
#line 579 "Parser.cc" // lalr1.cc:919
    break;

  case 6:
#line 89 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = (yystack_[0].value.statement); }
#line 585 "Parser.cc" // lalr1.cc:919
    break;

  case 7:
#line 90 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = (yystack_[0].value.statement); }
#line 591 "Parser.cc" // lalr1.cc:919
    break;

  case 8:
#line 91 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = (yystack_[0].value.statement); }
#line 597 "Parser.cc" // lalr1.cc:919
    break;

  case 9:
#line 92 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = (yystack_[0].value.statement); }
#line 603 "Parser.cc" // lalr1.cc:919
    break;

  case 10:
#line 93 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = (yystack_[0].value.statement); }
#line 609 "Parser.cc" // lalr1.cc:919
    break;

  case 11:
#line 94 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = (yystack_[0].value.statement); }
#line 615 "Parser.cc" // lalr1.cc:919
    break;

  case 12:
#line 96 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new ExpressionStatement(*(yystack_[0].value.expression)); }
#line 621 "Parser.cc" // lalr1.cc:919
    break;

  case 13:
#line 98 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new ReturnStatement(*(yystack_[0].value.expression)); }
#line 627 "Parser.cc" // lalr1.cc:919
    break;

  case 14:
#line 100 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new BlankReturnStatement(); }
#line 633 "Parser.cc" // lalr1.cc:919
    break;

  case 15:
#line 106 "Parser.y" // lalr1.cc:919
    { (yylhs.value.block) = (yystack_[1].value.block); }
#line 639 "Parser.cc" // lalr1.cc:919
    break;

  case 16:
#line 108 "Parser.y" // lalr1.cc:919
    { (yylhs.value.block) = new Block(); }
#line 645 "Parser.cc" // lalr1.cc:919
    break;

  case 17:
#line 113 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new For(*(yystack_[6].value.identifier), (yystack_[4].value.expression), (yystack_[2].value.expression), nullptr, true, (yystack_[0].value.block)); }
#line 651 "Parser.cc" // lalr1.cc:919
    break;

  case 18:
#line 115 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new For(*(yystack_[8].value.identifier), (yystack_[6].value.expression), (yystack_[4].value.expression), (yystack_[2].value.expression), true, (yystack_[0].value.block)); }
#line 657 "Parser.cc" // lalr1.cc:919
    break;

  case 19:
#line 117 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new For(*(yystack_[6].value.identifier), (yystack_[4].value.expression), (yystack_[2].value.expression), nullptr, false, (yystack_[0].value.block)); }
#line 663 "Parser.cc" // lalr1.cc:919
    break;

  case 20:
#line 119 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new For(*(yystack_[8].value.identifier), (yystack_[6].value.expression), (yystack_[4].value.expression), (yystack_[2].value.expression), false, (yystack_[0].value.block)); }
#line 669 "Parser.cc" // lalr1.cc:919
    break;

  case 21:
#line 125 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new Conditional((yystack_[2].value.expression), (yystack_[0].value.block)); }
#line 675 "Parser.cc" // lalr1.cc:919
    break;

  case 22:
#line 127 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new Conditional((yystack_[4].value.expression), (yystack_[2].value.block), (yystack_[0].value.block)); }
#line 681 "Parser.cc" // lalr1.cc:919
    break;

  case 23:
#line 132 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new VariableDeclaration(*(yystack_[2].value.identifier), *(yystack_[0].value.identifier)); }
#line 687 "Parser.cc" // lalr1.cc:919
    break;

  case 24:
#line 134 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new VariableDeclaration(*(yystack_[4].value.identifier), *(yystack_[2].value.identifier), (yystack_[0].value.expression)); }
#line 693 "Parser.cc" // lalr1.cc:919
    break;

  case 25:
#line 139 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new VariableDeclaration(*(yystack_[4].value.identifier), *(yystack_[2].value.identifier), (yystack_[0].value.expression), false); }
#line 699 "Parser.cc" // lalr1.cc:919
    break;

  case 26:
#line 145 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new VariableDeclaration(*(yystack_[2].value.identifier), *(yystack_[0].value.identifier)); }
#line 705 "Parser.cc" // lalr1.cc:919
    break;

  case 27:
#line 147 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new VariableDeclaration(*(yystack_[4].value.identifier), *(yystack_[2].value.identifier), (yystack_[0].value.expression)); }
#line 711 "Parser.cc" // lalr1.cc:919
    break;

  case 28:
#line 153 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new MethodDeclaration(*(yystack_[4].value.identifier), *(yystack_[2].value.variable_vector), *(yystack_[0].value.block)); }
#line 717 "Parser.cc" // lalr1.cc:919
    break;

  case 29:
#line 155 "Parser.y" // lalr1.cc:919
    { (yylhs.value.statement) = new MethodDeclaration(*(yystack_[6].value.identifier), *(yystack_[4].value.variable_vector), *(yystack_[1].value.identifier), *(yystack_[0].value.block)); }
#line 723 "Parser.cc" // lalr1.cc:919
    break;

  case 30:
#line 160 "Parser.y" // lalr1.cc:919
    { (yylhs.value.variable_vector) = new std::vector<VariableDeclaration*>(); }
#line 729 "Parser.cc" // lalr1.cc:919
    break;

  case 31:
#line 162 "Parser.y" // lalr1.cc:919
    { (yylhs.value.variable_vector) = new std::vector<VariableDeclaration*>(); (yylhs.value.variable_vector)->push_back((yystack_[0].value.method_arg_decl)); }
#line 735 "Parser.cc" // lalr1.cc:919
    break;

  case 32:
#line 164 "Parser.y" // lalr1.cc:919
    { (yystack_[2].value.variable_vector)->push_back((yystack_[0].value.method_arg_decl)); }
#line 741 "Parser.cc" // lalr1.cc:919
    break;

  case 33:
#line 169 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new MethodCall(*(yystack_[3].value.identifier), *(yystack_[1].value.expression_vector)); }
#line 747 "Parser.cc" // lalr1.cc:919
    break;

  case 34:
#line 174 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Assignment(*(yystack_[2].value.identifier), *(yystack_[0].value.expression)); }
#line 753 "Parser.cc" // lalr1.cc:919
    break;

  case 35:
#line 178 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = (yystack_[0].value.expression); }
#line 759 "Parser.cc" // lalr1.cc:919
    break;

  case 36:
#line 179 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = (yystack_[0].value.expression); }
#line 765 "Parser.cc" // lalr1.cc:919
    break;

  case 37:
#line 180 "Parser.y" // lalr1.cc:919
    { (yylhs.value.identifier) = (yystack_[0].value.identifier); }
#line 771 "Parser.cc" // lalr1.cc:919
    break;

  case 38:
#line 182 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Comparison((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 777 "Parser.cc" // lalr1.cc:919
    break;

  case 39:
#line 184 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Comparison((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 783 "Parser.cc" // lalr1.cc:919
    break;

  case 40:
#line 186 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Comparison((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 789 "Parser.cc" // lalr1.cc:919
    break;

  case 41:
#line 188 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Comparison((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 795 "Parser.cc" // lalr1.cc:919
    break;

  case 42:
#line 190 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Comparison((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 801 "Parser.cc" // lalr1.cc:919
    break;

  case 43:
#line 192 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Comparison((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 807 "Parser.cc" // lalr1.cc:919
    break;

  case 44:
#line 194 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Binary((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 813 "Parser.cc" // lalr1.cc:919
    break;

  case 45:
#line 196 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Binary((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 819 "Parser.cc" // lalr1.cc:919
    break;

  case 46:
#line 198 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Binary((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 825 "Parser.cc" // lalr1.cc:919
    break;

  case 47:
#line 200 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Binary((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 831 "Parser.cc" // lalr1.cc:919
    break;

  case 48:
#line 202 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Binary((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 837 "Parser.cc" // lalr1.cc:919
    break;

  case 49:
#line 204 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Binary((yystack_[2].value.expression), (yystack_[0].value.expression), (yystack_[1].value.token)); }
#line 843 "Parser.cc" // lalr1.cc:919
    break;

  case 50:
#line 205 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = (yystack_[0].value.expression); }
#line 849 "Parser.cc" // lalr1.cc:919
    break;

  case 51:
#line 210 "Parser.y" // lalr1.cc:919
    { (yylhs.value.identifier) = new Identifier(*(yystack_[0].value.string)); }
#line 855 "Parser.cc" // lalr1.cc:919
    break;

  case 52:
#line 215 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Integer(atol((yystack_[0].value.string)->c_str())); }
#line 861 "Parser.cc" // lalr1.cc:919
    break;

  case 53:
#line 217 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new String(*(yystack_[0].value.string)); }
#line 867 "Parser.cc" // lalr1.cc:919
    break;

  case 54:
#line 219 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Boolean(true); }
#line 873 "Parser.cc" // lalr1.cc:919
    break;

  case 55:
#line 221 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression) = new Boolean(false); }
#line 879 "Parser.cc" // lalr1.cc:919
    break;

  case 56:
#line 226 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression_vector) = new std::vector<Expression*>(); }
#line 885 "Parser.cc" // lalr1.cc:919
    break;

  case 57:
#line 228 "Parser.y" // lalr1.cc:919
    { (yylhs.value.expression_vector) = new std::vector<Expression*>(); (yylhs.value.expression_vector)->push_back((yystack_[0].value.expression)); }
#line 891 "Parser.cc" // lalr1.cc:919
    break;

  case 58:
#line 230 "Parser.y" // lalr1.cc:919
    { (yystack_[2].value.expression_vector)->push_back((yystack_[0].value.expression)); }
#line 897 "Parser.cc" // lalr1.cc:919
    break;


#line 901 "Parser.cc" // lalr1.cc:919
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


  const signed char  Parser ::yypact_ninf_ = -57;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short
   Parser ::yypact_[] =
  {
     141,   -57,   -57,   -57,    -3,    -3,    -3,    52,   -57,   -10,
     -57,   -57,     3,    21,   141,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   245,     9,   -57,    10,     5,    31,
     245,     7,    52,    -3,   -57,   -57,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    -3,
      52,    -3,    -3,    -3,   177,    18,   188,   188,   -57,   -57,
     -57,   -57,   -57,   -57,   -17,   -17,   257,   257,   245,    44,
      23,   245,   -57,    53,    49,    29,    32,    60,    52,   -57,
      52,    52,    33,    -3,    52,    52,   108,    64,   227,   245,
     245,    -3,   -57,   -57,   245,   245,   -57,   122,    60,    52,
      52,    60,   -57,   -57,   139,   158,   -57,    60,    52,    60,
      52,   -57,   196,   -57,   215,    60,    60,   -57,   -57
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       2,    52,    53,    51,     0,     0,     0,     0,    14,     0,
      54,    55,     0,     0,     3,     4,    11,     6,     7,     8,
      10,     9,    35,    36,    12,    37,    50,     0,     0,     0,
      13,    37,     0,     0,     1,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    56,     0,
       0,    30,     0,     0,     0,     0,    44,    45,    38,    43,
      40,    42,    39,    41,    46,    47,    49,    48,    57,     0,
      26,    34,    31,     0,     0,    23,     0,     0,     0,    33,
       0,     0,     0,     0,     0,     0,     0,    21,     0,    58,
      27,     0,    28,    32,    24,    25,    16,     0,     0,     0,
       0,     0,    15,    22,     0,     0,    29,     0,     0,     0,
       0,    17,     0,    19,     0,     0,     0,    18,    20
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -57,   -57,    -6,   -13,   -56,   -57,   -57,   -57,   -57,   -39,
     -57,   -57,   -57,   -57,    -7,    13,   -57,   -57
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
      -1,    13,    14,    15,    87,    16,    17,    18,    19,    20,
      21,    73,    22,    23,    24,    31,    26,    69
  };

  const unsigned char
   Parser ::yytable_[] =
  {
      30,    35,     3,    32,    36,    37,    38,    39,    40,    41,
      42,    43,    72,    25,    46,    47,    33,    27,    28,    29,
      48,    34,    48,    51,    52,    54,    92,    25,    49,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   103,    71,    93,   106,    55,    50,    86,    50,
      53,   111,    91,   113,    78,     1,     2,     3,    79,   117,
     118,    80,    70,    81,    74,    75,    76,    82,    49,    84,
      83,    88,    85,    89,    90,    86,    98,    94,    95,     0,
      97,     0,     0,     0,    35,    10,    11,     0,     0,     0,
       0,     0,   104,   105,     0,     0,    74,     0,     0,    25,
       0,   112,     0,   114,   101,     0,     0,     0,     0,     0,
      25,     1,     2,     3,     4,     5,     6,     7,     8,     9,
       0,     0,     0,     0,    96,     1,     2,     3,     4,     5,
       6,     7,     8,     9,     0,     0,     0,     0,   102,     0,
       0,    10,    11,    12,     1,     2,     3,     4,     5,     6,
       7,     8,     9,   107,     0,    10,    11,    12,     0,     0,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,   109,     0,    10,    11,    12,     0,   108,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    77,     0,     0,     0,     0,     0,   110,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
     115,    38,    39,    40,    41,    42,    43,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,   116,
       0,     0,     0,     0,     0,     0,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,     0,     0,     0,    99,   100,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    36,    37,
      38,    39,    40,    41,    42,    43
  };

  const signed char
   Parser ::yycheck_[] =
  {
       7,    14,     5,    13,    21,    22,    23,    24,    25,    26,
      27,    28,    51,     0,    31,    32,    13,     4,     5,     6,
      13,     0,    13,    13,    19,    32,    82,    14,    19,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    98,    50,    83,   101,    33,    40,    15,    40,
      19,   107,    19,   109,    36,     3,     4,     5,    14,   115,
     116,    17,    49,    40,    51,    52,    53,    14,    19,    40,
      17,    78,    40,    80,    81,    15,    12,    84,    85,    -1,
      86,    -1,    -1,    -1,    97,    33,    34,    -1,    -1,    -1,
      -1,    -1,    99,   100,    -1,    -1,    83,    -1,    -1,    86,
      -1,   108,    -1,   110,    91,    -1,    -1,    -1,    -1,    -1,
      97,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    16,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    33,    34,    35,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    14,    -1,    33,    34,    35,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    14,    -1,    33,    34,    35,    -1,    39,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    14,    -1,    -1,    -1,    -1,    -1,    39,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      14,    23,    24,    25,    26,    27,    28,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    37,    38,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    21,    22,
      23,    24,    25,    26,    27,    28
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      33,    34,    35,    42,    43,    44,    46,    47,    48,    49,
      50,    51,    53,    54,    55,    56,    57,    56,    56,    56,
      55,    56,    13,    13,     0,    44,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    13,    19,
      40,    13,    19,    19,    55,    56,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    58,
      56,    55,    50,    52,    56,    56,    56,    14,    36,    14,
      17,    40,    14,    17,    40,    40,    15,    45,    55,    55,
      55,    19,    45,    50,    55,    55,    16,    43,    12,    37,
      38,    56,    16,    45,    55,    55,    45,    14,    39,    14,
      39,    45,    55,    45,    55,    14,    14,    45,    45
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    41,    42,    42,    43,    43,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    45,    45,    46,    46,    46,
      46,    47,    47,    48,    48,    49,    50,    50,    51,    51,
      52,    52,    52,    53,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    56,    57,    57,    57,    57,    58,    58,    58
  };

  const unsigned char
   Parser ::yyr2_[] =
  {
       0,     2,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     2,     9,    11,     9,
      11,     5,     7,     4,     6,     6,     3,     5,     6,     8,
       0,     1,     3,     4,     3,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     0,     1,     3
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
  "T_SUB", "T_MUL", "T_DIV", "T_TRUE", "T_FALSE", "T_FOR", "T_IN",
  "T_RANGE", "T_UNTIL", "T_STEP", "TASSIGN", "$accept", "program",
  "statements", "statement", "block", "for_statement", "conditional",
  "var_decl", "val_decl", "method_arg_decl", "method_decl",
  "method_decl_args", "method_call_expr", "assignment_expr", "expression",
  "identifier", "constant", "method_call_args", YY_NULLPTR
  };


  const unsigned char
   Parser ::yyrline_[] =
  {
       0,    74,    74,    75,    81,    83,    89,    90,    91,    92,
      93,    94,    95,    97,    99,   105,   107,   112,   114,   116,
     118,   124,   126,   131,   133,   138,   144,   146,   152,   154,
     160,   161,   163,   168,   173,   178,   179,   180,   181,   183,
     185,   187,   189,   191,   193,   195,   197,   199,   201,   203,
     205,   209,   214,   216,   218,   220,   226,   227,   229
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
      35,    36,    37,    38,    39,    40
    };
    const unsigned user_token_number_max_ = 295;
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
#line 1350 "Parser.cc" // lalr1.cc:1242
#line 234 "Parser.y" // lalr1.cc:1243


#include "Lexer.h"

static int yylex(Vues::Parser::semantic_type *yylval, Lexer &lexer)
{
    return lexer.yylex(yylval);
}

void Vues::Parser::error(const std::string &err)
{
    std::cerr << "Error: " << err << std::endl;
}
