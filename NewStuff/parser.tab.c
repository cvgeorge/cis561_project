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
    INT_LIT = 267,
    INTEGER = 268,
    STRING_LIT = 269,
    IDENT = 270,
    STRING = 271,
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
	char sym;
  	struct tree_node* treeNode; 


#line 165 "parser.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 180 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   258

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  125

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
       0,    54,    54,    56,    64,    65,    70,    71,    76,    83,
      91,    99,   100,   101,   104,   111,   112,   118,   124,   132,
     133,   138,   145,   155,   158,   162,   166,   171,   177,   186,
     192,   199,   207,   210,   211,   217,   222,   229,   237,   250,
     253,   259,   265,   271,   277,   283,   289,   295,   303,   308,
     313,   318,   326,   333,   338,   345,   346,   349,   354,   359,
     362,   365,   368,   373,   381,   383
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "DEF", "EXTENDS", "IF", "ELIF",
  "ELSE", "WHILE", "RETURN", "DOT", "INT_LIT", "INTEGER", "STRING_LIT",
  "IDENT", "STRING", "EQ", "GEQ", "LEQ", "GT", "LT", "AND", "OR", "NOT",
  "PLUS", "MINUS", "MULT", "DIVIDE", "'('", "')'", "':'", "','", "'{'",
  "'}'", "';'", "'='", "$accept", "start", "program", "class_declarations",
  "statements", "class", "class_signature", "type", "parameter",
  "formal_args", "class_body", "methods", "method", "statement_block",
  "else_clause", "elseif_header", "elseif_block", "if_statement",
  "if_header", "statement", "l_expr", "boolean_operator",
  "arithmetic_operator", "r_expr", "testFinal", "dotMatcher",
  "actual_args", YY_NULLPTR
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

#define YYPACT_NINF -89

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-89)))

#define YYTABLE_NINF -41

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,     3,    23,   -89,    64,     2,    -6,     0,   -89,    -5,
      15,    -5,   -89,   -89,    68,    -5,   -89,   -89,    12,    53,
     -23,    91,   -89,   -89,    37,   -89,    33,    21,   221,    -5,
     110,    -5,   185,    86,    73,   -89,    39,    -5,    45,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
     -89,   -89,   -89,   -89,    57,    38,    40,    47,    60,   203,
     -89,   167,    54,   -89,    51,    -5,    12,   -89,    12,   -89,
      50,   129,   222,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,    75,    69,    57,     1,    33,    83,
      65,    12,    -5,   -89,   -89,   221,   -89,    73,    -5,   -89,
      -5,    76,   -89,   -89,   -89,   -89,   -89,   -89,    92,   -89,
     -89,   -89,   -89,   148,    93,    33,   -89,   -89,   -89,    94,
     -12,     1,   -89,    12,   -89
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     2,    55,     4,     0,     0,     1,    55,
       0,    55,    60,    59,    56,    55,     3,    33,     0,    55,
       0,     0,    54,     5,    55,     8,    15,    56,    32,    55,
       0,    55,     0,    55,    29,     7,     0,    55,     0,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      38,    52,    53,    57,    19,     0,    16,     0,     0,     0,
      35,    65,     0,    61,     0,    55,     0,    30,     0,    31,
       0,     0,    63,    43,    44,    45,    46,    47,    42,    41,
      48,    49,    50,    51,     0,     0,    19,    13,    15,    10,
      63,     0,    55,    58,    23,    25,    24,    26,    55,    36,
      55,     0,    18,    20,    11,    12,    14,    17,     0,    34,
      64,    27,    28,     0,     0,    15,     9,    37,    62,     0,
       0,    13,    22,     0,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,   -89,   101,    -8,   -89,   -89,     4,   -89,   -73,
     -89,    36,   -89,   -65,    42,   -89,    44,   -89,   -89,   -89,
     -89,   -89,   -89,    -9,   -89,   -89,   -88
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    16,     5,     6,   106,    56,    57,
      25,    85,    86,    34,    67,    68,    69,    17,    18,    19,
      20,    51,    52,    21,    22,    53,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      28,    96,    30,    97,   110,     1,    32,    12,    36,    13,
      27,    35,   114,    37,   104,   107,    54,   105,     7,   121,
      59,    33,    61,     8,    15,    64,   109,    24,    71,    26,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -6,   119,     9,    29,    33,    10,    11,    55,    12,
      31,    13,    14,    -6,    70,   122,    95,    -6,   124,     9,
      72,    84,    10,    11,    -6,    12,    15,    13,    14,    87,
       9,    -6,    88,    10,    11,    90,    12,    89,    13,    14,
      65,    66,    15,    61,    93,    94,    98,    -6,   108,   113,
     101,    61,     9,    15,   100,    10,    11,    31,    12,   -39,
      13,    14,    38,   102,   -39,   115,    23,   116,    39,    40,
      41,    42,    43,    44,    45,    15,    46,    47,    48,    49,
      -6,    58,   103,   118,   120,   123,    50,    39,    40,    41,
      42,    43,    44,    45,     0,    46,    47,    48,    49,   111,
      58,   112,     0,     0,     0,    60,    39,    40,    41,    42,
      43,    44,    45,     0,    46,    47,    48,    49,     0,    58,
       0,     0,     0,     0,    99,    39,    40,    41,    42,    43,
      44,    45,     0,    46,    47,    48,    49,     0,    58,     0,
       0,     0,     0,   117,    39,    40,    41,    42,    43,    44,
      45,     0,    46,    47,    48,    49,    58,     0,     0,    92,
       0,     0,    39,    40,    41,    42,    43,    44,    45,     0,
      46,    47,    48,    49,    58,    63,     0,     0,     0,     0,
      39,    40,    41,    42,    43,    44,    45,     0,    46,    47,
      48,    49,    58,    91,     0,     0,     0,     0,    39,    40,
      41,    42,    43,    44,    45,     0,    46,    47,    48,    49,
       0,   100,     0,   -40,     0,     0,     0,     0,   -40
};

