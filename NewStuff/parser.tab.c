/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

/*
 * Parts of this file were taken from the examples at http://aquamentus.com/flex_bison.html
 */

#include <cstdio>
#include <iostream>
#include "abstract_syntax_tree.h"
using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int lineNumber;
extern int yyparse();


void yyerror(const char *s);
int condition = 0;

#line 87 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CLASS = 258,
    DEF = 259,
    EXTENDS = 260,
    IF = 261,
    ELIF = 262,
    ELSE = 263,
    WHILE = 264,
    RETURN = 265,
    DOT = 266,
    STRING_LIT = 267,
    IDENT = 268,
    STRING = 269,
    INT_LIT = 270,
    INTEGER = 271,
    EQ = 272,
    GEQ = 273,
    LEQ = 274,
    GT = 275,
    LT = 276,
    AND = 277,
    OR = 278,
    NOT = 279,
    PLUS = 280,
    MINUS = 281,
    MULT = 282,
    DIVIDE = 283
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 22 "parser.y" /* yacc.c:355  */

	int ival;
	char* sval;
	bool bval;
  	struct tree_node* treeNode; 


#line 164 "parser.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 179 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   253

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      29,    30,     2,     2,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    31,    35,
       2,    36,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    54,    62,    63,    68,    69,    75,    82,
      93,   104,   113,   114,   120,   127,   135,   136,   142,   150,
     161,   164,   168,   172,   177,   183,   192,   198,   205,   213,
     216,   217,   223,   228,   236,   244,   257,   262,   268,   274,
     280,   286,   292,   298,   304,   312,   317,   322,   327,   335,
     342,   347,   354,   355,   358,   363,   368,   371,   374,   377,
     382,   390,   392
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "DEF", "EXTENDS", "IF", "ELIF",
  "ELSE", "WHILE", "RETURN", "DOT", "STRING_LIT", "IDENT", "STRING",
  "INT_LIT", "INTEGER", "EQ", "GEQ", "LEQ", "GT", "LT", "AND", "OR", "NOT",
  "PLUS", "MINUS", "MULT", "DIVIDE", "'('", "')'", "':'", "','", "'{'",
  "'}'", "';'", "'='", "$accept", "start", "program", "class_declarations",
  "statements", "class", "class_signature", "parameter", "formal_args",
  "class_body", "methods", "method", "statement_block", "else_clause",
  "elseif_header", "elseif_block", "if_statement", "if_header",
  "statement", "l_expr", "boolean_operator", "arithmetic_operator",
  "r_expr", "testFinal", "dotMatcher", "actual_args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    40,
      41,    58,    44,   123,   125,    59,    61
};
# endif

#define YYPACT_NINF -90

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-90)))

