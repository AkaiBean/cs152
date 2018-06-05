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

/* "%code top" blocks.  */
#line 2 "mini_l.y" /* yacc.c:316  */

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define YY_USER_INIT yylloc.first_line=1;
    void yyerror(const char* msg);
    /*int yyerror(const char* msg);*/
    extern int currLine;
    extern int currPos;
    FILE * yyin;

#line 75 "y.tab.c" /* yacc.c:316  */



/* Copy the first part of user declarations.  */

#line 81 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 15 "mini_l.y" /* yacc.c:355  */

    typedef struct 
    {
        char* vName;
        char* vType;
        int vID;
        char vStatement[128];
    }variable;

    variable vArr[1024];
    int numList[1024];
    variable tracker[1024];
    void tpush(variable ele);
    variable tpop();
    int top;

    variable createTempStr(variable* arr, int* intList, char* ident);
    variable createTempNum(variable* arr, int* intList, int num);
    variable decTemp(variable* arr, int* intList);
    void initTemp(variable* arr, variable ele);
    int insArr(variable* arr, variable ele);
    void initArr(variable* arr, int size);
    void printArr(variable* arr);

    int boolean;
    int numCnt;
    int labCnt;
    int paramCnt;
    int isMain;
    void deepcpy(char* dest, char* src);
    void deepFind(char* dest, char* src);
    
    variable ltracker[1024];
    void lpush(variable ele);
    variable lpop();
    int ltop;
    int errFlag;
    
    variable whiletracker[1024];
    void whilepush(variable ele);
    variable whilepop();
    int whiletop;
    int whileCnt;
    int numAnd;
    int readCnt;
    int writeCnt;
    void checkDec(variable* arr, char* ident);

#line 160 "y.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FUNCTION = 258,
    BEGINPARAMS = 259,
    ENDPARAMS = 260,
    BEGINLOCALS = 261,
    ENDLOCALS = 262,
    BEGINBODY = 263,
    ENDBODY = 264,
    INTEGER = 265,
    ARRAY = 266,
    OF = 267,
    IF = 268,
    THEN = 269,
    ENDIF = 270,
    ELSE = 271,
    WHILE = 272,
    DO = 273,
    FOREACH = 274,
    IN = 275,
    BEGINLOOP = 276,
    ENDLOOP = 277,
    CONTINUE = 278,
    READ = 279,
    WRITE = 280,
    TRUE = 281,
    FALSE = 282,
    RETURN = 283,
    SEMICOLON = 284,
    COLON = 285,
    COMMA = 286,
    L_PAREN = 287,
    R_PAREN = 288,
    L_SQUARE_BRACKET = 289,
    R_SQUARE_BRACKET = 290,
    IDENT = 291,
    NUMBER = 292,
    MULT = 293,
    DIV = 294,
    MOD = 295,
    ADD = 296,
    SUB = 297,
    LT = 298,
    LTE = 299,
    GT = 300,
    GTE = 301,
    EQ = 302,
    NEQ = 303,
    AND = 304,
    OR = 305,
    ASSIGN = 306,
    NOT = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 64 "mini_l.y" /* yacc.c:355  */

    char* sval;
    int ival;

#line 230 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 247 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   162

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    80,    80,    92,    93,    96,   104,   114,   120,   126,
     127,   130,   147,   160,   167,   170,   188,   189,   208,   209,
     212,   269,   280,   284,   300,   310,   340,   349,   373,   396,
     408,   462,   473,   489,   501,   513,   523,   547,   575,   591,
     592,   602,   614,   615,   625,   630,   642,   648,   655,   656,
     670,   671,   685,   686,   687,   697,   698,   699,   700,   701,
     704,   729,   730,   742,   754,   769,   783,   784,   785,   788,
     789,   803,   819,   820,   832,   844,   858,   859,   860,   861,
     862,   863,   864,   903
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNCTION", "BEGINPARAMS", "ENDPARAMS",
  "BEGINLOCALS", "ENDLOCALS", "BEGINBODY", "ENDBODY", "INTEGER", "ARRAY",
  "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "FOREACH", "IN",
  "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE", "TRUE", "FALSE",
  "RETURN", "SEMICOLON", "COLON", "COMMA", "L_PAREN", "R_PAREN",
  "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "IDENT", "NUMBER", "MULT", "DIV",
  "MOD", "ADD", "SUB", "LT", "LTE", "GT", "GTE", "EQ", "NEQ", "AND", "OR",
  "ASSIGN", "NOT", "$accept", "progam", "functions", "function",
  "functionIdent", "beginparamIdent", "endparamIdent", "declarations",
  "declaration", "checkident", "commaIdent", "statements", "statement",
  "foreachwhile", "ifelse", "whileexp", "whilebegin", "dobegin",
  "endwhile", "statement_var", "ifclause", "rvars", "wvars", "var",
  "bool_exp", "relation_and_exp", "relation_exp", "relation_exp_comp",
  "expressions", "expression", "multiplicative_expression", "term",
  "number", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

#define YYPACT_NINF -47

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-47)))