static const yytype_int8 yycheck[] =
{
       9,    66,    11,    68,    92,     3,    15,    12,    31,    14,
      15,    19,   100,    36,    13,    88,    24,    16,    15,    31,
      29,    33,    31,     0,    29,    33,    91,    33,    37,    29,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,     4,   115,     6,    29,    33,     9,    10,    15,    12,
      29,    14,    15,     0,    15,   120,    65,     4,   123,     6,
      15,     4,     9,    10,     0,    12,    29,    14,    15,    31,
       6,    34,    32,     9,    10,    15,    12,    30,    14,    15,
       7,     8,    29,    92,    30,    34,    36,    34,     5,    98,
      15,   100,     6,    29,    29,     9,    10,    29,    12,    31,
      14,    15,    11,    34,    36,    29,     5,    15,    17,    18,
      19,    20,    21,    22,    23,    29,    25,    26,    27,    28,
      34,    11,    86,    30,    30,   121,    35,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    97,
      11,    97,    -1,    -1,    -1,    35,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    -1,    11,
      -1,    -1,    -1,    -1,    35,    17,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    27,    28,    -1,    11,    -1,
      -1,    -1,    -1,    35,    17,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    11,    -1,    -1,    32,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    11,    30,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    11,    30,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    38,    39,    40,    42,    43,    15,     0,     6,
       9,    10,    12,    14,    15,    29,    41,    54,    55,    56,
      57,    60,    61,    40,    33,    47,    29,    15,    60,    29,
      60,    29,    60,    33,    50,    41,    31,    36,    11,    17,
      18,    19,    20,    21,    22,    23,    25,    26,    27,    28,
      35,    58,    59,    62,    41,    15,    45,    46,    11,    60,
      35,    60,    63,    30,    41,     7,     8,    51,    52,    53,
      15,    60,    15,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,     4,    48,    49,    31,    32,    30,
      15,    30,    32,    30,    34,    60,    50,    50,    36,    35,
      29,    15,    34,    48,    13,    16,    44,    46,     5,    50,
      63,    51,    53,    60,    63,    29,    15,    35,    30,    46,
      30,    31,    50,    44,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    40,    40,    41,    41,    42,    43,
      43,    44,    44,    44,    45,    46,    46,    46,    47,    48,
      48,    49,    49,    50,    51,    52,    53,    53,    53,    54,
      54,    54,    55,    56,    56,    56,    56,    56,    56,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      59,    59,    60,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     0,     2,     2,     7,
       5,     1,     1,     0,     3,     0,     1,     3,     4,     0,
       2,     8,     6,     3,     2,     2,     2,     3,     3,     2,
       3,     3,     2,     1,     5,     3,     4,     6,     2,     1,
       3,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     0,     1,     2,     4,     1,
       1,     3,     5,     2,     3,     1
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
#line 54 "parser.y" /* yacc.c:1646  */
    {cout << "Finished parse with no errors" << endl;}
#line 1368 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 56 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "a" << endl;
										(yyval.treeNode)->type = TN_PROGRAM;
										(yyval.treeNode)->numOperands = 2;
										(yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);
										(yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1378 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 64 "parser.y" /* yacc.c:1646  */
    {;}
#line 1384 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 65 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].treeNode)->pNextStatement = (yyvsp[0].treeNode);
									(yyval.treeNode) = (yyvsp[-1].treeNode);}
#line 1391 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 70 "parser.y" /* yacc.c:1646  */
    {;}
#line 1397 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 71 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].treeNode)->pNextStatement = (yyvsp[0].treeNode);
								(yyval.treeNode) = (yyvsp[-1].treeNode);}