#define YYTABLE_NINF -38

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,     6,    21,   -90,    90,     9,    -6,    14,   -90,    35,
      15,    35,   -90,    30,   -90,    35,   -90,   -90,    13,    45,
      46,    95,   -90,   -90,    63,   -90,    39,    24,   225,    35,
     114,    35,   189,    -5,    18,   -90,    49,    35,    67,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
     -90,   -90,   -90,   -90,    77,    53,    54,    55,    74,   207,
     -90,   171,    58,   -90,    59,    35,    13,   -90,    13,   -90,
      62,   133,    34,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
     -90,   -90,   -90,   -90,    81,    61,    77,    88,    39,    99,
      78,    13,    35,   -90,   -90,   225,   -90,    18,    35,   -90,
      35,    79,   -90,   -90,   -90,   -90,    96,   -90,   -90,   -90,
     -90,   152,    80,    39,   -90,   -90,   -90,    94,   -18,    98,
     -90,    13,   -90
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     2,    52,     4,     0,     0,     1,    52,
       0,    52,    56,    53,    57,    52,     3,    30,     0,    52,
       0,     0,    51,     5,    52,     8,    12,    53,    29,    52,
       0,    52,     0,    52,    26,     7,     0,    52,     0,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      35,    49,    50,    54,    16,     0,    13,     0,     0,     0,
      32,    62,     0,    58,     0,    52,     0,    27,     0,    28,
       0,     0,    60,    40,    41,    42,    43,    44,    39,    38,
      45,    46,    47,    48,     0,     0,    16,     0,    12,    10,
      60,     0,    52,    55,    20,    22,    21,    23,    52,    33,
      52,     0,    15,    17,    11,    14,     0,    31,    61,    24,
      25,     0,     0,    12,     9,    34,    59,     0,     0,     0,
      19,     0,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -90,   -90,   -90,   121,   -10,   -90,   -90,   -90,   -71,   -90,
      41,   -90,   -50,    31,   -90,    32,   -90,   -90,   -90,   -90,
     -90,   -90,    -9,   -90,   -90,   -89
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    16,     5,     6,    56,    57,    25,
      85,    86,    34,    67,    68,    69,    17,    18,    19,    20,
      51,    52,    21,    22,    53,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      28,     9,    30,   108,    10,    11,    32,    12,    13,    35,
      14,   112,     1,   119,    54,    33,    96,   105,    97,     7,
      59,     8,    61,    64,    15,    65,    66,    24,    71,    -6,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,   107,   117,    26,    29,    -6,    33,    12,    27,    -6,
      14,     9,    55,    31,    10,    11,    95,    12,    13,    31,
      14,   -36,    70,   100,    15,   -37,   -36,    -6,   120,     9,
     -37,   122,    10,    11,    15,    12,    13,    36,    14,    -6,
      72,    84,    37,    61,    87,    89,    88,    90,    93,   111,
      -6,    61,    15,    94,   101,   102,     9,    -6,    98,    10,
      11,   104,    12,    13,   106,    14,    38,   100,   113,   114,
     116,   121,    39,    40,    41,    42,    43,    44,    45,    15,
      46,    47,    48,    49,   118,    58,    23,   103,   109,   110,
      50,    39,    40,    41,    42,    43,    44,    45,     0,    46,
      47,    48,    49,     0,    58,     0,     0,     0,     0,    60,
      39,    40,    41,    42,    43,    44,    45,     0,    46,    47,
      48,    49,     0,    58,     0,     0,     0,     0,    99,    39,
      40,    41,    42,    43,    44,    45,     0,    46,    47,    48,
      49,     0,    58,     0,     0,     0,     0,   115,    39,    40,
      41,    42,    43,    44,    45,     0,    46,    47,    48,    49,
      58,     0,     0,    92,     0,     0,    39,    40,    41,    42,
      43,    44,    45,     0,    46,    47,    48,    49,    58,    63,
       0,     0,     0,     0,    39,    40,    41,    42,    43,    44,
      45,     0,    46,    47,    48,    49,    58,    91,     0,     0,
       0,     0,    39,    40,    41,    42,    43,    44,    45,     0,
      46,    47,    48,    49
};

