/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

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

	#define Trace(t)        if(isP==1)printf(t); if(isP==1) printf("\n")
	#include <iostream>
	#include "lex.yy.cpp"
	#include "symbols.hpp"
	int isP = 0;
	bool havemain =false;
	void yyerror(const char *msg);
	SymbolTableList symbols;
	vector<vector<idInfo>> function;

#line 78 "y.tab.cpp" /* yacc.c:339  */

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
   by #include "y.tab.hpp".  */
#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
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
    BOOLEAN = 258,
    BREAK = 259,
    CHAR = 260,
    CASE = 261,
    CLASS = 262,
    CONTINUE = 263,
    DEF = 264,
    DO = 265,
    ELSE = 266,
    EXIT = 267,
    FLOAT = 268,
    FOR = 269,
    IF = 270,
    INT = 271,
    NUL = 272,
    OBJECT = 273,
    PRINT = 274,
    PRINTLN = 275,
    REPEAT = 276,
    RETURN = 277,
    READ = 278,
    STRING = 279,
    TO = 280,
    TYPE = 281,
    VAL = 282,
    VAR = 283,
    WHILE = 284,
    LE_OP = 285,
    GE_OP = 286,
    EQ_OP = 287,
    NE_OP = 288,
    AND_OP = 289,
    OR_OP = 290,
    ID = 291,
    STR = 292,
    NUM = 293,
    DOUBLE = 294,
    _CHAR = 295,
    FALSE = 296,
    TRUE = 297,
    UMINUS = 298
  };
#endif
/* Tokens.  */
#define BOOLEAN 258
#define BREAK 259
#define CHAR 260
#define CASE 261
#define CLASS 262
#define CONTINUE 263
#define DEF 264
#define DO 265
#define ELSE 266
#define EXIT 267
#define FLOAT 268
#define FOR 269
#define IF 270
#define INT 271
#define NUL 272
#define OBJECT 273
#define PRINT 274
#define PRINTLN 275
#define REPEAT 276
#define RETURN 277
#define READ 278
#define STRING 279
#define TO 280
#define TYPE 281
#define VAL 282
#define VAR 283
#define WHILE 284
#define LE_OP 285
#define GE_OP 286
#define EQ_OP 287
#define NE_OP 288
#define AND_OP 289
#define OR_OP 290
#define ID 291
#define STR 292
#define NUM 293
#define DOUBLE 294
#define _CHAR 295
#define FALSE 296
#define TRUE 297
#define UMINUS 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "parser.y" /* yacc.c:355  */

	int ival;
	double dval;
	char cval;
	bool bval;
	string *sval;
	class idInfo *info;
	int type;

#line 214 "y.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 231 "y.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   272

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,     2,     2,     2,     2,     2,
      57,    58,    48,    46,    59,    47,     2,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,     2,
      44,    53,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    54,    63,    66,    69,    72,    75,    81,
      82,    87,    94,   107,   115,   123,   130,   138,   148,   151,
     154,   157,   160,   163,   176,   177,   182,   183,   188,   188,
     204,   205,   209,   210,   214,   222,   226,   227,   228,   229,
     234,   242,   252,   253,   254,   259,   260,   264,   265,   266,
     271,   272,   277,   281,   294,   307,   320,   333,   346,   359,
     372,   385,   398,   411,   424,   437,   454,   454,   461,   461,
     468,   472,   473,   479,   483,   491,   495,   495,   505,   505,
     527,   530,   533
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOLEAN", "BREAK", "CHAR", "CASE",
  "CLASS", "CONTINUE", "DEF", "DO", "ELSE", "EXIT", "FLOAT", "FOR", "IF",
  "INT", "NUL", "OBJECT", "PRINT", "PRINTLN", "REPEAT", "RETURN", "READ",
  "STRING", "TO", "TYPE", "VAL", "VAR", "WHILE", "LE_OP", "GE_OP", "EQ_OP",
  "NE_OP", "AND_OP", "OR_OP", "ID", "STR", "NUM", "DOUBLE", "_CHAR",
  "FALSE", "TRUE", "'!'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "UMINUS", "'{'", "'}'", "'='", "':'", "'['", "']'", "'('", "')'", "','",
  "$accept", "program", "var_type", "declaration", "value", "variable",
  "constant_exp", "declaration_list", "method_list", "method", "$@1",
  "method_type", "formal_argument_list", "formal_argument", "statement",
  "simple", "expression", "int_expreesion", "bool_expression",
  "compound_statement", "$@2", "$@3", "statement_list",
  "selection_statement", "iteration_statement", "$@4",
  "procedure_statement", "$@5", "comma_separated_exp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    33,    60,    62,    43,    45,    42,    47,
     298,   123,   125,    61,    58,    91,    93,    40,    41,    44
};
# endif