#line 1404 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 76 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "b" << endl;
		 							 (yyval.treeNode)->type = TN_CLASS;
		 							 (yyval.treeNode)->numOperands = 2;
		 							 (yyval.treeNode)->operands[1] = (yyvsp[-1].treeNode);
		 							 (yyval.treeNode)->operands[2] = (yyvsp[0].treeNode);}
#line 1414 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 83 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "c" << endl;
		 												(yyval.treeNode)->type = TN_CLASSDEF; cout << "1" << endl;
		 												cout << (yyvsp[-5].sval) << endl; cout << "asdf" << endl;

		 												(yyval.treeNode)->sval = strdup((yyvsp[-5].sval)); cout << "2" << endl;
		 												(yyval.treeNode)->superval = strdup((yyvsp[0].sval)); cout << "3" << endl;
		 												(yyval.treeNode)->numOperands = 1; cout << "4" << endl;
		 												(yyval.treeNode)->operands[0] = (yyvsp[-3].treeNode);cout << "5" << endl;}
#line 1427 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 91 "parser.y" /* yacc.c:1646  */
    { (yyval.treeNode) = newTreeNode(); cout << "d" << endl;
											(yyval.treeNode)->type = TN_CLASSDEF;
											(yyval.treeNode)->sval = strdup((yyvsp[-3].sval));
											char obj[] = "Obj";
											(yyval.treeNode)->superval = obj;
											(yyval.treeNode)->numOperands = 1;
											(yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);}
#line 1439 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 99 "parser.y" /* yacc.c:1646  */
    { (yyval.ival) = INTEGER_LITERAL;}
#line 1445 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 100 "parser.y" /* yacc.c:1646  */
    {(yyval.ival) = STRING_LITERAL;}
#line 1451 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 101 "parser.y" /* yacc.c:1646  */
    {(yyval.ival) = NONE_TYPE;}
#line 1457 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 104 "parser.y" /* yacc.c:1646  */
    {	(yyval.treeNode) = newTreeNode(); cout << "e" << endl;
							(yyval.treeNode)->type = TN_PARAMETER;
							(yyval.treeNode)->sval = strdup((yyvsp[-2].sval));
							(yyval.treeNode)->ival = (yyvsp[0].ival);}
#line 1466 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 111 "parser.y" /* yacc.c:1646  */
    {;}
#line 1472 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 112 "parser.y" /* yacc.c:1646  */
    {   
						(yyval.treeNode) = newTreeNode(); cout << "f" << endl;
						(yyval.treeNode)->type = TN_PARAMLIST;
						(yyval.treeNode)->numOperands = 1;
						(yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);
					}
#line 1483 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 118 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);
									 (yyval.treeNode)->operands[(yyval.treeNode)->numOperands++] = (yyvsp[-2].treeNode);
									}
#line 1491 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 124 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "g" << endl;
		 							 (yyval.treeNode)->type = TN_CLASSBODY;
		 							 (yyval.treeNode)->numOperands = 2;
		 							 (yyval.treeNode)->operands[0] = (yyvsp[-2].treeNode);
		 							 (yyval.treeNode)->operands[1] = (yyvsp[-1].treeNode);
		 							 }