static const yytype_int8 yycheck[] =
{
       9,     6,    11,    92,     9,    10,    15,    12,    13,    19,
      15,   100,     3,    31,    24,    33,    66,    88,    68,    13,
      29,     0,    31,    33,    29,     7,     8,    33,    37,    34,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    91,   113,    29,    29,     0,    33,    12,    13,     4,
      15,     6,    13,    29,     9,    10,    65,    12,    13,    29,
      15,    31,    13,    29,    29,    31,    36,     4,   118,     6,
      36,   121,     9,    10,    29,    12,    13,    31,    15,    34,
      13,     4,    36,    92,    31,    30,    32,    13,    30,    98,
       0,   100,    29,    34,    13,    34,     6,    34,    36,     9,
      10,    13,    12,    13,     5,    15,    11,    29,    29,    13,
      30,    13,    17,    18,    19,    20,    21,    22,    23,    29,
      25,    26,    27,    28,    30,    11,     5,    86,    97,    97,
      35,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,    -1,    11,    -1,    -1,    -1,    -1,    35,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    -1,    11,    -1,    -1,    -1,    -1,    35,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,    -1,    11,    -1,    -1,    -1,    -1,    35,    17,    18,
      19,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      11,    -1,    -1,    32,    -1,    -1,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    11,    30,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    11,    30,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    38,    39,    40,    42,    43,    13,     0,     6,
       9,    10,    12,    13,    15,    29,    41,    53,    54,    55,
      56,    59,    60,    40,    33,    46,    29,    13,    59,    29,
      59,    29,    59,    33,    49,    41,    31,    36,    11,    17,
      18,    19,    20,    21,    22,    23,    25,    26,    27,    28,
      35,    57,    58,    61,    41,    13,    44,    45,    11,    59,
      35,    59,    62,    30,    41,     7,     8,    50,    51,    52,
      13,    59,    13,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,     4,    47,    48,    31,    32,    30,
      13,    30,    32,    30,    34,    59,    49,    49,    36,    35,
      29,    13,    34,    47,    13,    45,     5,    49,    62,    50,
      52,    59,    62,    29,    13,    35,    30,    45,    30,    31,
      49,    13,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    40,    40,    41,    41,    42,    43,
      43,    44,    45,    45,    45,    46,    47,    47,    48,    48,
      49,    50,    51,    52,    52,    52,    53,    53,    53,    54,
      55,    55,    55,    55,    55,    55,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    58,    58,    58,    58,    59,
      59,    59,    60,    60,    60,    60,    60,    60,    60,    61,
      61,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     0,     2,     2,     7,
       5,     3,     0,     1,     3,     4,     0,     2,     8,     6,
       3,     2,     2,     2,     3,     3,     2,     3,     3,     2,
       1,     5,     3,     4,     6,     2,     1,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     0,     1,     2,     4,     1,     1,     3,     5,
       2,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 52 "parser.y" /* yacc.c:1646  */
    {cout << "Finished parse with no errors" << endl;}
#line 1366 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 54 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "a" << endl;
										(yyval.treeNode)->type = TN_PROGRAM;
										(yyval.treeNode)->numOperands = 2;
										(yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);
										(yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1376 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 62 "parser.y" /* yacc.c:1646  */
    {;}
#line 1382 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 63 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].treeNode)->pNextStatement = (yyvsp[0].treeNode);
									(yyval.treeNode) = (yyvsp[-1].treeNode);}
#line 1389 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 68 "parser.y" /* yacc.c:1646  */
    {cout << "empty statement" << endl;}
#line 1395 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 69 "parser.y" /* yacc.c:1646  */
    {cout << "statements" << endl;
								(yyvsp[-1].treeNode)->pNextStatement = (yyvsp[0].treeNode);
								(yyval.treeNode) = (yyvsp[-1].treeNode);}
#line 1403 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 75 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "b" << endl;
		 							 (yyval.treeNode)->type = TN_CLASS;
		 							 (yyval.treeNode)->numOperands = 2;
		 							 (yyval.treeNode)->operands[1] = (yyvsp[-1].treeNode);
		 							 (yyval.treeNode)->operands[2] = (yyvsp[0].treeNode);}
#line 1413 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 82 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode();
		 												
		 												(yyval.treeNode)->type = TN_CLASSDEF;
		 												/*$$->sval = ($2); cout << "2" << endl;*/
		 												
		 												(yyval.treeNode)->sval = ((yyvsp[-5].sval));
		 												
		 												(yyval.treeNode)->numOperands = 1;
		 												
		 												(yyval.treeNode)->operands[0] = (yyvsp[-3].treeNode);
		 												}
#line 1429 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 93 "parser.y" /* yacc.c:1646  */
    { (yyval.treeNode) = newTreeNode(); cout << "d" << endl;
											(yyval.treeNode)->type = TN_CLASSDEF;
											(yyval.treeNode)->sval = ((yyvsp[-3].sval));
											(yyval.treeNode)->numOperands = 1;
											(yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);}
#line 1439 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 104 "parser.y" /* yacc.c:1646  */
    {	(yyval.treeNode) = newTreeNode(); cout << "e" << endl;
							(yyval.treeNode)->type = TN_PARAMETER;
							(yyval.treeNode)->sval = ((yyvsp[-2].sval));

							(yyval.treeNode)->dataType = ((yyvsp[0].sval));
							/*$$->ival = $3;*/}
#line 1450 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 113 "parser.y" /* yacc.c:1646  */
    {cout << "fa" << endl;}
#line 1456 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 114 "parser.y" /* yacc.c:1646  */
    {   
						(yyval.treeNode) = newTreeNode(); cout << "f" << endl;
						(yyval.treeNode)->type = TN_PARAMLIST;
						(yyval.treeNode)->numOperands = 1;
						(yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);
					}
#line 1467 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 120 "parser.y" /* yacc.c:1646  */
    {cout << "more formal args" << endl;
									 (yyval.treeNode) = (yyvsp[0].treeNode);
									 (yyval.treeNode)->operands[(yyval.treeNode)->numOperands++] = (yyvsp[-2].treeNode);
									}