#define YYPACT_NINF -59

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-59)))

#define YYTABLE_NINF -67

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,   -21,    27,   -18,   -59,     1,    -5,    15,    28,   -59,
     -59,   -59,     1,    -4,   -59,   -59,     2,     9,   -59,    -3,
     -59,   -59,    22,    39,     6,    39,     6,   -59,    30,   -41,
     -59,   -59,   -59,   -59,   -59,    39,    39,   -59,   203,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,    41,   203,   -35,
       5,    44,    53,    39,   -59,   -59,   139,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,     6,    43,    30,   203,    58,    39,   -59,    23,
      23,    23,    23,   223,   197,    23,    23,    35,    35,   -59,
     -59,   203,   203,    59,   -59,     6,    67,   -59,   -59,   133,
      61,   -59,   -59,   -20,   -59,    39,   -59,   -59,    81,   125,
     -59,   102,    66,    69,    39,    39,    39,    91,    75,   -29,
     -59,   -59,   -59,    38,   -59,   -59,    84,    97,    39,   203,
     203,   203,   -59,    39,    39,    39,   -59,   -59,   -59,    90,
     168,   174,   203,    85,    95,   125,   125,    93,    99,   132,
     -59,    39,   124,   125,   203,   112,   -59,    94,   -59,   125,
     -59
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,    24,
       9,    10,     0,     0,    26,    28,     0,    13,    25,     0,
       3,    27,     0,     0,     0,     0,     0,     2,    35,    51,
      18,    19,    20,    22,    21,     0,     0,    50,    11,    47,
      48,    52,     7,     5,     8,     4,     6,     0,    15,    14,
       0,     0,    33,     0,    78,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    35,     0,    47,    82,    49,    60,
      62,    61,    63,    65,    64,    58,    59,    53,    54,    55,
      56,    12,    16,    47,    34,     0,     0,    32,    23,    81,
       0,    17,    30,    68,    29,    82,    79,    70,     0,     0,
      80,     0,     0,     0,     0,     0,    46,     0,     0,     0,
      71,    36,    37,     0,    38,    39,     0,     0,     0,    42,
      43,    45,    44,     0,     0,     0,    69,    72,    67,     0,
       0,     0,    40,    47,     0,     0,     0,     0,     0,    74,
      75,     0,     0,     0,    41,     0,    73,     0,    76,     0,
      77
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -59,   -22,   -11,   -59,   -59,   -59,    47,   144,     4,
     -59,   -59,    77,   -59,   -58,   -59,   -23,   -50,   -59,    62,
     -59,   -59,    46,   -59,   -59,   -59,   -59,   -59,    54
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    47,     9,    10,    11,    37,    12,    13,    14,
      22,    96,    51,    52,   120,   121,    75,    39,    40,   122,
     108,   109,   123,   124,   125,   159,    41,    77,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    18,    48,    76,    49,     6,     6,   -66,   -66,    42,
       6,    43,    55,    56,    53,     3,    54,    21,    70,    44,
      71,    93,    45,    21,   134,     1,   135,     4,     7,     8,
      46,    15,   107,     5,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    20,    27,
      94,    16,   112,   113,    99,    23,    24,   114,   115,    72,
     116,   117,    25,    26,    17,   137,    50,   118,   137,    65,
      66,    67,    68,   102,   119,    29,    30,    31,    32,    28,
      33,    34,    99,    67,    68,   143,    35,   149,   150,   103,
     136,   129,   130,   131,    69,   156,    36,    95,   112,   113,
      18,   160,    73,   114,   115,   140,   116,   117,     7,     8,
     141,   142,    74,   118,    98,   101,   112,   113,   103,   106,
     119,   114,   115,   127,   116,   117,   128,   132,   154,     7,
       8,   118,   133,   139,   144,   103,   138,   152,   119,   112,
     113,   147,   148,   153,   114,   115,   151,   116,   117,   155,
     157,    97,   158,   103,   118,   111,    19,   126,   104,   110,
       0,   119,     0,    57,    58,    59,    60,    61,    62,    57,
      58,    59,    60,    61,    62,     0,   103,    63,    64,    65,
      66,    67,    68,    63,    64,    65,    66,    67,    68,     0,
       0,     0,   105,     0,     0,     0,     0,    78,    57,    58,
      59,    60,    61,    62,    57,    58,    59,    60,    61,    62,
       0,     0,    63,    64,    65,    66,    67,    68,    63,    64,
      65,    66,    67,    68,     0,     0,   145,    57,    58,    59,
      60,    61,   146,    57,    58,    59,    60,    61,    62,     0,
       0,    63,    64,    65,    66,    67,    68,    63,    64,    65,
      66,    67,    68,    57,    58,    59,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68
};