#line 1502 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 132 "parser.y" /* yacc.c:1646  */
    {;}
#line 1508 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 133 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].treeNode)->pNextStatement = (yyvsp[0].treeNode);
						  (yyval.treeNode) = (yyvsp[-1].treeNode);}
#line 1515 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 138 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "h" << endl;
		  															(yyval.treeNode)->type = TN_METHOD;
		  															(yyval.treeNode)->sval = strdup((yyvsp[-6].sval));
		  															(yyval.treeNode)->numOperands = 2;
		  															(yyval.treeNode)->ival = (yyvsp[-1].ival);
		  															(yyval.treeNode)->operands[0] = (yyvsp[-4].treeNode);
		  															(yyval.treeNode)->operands[1] = (yyvsp[0].treeNode);}
#line 1527 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 145 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "i" << endl;
														(yyval.treeNode)->type = TN_METHOD;
														(yyval.treeNode)->sval = strdup((yyvsp[-4].sval));
														(yyval.treeNode)->numOperands = 2;
														(yyval.treeNode)->ival = NONE_TYPE;
														(yyval.treeNode)->operands[0] = (yyvsp[-2].treeNode);
														(yyval.treeNode)->operands[1] = (yyvsp[0].treeNode);}
#line 1539 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 155 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[-1].treeNode);}
#line 1545 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval.treeNode) = (yyvsp[0].treeNode);}
#line 1551 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 162 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);}
#line 1557 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 166 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "j" << endl;
										(yyval.treeNode)->type = TN_IF;
										(yyval.treeNode)->numOperands = 2;
										(yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);
										(yyval.treeNode)->operands[1] = (yyvsp[0].treeNode);}
#line 1567 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 171 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "k" << endl;
													(yyval.treeNode)->type = TN_IF;
													(yyval.treeNode)->numOperands = 3;
													(yyval.treeNode)->operands[0] = (yyvsp[-2].treeNode);
													(yyval.treeNode)->operands[1] = (yyvsp[-1].treeNode);
													(yyval.treeNode)->operands[2] = (yyvsp[0].treeNode);}
#line 1578 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 177 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "l" << endl;
													(yyval.treeNode)->type = TN_IF;
													(yyval.treeNode)->numOperands = 3;
													(yyval.treeNode)->operands[0] = (yyvsp[-2].treeNode);
													(yyval.treeNode)->operands[1] = (yyvsp[-1].treeNode);
													(yyval.treeNode)->operands[2] = (yyvsp[0].treeNode);}
#line 1589 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 186 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "m" << endl;
		  							 (yyval.treeNode)->type = TN_IF;
		  							 (yyval.treeNode)->numOperands = 2;
		  							 (yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);
		  							 (yyval.treeNode)->operands[1] = (yyvsp[0].treeNode);
		  							}
#line 1600 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 192 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "n" << endl;
												 (yyval.treeNode)->type = TN_IF;
												 (yyval.treeNode)->numOperands = 3;
												 (yyval.treeNode)->operands[0] = (yyvsp[-2].treeNode);
												 (yyval.treeNode)->operands[1] = (yyvsp[-1].treeNode);
												 (yyval.treeNode)->operands[2] = (yyvsp[0].treeNode);
												}
#line 1612 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 199 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "o" << endl;
												  (yyval.treeNode)->type = TN_IF;
										 		  (yyval.treeNode)->numOperands = 3;
												  (yyval.treeNode)->operands[0] = (yyvsp[-2].treeNode);
												  (yyval.treeNode)->operands[1] = (yyvsp[-1].treeNode);
												  (yyval.treeNode)->operands[2] = (yyvsp[0].treeNode);}
#line 1623 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 207 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);}
#line 1629 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 210 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);}
#line 1635 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 211 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "p" << endl;
												(yyval.treeNode)->type = TN_WHILE;
												(yyval.treeNode)->numOperands = 2;
												(yyval.treeNode)->operands[0] = (yyvsp[-2].treeNode);
												(yyval.treeNode)->operands[1] = (yyvsp[0].treeNode);}