#define YYTABLE_NINF -10

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      36,   -31,    30,   -47,    36,    12,   -47,   -47,   -47,    44,
     -47,    10,   -47,   -47,    49,    32,    47,   -47,    74,     2,
      54,    72,    11,   -47,    47,    48,   105,   -47,   -47,    79,
     106,   -29,    64,    80,    81,   -10,   -47,    95,    83,   -47,
      84,    86,   -13,    89,   108,    96,    64,   103,   -10,    64,
      75,    64,   115,    93,   -47,   -47,   -10,    -1,   -47,     8,
      59,   -47,   116,    82,    85,   -47,    60,   -21,    71,   -47,
     -47,   109,   100,   -47,    -6,   -47,   -13,   -47,   -13,   -47,
      64,   111,    64,   -47,   113,   -13,    78,   126,   125,   107,
      27,   -13,   -13,   -13,   104,   -47,   -47,   -47,   -47,   -10,
     -47,   -47,   -10,   -10,   -13,   -13,   -13,   -13,   -13,   -13,
     -13,   -13,   -13,   -13,   -13,   110,    84,    86,   -13,   112,
     114,   -47,   -47,   117,   124,   -10,   -47,   -47,   -47,    64,
     -47,   132,   -47,   -47,   118,   119,   120,   121,   123,   -47,
     -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,   -47,   122,   -47,   -47,   127,   -47,   -47,   -47,   -47,
     129,   -47,   -47,   -13,   -47,   -47,   -47,   -47,   -47,   -47,
     -47
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     3,     0,     6,     1,     4,     0,
       7,     0,    15,    14,     0,     0,    16,     8,     0,     0,
       0,     0,     0,    10,    16,     0,     0,    17,    11,     0,
       0,     0,    18,     0,     0,     0,    33,     0,     0,    28,
      39,    42,     0,    36,     0,     0,    18,     0,     0,    18,
       0,    18,     0,     0,    53,    54,     0,    46,    83,     0,
       0,    76,     0,    48,    50,    52,     0,    69,    72,    77,
      34,     0,    40,    26,    43,    27,     0,    29,     0,     5,
      18,     0,    18,    32,     0,     0,     0,     0,     0,     0,
       0,    66,     0,     0,    46,    80,    79,    57,    58,     0,
      56,    38,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    42,     0,     0,
       0,    19,    25,     0,     0,     0,    20,    21,    31,    18,
      12,     0,    55,    78,     0,    67,     0,     0,     0,    49,
      51,    62,    64,    63,    65,    60,    61,    70,    71,    73,
      74,    75,     0,    41,    45,     0,    37,    23,    35,    24,
       0,    13,    82,    66,    47,    81,    59,    30,    44,    22,
      68
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -47,   -47,   143,   -47,   -47,   -47,   -47,    33,   -47,   -47,
     128,   -45,   -47,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,    37,    31,    98,   -46,    55,   -47,    99,    -3,   -42,
     -15,   -47,   -47
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,    11,    18,    14,    15,    16,
      21,    44,    45,    46,   129,    47,    48,    49,   125,    50,
      51,    73,    75,    61,    62,    63,    64,    65,   134,    66,
      67,    68,    69
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,    81,    83,    12,    84,     6,    86,    -9,    33,    -9,
      89,    12,    12,    34,    90,    -9,    54,    55,    -9,    76,
     110,   111,    56,    57,    58,   117,    57,    58,   118,    59,
       7,    91,    59,    92,   119,   121,   120,   123,    13,     1,
      93,     9,    60,   126,    94,    95,    13,    13,    10,   135,
     136,   137,    23,   138,    17,    26,   139,    90,    28,    29,
     133,    19,   141,   142,   143,   144,   145,   146,   147,   148,
     104,   105,   106,   107,   108,   109,   155,    35,    20,   159,
      22,    36,    37,    38,   160,    97,    98,    39,    40,    41,
      24,    99,    42,   127,   128,    57,    58,   149,   150,   151,
      43,    59,    25,   104,   105,   106,   107,   108,   109,   112,
     113,   114,    30,    31,    32,    52,    70,    79,    53,    71,
      72,   135,    74,    78,    82,    80,    85,    87,    88,   115,
     101,   116,   102,   122,   103,   124,   130,   131,    92,   157,
     132,   158,   161,   167,   169,   133,   152,     8,   154,   156,
     163,   162,    27,   153,   165,   164,   166,    96,   140,   100,
     170,     0,   168
};