#line 1476 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 127 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "g" << endl;
		 							 (yyval.treeNode)->type = TN_CLASSBODY;
		 							 (yyval.treeNode)->numOperands = 2;
		 							 (yyval.treeNode)->operands[0] = (yyvsp[-2].treeNode);
		 							 (yyval.treeNode)->operands[1] = (yyvsp[-1].treeNode);
		 							 }
#line 1487 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 135 "parser.y" /* yacc.c:1646  */
    {cout << "empty methods";}
#line 1493 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 136 "parser.y" /* yacc.c:1646  */
    {cout << "method" << endl;
							(yyvsp[-1].treeNode)->pNextStatement = (yyvsp[0].treeNode);
						  (yyval.treeNode) = (yyvsp[-1].treeNode);}
#line 1501 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 142 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "h" << endl;
		  															(yyval.treeNode)->type = TN_METHOD;
		  															(yyval.treeNode)->sval = ((yyvsp[-6].sval));
		  															(yyval.treeNode)->dataType = (yyvsp[-1].sval);
		  															(yyval.treeNode)->numOperands = 2;
		  															/*$$->ival = $7;*/
		  															(yyval.treeNode)->operands[0] = (yyvsp[-4].treeNode);
		  															(yyval.treeNode)->operands[1] = (yyvsp[0].treeNode);}
#line 1514 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 150 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "i" << endl;
														(yyval.treeNode)->type = TN_METHOD;
														(yyval.treeNode)->sval = ((yyvsp[-4].sval));
														(yyval.treeNode)->dataType = (char *) "void";
														(yyval.treeNode)->numOperands = 2;
														/*$$->ival = NONE_TYPE;*/
														(yyval.treeNode)->operands[0] = (yyvsp[-2].treeNode);
														(yyval.treeNode)->operands[1] = (yyvsp[0].treeNode);}
#line 1527 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 161 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[-1].treeNode);}
#line 1533 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.treeNode) = (yyvsp[0].treeNode);}
#line 1539 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 168 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);}
#line 1545 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 172 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "j" << endl;
										(yyval.treeNode)->type = TN_IF;
										(yyval.treeNode)->numOperands = 2;
										(yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);
										(yyval.treeNode)->operands[1] = (yyvsp[0].treeNode);}
#line 1555 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 177 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "k" << endl;
													(yyval.treeNode)->type = TN_IF;
													(yyval.treeNode)->numOperands = 3;
													(yyval.treeNode)->operands[0] = (yyvsp[-2].treeNode);
													(yyval.treeNode)->operands[1] = (yyvsp[-1].treeNode);
													(yyval.treeNode)->operands[2] = (yyvsp[0].treeNode);}
#line 1566 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 183 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "l" << endl;
													(yyval.treeNode)->type = TN_IF;
													(yyval.treeNode)->numOperands = 3;
													(yyval.treeNode)->operands[0] = (yyvsp[-2].treeNode);
													(yyval.treeNode)->operands[1] = (yyvsp[-1].treeNode);
													(yyval.treeNode)->operands[2] = (yyvsp[0].treeNode);}
#line 1577 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 192 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "m" << endl;
		  							 (yyval.treeNode)->type = TN_IF;
		  							 (yyval.treeNode)->numOperands = 2;
		  							 (yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);
		  							 (yyval.treeNode)->operands[1] = (yyvsp[0].treeNode);
		  							}
#line 1588 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 198 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "n" << endl;
												 (yyval.treeNode)->type = TN_IF;
												 (yyval.treeNode)->numOperands = 3;
												 (yyval.treeNode)->operands[0] = (yyvsp[-2].treeNode);
												 (yyval.treeNode)->operands[1] = (yyvsp[-1].treeNode);
												 (yyval.treeNode)->operands[2] = (yyvsp[0].treeNode);
												}
#line 1600 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 205 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "o" << endl;
												  (yyval.treeNode)->type = TN_IF;
										 		  (yyval.treeNode)->numOperands = 3;
												  (yyval.treeNode)->operands[0] = (yyvsp[-2].treeNode);
												  (yyval.treeNode)->operands[1] = (yyvsp[-1].treeNode);
												  (yyval.treeNode)->operands[2] = (yyvsp[0].treeNode);}
#line 1611 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 213 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);}
#line 1617 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 216 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);}
#line 1623 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 217 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "p" << endl;
												(yyval.treeNode)->type = TN_WHILE;
												(yyval.treeNode)->numOperands = 2;
												(yyval.treeNode)->operands[0] = (yyvsp[-2].treeNode);
												(yyval.treeNode)->operands[1] = (yyvsp[0].treeNode);}