#line 1645 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 217 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "q" << endl;
							 (yyval.treeNode)->type = TN_RETURN;
							 (yyval.treeNode)->numOperands = 1;
							 (yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);}
#line 1654 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 222 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "r" << endl;
								 (yyval.treeNode)->type = TN_ASSIGNMENT;
								 (yyval.treeNode)->numOperands = 2;
								 (yyval.treeNode)->operands[0] = (yyvsp[-3].treeNode);
								 (yyval.treeNode)->operands[1] = (yyvsp[-1].treeNode);
								 }
#line 1665 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 229 "parser.y" /* yacc.c:1646  */
    {
								 (yyval.treeNode) = newTreeNode(); cout << "s" << endl;
								 (yyval.treeNode)->type = TN_ASSIGNMENT;
								 (yyval.treeNode)->sval = (yyvsp[-3].sval);
								 (yyval.treeNode)->numOperands = 2;
								 (yyval.treeNode)->operands[0] = (yyvsp[-5].treeNode);
								 (yyval.treeNode)->operands[1] = (yyvsp[-1].treeNode);}
#line 1677 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 237 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "t" << endl;
					  (yyval.treeNode)->type = TN_EXPR_STATEMENT;
					  (yyval.treeNode)->numOperands = 1;
					  (yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);}
#line 1686 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 250 "parser.y" /* yacc.c:1646  */
    { (yyval.treeNode) = newTreeNode(); cout << "u" << endl;
				(yyval.treeNode)->type = TN_LEFT_EXPRESSION;
				(yyval.treeNode)->sval = strdup((yyvsp[0].sval));}
#line 1694 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 253 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "v" << endl;
							(yyval.treeNode)->type = TN_LEFT_EXPRESSION;
							(yyval.treeNode)->numOperands = 1;
							(yyval.treeNode)->operands[0] = (yyvsp[-2].treeNode);}
#line 1703 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 259 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "w" << endl;
							 (yyval.treeNode)->type = TN_BOOLEAN_EXPRESSION;
							 (yyval.treeNode)->sval = strdup((yyvsp[-1].sval));
							 (yyval.treeNode)->numOperands = 1;
							 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1713 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 265 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "x" << endl;
							 (yyval.treeNode)->type = TN_BOOLEAN_EXPRESSION;
							 (yyval.treeNode)->sval = strdup((yyvsp[-1].sval));
							 (yyval.treeNode)->numOperands = 1;
							 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1723 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 271 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "y" << endl;
							 (yyval.treeNode)->type = TN_BOOLEAN_EXPRESSION;
							 (yyval.treeNode)->sval = strdup((yyvsp[-1].sval));
							 (yyval.treeNode)->numOperands = 1;
							 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1733 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 277 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "z" << endl;
							 (yyval.treeNode)->type = TN_BOOLEAN_EXPRESSION;
							 (yyval.treeNode)->sval = strdup((yyvsp[-1].sval));
							 (yyval.treeNode)->numOperands = 1;
							 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1743 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 283 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "A" << endl;
							 (yyval.treeNode)->type = TN_BOOLEAN_EXPRESSION;
							 (yyval.treeNode)->sval = strdup((yyvsp[-1].sval));
							 (yyval.treeNode)->numOperands = 1;
							 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1753 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 289 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "B" << endl;
							 (yyval.treeNode)->type = TN_BOOLEAN_EXPRESSION;
							 (yyval.treeNode)->sval = strdup((yyvsp[-1].sval));
							 (yyval.treeNode)->numOperands = 1;
							 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1763 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 295 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "C" << endl;
							 (yyval.treeNode)->type = TN_BOOLEAN_EXPRESSION;
							 (yyval.treeNode)->sval = strdup((yyvsp[-1].sval));
							 (yyval.treeNode)->numOperands = 1;
							 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1773 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 303 "parser.y" /* yacc.c:1646  */
    {  (yyval.treeNode) = newTreeNode(); cout << "D" << endl;
									 (yyval.treeNode)->type = TN_ARITHMETIC_EXPRESSION;
									 (yyval.treeNode)->sval = strdup((yyvsp[-1].sval));
									 (yyval.treeNode)->numOperands = 1;
									 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1783 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 308 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "E" << endl;
									 (yyval.treeNode)->type = TN_ARITHMETIC_EXPRESSION;
									 (yyval.treeNode)->sval = strdup((yyvsp[-1].sval));
									 (yyval.treeNode)->numOperands = 1;
									 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1793 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 313 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "F" << endl;
									 (yyval.treeNode)->type = TN_ARITHMETIC_EXPRESSION;
									 (yyval.treeNode)->sval = strdup((yyvsp[-1].sval));
									 (yyval.treeNode)->numOperands = 1;
									 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1803 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 318 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "G" << endl;
									 (yyval.treeNode)->type = TN_ARITHMETIC_EXPRESSION;
									 (yyval.treeNode)->sval = strdup((yyvsp[-1].sval));
									 (yyval.treeNode)->numOperands = 1;
									 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1813 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 326 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "H" << endl;
										 (yyval.treeNode)->type = TN_BOOLEAN_EXPRESSION;
										 (yyval.treeNode)->numOperands = 2;
										 (yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);
										 (yyval.treeNode)->operands[1] = (yyvsp[0].treeNode);}