static const yytype_int16 yycheck[] =
{
      42,    46,    48,     1,    49,    36,    51,     5,    37,     7,
      56,     1,     1,    42,    56,     5,    26,    27,     7,    32,
      41,    42,    32,    36,    37,    31,    36,    37,    34,    42,
       0,    32,    42,    34,    76,    80,    78,    82,    36,     3,
      32,    29,    52,    85,    36,    37,    36,    36,     4,    91,
      92,    93,    19,    99,     5,    22,   102,    99,    10,    11,
      33,    29,   104,   105,   106,   107,   108,   109,   110,   111,
      43,    44,    45,    46,    47,    48,   118,    13,    31,   125,
       6,    17,    18,    19,   129,    26,    27,    23,    24,    25,
      36,    32,    28,    15,    16,    36,    37,   112,   113,   114,
      36,    42,    30,    43,    44,    45,    46,    47,    48,    38,
      39,    40,     7,    34,     8,    35,    21,     9,    37,    36,
      36,   163,    36,    34,    21,    29,    51,    12,    35,    20,
      14,    31,    50,    22,    49,    22,    10,    12,    34,    22,
      33,    17,    10,    21,    15,    33,    36,     4,   117,    35,
      31,    33,    24,   116,    33,    35,    33,    59,   103,    60,
     163,    -1,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    54,    55,    56,    57,    36,     0,    55,    29,
       4,    58,     1,    36,    60,    61,    62,     5,    59,    29,
      31,    63,     6,    60,    36,    30,    60,    63,    10,    11,
       7,    34,     8,    37,    42,    13,    17,    18,    19,    23,
      24,    25,    28,    36,    64,    65,    66,    68,    69,    70,
      72,    73,    35,    37,    26,    27,    32,    36,    37,    42,
      52,    76,    77,    78,    79,    80,    82,    83,    84,    85,
      21,    36,    36,    74,    36,    75,    32,    82,    34,     9,
      29,    64,    21,    77,    64,    51,    64,    12,    35,    77,
      82,    32,    34,    32,    36,    37,    76,    26,    27,    32,
      80,    14,    50,    49,    43,    44,    45,    46,    47,    48,
      41,    42,    38,    39,    40,    20,    31,    31,    34,    82,
      82,    64,    22,    64,    22,    71,    82,    15,    16,    67,
      10,    12,    33,    33,    81,    82,    82,    82,    77,    77,
      78,    82,    82,    82,    82,    82,    82,    82,    82,    83,
      83,    83,    36,    74,    75,    82,    35,    22,    17,    77,
      64,    10,    33,    31,    35,    33,    33,    21,    35,    15,
      81
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    57,    58,    59,    60,
      60,    61,    61,    61,    62,    62,    63,    63,    64,    64,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      66,    67,    68,    69,    70,    71,    72,    72,    73,    74,
      74,    74,    75,    75,    75,    75,    76,    76,    77,    77,
      78,    78,    79,    79,    79,    79,    79,    79,    79,    79,
      80,    80,    80,    80,    80,    80,    81,    81,    81,    82,
      82,    82,    83,    83,    83,    83,    84,    84,    84,    84,
      84,    84,    84,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,    11,     2,     1,     1,     0,
       3,     4,     9,    10,     1,     1,     0,     3,     0,     3,
       3,     3,     5,     4,     4,     3,     2,     2,     1,     2,
       5,     1,     2,     1,     2,     2,     1,     4,     3,     0,
       1,     3,     0,     1,     4,     3,     1,     4,     1,     3,
       1,     3,     1,     1,     1,     3,     2,     2,     2,     4,
       3,     3,     3,     3,     3,     3,     0,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     1,     3,     2,
       2,     4,     4,     1
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
#line 81 "mini_l.y" /* yacc.c:1646  */
    {
            if(!isMain)
            {
                errFlag = 1;
                char* msg;
                msg = "\"main\" function is not defined.";
                yyerror(msg);
            }
        }
#line 1456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 97 "mini_l.y" /* yacc.c:1646  */
    {
            variable myVar = {"endfunc", "endfunction", -1, "endfunc\n"};
            insArr(vArr, myVar);
            paramCnt = 0;   // reset paramCnt for next function
        }
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 105 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            sprintf(msg, "func %s\n", (yyvsp[0].sval));
            variable myVar = {(yyvsp[0].sval), "function", -1};
            deepcpy(myVar.vStatement, msg);
            insArr(vArr, myVar);
        }
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 115 "mini_l.y" /* yacc.c:1646  */
    {
            boolean = 1;
        }
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 121 "mini_l.y" /* yacc.c:1646  */
    {
            boolean = 0;
        }
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 131 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            sprintf(msg, ". %s\n", (yyvsp[-3].sval));
            variable myVar = {(yyvsp[-3].sval), "dec", -1};
            deepcpy(myVar.vStatement, msg);
            if(boolean)
            {
                char msg2[128];
                myVar.vType = "paramdec";
                myVar.vID = numList[paramCnt]; 
                sprintf(msg2, ". %s\n= %s, $%d\n", (yyvsp[-3].sval), (yyvsp[-3].sval), myVar.vID);
                deepcpy(myVar.vStatement, msg2);
                paramCnt++;
            }
            insArr(vArr, myVar);
        }
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 148 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            if((yyvsp[-3].ival) <= 0)
            {
                errFlag = 1;
                yyerror("array size cannot be <= 0.");
            }
            sprintf(msg, ".[] %s, %d\n", (yyvsp[-8].sval), (yyvsp[-3].ival));
            variable myVar = {(yyvsp[-8].sval), "arrdec", (yyvsp[-3].ival)};
            deepcpy(myVar.vStatement, msg);
            insArr(vArr, myVar);
        }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 161 "mini_l.y" /* yacc.c:1646  */
    {
            errFlag = 1;
            yyerror("array size cannot be <= 0.");
        }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 168 "mini_l.y" /* yacc.c:1646  */
    {
          }
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 171 "mini_l.y" /* yacc.c:1646  */
    {
              printf("");
              /*int i;
              for(i = 0; i< 29; i++)
              {
                  printf("vArr[i]: %s, ident: %s\n", vArr[i].vName, $$);
                  if(strcmp(vArr[i].vName, $$) == 0)
                  {
                      printf("found error\n");
                      char msg[128];
                      sprintf(msg, "variable name \"%s\" is a reserved keyword.", $$);
                      yyerror(msg);
                  }
              }*/
          }
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 190 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            sprintf(msg, ". %s\n", (yyvsp[-1].sval));
            variable myVar = {(yyvsp[-1].sval), "dec", -1};
            deepcpy(myVar.vStatement, msg);
            if(boolean)
            {
                char msg2[128];                
                myVar.vType = "paramdec";
                myVar.vID = numList[paramCnt];
                sprintf(msg2, ". %s\n= %s, $%d\n", (yyvsp[-1].sval), (yyvsp[-1].sval), myVar.vID);
                deepcpy(myVar.vStatement, msg2);
                paramCnt++;
            }
            insArr(vArr, myVar);
        }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 213 "mini_l.y" /* yacc.c:1646  */
    {
            // now have to check for expression type also
            char msg[128];
            variable src = tpop();      //expression
            variable myVar2 = tpop();   //statement var
               
            if(strcmp(myVar2.vType, "variable") == 0 && (strcmp(src.vType, "temp") == 0 || strcmp(src.vType, "multiplicative") == 0))
            {
                checkDec(vArr, myVar2.vName); 
                sprintf(msg, "= %s, %s%d\n", myVar2.vName, src.vName, src.vID);
                deepcpy(myVar2.vStatement, msg);
                initTemp(vArr, myVar2);
            }
            else if(strcmp(myVar2.vType, "temp") == 0 && strcmp(src.vType, "arrVariable") == 0)
            {
                variable myIdent = tpop();
                if(strcmp(myIdent.vType, "variable") == 0)
                {
                    variable myVar3 = {myIdent.vName, "assignToArray", -1};
                    sprintf(msg, "=[] %s, %s, %s%d\n", myIdent.vName, src.vName, myVar2.vName, myVar2.vID);
                    deepcpy(myVar3.vStatement, msg);
                    initTemp(vArr, myVar3);
                }
                else if(strcmp(myIdent.vType, "arrVariable") == 0)
                {
                    variable identIndex = tpop();
                    variable temp = {"temp_", "temp", numCnt};
                    numCnt++;
                    variable myVar3 = {myIdent.vName, "arrayToArray", -1};
                    
                    sprintf(msg, ". %s%d\n=[] %s%d, %s, %s%d\n", temp.vName, temp.vID, temp.vName, temp.vID, src.vName, myVar2.vName, myVar2.vID);
                    deepcpy(temp.vStatement, msg);
                    initTemp(vArr, temp);
                    char msg2[128];
                    sprintf(msg2, "[]= %s, %s%d, %s%d\n", myIdent.vName, identIndex.vName, identIndex.vID, temp.vName, temp.vID);
                    deepcpy(myVar3.vStatement, msg2);
                    initTemp(vArr, myVar3);
                }
            }
            else if(strcmp(myVar2.vType, "arrVariable") == 0 && strcmp(src.vType, "temp") == 0)
            {
                variable indexx = tpop();   //expression
                variable myVar3 = {myVar2.vName, "arrAssign", -1};
                sprintf(msg, "[]= %s, %s%d, %s%d\n", myVar2.vName, indexx.vName, indexx.vID, src.vName, src.vID);
                deepcpy(myVar3.vStatement, msg);
                initTemp(vArr, myVar3);
            }
            else if(strcmp(myVar2.vType, "arrVariable") == 0 && strcmp(src.vType, "multiplicative") == 0)
            {
                variable express = tpop();  //expression
                variable myVar3 = {myVar2.vName, "arrAssignMult", -1};
                sprintf(msg, "[]= %s, %s%d, %s%d\n", myVar2.vName, express.vName, express.vID, src.vName, src.vID);
                deepcpy(myVar3.vStatement, msg);
                initTemp(vArr, myVar3);
            }
        }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 270 "mini_l.y" /* yacc.c:1646  */
    {
            if(strcmp(ltracker[ltop].vType, "do_while_loop_cond") != 0)
            {
                char msg[128];
                variable myVar = lpop();
                sprintf(msg, ": %s%d\n", myVar.vName, myVar.vID);
                deepcpy(myVar.vStatement, msg);
                initTemp(vArr, myVar);
            }
        }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 281 "mini_l.y" /* yacc.c:1646  */
    {
            
        }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 285 "mini_l.y" /* yacc.c:1646  */
    {
           char msg[128];
           char msg2[128];
           variable f = whilepop();
           variable f2 = {"gobackwhile", "gobackwhile", -1};
           sprintf(msg2, ":= %s%d\n", f.vName, f.vID);
           deepcpy(f2.vStatement, msg2);
           initTemp(vArr, f2);

           variable v = lpop();
           variable v2= {"whileendloop", "whileendloop", -1};
           sprintf(msg, ": %s%d\n", v.vName, v.vID);
           deepcpy(v2.vStatement, msg);
           initTemp(vArr, v2);
        }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 301 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable myVar1 = tpop();
            variable myVar2 = whilepop();
            variable myVar3 = {"endwhileloop", "endwhileloop", -1};
            sprintf(msg, "?:= %s%d, %s%d\n", myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar3.vStatement,msg);
            initTemp(vArr, myVar3);
        }
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 311 "mini_l.y" /* yacc.c:1646  */
    {
            variable v3 = tpop();
            variable t1 = tpop();   
            variable v = tpop();   
            variable v2 = tpop();   
            //printf("v2 %s", v2.vStatement);
            // add 1 then check if is_prime < size, if not go to new label
           
            /*char msg1[128];
            variable chk = {"temp_", "temp", numCnt};
            numCnt++;
            sprintf(msg1, ". %s%d\n< %s%d, %s, %d\n?:= %s%d, %s%d\n", chk.vName, chk.vID, chk.vName, chk.vID, ttop.vName, v2.vID, v3.vName, v3.vID, chk.vName, chk.vID);
            deepcpy(chk.vStatement, msg1);
            initTemp(vArr, chk);*/

            char msg1[128];
            variable inc = {"temp_", "temp", numCnt};
            numCnt++;
            sprintf(msg1, ". %s%d\n= %s%d, %s%d\n+ %s%d, %s%d, 1\n", inc.vName, inc.vID, inc.vName, inc.vID, t1.vName, t1.vID, t1.vName, t1.vID, inc.vName, inc.vID);
            deepcpy(inc.vStatement, msg1);
            initTemp(vArr, inc);

            char msg2[128];
            variable chk = {"temp_", "temp", numCnt};
            numCnt++;
            sprintf(msg2, ". %s%d\n< %s%d, %s%d, %d\n?:= %s%d, %s%d\n", chk.vName, chk.vID, chk.vName, chk.vID, t1.vName, t1.vID, v2.vID, v3.vName, v3.vID, chk.vName, chk.vID);
            deepcpy(chk.vStatement, msg2);
            initTemp(vArr, chk);
        }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 341 "mini_l.y" /* yacc.c:1646  */
    {
            int i;
            for(i = 0; i < readCnt; i++)
            {
                initTemp(vArr, tpop());
            }
            readCnt = 0;
        }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 350 "mini_l.y" /* yacc.c:1646  */
    {
            variable testVar = tracker[top];
            if(strcmp(testVar.vType, "arrWrite") == 0)
            {
                char msg[128];
                testVar = tpop();
                variable myVar1 = tpop();
                variable myVar2 = {testVar.vName, "arrWriteAssign", -1};
                sprintf(msg, ".[]> %s, %s%d\n", testVar.vName, myVar1.vName, myVar1.vID);
                deepcpy(myVar2.vStatement, msg);
                initTemp(vArr, myVar2);
            }
            else if(strcmp(testVar.vType, "write") == 0)
            {
                int i;
                variable reverse[128];
                for(i = 0; i < writeCnt; i++)
                {
                    initTemp(vArr, tpop());
                }
                writeCnt = 0;
            }
        }
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 374 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable myVar2 = whilepop();
            whilepush(myVar2);
            if(strcmp(myVar2.vType, "dowhileloop") == 0)
            {
                variable myVar1 = {"do_while_loop_check_", "do_while_loop_cond", whileCnt};
                whileCnt++;
                sprintf(msg, ":= %s%d\n", myVar1.vName, myVar1.vID);
                deepcpy(myVar1.vStatement, msg);
                whilepush(myVar1);
                initTemp(vArr, myVar1);
            }
            else if(strcmp(myVar2.vType, "whileloop") == 0)
            {
               // go back to beginning
               variable v = {"continue", "continuewhile", -1};
               sprintf(msg, ":= %s%d\n", myVar2.vName, myVar2.vID);
               deepcpy(v.vStatement, msg);
               initTemp(vArr, v);
            }
        }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 397 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable myVar1;
            variable myVar2 = {"ret", "return", -1};
            myVar1 = tpop();
            sprintf(msg, "ret %s%d\n", myVar1.vName, myVar1.vID);             
            deepcpy(myVar2.vStatement, msg);
            initTemp(vArr, myVar2);
        }
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 409 "mini_l.y" /* yacc.c:1646  */
    {
            variable v = {(yyvsp[-3].sval), "foreachident", 0};
            insArr(vArr, v);
            int i;
            int err = 1;
            variable v2;
            for(i = 0; i < 1024; i++)
            {
                if(strcmp(vArr[i].vName, (yyvsp[-1].sval)) == 0 && strcmp(vArr[i].vType, "arrdec") == 0)
                {
                    err = 0;
                    v2 = vArr[i];
                    tpush(v2);
                }
            }
            if(err)
            {
                errFlag = 1;
                char msg[128];
                sprintf(msg, "used variable \"%s\" is scalar", (yyvsp[-1].sval));
                yyerror(msg);
            }
            char msg1[128];
            sprintf(msg1, ". %s\n", v.vName);
            deepcpy(v.vStatement, msg1);
            initTemp(vArr, v);
            tpush(v);
            
            char msg2[128];
            variable t1 = {"temp_", "temp", numCnt};
            numCnt++;
            sprintf(msg2, ". %s%d\n= %s%d, 0\n", t1.vName, t1.vID, t1.vName, t1.vID);
            deepcpy(t1.vStatement, msg2);
            initTemp(vArr, t1);
            tpush(t1);

            char msg3[128];
            variable v3 = {"for_each_loop_", "foreachloop", whileCnt};
            whileCnt++;
            sprintf(msg3, ": %s%d\n", v3.vName, v3.vID);
            deepcpy(v3.vStatement, msg3);
            initTemp(vArr, v3);
            tpush(v3);

            char msg4[128];
            variable v4 = {"arrAccess", "arrAccess", -1};
            sprintf(msg4, "=[] %s, %s, %s%d\n", v.vName, v2.vName, t1.vName, t1.vID);
            deepcpy(v4.vStatement, msg4);
            initTemp(vArr, v4);
            
        }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 463 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable v = lpop();
            variable v2 = {"else", "ifelse", -1};
            sprintf(msg, ": %s%d\n", v.vName, v.vID);
            deepcpy(v2.vStatement,msg);
            initTemp(vArr, v2);
        }
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 474 "mini_l.y" /* yacc.c:1646  */
    {
               // check if condition is false
               char msg[128];
               variable v = tpop();
               variable a = {"temp_", "whilecond", numCnt};
               variable l = {"label_", "label", labCnt};
               numCnt++;
               labCnt++;
               sprintf(msg, ". %s%d\n== %s%d, %s%d, 0\n?:= %s%d, %s%d\n", a.vName, a.vID, a.vName, a.vID, v.vName, v.vID, l.vName, l.vID, a.vName, a.vID);
               deepcpy(a.vStatement, msg);
               initTemp(vArr, a);
               lpush(l);   
        }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 490 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable myVar1 = {"while_loop_", "whileloop", whileCnt};
            whileCnt++;
            sprintf(msg, ": %s%d\n", myVar1.vName, myVar1.vID);
            deepcpy(myVar1.vStatement, msg);
            initTemp(vArr, myVar1);
            whilepush(myVar1);
        }
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 502 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable myVar1 = {"do_while_loop_", "dowhileloop", whileCnt};
            whileCnt++;
            sprintf(msg, ": %s%d\n", myVar1.vName, myVar1.vID);
            deepcpy(myVar1.vStatement, msg);
            initTemp(vArr, myVar1);
            whilepush(myVar1);
        }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 514 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable myVar1 = whilepop();
            variable myVar2 = {"do_while_loop_check_", "do_while_loop_cond", myVar1.vID};
            sprintf(msg, ": %s%d\n", myVar2.vName, myVar2.vID);
            deepcpy(myVar2.vStatement, msg);
            initTemp(vArr, myVar2);
        }
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 524 "mini_l.y" /* yacc.c:1646  */
    {
            // basically check dec
            int i = 0;
            int decFlag = 1;
            while(vArr[i].vName != "")
            {
                if(strcmp(vArr[i].vName, (yyvsp[0].sval)) == 0 && strcmp(vArr[i].vType, "arrdec") == 0)
                {
                    decFlag = 0;
                    break;
                }
                i++;
            }
            if(!decFlag)
            {
                errFlag = 1;
                char msg[128];
                sprintf(msg, "need to specify an index for array variable \"%s\".", (yyvsp[0].sval));
                yyerror(msg);
            }
            variable myVar = {(yyvsp[0].sval), "variable", -1};
            tpush(myVar);
        }
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 548 "mini_l.y" /* yacc.c:1646  */
    {
            //basically check dec
            int i = 0;
            int decFlag = 1;
            while(vArr[i].vName != "")
            {
                //printf("%s, %s\n", vArr[i].vName, vArr[i].vType);
                if(strcmp(vArr[i].vName, (yyvsp[-3].sval)) == 0 && strcmp(vArr[i].vType, "dec") == 0)
                {
                    decFlag = 0;
                    break;
                }
                i++;
            }
            if(!decFlag)
            {
                errFlag = 1;
                char msg[128];
                sprintf(msg, "\"%s\" is not an array variable. Cannot use a regular variable as an array variable.", (yyvsp[-3].sval));
                yyerror(msg);
            }
            variable myVar = {(yyvsp[-3].sval), "arrVariable", -1};
            tpush(myVar);
        }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 576 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable myVar1 = {"label_", "label", labCnt};
            labCnt++;
            variable myVar2 = {"label_", "label", labCnt};
            labCnt++;
            variable myVar3 = tpop();   // might have to for loop using top variable
            sprintf(msg, "?:= %s%d, %s%d\n:= %s%d\n: %s%d\n", myVar1.vName, myVar1.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar1.vStatement, msg);
            initTemp(vArr, myVar1);
            lpush(myVar2);
        }
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 593 "mini_l.y" /* yacc.c:1646  */
    {
            checkDec(vArr, (yyvsp[0].sval));
            char msg[128];
            variable myVar1 = {(yyvsp[0].sval), "read", -1};
            sprintf(msg, ".< %s\n", (yyvsp[0].sval));
            deepcpy(myVar1.vStatement, msg);
            tpush(myVar1);
            readCnt++;
        }
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 603 "mini_l.y" /* yacc.c:1646  */
    {
            checkDec(vArr, (yyvsp[-2].sval));
            char msg[128];
            variable myVar1 = {(yyvsp[-2].sval), "read", -1};
            sprintf(msg, ".< %s\n", (yyvsp[-2].sval));
            deepcpy(myVar1.vStatement, msg);
            tpush(myVar1);
            readCnt++;
        }
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 616 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable myVar1 = {(yyvsp[0].sval), "write", -1};
            sprintf(msg, ".> %s\n", (yyvsp[0].sval));
            deepcpy(myVar1.vStatement, msg);
            //initTemp(vArr, myVar1);
            tpush(myVar1);
            writeCnt++;
        }
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 626 "mini_l.y" /* yacc.c:1646  */
    {
            variable myVar = {(yyvsp[-3].sval), "arrWrite", -1};
            tpush(myVar);
        }
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 631 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable v = {(yyvsp[-2].sval), "write", -1};
            sprintf(msg, ".> %s\n", (yyvsp[-2].sval));
            deepcpy(v.vStatement, msg);
            //initTemp(vArr, v);
            tpush(v);
            writeCnt++;
        }
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 643 "mini_l.y" /* yacc.c:1646  */
    {
            variable myVar;
            myVar = createTempStr(vArr, numList, (yyvsp[0].sval));
            tpush(myVar);
        }
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 649 "mini_l.y" /* yacc.c:1646  */
    {
            variable myVar = {(yyvsp[-3].sval), "arrVariable", -1};
            tpush(myVar);
        }
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 657 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable myVar1 = tpop();   //boolean for second while loop
            variable myVar2 = tpop();   //temp for second while loop
            variable myVar3 = {"temp_", "temp", numCnt};
            numCnt++;
            sprintf(msg, ". %s%d\n|| %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar3.vStatement, msg);
            initTemp(vArr, myVar3);
            tpush(myVar3);
        }
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 672 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable myVar1 = tpop();
            variable myVar2 = tpop();
            variable myVar3 = {"temp_", "temp", numCnt};
            numCnt++;
            sprintf(msg, ". %s%d\n&& %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar3.vStatement, msg);
            initTemp(vArr, myVar3);
            tpush(myVar3);
        }
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 688 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable myVar1 = {"temp_", "bool", numCnt};
            numCnt++;
            sprintf(msg, ". %s%d\n= %s%d, 0\n", myVar1.vName, myVar1.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar1.vStatement, msg);
            initTemp(vArr, myVar1);
            tpush(myVar1);
        }
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 705 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable myVar1 = tpop();
            variable myVar2 = tpop();
            variable myVar3 = {"temp_", "temp", numCnt};
            numCnt++;

            if(strcmp(myVar2.vType, "multiplicative") == 0 || strcmp(myVar2.vType, "temp") == 0)
            {
                sprintf(msg, ". %s%d\n== %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            }
            else if(strcmp(myVar2.vType, "arrVariable") == 0)
            {
                //printf("name: %s, type: %s, id: %d, statement: %s", myVar1.vName, myVar1.vType, myVar1.vID, myVar1.vStatement);
             
                //printf("name: %s, type: %s, id: %d, statement: %s", myVar2.vName, myVar2.vType, myVar2.vID, myVar2.vStatement);   
                variable v = tpop();
                sprintf(msg, ". %s%d\n=[] %s%d, %s, %s%d\n== %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, v.vName, v.vID, myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar1.vName, myVar1.vID);
            }
            deepcpy(myVar3.vStatement, msg);
            initTemp(vArr, myVar3);
            tpush(myVar3);

        }
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 731 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable myVar1 = tpop();
            variable myVar2 = tpop();
            variable myVar3 = {"temp_", "temp", numCnt};
            numCnt++;
            sprintf(msg, ". %s%d\n< %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar3.vStatement, msg);
            initTemp(vArr, myVar3);
            tpush(myVar3);
        }
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 743 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable v1 = tpop();
            variable v2 = tpop();
            variable v3 = {"temp_", "temp", numCnt};
            numCnt++;
            sprintf(msg, ". %s%d\n> %s%d, %s%d, %s%d\n", v3.vName, v3.vID, v3.vName, v3.vID, v2.vName, v2.vID, v1.vName, v1.vID);
            deepcpy(v3.vStatement, msg);
            initTemp(vArr, v3);
            tpush(v3);
        }
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 755 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable myVar1;
            variable myVar2;
            variable myVar3;
            myVar1 = tpop();
            myVar2 = tpop();
            myVar3 = decTemp(vArr, numList);
            sprintf(msg, ". %s%d\n<= %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar3.vStatement, msg);
            initTemp(vArr, myVar3);
            tpush(myVar3);
        }
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 770 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable myVar1 = tpop();
            variable myVar2 = tpop();
            variable myVar3 = {"temp_", "temp", numCnt};
            numCnt++;
            sprintf(msg, ". %s%d\n>= %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar3.vStatement, msg);
            initTemp(vArr, myVar3);
            tpush(myVar3);
        }
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 790 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable myVar1;
            variable myVar2;
            variable myVar3;
            myVar1 = tpop();
            myVar2 = tpop();
            myVar3 = decTemp(vArr, numList);
            sprintf(msg, ". %s%d\n+ %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar3.vStatement, msg);
            initTemp(vArr, myVar3);
            tpush(myVar3); 
        }
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 804 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable myVar1;
            variable myVar2;
            variable myVar3;
            myVar1 = tpop();
            myVar2 = tpop();
            myVar3 = decTemp(vArr, numList);
            sprintf(msg, ". %s%d\n- %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar3.vStatement, msg);
            initTemp(vArr, myVar3);
            tpush(myVar3); 
        }
#line 2286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 821 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable myVar1 = tpop();
            variable myVar2 = tpop();
            variable myVar3 = {"temp_", "multiplicative", numCnt};
            numCnt++;
            sprintf(msg, ". %s%d\n* %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar3.vStatement, msg);
            initTemp(vArr, myVar3);
            tpush(myVar3);
        }
#line 2302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 833 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable v1 = tpop();
            variable v2 = tpop();
            variable v3 = {"temp_", "multiplicative", numCnt};
            numCnt++;
            sprintf(msg, ". %s%d\n/ %s%d, %s%d, %s%d\n", v3.vName, v3.vID, v3.vName, v3.vID, v2.vName, v2.vID, v1.vName, v1.vID);
            deepcpy(v3.vStatement, msg);
            initTemp(vArr, v3);
            tpush(v3);
        }