static const yytype_int16 yycheck[] =
{
      23,    12,    25,    53,    26,     9,     9,    27,    28,     3,
       9,     5,    35,    36,    55,    36,    57,    13,    53,    13,
      55,    71,    16,    19,    53,    18,    55,     0,    27,    28,
      24,    36,    52,    51,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    52,    52,
      72,    36,    14,    15,    77,    53,    54,    19,    20,    54,
      22,    23,    53,    54,    36,   123,    36,    29,   126,    46,
      47,    48,    49,    95,    36,    36,    37,    38,    39,    57,
      41,    42,   105,    48,    49,   135,    47,   145,   146,    51,
      52,   114,   115,   116,    53,   153,    57,    54,    14,    15,
     111,   159,    58,    19,    20,   128,    22,    23,    27,    28,
     133,   134,    59,    29,    56,    56,    14,    15,    51,    58,
      36,    19,    20,    57,    22,    23,    57,    36,   151,    27,
      28,    29,    57,    36,    44,    51,    52,    38,    36,    14,
      15,    56,    47,    11,    19,    20,    53,    22,    23,    25,
      38,    74,    58,    51,    29,   108,    12,   111,    96,   105,
      -1,    36,    -1,    30,    31,    32,    33,    34,    35,    30,
      31,    32,    33,    34,    35,    -1,    51,    44,    45,    46,
      47,    48,    49,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    58,    30,    31,
      32,    33,    34,    35,    30,    31,    32,    33,    34,    35,
      -1,    -1,    44,    45,    46,    47,    48,    49,    44,    45,
      46,    47,    48,    49,    -1,    -1,    58,    30,    31,    32,
      33,    34,    58,    30,    31,    32,    33,    34,    35,    -1,
      -1,    44,    45,    46,    47,    48,    49,    44,    45,    46,
      47,    48,    49,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    61,    36,     0,    51,     9,    27,    28,    63,
      64,    65,    67,    68,    69,    36,    36,    36,    63,    68,
      52,    69,    70,    53,    54,    53,    54,    52,    57,    36,
      37,    38,    39,    41,    42,    47,    57,    66,    76,    77,
      78,    86,     3,     5,    13,    16,    24,    62,    76,    62,
      36,    72,    73,    55,    57,    76,    76,    30,    31,    32,
      33,    34,    35,    44,    45,    46,    47,    48,    49,    53,
      53,    55,    54,    58,    59,    76,    77,    87,    58,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    77,    62,    54,    71,    72,    56,    76,
      88,    56,    62,    51,    79,    59,    58,    52,    80,    81,
      88,    67,    14,    15,    19,    20,    22,    23,    29,    36,
      74,    75,    79,    82,    83,    84,    82,    57,    57,    76,
      76,    76,    36,    57,    53,    55,    52,    74,    52,    36,
      76,    76,    76,    77,    44,    58,    58,    56,    47,    74,
      74,    53,    38,    11,    76,    25,    74,    38,    58,    85,
      74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    62,    62,    62,    63,
      63,    64,    64,    65,    65,    65,    65,    65,    66,    66,
      66,    66,    66,    66,    67,    67,    68,    68,    70,    69,
      71,    71,    72,    72,    73,    73,    74,    74,    74,    74,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    76,
      76,    76,    76,    77,    77,    77,    77,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    80,    79,    81,    79,
      79,    82,    82,    83,    83,    84,    85,    84,    87,    86,
      88,    88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     5,     1,     1,     1,     1,     1,     1,
       1,     4,     6,     2,     4,     4,     6,     7,     1,     1,
       1,     1,     1,     4,     1,     2,     1,     2,     0,     8,
       2,     0,     3,     1,     3,     0,     1,     1,     1,     1,
       3,     6,     2,     2,     2,     2,     1,     1,     1,     3,
       1,     1,     1,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     0,     5,     0,     4,
       2,     1,     2,     7,     5,     5,     0,    11,     0,     5,
       3,     1,     0
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
#line 48 "parser.y" /* yacc.c:1646  */
    {
													Trace("program");
													//symbols.dump();
													symbols.pop();
													if(!havemain) yyerror("without main");
													}
#line 1452 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 54 "parser.y" /* yacc.c:1646  */
    {
								Trace("program");
								//symbols.dump();
								symbols.pop();
								if(!havemain) yyerror("without main");
								}
#line 1463 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 63 "parser.y" /* yacc.c:1646  */
    {
		(yyval.type) = intType;
		}
#line 1471 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 66 "parser.y" /* yacc.c:1646  */
    {
		(yyval.type) = charType;
		}
#line 1479 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 69 "parser.y" /* yacc.c:1646  */
    {
			(yyval.type) = strType;
			}
#line 1487 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 72 "parser.y" /* yacc.c:1646  */
    {
			(yyval.type) = boolType;
			}
#line 1495 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 75 "parser.y" /* yacc.c:1646  */
    {
		(yyval.type) = realType;
		}
#line 1503 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 87 "parser.y" /* yacc.c:1646  */
    {
						Trace("constant declaration without type");
						if(!isConst(*(yyvsp[0].info))) yyerror("expression not constant");
						(yyvsp[0].info)->flag = constVariableFlag;
						(yyvsp[0].info)->init = true;
						if (symbols.insert(*(yyvsp[-2].sval),*(yyvsp[0].info))==-1) yyerror("constant redefinition");
						}
#line 1515 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 94 "parser.y" /* yacc.c:1646  */
    {
										Trace("constant declaration with type");
										if(!isConst(*(yyvsp[0].info))) yyerror("expression not constant");
										if((yyvsp[-2].type)!=(yyvsp[0].info)->type)	yyerror("type not match");
										(yyvsp[0].info)->flag = constVariableFlag;
										(yyvsp[0].info)->init = true;
										if (symbols.insert(*(yyvsp[-4].sval),*(yyvsp[0].info))==-1) yyerror("constant redefinition");
										
										}
#line 1529 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 107 "parser.y" /* yacc.c:1646  */
    {
			Trace("variable declaration");
			idInfo *info = new idInfo();
			info->flag = variableFlag;
			info->type = intType;
			info->init = false;
			if (symbols.insert(*(yyvsp[0].sval), *info) == -1) yyerror("variable redefinition");
			}
#line 1542 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 115 "parser.y" /* yacc.c:1646  */
    {
						Trace("variable declaration with type");
						idInfo *info = new idInfo();
						info->flag = variableFlag;
						info->type = (yyvsp[0].type);
						info->init = false;
						if (symbols.insert(*(yyvsp[-2].sval), *info) == -1) yyerror("variable redefinition");
						}
#line 1555 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 123 "parser.y" /* yacc.c:1646  */
    {
						Trace("variable declaration with value");
						if (!isConst(*(yyvsp[0].info))) yyerror("expression not constant");
						(yyvsp[0].info)->flag = variableFlag;
						(yyvsp[0].info)->init =true;
						if (symbols.insert(*(yyvsp[-2].sval),*(yyvsp[0].info))== -1) yyerror("variable redefinition");						
						}
#line 1567 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 130 "parser.y" /* yacc.c:1646  */
    {
										Trace("variable declaration with type and value");										
										if (!isConst(*(yyvsp[0].info))) yyerror("expression not constant");
										if ((yyvsp[-2].type)!=(yyvsp[0].info)->type)	yyerror("type not match");
										(yyvsp[0].info)->flag= variableFlag;
										(yyvsp[0].info)->init = true;
										if (symbols.insert(*(yyvsp[-4].sval),*(yyvsp[0].info))== -1) yyerror("variable redefinition");
										}
#line 1580 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 138 "parser.y" /* yacc.c:1646  */
    {
											Trace("array variable declaration");
											if(!isConst(*(yyvsp[-1].info))) yyerror("size not constant");
											if((yyvsp[-1].info)->type!=intType)	yyerror("size not int");
											if((yyvsp[-1].info)->value.ival < 1)	yyerror("size < 1");
											if(symbols.insert(*(yyvsp[-5].sval),(yyvsp[-3].type),(yyvsp[-1].info)->value.ival)==-1) yyerror("variable redefinition");
}
#line 1592 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 148 "parser.y" /* yacc.c:1646  */
    {
		(yyval.info) = strConst((yyvsp[0].sval));
		}
#line 1600 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 151 "parser.y" /* yacc.c:1646  */
    {
		(yyval.info) = intConst((yyvsp[0].ival));
		}
#line 1608 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 154 "parser.y" /* yacc.c:1646  */
    {
		(yyval.info) = floatConst((yyvsp[0].dval));
		}
#line 1616 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 157 "parser.y" /* yacc.c:1646  */
    {
		(yyval.info) = boolConst((yyvsp[0].bval));
		}
#line 1624 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 160 "parser.y" /* yacc.c:1646  */
    {
		(yyval.info) = boolConst((yyvsp[0].bval));
		}
#line 1632 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 163 "parser.y" /* yacc.c:1646  */
    {
					idInfo *info = symbols.lookup(*(yyvsp[-3].sval));
                    if (info == NULL) yyerror("undeclared ID");
                    if (info->type != arrayType) yyerror("not array type");
                    if ((yyvsp[-1].info)->type != intType) yyerror("invalid index");
                    if ((yyvsp[-1].info)->value.ival >= info->value.aval.size()) yyerror("index out of range");
                    (yyval.info) = new idInfo(info->value.aval[(yyvsp[-1].info)->value.ival]);
					}
#line 1645 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 188 "parser.y" /* yacc.c:1646  */
    {
			idInfo *info = new idInfo();
			info->flag = functionFlag;
			info->init = false;
			if(symbols.insert(*(yyvsp[0].sval),*info) == -1) yyerror("function redefinition");
			symbols.push();
			if(*(yyvsp[0].sval)=="main") havemain=true;
			}
#line 1658 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 196 "parser.y" /* yacc.c:1646  */
    {
														Trace("method");
														//symbols.dump();
														symbols.pop();
														}
#line 1668 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 204 "parser.y" /* yacc.c:1646  */
    {symbols.setFuncType((yyvsp[0].type));}
#line 1674 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 205 "parser.y" /* yacc.c:1646  */
    {symbols.setFuncType(voidType);}
#line 1680 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 214 "parser.y" /* yacc.c:1646  */
    {
					idInfo *info = new idInfo();
                    info->flag = variableFlag;
                    info->type = (yyvsp[0].type);
                    info->init = false;
                    if (symbols.insert(*(yyvsp[-2].sval), *info) == -1) yyerror("variable redefinition");
                    symbols.addFuncArg(*(yyvsp[-2].sval), *info);
					}
#line 1693 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 234 "parser.y" /* yacc.c:1646  */
    {
					Trace("variable assignment");
					idInfo *info = symbols.lookup(*(yyvsp[-2].sval));
					if (info == NULL) yyerror("undeclared ID");
					if (info->flag == constVariableFlag) yyerror("can't assign value to constant");
					if (info->flag == functionFlag) yyerror("can't assign value to function");
					if (info->type != (yyvsp[0].info)->type) yyerror("type not match");
					}
#line 1706 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 242 "parser.y" /* yacc.c:1646  */
    {
										Trace("array assignment");
										idInfo *info = symbols.lookup(*(yyvsp[-5].sval));
										if (info == NULL) yyerror("undeclared ID");
										if (info->flag != variableFlag) yyerror("not variable");
										if (info->type != arrayType) yyerror("not array");
										if ((yyvsp[-3].info)->type != intType) yyerror("index not int");
										if ((yyvsp[-3].info)->value.ival >= info->value.aval.size() || (yyvsp[-3].info)->value.ival<0) yyerror("index out of range");
										if (info->value.aval[0].type != (yyvsp[0].info)->type)	yyerror("type not match");
										}
#line 1721 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 252 "parser.y" /* yacc.c:1646  */
    {Trace("print");}
#line 1727 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 253 "parser.y" /* yacc.c:1646  */
    {Trace("println");}
#line 1733 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 254 "parser.y" /* yacc.c:1646  */
    {
			Trace("read ID");
			idInfo *info = symbols.lookup(*(yyvsp[0].sval));
			if(info == NULL) yyerror("undeclared ID");
			}
#line 1743 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 259 "parser.y" /* yacc.c:1646  */
    {Trace("retrun");}
#line 1749 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 266 "parser.y" /* yacc.c:1646  */
    {
						Trace("(expression)");
						(yyval.info) = (yyvsp[-1].info);
						}
#line 1758 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 272 "parser.y" /* yacc.c:1646  */
    {
		idInfo *info = symbols.lookup(*(yyvsp[0].sval));
		if (info == NULL) yyerror("undeclared ID");
		(yyval.info) = info;
		}
#line 1768 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 281 "parser.y" /* yacc.c:1646  */
    {
 							Trace("expression + expression");

                        	if ((yyvsp[-2].info)->type != (yyvsp[0].info)->type)
								yyerror("type not match"); /* type check */
                          	if ((yyvsp[-2].info)->type == boolType || (yyvsp[-2].info)->type == strType || (yyvsp[-2].info)->type == charType || (yyvsp[-2].info)->type == arrayType)
								yyerror("operator type error"); /* operator check */

                          	idInfo *info = new idInfo();
                          	info->flag = variableFlag;
                          	info->type = (yyvsp[-2].info)->type;
                          	(yyval.info) = info;
							}
#line 1786 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 294 "parser.y" /* yacc.c:1646  */
    {
 							Trace("expression - expression");

                        	if ((yyvsp[-2].info)->type != (yyvsp[0].info)->type)
								yyerror("type not match");  /* type check */
                          	if ((yyvsp[-2].info)->type == boolType || (yyvsp[-2].info)->type == strType || (yyvsp[-2].info)->type == charType || (yyvsp[-2].info)->type == arrayType)
								yyerror("operator type error"); /* operator check */

                          	idInfo *info = new idInfo();
                          	info->flag = variableFlag;
                          	info->type = (yyvsp[-2].info)->type;
                          	(yyval.info) = info;
							}
#line 1804 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 307 "parser.y" /* yacc.c:1646  */
    {
 							Trace("expression * expression");

                        	if ((yyvsp[-2].info)->type != (yyvsp[0].info)->type)
								yyerror("type not match"); /* type check */
                          	if ((yyvsp[-2].info)->type == boolType || (yyvsp[-2].info)->type == strType || (yyvsp[-2].info)->type == charType || (yyvsp[-2].info)->type == arrayType)
								yyerror("operator type error"); /* operator check */

                          	idInfo *info = new idInfo();
                          	info->flag = variableFlag;
                          	info->type = (yyvsp[-2].info)->type;
                          	(yyval.info) = info;
							}
#line 1822 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 320 "parser.y" /* yacc.c:1646  */
    {
 							Trace("expression / expression");

                        	if ((yyvsp[-2].info)->type != (yyvsp[0].info)->type)
								yyerror("type not match"); /* type check */
                          	if ((yyvsp[-2].info)->type == boolType || (yyvsp[-2].info)->type == strType || (yyvsp[-2].info)->type  == charType || (yyvsp[-2].info)->type == arrayType)
								yyerror("operator type error"); /* operator check */

                          	idInfo *info = new idInfo();
                          	info->flag = variableFlag;
                          	info->type = (yyvsp[-2].info)->type;
                          	(yyval.info) = info;
							}
#line 1840 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 333 "parser.y" /* yacc.c:1646  */
    {
 								Trace("-expression");
                          		if ((yyvsp[0].info)->type == boolType || (yyvsp[0].info)->type == strType || (yyvsp[0].info)->type == charType || (yyvsp[0].info)->type == arrayType)
									yyerror("operator type error"); /* operator check  */

                        	  	idInfo *info = new idInfo();
                    	      	info->flag = variableFlag;
                 	         	info->type = (yyvsp[0].info)->type;
                          		(yyval.info) = info;
								}
#line 1855 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 346 "parser.y" /* yacc.c:1646  */
    {
 							Trace("expression < expression");

                        	if ((yyvsp[-2].info)->type != (yyvsp[0].info)->type)
								yyerror("type not match"); /* type check */
                          	if ((yyvsp[-2].info)->type == boolType || (yyvsp[-2].info)->type == strType || (yyvsp[-2].info)->type == charType || (yyvsp[-2].info)->type == arrayType)
								yyerror("operator type error"); /* operator check */

                          	idInfo *info = new idInfo();
                          	info->flag = variableFlag;
                          	info->type = boolType;
                          	(yyval.info) = info;
							}
#line 1873 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 359 "parser.y" /* yacc.c:1646  */
    {
 							Trace("expression > expression");

   	                    	if ((yyvsp[-2].info)->type != (yyvsp[0].info)->type)
								yyerror("type not match"); /* type check */
            	          	if ((yyvsp[-2].info)->type == boolType || (yyvsp[-2].info)->type == strType || (yyvsp[-2].info)->type == charType || (yyvsp[-2].info)->type == arrayType)
								yyerror("operator type error"); /* operator check */
	
    	                  	idInfo *info = new idInfo();
                        	info->flag = variableFlag;
           	              	info->type = boolType;
            	          	(yyval.info) = info;
							}
#line 1891 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 372 "parser.y" /* yacc.c:1646  */
    {
 								Trace("expression <= expression");
	
    	                    	if ((yyvsp[-2].info)->type != (yyvsp[0].info)->type)
									yyerror("type not match"); /* type check */
            	              	if ((yyvsp[-2].info)->type == boolType || (yyvsp[-2].info)->type == strType || (yyvsp[-2].info)->type == charType || (yyvsp[-2].info)->type == arrayType)
									yyerror("operator type error"); /* operator check */
	
    	                      	idInfo *info = new idInfo();
        	                  	info->flag = variableFlag;
            	              	info->type = boolType;
                	          	(yyval.info) = info;
								}
#line 1909 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 385 "parser.y" /* yacc.c:1646  */
    {
	 							Trace("expression == expression");
	
    	                    	if ((yyvsp[-2].info)->type != (yyvsp[0].info)->type)
									yyerror("type not match"); /* type check */
            	              	if ((yyvsp[-2].info)->type == boolType || (yyvsp[-2].info)->type == strType || (yyvsp[-2].info)->type == charType || (yyvsp[-2].info)->type == arrayType)
									yyerror("operator type error"); /* operator check */
	
    	                      	idInfo *info = new idInfo();
        	                  	info->flag = variableFlag;
            	              	info->type = boolType;
                	          	(yyval.info) = info;
								}
#line 1927 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 398 "parser.y" /* yacc.c:1646  */
    {
	 							Trace("expression >= expression");
	
    	                    	if ((yyvsp[-2].info)->type != (yyvsp[0].info)->type)
									yyerror("type not match"); /* type check */
            	              	if ((yyvsp[-2].info)->type == boolType || (yyvsp[-2].info)->type == strType || (yyvsp[-2].info)->type == charType || (yyvsp[-2].info)->type == arrayType)
									yyerror("operator type error"); /* operator check */
	
    	                      	idInfo *info = new idInfo();
        	                  	info->flag = variableFlag;
            	              	info->type = boolType;
                	          	(yyval.info) = info;
								}
#line 1945 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 411 "parser.y" /* yacc.c:1646  */
    {
	 							Trace("expression != expression");
	
    	                    	if ((yyvsp[-2].info)->type != (yyvsp[0].info)->type)
									yyerror("type not match"); /* type check */
            	              	if ((yyvsp[-2].info)->type == boolType || (yyvsp[-2].info)->type == strType || (yyvsp[-2].info)->type == charType || (yyvsp[-2].info)->type == arrayType)
									yyerror("operator type error"); /* operator check */
	
    	                      	idInfo *info = new idInfo();
        	                  	info->flag = variableFlag;
            	              	info->type = boolType;
                	          	(yyval.info) = info;
								}
#line 1963 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 424 "parser.y" /* yacc.c:1646  */
    {
	 							Trace("expression || expression");
	
    	                    	if ((yyvsp[-2].info)->type != (yyvsp[0].info)->type)
									yyerror("type not match"); /* type check */
            	              	if ((yyvsp[-2].info)->type != boolType)
									yyerror("operator type error"); /* operator check */
	
        	                  	idInfo *info = new idInfo();
            	              	info->flag = variableFlag;
                	          	info->type = boolType;
                    	      	(yyval.info) = info;
								}
#line 1981 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 437 "parser.y" /* yacc.c:1646  */
    {
	 							Trace("expression && expression");
	
	                        	if ((yyvsp[-2].info)->type != (yyvsp[0].info)->type)
									yyerror("type not match"); /* type check */
	                          	if ((yyvsp[-2].info)->type != boolType)
									yyerror("operator type error"); /* operator check */
	
    	                      	idInfo *info = new idInfo();
        	                  	info->flag = variableFlag;
            	              	info->type = boolType;
                	          	(yyval.info) = info;
								}
#line 1999 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 454 "parser.y" /* yacc.c:1646  */
    {
		symbols.push();
		}
#line 2007 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 457 "parser.y" /* yacc.c:1646  */
    {
										//symbols.dump();
										symbols.pop();
										}
#line 2016 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 461 "parser.y" /* yacc.c:1646  */
    {
		symbols.push();
		}
#line 2024 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 464 "parser.y" /* yacc.c:1646  */
    {
					//symbols.dump();
					symbols.pop();
					}
#line 2033 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 479 "parser.y" /* yacc.c:1646  */
    {
													Trace("selection condition with else");
													if ((yyvsp[-4].info)->type!=boolType) yyerror("condition type error");
													}
#line 2042 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 483 "parser.y" /* yacc.c:1646  */
    {
									Trace("selection condition");
									if ((yyvsp[-2].info)->type!=boolType) yyerror("condition type error");
									}
#line 2051 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 491 "parser.y" /* yacc.c:1646  */
    {
										Trace("while loop");
										if ((yyvsp[-2].info)->type!=boolType) yyerror("condition type error");
										}
#line 2060 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 495 "parser.y" /* yacc.c:1646  */
    {
									Trace("for loop");
									idInfo *info = symbols.lookup(*(yyvsp[-6].sval));
									if (info == NULL) yyerror("undeclared ID");
									}
#line 2070 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 505 "parser.y" /* yacc.c:1646  */
    {
		function.push_back(vector<idInfo>());
		}
#line 2078 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 508 "parser.y" /* yacc.c:1646  */
    {
							Trace("procedure_statement");

							idInfo *info = symbols.lookup(*(yyvsp[-4].sval));
							if (info==NULL) yyerror("undeclared ID");
							if (info->flag!=functionFlag) yyerror("Not a function)");
	
							vector<idInfo> parameter = info->value.aval;
							if (parameter.size() != function[function.size()-1].size()) yyerror("parameter size not match");
							for(int i=0;i<parameter.size();i++)
							{
								if(parameter[i].type!= function[function.size()-1][i].type) yyerror("parameter type not match");
							}
							(yyval.info) = info;
							function.pop_back();
							}
#line 2099 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 527 "parser.y" /* yacc.c:1646  */
    {
										function[function.size()-1].push_back (*(yyvsp[-2].info));
										}
#line 2107 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 530 "parser.y" /* yacc.c:1646  */
    {
				function[function.size()-1].push_back (*(yyvsp[0].info));
				}
#line 2115 "y.tab.cpp" /* yacc.c:1646  */
    break;


#line 2119 "y.tab.cpp" /* yacc.c:1646  */
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
#line 538 "parser.y" /* yacc.c:1906  */


void yyerror(const char *msg)
{
    fprintf(stderr, "%s\n", msg);
}

int main()
{
	yyparse();
	return 0;
}