#line 1823 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 333 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "I" << endl;
										 (yyval.treeNode)->type = TN_ARITHMETIC_EXPRESSION;
										 (yyval.treeNode)->numOperands = 2;
										 (yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);
										 (yyval.treeNode)->operands[1] = (yyvsp[0].treeNode);}
#line 1833 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 338 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "J" << endl;
					 (yyval.treeNode)->type = TN_INTERMEDIATE_EXPRESSION;
					 (yyval.treeNode)->numOperands = 1;
					 (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);
					}
#line 1843 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 345 "parser.y" /* yacc.c:1646  */
    {;}
#line 1849 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 346 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "K" << endl;
			(yyval.treeNode)->type = TN_IDENT_EXPRESSION;
			(yyval.treeNode)->sval = strdup((yyvsp[0].sval));}
#line 1857 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 349 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "L" << endl;
						(yyval.treeNode)->type = TN_DEREF;
						(yyval.treeNode)->numOperands = 2;
						(yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);
						(yyval.treeNode)->operands[1] = (yyvsp[0].treeNode);}
#line 1867 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 354 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "M" << endl;
								(yyval.treeNode)->type = TN_FUNCTION_CALL_EXPRESSION;
								(yyval.treeNode)->sval = strdup((yyvsp[-3].sval));
								(yyval.treeNode)->numOperands = 1;
								(yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);}
#line 1877 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 359 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "N" << endl;
			(yyval.treeNode)->type = TN_STRING_EXPRESSION;
			(yyval.treeNode)->sval = strdup((yyvsp[0].sval));}
#line 1885 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 362 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "O" << endl;
			(yyval.treeNode)->type = TN_INTEGER_EXPRESSION;
			(yyval.treeNode)->ival = (yyvsp[0].ival);}
#line 1893 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 365 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[-1].treeNode);}
#line 1899 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 368 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "P" << endl;
										   (yyval.treeNode)->type = TN_DEREFERENCE_FUNC;
										   (yyval.treeNode)->sval = strdup((yyvsp[-3].sval));
										   (yyval.treeNode)->numOperands = 1;
										   (yyval.treeNode)->operands[0] = (yyvsp[-1].treeNode);}
#line 1909 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 373 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "Q" << endl;
					   (yyval.treeNode)->type = TN_DEREFERENCE_VAR;
					   (yyval.treeNode)->sval = strdup((yyvsp[0].sval));
					   }
#line 1918 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 381 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = (yyvsp[0].treeNode);
									(yyval.treeNode)->operands[(yyval.treeNode)->numOperands++] = (yyvsp[-2].treeNode);}
#line 1925 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 383 "parser.y" /* yacc.c:1646  */
    {(yyval.treeNode) = newTreeNode(); cout << "R" << endl;
				  (yyval.treeNode)->type = TN_ARGLIST;
				  (yyval.treeNode)->numOperands = 1;
				  (yyval.treeNode)->operands[0] = (yyvsp[0].treeNode);}
#line 1934 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1938 "parser.tab.c" /* yacc.c:1646  */
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
#line 391 "parser.y" /* yacc.c:1906  */


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