#line 2318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 845 "mini_l.y" /* yacc.c:1646  */
    {
            char msg[128];
            variable myVar1 = tpop();
            variable myVar2 = tpop();
            variable myVar3 = {"temp_", "multiplicative", numCnt};
            numCnt++;
            sprintf(msg, ". %s%d\n%% %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar3.vStatement, msg);
            initTemp(vArr, myVar3);
            tpush(myVar3);
        }
#line 2334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 865 "mini_l.y" /* yacc.c:1646  */
    {
            // check function name
            int flag = 1;
            int i;
            for(i = 29; i < 1024; i++)
            {
                if(strcmp(vArr[i].vName, (yyvsp[-3].sval)) == 0)    
                {
                    flag = 0;
                }
            }
            if(flag)
            {
                errFlag = 1;
                char errmsg[128];
                sprintf(errmsg, "function \"%s\" is not defined.", (yyvsp[-3].sval));
                yyerror(errmsg);
            }
            
            // param section
            char msg[128];
            variable myVar1 = tpop();
            variable myVar2 = {"param", "parameter", -1};
            sprintf(msg, "param %s%d\n", myVar1.vName, myVar1.vID);
            deepcpy(myVar2.vStatement, msg);
            initTemp(vArr, myVar2);
            
            // function call section
            char msg2[128];
            variable myVar3 = {"temp_", "temp", numCnt};
            numCnt++;
            sprintf(msg2, ". %s%d\ncall %s, %s%d\n", myVar3.vName, myVar3.vID, (yyvsp[-3].sval), myVar3.vName, myVar3.vID);
            deepcpy(myVar3.vStatement, msg2);
            initTemp(vArr, myVar3);
            tpush(myVar3);
        }
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 904 "mini_l.y" /* yacc.c:1646  */
    {
            variable myVar;
            myVar = createTempNum(vArr, numList, (yyvsp[0].ival));
            tpush(myVar); 
        }
#line 2385 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2389 "y.tab.c" /* yacc.c:1646  */
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
#line 910 "mini_l.y" /* yacc.c:1906  */


// Helper Functions
void yyerror(const char *msg)
{
    errFlag = 1;
    printf("Error line %d, column %d: %s\n", currLine, currPos, msg);
}

void whilepush(variable ele)
{
    whiletop = whiletop + 1;
    whiletracker[whiletop] = ele;
}

variable whilepop()
{
    int temp = whiletop;
    whiletop = whiletop - 1;
    if(whiletop < -1)
    {
        /*printf("popping empty stack whiletracker\n");
        printf("previous -> name:%s , type:%s , id:%d\n", whiletracker[0].vName, whiletracker[0].vType, whiletracker[0].vID);*/
        char msg[128];
        sprintf(msg, "continue statement is outside a loop");
        yyerror(msg);
        variable empty;
        return empty;
    }
    return whiletracker[temp];
}

void lpush(variable ele)
{
    ltop = ltop + 1;
    ltracker[ltop] = ele;
}

variable lpop()
{
    int temp = ltop;
    ltop = ltop - 1;
    if(ltop < -1)
    {
        printf("popping empty stack ltracker\n");
        printf("previous -> name:%s , type:%s , id:%d\n", ltracker[0].vName, ltracker[0].vType, ltracker[0].vID);
        exit(0);
    }
    return ltracker[temp];
}

void tpush(variable ele)
{
    top = top + 1;
    tracker[top] = ele;
}

variable tpop()
{
    int temp = top;
    top = top - 1;
    if(top < -1)
    {
        printf("popping empty stack tracker\n");
        printf("previous -> name:%s , type:%s , id:%d\n", tracker[1].vName, tracker[1].vType, tracker[1].vID);
        exit(0);
    }
    return tracker[temp];
}

variable createTempStr(variable* arr, int* intList, char* ident)
{
    int i = 0;
    int decFlag = 0;
    while(arr[i].vName != "")
    {
        if(strcmp(arr[i].vName, ident) == 0)
        {
            // if declared then its fine to use
            decFlag = 1;
        }
        i++;
    }
    if(!decFlag)    // if undeclared print error
    {
        errFlag = 1;
        char msg[128];
        sprintf(msg, "used variable \"%s\" was not previously declared.", ident);
        yyerror(msg);
    }
    variable myVar = {"temp_", "temp", intList[numCnt]};
    char msg[128];
    sprintf(msg, ". %s%d\n= %s%d, %s\n", myVar.vName, myVar.vID, myVar.vName, myVar.vID, ident);
    deepcpy(myVar.vStatement, msg);
    arr[i] = myVar;
    numCnt++;
    return myVar;
}

void checkDec(variable* arr, char* ident)
{
    int i = 0;
    int decFlag = 0;
    while(arr[i].vName != "")
    {
        if(strcmp(arr[i].vName, ident) == 0)
        {
            decFlag = 1;
        }
        i++;
    }
    if(!decFlag)
    {
        errFlag = 1;
        char msg[128];
        sprintf(msg, "used variable \"%s\" was not previously declared.", ident);
        yyerror(msg);
    }
}

variable createTempNum(variable* arr, int* intList, int num)
{
    int i = 0;
    while(arr[i].vName != "")
    {
        i++;
    }
    variable myVar = {"temp_", "temp", intList[numCnt]};
    char msg[128];
    sprintf(msg, ". %s%d\n= %s%d, %d\n", myVar.vName, myVar.vID, myVar.vName, myVar.vID, num);
    deepcpy(myVar.vStatement, msg);
    arr[i] = myVar;
    numCnt++; 
    return arr[i];
}

variable decTemp(variable* arr, int* intList)
{
    int i = 0;
    while(arr[i].vName != "")
    {
        i++;
    }
    variable myVar = {"temp_", "temp", intList[numCnt]};
    numCnt++;
    return myVar;
}

void initTemp(variable* arr, variable ele)
{
    int i = 0;
    int undecFlag = 0;
    while(arr[i].vName != "")
    {
        i++;
    }
    arr[i] = ele;
}

int insArr(variable* arr, variable ele)
{
    if(strcmp(ele.vName, "main") == 0)
    {
        isMain = 1;
    }

    int i;

    for(i = 0; i < 29; ++i) // check if ele is a reserved word
    {
        if(strcmp(arr[i].vName, ele.vName) == 0)
        {
            errFlag = 1;
            char msg[128];
            sprintf(msg, "symbol \"%s\" is a reserved keyword.", ele.vName);
            yyerror(msg);
            return -1;
        }
    }

    for(i = 29; i < 1024; ++i)
    {
        if(arr[i].vName != "" && strcmp(arr[i].vName, ele.vName) == 0)  // check if empty to prevent traverse whole array
        {
            if(strcmp(arr[i].vName, "endfunc") == 0)
                continue;
            
            errFlag = 1;
            char msg[128];
            sprintf(msg, "symbol \"%s\" is multiply-defined.", ele.vName);
            yyerror(msg);
            return -1;
        }
        else if(arr[i].vName != "")  // not empty then increment
        {
            continue;
        }
        else  // insert element if empty and no duplicate
        {
            arr[i] = ele;
            return 1;
        }
    }
    // should not reach here
    return -1;
}

void initArr(variable* arr, int size)
{
    int i;
    variable var0 = {"function", "reserved", -1};       arr[0] = var0;
    variable var1 = {"beginparams", "reserved", -1};    arr[1] = var1;
    variable var2 = {"endparams", "reserved", -1};      arr[2] = var2;
    variable var3 = {"beginlocals", "reserved", -1};    arr[3] = var3;
    variable var4 = {"endlocals", "reserved", -1};      arr[4] = var4;
    variable var5 = {"beginbody", "reserved", -1};      arr[5] = var5;
    variable var6 = {"endbody", "reserved", -1};        arr[6] = var6;
    variable var7 = {"integer", "reserved", -1};        arr[7] = var7;
    variable var8 = {"array", "reserved", -1};          arr[8] = var8;
    variable var9 = {"of", "reserved", -1};             arr[9] = var9;
    variable var10 = {"if", "reserved", -1};            arr[10] = var10;
    variable var11 = {"then", "reserved", -1};          arr[11] = var11; 
    variable var12 = {"endif", "reserved", -1};         arr[12] = var12;
    variable var13 = {"else", "reserved", -1};          arr[13] = var13;
    variable var14 = {"while", "reserved", -1};         arr[14] = var14;
    variable var15 = {"do", "reserved", -1};            arr[15] = var15;
    variable var16 = {"foreach", "reserved", -1};       arr[16] = var16;
    variable var17 = {"in", "reserved", -1};            arr[17] = var17;
    variable var18 = {"beginloop", "reserved", -1};     arr[18] = var18;
    variable var19 = {"endloop", "reserved", -1};       arr[19] = var19;
    variable var20 = {"continue", "reserved", -1};      arr[20] = var20;
    variable var21 = {"read", "reserved", -1};          arr[21] = var21;
    variable var22 = {"write", "reserved", -1};         arr[22] = var22;
    variable var23 = {"and", "reserved", -1};           arr[23] = var23;
    variable var24 = {"or", "reserved", -1};            arr[24] = var24;
    variable var25 = {"not", "reserved", -1};           arr[25] = var25;
    variable var26 = {"true", "reserved", -1};          arr[26] = var26;
    variable var27 = {"false", "reserved", -1};         arr[27] = var27;
    variable var28 = {"return", "reserved", -1};        arr[28] = var28;

    for(i = 29; i < size; i++)
    {
        arr[i].vName = "";
        arr[i].vType = "";
        arr[i].vID = -1;
    }
    return;
}

void printArr(variable* arr)
{
    int i;
    for(i = 29; i < 1024; i++)
    {
        if(arr[i].vName != "")
        { 
            printf("%s", arr[i].vStatement);
        }
        else
        {
            return;
        }
    }
    return;
}

void initList(int* intList)
{
    int i;
    for(i = 0; i < 1024; i++)
    {
        intList[i] = i;
    }
}

void printList(int* intList)
{
    int i;
    for(i = 0; i < 1024; i++)
    {
        printf("%d\n", intList[i]);
    }
}

void deepcpy(char* dest, char* src)
{
    int i;
    for(i = 0; i < 128; i++)
    {
        dest[i] = src[i];
    }
    return;
}

void deepFind(char* dest, char* src)
{
    int i;
    int j;
    int bIndex = 0;
    int eIndex = 0;
    for(i = 0; i < 128; i++)
    {
        if(src[i] == ',')
        {
            bIndex = i + 2;
        }
        if(src[i] == '\n')
        {
            eIndex = i;
        }
    }
    for(i = bIndex, j = 0; i < eIndex; i++, j++)
    {
        dest[j] = src[i];
    }
    dest[j] = '\0';
    return;
}
// End Helper Functions





// Main Function
int main (int argc, char **argv)
{
    if(argc > 1)
    {
        yyin = fopen(argv[1], "r");
        if(yyin == NULL)
        {
            printf("syntax: %s filename\n", argv[0]);
        }
    }
    whiletop = ltop = top = -1;
    readCnt = writeCnt = numAnd = whileCnt = errFlag = isMain = numCnt = paramCnt = labCnt = 0;
    initList(numList);
    initArr(vArr, 1024);
    yyparse();
    if(!errFlag)
        printArr(vArr);
    
    return 0;
}