#line 1633 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 223 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "q" << endl;
							 (yyval.treeNode)->type = TN_RETURN;
							 (yyval.treeNode)->numOperands = 1;
							 (yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);}
#line 1642 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 228 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "r" << endl;
								 (yyval.treeNode)->type = TN_ASSIGNMENT;
								 (yyval.treeNode)->numOperands = 2;
								 (yyval.treeNode)->operands[0] = (yyvsp[-3].treeNode);
								 (yyval.treeNode)->operands[1] = (yyvsp[-1].treeNode);
								 cout << "bnm" << endl;
								 }
#line 1654 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 236 "parser.y" /* yacc.c:1646  */
    {
								 (yyval.treeNode) = newTreeNode(); cout << "s" << endl;
								 (yyval.treeNode)->type = TN_ASSIGNMENT;
								 (yyval.treeNode)->sval = (yyvsp[-3].sval);
								 (yyval.treeNode)->numOperands = 2;
								 (yyval.treeNode)->operands[0] = (yyvsp[-5].treeNode);
								 (yyval.treeNode)->operands[1] = (yyvsp[-1].treeNode);}
#line 1666 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 244 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "t" << endl;
					  (yyval.treeNode)->type = TN_EXPR_STATEMENT;
					  (yyval.treeNode)->numOperands = 1;
					  (yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);}
#line 1675 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 257 "parser.y" /* yacc.c:1646  */
    { (yyval.treeNode) = newTreeNode(); cout << "u" << endl;
				(yyval.treeNode)->type = TN_LEFT_EXPRESSION;

				(yyval.treeNode)->sval = ((yyvsp[0].sval));
				}
#line 1685 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 262 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "v" << endl;
							(yyval.treeNode)->type = TN_LEFT_EXPRESSION;
							(yyval.treeNode)->numOperands = 1;
							(yyval.treeNode)->operands[0] = (yyvsp[-2].treeNode);}
#line 1694 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 268 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "w" << endl;
							 (yyval.treeNode)->type = TN_BOOLEAN_EXPRESSION;
							 (yyval.treeNode)->sval = ((yyvsp[-1].sval));
							 (yyval.treeNode)->numOperands = 1;
							 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1704 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 274 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "x" << endl;
							 (yyval.treeNode)->type = TN_BOOLEAN_EXPRESSION;
							 (yyval.treeNode)->sval = ((yyvsp[-1].sval));
							 (yyval.treeNode)->numOperands = 1;
							 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1714 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 280 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "y" << endl;
							 (yyval.treeNode)->type = TN_BOOLEAN_EXPRESSION;
							 (yyval.treeNode)->sval = ((yyvsp[-1].sval));
							 (yyval.treeNode)->numOperands = 1;
							 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1724 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 286 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "z" << endl;
							 (yyval.treeNode)->type = TN_BOOLEAN_EXPRESSION;
							 (yyval.treeNode)->sval = ((yyvsp[-1].sval));
							 (yyval.treeNode)->numOperands = 1;
							 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1734 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 292 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "A" << endl;
							 (yyval.treeNode)->type = TN_BOOLEAN_EXPRESSION;
							 (yyval.treeNode)->sval = ((yyvsp[-1].sval));
							 (yyval.treeNode)->numOperands = 1;
							 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1744 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 298 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "B" << endl;
							 (yyval.treeNode)->type = TN_BOOLEAN_EXPRESSION;
							 (yyval.treeNode)->sval = ((yyvsp[-1].sval));
							 (yyval.treeNode)->numOperands = 1;
							 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 304 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "C" << endl;
							 (yyval.treeNode)->type = TN_BOOLEAN_EXPRESSION;
							 (yyval.treeNode)->sval = ((yyvsp[-1].sval));
							 (yyval.treeNode)->numOperands = 1;
							 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1764 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 312 "parser.y" /* yacc.c:1646  */
    {  (yyval.treeNode) = newTreeNode(); cout << "D" << endl;
									 (yyval.treeNode)->type = TN_ARITHMETIC_EXPRESSION;
									 (yyval.treeNode)->sval = ((yyvsp[-1].sval));
									 (yyval.treeNode)->numOperands = 1;
									 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1774 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 317 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "E" << endl;
									 (yyval.treeNode)->type = TN_ARITHMETIC_EXPRESSION;
									 (yyval.treeNode)->sval = ((yyvsp[-1].sval));
									 (yyval.treeNode)->numOperands = 1;
									 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 322 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "F" << endl;
									 (yyval.treeNode)->type = TN_ARITHMETIC_EXPRESSION;
									 (yyval.treeNode)->sval = ((yyvsp[-1].sval));
									 (yyval.treeNode)->numOperands = 1;
									 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1794 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 327 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "G" << endl;
									 (yyval.treeNode)->type = TN_ARITHMETIC_EXPRESSION;
									 (yyval.treeNode)->sval = ((yyvsp[-1].sval));
									 (yyval.treeNode)->numOperands = 1;
									 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1804 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 335 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "H" << endl;
										 (yyval.treeNode)->type = TN_BOOLEAN_EXPRESSION;
										 (yyval.treeNode)->numOperands = 2;
										 (yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);
										 (yyval.treeNode)->operands[1] = (yyvsp[0].treeNode);}
#line 1814 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 342 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "I" << endl;
										 (yyval.treeNode)->type = TN_ARITHMETIC_EXPRESSION;
										 (yyval.treeNode)->numOperands = 2;
										 (yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);
										 (yyval.treeNode)->operands[1] = (yyvsp[0].treeNode);}
#line 1824 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 347 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "J" << endl;
					 (yyval.treeNode)->type = TN_INTERMEDIATE_EXPRESSION;
					 (yyval.treeNode)->numOperands = 1;
					 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);
					}
#line 1834 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 354 "parser.y" /* yacc.c:1646  */
    {;}
#line 1840 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 355 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "K" << endl;
			(yyval.treeNode)->type = TN_IDENT_EXPRESSION;
			(yyval.treeNode)->sval = ((yyvsp[0].sval));}
#line 1848 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 358 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "L" << endl;
						(yyval.treeNode)->type = TN_DEREF;
						(yyval.treeNode)->numOperands = 2;
						(yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);
						(yyval.treeNode)->operands[1] = (yyvsp[0].treeNode);}
#line 1858 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 363 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "M" << endl;
								(yyval.treeNode)->type = TN_FUNCTION_CALL_EXPRESSION;
								(yyval.treeNode)->sval = ((yyvsp[-3].sval));
								(yyval.treeNode)->numOperands = 1;
								(yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);}
#line 1868 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 368 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "N" << endl;
			(yyval.treeNode)->type = TN_STRING_EXPRESSION;
			(yyval.treeNode)->sval = ((yyvsp[0].sval));}
#line 1876 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 371 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "O" << endl;
			(yyval.treeNode)->type = TN_INTEGER_EXPRESSION;
			/*$$->ival = $1;*/}
#line 1884 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 374 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[-1].treeNode);}
#line 1890 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 377 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "P" << endl;
										   (yyval.treeNode)->type = TN_DEREFERENCE_FUNC;
										   (yyval.treeNode)->sval = ((yyvsp[-3].sval));
										   (yyval.treeNode)->numOperands = 1;
										   (yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);}
#line 1900 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 382 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "Q" << endl;
					   (yyval.treeNode)->type = TN_DEREFERENCE_VAR;
					   (yyval.treeNode)->sval = ((yyvsp[0].sval));
					   }
#line 1909 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 390 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);
									(yyval.treeNode)->operands[(yyval.treeNode)->numOperands++] = (yyvsp[-2].treeNode);}
#line 1916 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 392 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "R" << endl;
				  (yyval.treeNode)->type = TN_ARGLIST;
				  (yyval.treeNode)->numOperands = 1;
				  (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1925 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1929 "parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 400 "parser.y" /* yacc.c:1906  */


int main(int argc, char** argv) {
	// open a file handle to a particular file:
	if(argc != 2){
		cout << "The parser must be run in the format:   ./parser <filename>";
		return 0;
	}

	FILE *myfile = fopen(argv[1], "r");
	int condition;
	// make sure it's valid:
	if (!myfile) {
		cout << "I can't open a quack file!" << endl;
		return -1;
	}
	// set flex to read from it instead of defaulting to STDIN:
	yyin = myfile;

	// parse through the input until there is no more:
	do {
		condition = yyparse();
	} while (!feof(yyin));
	
}

void yyerror(const char *s) {
	cout << lineNumber << ": " << s << endl;
	// might as well halt now:
	exit(-1);
}
