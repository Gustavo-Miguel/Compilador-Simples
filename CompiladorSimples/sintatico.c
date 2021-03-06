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
#line 12 "sintatico.y" /* yacc.c:339  */

	#include <stdio.h>	
	#include <string.h>
	#include <stdlib.h>
	#include <stdarg.h>
    
  #include "utils.c"
	#include "lexico.c"

  int yylex();
  void yyerror (char *s){
    ERRO("ERRO SINTATICO");
  }

#line 81 "sintatico.c" /* yacc.c:339  */

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
   by #include "sintatico.h".  */
#ifndef YY_YY_SINTATICO_H_INCLUDED
# define YY_YY_SINTATICO_H_INCLUDED
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
    T_PROGRAMA = 258,
    T_INICIO = 259,
    T_FIM = 260,
    T_IDENTIF = 261,
    T_LEIA = 262,
    T_ESCREVA = 263,
    T_ENQTO = 264,
    T_FACA = 265,
    T_FIMENQTO = 266,
    T_SE = 267,
    T_ENTAO = 268,
    T_SENAO = 269,
    T_FIMSE = 270,
    T_ATRIB = 271,
    T_VEZES = 272,
    T_DIV = 273,
    T_MAIS = 274,
    T_MENOS = 275,
    T_MAIOR = 276,
    T_MENOR = 277,
    T_IGUAL = 278,
    T_E = 279,
    T_OU = 280,
    T_V = 281,
    T_F = 282,
    T_NUMERO = 283,
    T_NAO = 284,
    T_ABRE = 285,
    T_FECHA = 286,
    T_LOGICO = 287,
    T_INTEIRO = 288,
    T_FUNC = 289,
    T_FIMFUNC = 290,
    T_PROC = 291,
    T_FIMPROC = 292,
    T_REF = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SINTATICO_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 171 "sintatico.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   182

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

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
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    79,    79,    83,    86,    90,    79,    98,   105,   107,
     107,   115,   116,   121,   125,   134,   133,   141,   141,   151,
     153,   153,   173,   174,   175,   176,   177,   181,   182,   186,
     195,   194,   204,   203,   220,   228,   219,   241,   244,   240,
     254,   253,   270,   269,   286,   285,   302,   301,   318,   317,
     334,   333,   352,   351,   368,   367,   384,   383,   398,   402,
     418,   422,   426,   430,   434,   435,   438,   440,   444,   446,
     446,   454,   455,   461,   466,   460,   476,   481,   475,   489,
     492,   491,   502,   502,   513,   517,   525,   524,   536,   535,
     545,   547,   551,   552,   557,   557
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_PROGRAMA", "T_INICIO", "T_FIM",
  "T_IDENTIF", "T_LEIA", "T_ESCREVA", "T_ENQTO", "T_FACA", "T_FIMENQTO",
  "T_SE", "T_ENTAO", "T_SENAO", "T_FIMSE", "T_ATRIB", "T_VEZES", "T_DIV",
  "T_MAIS", "T_MENOS", "T_MAIOR", "T_MENOR", "T_IGUAL", "T_E", "T_OU",
  "T_V", "T_F", "T_NUMERO", "T_NAO", "T_ABRE", "T_FECHA", "T_LOGICO",
  "T_INTEIRO", "T_FUNC", "T_FIMFUNC", "T_PROC", "T_FIMPROC", "T_REF",
  "$accept", "programa", "$@1", "$@2", "$@3", "$@4", "cabecalho",
  "variaveis", "$@5", "declaracao_variaveis", "tipo", "lista_variaveis",
  "$@6", "$@7", "lista_comandos", "$@8", "comando", "entrada_saida",
  "leitura", "escrita", "$@9", "repeticao", "$@10", "selecao", "$@11",
  "$@12", "atribuicao", "$@13", "$@14", "expressao", "$@15", "$@16",
  "$@17", "$@18", "$@19", "$@20", "$@21", "$@22", "$@23", "termo",
  "subprogramas", "lista_subprogramas", "$@24", "subprograma", "funcao",
  "$@25", "$@26", "procedimento", "$@27", "$@28", "lista_parametros",
  "$@29", "parametro", "$@30", "forma_passagem", "chamada_procedimento",
  "$@31", "chamada_funcao", "$@32", "argumentos", "lista_argumentos",
  "argumento", "$@33", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF -91

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-91)))

#define YYTABLE_NINF -92

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -91,     3,    27,   -91,    30,   -91,   -91,   -12,   -91,    43,
      50,   -91,   -91,    43,   -91,    88,   -91,   -30,   -91,   116,
     119,   -91,   -91,   -91,    90,   -91,   -91,   116,   120,   -91,
     122,    43,   123,   -91,   -91,   125,    81,   126,   -91,   -91,
      98,   127,   -91,   -91,   -91,    99,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   104,   115,   105,   -91,    -4,    -4,
      -4,   -91,   106,   -91,   -91,   107,   109,   -91,   -91,   -91,
      -4,    -4,    61,   -91,   -91,    19,    -8,   -91,   110,    -4,
     111,   112,   -91,    -4,   -91,   -91,    46,   128,   129,   118,
     124,   130,   132,   117,   131,   121,   137,   135,   133,   146,
     -91,    61,   -91,   -91,    61,   107,   -91,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,   140,   -91,   146,   150,
     -91,   134,   136,   139,    92,    55,    15,   101,    95,    28,
      80,    61,   -91,   143,   154,   138,   -91,    43,   -91,   144,
     141,   142,   155,   145,   147,   -91,   -91,   -91,   -91
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     7,     8,     4,     0,
      69,    14,    13,    10,    17,     0,    67,     0,    17,    12,
       0,     5,    73,    76,    69,    71,    72,    11,     0,    18,
      20,     0,     0,    70,    16,     0,     0,     0,    77,     6,
      37,     0,    30,    32,    34,    19,    22,    27,    28,    23,
      24,    25,    26,    74,     0,     0,     0,    29,     0,     0,
       0,    21,     0,    79,    38,    94,    59,    61,    62,    60,
       0,     0,    31,    58,    65,    40,    40,    79,    80,     0,
       0,    94,    93,     0,    88,    63,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    20,    80,     9,
      82,    39,    87,    92,    95,    94,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    35,     9,     0,
      81,    85,     0,    41,    43,    45,    47,    49,    51,    53,
      55,    57,    33,     0,     0,    20,    84,     0,    89,    20,
      20,     0,     0,     0,     0,    78,    83,    36,    75
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -90,   -91,   -91,
     -13,   148,   -91,   -91,   -44,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -52,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,    93,
     -91,   149,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
      85,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,    60,
     -91,    87,   -91
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,    10,    30,     5,     8,     9,    13,
      14,    19,    28,    20,    35,    36,    45,    46,    47,    48,
      58,    49,    59,    50,    60,   133,    51,    55,    79,    72,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    73,
      15,    16,    17,    24,    25,    31,    62,    26,    32,    54,
      78,   100,   120,   121,   137,    52,    56,    74,   105,    80,
      81,    82,    83
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    61,    66,     3,    22,    97,    23,    75,    76,   119,
     -42,   -44,   -46,   -50,   -48,   -52,   -54,   -56,    37,    86,
      -9,    -9,    67,    68,    69,    70,    71,   101,   134,    96,
       4,   104,   -40,   -42,   -44,   -46,     6,   -42,   -44,   -46,
     -50,   -48,   -52,   -54,   -56,   -40,   -42,   -44,   -46,   -50,
     -48,   -52,   116,   117,   -66,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   -42,   -44,   -46,   -50,   -48,   -52,
     -54,   -56,   -40,   -42,   -44,    11,    12,   106,   -40,   -42,
     -44,   -46,   -50,   -48,   -52,   -54,   -56,    40,    41,    42,
      43,   141,    21,    44,   -68,   143,   144,   -40,   -42,   -44,
     -46,   -50,   -48,   -52,   -54,   -20,   -20,   -20,   -20,   -40,
     -42,   -20,   -40,   -42,   -44,   -46,   -50,   -48,   -40,   -42,
     -44,   -46,   -15,   -48,   142,    29,    34,   -19,   -86,    38,
      39,    64,    53,    57,    63,    65,    77,   109,   -90,    84,
     113,    99,   102,   -91,   110,   107,   115,   108,   -19,   -19,
      -8,   132,   111,   112,   135,   114,   -40,   139,   140,   -19,
     147,   146,    98,    85,   118,   122,    27,   138,   103,     0,
       0,     0,   136,    33,     0,   -19,   -19,     0,     0,   145,
       0,     0,   148
};

static const yytype_int16 yycheck[] =
{
      13,    45,     6,     0,    34,    13,    36,    59,    60,    99,
      18,    19,    20,    21,    22,    23,    24,    25,    31,    71,
      32,    33,    26,    27,    28,    29,    30,    79,   118,    10,
       3,    83,    17,    18,    19,    20,     6,    18,    19,    20,
      21,    22,    23,    24,    25,    17,    18,    19,    20,    21,
      22,    23,    96,    97,     4,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    18,    19,    20,    21,    22,    23,
      24,    25,    17,    18,    19,    32,    33,    31,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     6,     7,     8,
       9,   135,     4,    12,     4,   139,   140,    17,    18,    19,
      20,    21,    22,    23,    24,     6,     7,     8,     9,    17,
      18,    12,    17,    18,    19,    20,    21,    22,    17,    18,
      19,    20,     6,    22,   137,     6,     6,     5,    30,     6,
       5,    16,     6,     6,    30,    30,    30,    19,    31,    30,
      23,    31,    31,    31,    20,    17,    25,    18,    11,    14,
       4,    11,    22,    21,     4,    24,    17,    14,     4,    15,
      15,     6,    77,    70,    31,   105,    18,    31,    81,    -1,
      -1,    -1,    38,    24,    -1,    37,    35,    -1,    -1,    37,
      -1,    -1,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    41,     0,     3,    45,     6,    42,    46,    47,
      43,    32,    33,    48,    49,    79,    80,    81,    49,    50,
      52,     4,    34,    36,    82,    83,    86,    50,    51,     6,
      44,    84,    87,    80,     6,    53,    54,    49,     6,     5,
       6,     7,     8,     9,    12,    55,    56,    57,    58,    60,
      62,    65,    94,     6,    88,    66,    95,     6,    59,    61,
      63,    53,    85,    30,    16,    30,     6,    26,    27,    28,
      29,    30,    68,    78,    96,    68,    68,    30,    89,    67,
      98,    99,   100,   101,    30,    78,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    10,    13,    89,    31,
      90,    68,    31,   100,    68,    97,    31,    17,    18,    19,
      20,    22,    21,    23,    24,    25,    53,    53,    31,    46,
      91,    92,    98,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    11,    64,    46,     4,    38,    93,    31,    14,
       4,    53,    49,    53,    53,    37,     6,    15,    35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    41,    42,    43,    44,    40,    45,    46,    47,
      46,    48,    48,    49,    49,    51,    50,    52,    50,    53,
      54,    53,    55,    55,    55,    55,    55,    56,    56,    57,
      59,    58,    61,    60,    63,    64,    62,    66,    67,    65,
      69,    68,    70,    68,    71,    68,    72,    68,    73,    68,
      74,    68,    75,    68,    76,    68,    77,    68,    68,    78,
      78,    78,    78,    78,    78,    78,    79,    79,    80,    81,
      80,    82,    82,    84,    85,    83,    87,    88,    86,    89,
      90,    89,    92,    91,    93,    93,    95,    94,    97,    96,
      98,    98,    99,    99,   101,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,    10,     2,     0,     0,
       2,     3,     2,     1,     1,     0,     3,     0,     2,     0,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     3,     0,     6,     0,     0,     9,     0,     0,     5,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     1,     1,
       1,     1,     1,     2,     3,     1,     0,     1,     0,     0,
       3,     1,     1,     0,     0,    12,     0,     0,    11,     0,
       0,     3,     0,     4,     1,     0,     0,     5,     0,     5,
       0,     1,     2,     1,     0,     2
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
#line 79 "sintatico.y" /* yacc.c:1646  */
    { 
        raiz = criaNo(PRG, ""); 
        no_aux = raiz; 					// no auxiliar para nao perder o contexto do programa
      }
#line 1378 "sintatico.c" /* yacc.c:1646  */
    break;

  case 3:
#line 83 "sintatico.y" /* yacc.c:1646  */
    {
        no_aux_declaracao = raiz; 		// referencia o no de declaracao de variaveis
      }
#line 1386 "sintatico.c" /* yacc.c:1646  */
    break;

  case 4:
#line 86 "sintatico.y" /* yacc.c:1646  */
    { 
        no_aux_rotinas = raiz;  		// referencia o no de lista de rotinas
      }
#line 1394 "sintatico.c" /* yacc.c:1646  */
    break;

  case 5:
#line 90 "sintatico.y" /* yacc.c:1646  */
    { 
        no_aux_comandos = raiz; 		// referencia o no de lista de comandos
      }
#line 1402 "sintatico.c" /* yacc.c:1646  */
    break;

  case 7:
#line 99 "sintatico.y" /* yacc.c:1646  */
    { 
      adicionaFilho(raiz, criaNo(IDN, atomo)); // cria identificador do programa
    }
#line 1410 "sintatico.c" /* yacc.c:1646  */
    break;

  case 9:
#line 107 "sintatico.y" /* yacc.c:1646  */
    {
        no_aux = criaNo(DVR, ""); 					// cria no de declaracao de variaveis
        adicionaFilho(no_aux_declaracao, no_aux); 	// adiciona como filho (pode ser filho do programa ou de uma rotina)
      }
#line 1419 "sintatico.c" /* yacc.c:1646  */
    break;

  case 13:
#line 122 "sintatico.y" /* yacc.c:1646  */
    { 
      adicionaFilho(no_aux, criaNo(TIP, "inteiro")); 
    }
#line 1427 "sintatico.c" /* yacc.c:1646  */
    break;

  case 14:
#line 126 "sintatico.y" /* yacc.c:1646  */
    { 
      adicionaFilho(no_aux, criaNo(TIP, "logico")); 
    }
#line 1435 "sintatico.c" /* yacc.c:1646  */
    break;

  case 15:
#line 134 "sintatico.y" /* yacc.c:1646  */
    { 
      adicionaFilho(no_aux, criaNo(LVR, "")); 		// cria no para lista de variaveis
      no_aux = no_aux->filho->irmao; 				// contexto recebe no nivel abaixo para criar identificador da variavel
    }
#line 1444 "sintatico.c" /* yacc.c:1646  */
    break;

  case 16:
#line 138 "sintatico.y" /* yacc.c:1646  */
    { 
      adicionaFilho(no_aux, criaNo(IDN, atomo)); 	// variavel declarada e seu valor
    }
#line 1452 "sintatico.c" /* yacc.c:1646  */
    break;

  case 17:
#line 141 "sintatico.y" /* yacc.c:1646  */
    { // se nao houver mais variaveis
      adicionaFilho(no_aux, criaNo(LVR, "")); 
      no_aux = no_aux->filho->irmao; 
    }
#line 1461 "sintatico.c" /* yacc.c:1646  */
    break;

  case 18:
#line 145 "sintatico.y" /* yacc.c:1646  */
    { 
      adicionaFilho(no_aux, criaNo(IDN, atomo)); 
    }
#line 1469 "sintatico.c" /* yacc.c:1646  */
    break;

  case 20:
#line 153 "sintatico.y" /* yacc.c:1646  */
    { // criacao de uma estrutura de vetor para referenciar os nos passados (simula uma pilha)
        conta_exp = 0;										// contador de expressoes
        if(TOPO_selecao > -1){ 								// se houver elementos na vetor
          no_aux = criaNo(LCM, ""); 						// cria no de lista de comandos          
          adicionaFilho(pilha_selecao[TOPO_selecao], no_aux); 	// adiciona no topo da vetor de nos de selecao
          TOPO_selecao++; 									// incrementa topo da pilha         
          pilha_selecao[TOPO_selecao] = no_aux;         
        } else if(TOPO_repeticao > -1){ 						// estrutura para comando de repeticao          
          no_aux = criaNo(LCM, "");          
          adicionaFilho(pilha_selecao[TOPO_repeticao], no_aux);          
          pilha_selecao[TOPO_repeticao] = no_aux;
        } else { 											// senao acrescenta no lista de comando 
          no_aux = criaNo(LCM, "");          
          adicionaFilho(no_aux_comandos, no_aux);           
          no_aux_comandos = no_aux;
        } 
      }
#line 1491 "sintatico.c" /* yacc.c:1646  */
    break;

  case 29:
#line 187 "sintatico.y" /* yacc.c:1646  */
    {
        adicionaFilho(no_aux, criaNo(LEI, ""));
        adicionaFilho(no_aux->filho, criaNo(IDN, atomo));
      }
#line 1500 "sintatico.c" /* yacc.c:1646  */
    break;

  case 30:
#line 195 "sintatico.y" /* yacc.c:1646  */
    { 
      adicionaFilho(no_aux, criaNo(ESC, "")); 
      no_aux = no_aux->filho;
    }
#line 1509 "sintatico.c" /* yacc.c:1646  */
    break;

  case 32:
#line 204 "sintatico.y" /* yacc.c:1646  */
    { 
      	aux_var = 1;
        adicionaFilho(no_aux, criaNo(REP, "")); 
        no_aux = no_aux->filho; 
        TOPO_repeticao++;								// adiciona ao vetor um novo no
        pilha_selecao[TOPO_repeticao] = no_aux;
      }
#line 1521 "sintatico.c" /* yacc.c:1646  */
    break;

  case 33:
#line 212 "sintatico.y" /* yacc.c:1646  */
    {
        TOPO_repeticao--;								// desempilha (vetor) uma referencia de no de repeticao
      }
#line 1529 "sintatico.c" /* yacc.c:1646  */
    break;

  case 34:
#line 220 "sintatico.y" /* yacc.c:1646  */
    { 
      	aux_var = 1;     
        adicionaFilho(no_aux, criaNo(SEL, ""));         
        no_aux = no_aux->filho;         
        TOPO_selecao++;               
        pilha_selecao[TOPO_selecao] = no_aux; 
      }
#line 1541 "sintatico.c" /* yacc.c:1646  */
    break;

  case 35:
#line 228 "sintatico.y" /* yacc.c:1646  */
    {      	
        TOPO_selecao--;
      }
#line 1549 "sintatico.c" /* yacc.c:1646  */
    break;

  case 36:
#line 233 "sintatico.y" /* yacc.c:1646  */
    {      	      	
        TOPO_selecao = TOPO_selecao - 2;
      }
#line 1557 "sintatico.c" /* yacc.c:1646  */
    break;

  case 37:
#line 241 "sintatico.y" /* yacc.c:1646  */
    {
        no_aux_atribuicao = criaNo(IDN, atomo);		// cria no de destino (identificador do destino)
      }
#line 1565 "sintatico.c" /* yacc.c:1646  */
    break;

  case 38:
#line 244 "sintatico.y" /* yacc.c:1646  */
    { 
        adicionaFilho(no_aux, criaNo(ATR, "")); 	
        no_aux = no_aux->filho; 			
        no_aux->filho = no_aux_atribuicao;					
      }
#line 1575 "sintatico.c" /* yacc.c:1646  */
    break;

  case 40:
#line 254 "sintatico.y" /* yacc.c:1646  */
    { 
      conta_exp++;											// incrementa quantidade de expressoes
      if (conta_exp > 1 || no_aux->tipo == ATR){ 			// se ja houver outra expressao adiciona no irmao
        no_aux_expressao = criaNo(MUL, ""); 				//	cria no multiplicacao e adiciona no auxiliar de expressao
        no_aux_expressao->filho = no_aux->filho->irmao; 
        no_aux->filho->irmao = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } else { 										
        no_aux_expressao = criaNo(MUL, ""); 
        no_aux_expressao->filho = no_aux->filho; 
        no_aux->filho = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } 
    }
#line 1594 "sintatico.c" /* yacc.c:1646  */
    break;

  case 42:
#line 270 "sintatico.y" /* yacc.c:1646  */
    { 
      conta_exp++;											// incrementa quantidade de expressoes
      if (conta_exp > 1 || no_aux->tipo == ATR){ 			// se ja houver outra expressao adiciona no irmao 
        no_aux_expressao = criaNo(DIV, ""); 				//	cria no divisao e adiciona no auxiliar de expressao
        no_aux_expressao->filho = no_aux->filho->irmao; 
        no_aux->filho->irmao = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } else { 
        no_aux_expressao = criaNo(DIV, ""); 
        no_aux_expressao->filho = no_aux->filho; 
        no_aux->filho = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } 
    }
#line 1613 "sintatico.c" /* yacc.c:1646  */
    break;

  case 44:
#line 286 "sintatico.y" /* yacc.c:1646  */
    { 
      conta_exp++;											// incrementa quantidade de expressoes
      if (conta_exp > 1 || no_aux->tipo == ATR){ 			// se ja houver outra expressao adiciona no irmao 
        no_aux_expressao = criaNo(SOM, ""); 				//	cria no soma e adiciona no auxiliar de expressao
        no_aux_expressao->filho = no_aux->filho->irmao; 
        no_aux->filho->irmao = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } else { 
        no_aux_expressao = criaNo(SOM, ""); 
        no_aux_expressao->filho = no_aux->filho; 
        no_aux->filho = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } 
    }
#line 1632 "sintatico.c" /* yacc.c:1646  */
    break;

  case 46:
#line 302 "sintatico.y" /* yacc.c:1646  */
    { 
      conta_exp++;											// incrementa quantidade de expressoes
      if (conta_exp > 1 || no_aux->tipo == ATR){ 			// se ja houver outra expressao adiciona no irmao
        no_aux_expressao = criaNo(SUB, ""); 				//	cria no soma e adiciona no auxiliar de expressao
        no_aux_expressao->filho = no_aux->filho->irmao; 
        no_aux->filho->irmao = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } else { 
        no_aux_expressao = criaNo(SUB, ""); 
        no_aux_expressao->filho = no_aux->filho; 
        no_aux->filho = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } 
    }
#line 1651 "sintatico.c" /* yacc.c:1646  */
    break;

  case 48:
#line 318 "sintatico.y" /* yacc.c:1646  */
    { 
      conta_exp++;											// incrementa quantidade de expressoes
      if (conta_exp > 1 || no_aux->tipo == ATR){ 			// se ja houver outra expressao adiciona no irmao
        no_aux_expressao = criaNo(MEN, ""); 				//	cria no menor e adiciona no auxiliar de expressao
        no_aux_expressao->filho = no_aux->filho->irmao; 
        no_aux->filho->irmao = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } else { 
        no_aux_expressao = criaNo(MEN, ""); 
        no_aux_expressao->filho = no_aux->filho; 
        no_aux->filho = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } 
    }
#line 1670 "sintatico.c" /* yacc.c:1646  */
    break;

  case 50:
#line 334 "sintatico.y" /* yacc.c:1646  */
    { 
      conta_exp++;											// incrementa quantidade de expressoes
      if (conta_exp > 1 || no_aux->tipo == ATR){  			// se ja houver outra expressao adiciona no irmao 
      	aux_var = 1;    	   								//	cria no maior e adiciona no auxiliar de expressao
        no_aux_expressao = criaNo(MAI, ""); 
        no_aux_expressao->filho = no_aux->filho->irmao; 
        no_aux->filho->irmao = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } else { 
      	aux_var = 1;
        no_aux_expressao = criaNo(MAI, ""); 
        no_aux_expressao->filho = no_aux->filho; 
        no_aux->filho = no_aux_expressao;
        no_aux = no_aux_expressao; 
      } 
    }
#line 1691 "sintatico.c" /* yacc.c:1646  */
    break;

  case 52:
#line 352 "sintatico.y" /* yacc.c:1646  */
    { 
      conta_exp++;											// incrementa quantidade de expressoes
      if (conta_exp > 1 || no_aux->tipo == ATR){ 			// se ja houver outra expressao adiciona no irmao
        no_aux_expressao = criaNo(IGU, ""); 				//	cria no igual e adiciona no auxiliar de expressao
        no_aux_expressao->filho = no_aux->filho->irmao; 
        no_aux->filho->irmao = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } else { 
        no_aux_expressao = criaNo(IGU, "");
        no_aux_expressao->filho = no_aux->filho;
        no_aux->filho = no_aux_expressao;
        no_aux = no_aux_expressao;
      } 
    }
#line 1710 "sintatico.c" /* yacc.c:1646  */
    break;

  case 54:
#line 368 "sintatico.y" /* yacc.c:1646  */
    { 
      conta_exp++;											// incrementa quantidade de expressoes
      if (conta_exp > 1 || no_aux->tipo == ATR){ 			// se ja houver outra expressao adiciona no irmao
        no_aux_expressao = criaNo(CON, ""); 				//	cria no conjuncao e adiciona no auxiliar de expressao
        no_aux_expressao->filho = no_aux->filho->irmao; 
        no_aux->filho->irmao = no_aux_expressao;
        no_aux = no_aux_expressao; 
      } else { 
        no_aux_expressao = criaNo(CON, ""); 
        no_aux_expressao->filho = no_aux->filho; 
        no_aux->filho = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } 
    }
#line 1729 "sintatico.c" /* yacc.c:1646  */
    break;

  case 56:
#line 384 "sintatico.y" /* yacc.c:1646  */
    { 
      conta_exp++;											// incrementa quantidade de expressoes
      if (conta_exp > 1 || no_aux->tipo == ATR){ 			// se ja houver outra expressao adiciona no irmao
        no_aux_expressao = criaNo(DIS, ""); 				//	cria no disjuncao e adiciona no auxiliar de expressao
        no_aux_expressao->filho = no_aux->filho->irmao; 
        no_aux->filho->irmao = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } else { 
        no_aux_expressao = criaNo(DIS, ""); 
        no_aux_expressao->filho = no_aux->filho; 
        no_aux->filho = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } 
    }
#line 1748 "sintatico.c" /* yacc.c:1646  */
    break;

  case 59:
#line 403 "sintatico.y" /* yacc.c:1646  */
    {	
      	if(aux_var == 1){									// verifica se eh no de valor ou identificador 
      		if (no_aux->tipo == LAR){
          		adicionaFilho(no_aux, criaNo(VAR, &arg));	// se estiver em lista de argumentos cria com valor de argumento
       		} else {
          		adicionaFilho(no_aux, criaNo(VAR, atomo));
        	}
      	} else {
	        if (no_aux->tipo == LAR){
	          adicionaFilho(no_aux, criaNo(IDN, &arg));
	        } else {
	          adicionaFilho(no_aux, criaNo(IDN, atomo));
	        }
	    }
      }
#line 1768 "sintatico.c" /* yacc.c:1646  */
    break;

  case 60:
#line 419 "sintatico.y" /* yacc.c:1646  */
    { 
        adicionaFilho(no_aux, criaNo(NUM, atomo)); 
      }
#line 1776 "sintatico.c" /* yacc.c:1646  */
    break;

  case 61:
#line 423 "sintatico.y" /* yacc.c:1646  */
    { 
        adicionaFilho(no_aux, criaNo(VER, "")); 
      }
#line 1784 "sintatico.c" /* yacc.c:1646  */
    break;

  case 62:
#line 427 "sintatico.y" /* yacc.c:1646  */
    { 
        adicionaFilho(no_aux, criaNo(FAL, "")); 
      }
#line 1792 "sintatico.c" /* yacc.c:1646  */
    break;

  case 63:
#line 431 "sintatico.y" /* yacc.c:1646  */
    { 
        adicionaFilho(no_aux, criaNo(NAO, "")); 
      }
#line 1800 "sintatico.c" /* yacc.c:1646  */
    break;

  case 69:
#line 446 "sintatico.y" /* yacc.c:1646  */
    {
    no_aux = criaNo(LRT, ""); 
    adicionaFilho(no_aux_rotinas, no_aux); 
    no_aux_rotinas = no_aux;
  }
#line 1810 "sintatico.c" /* yacc.c:1646  */
    break;

  case 73:
#line 461 "sintatico.y" /* yacc.c:1646  */
    {
    adicionaFilho(no_aux, criaNo(FUN, ""));
    no_aux = no_aux->filho;
    no_aux_declaracao = no_aux;	// declaracao de variaveis dentro da funcao
  }
#line 1820 "sintatico.c" /* yacc.c:1646  */
    break;

  case 74:
#line 466 "sintatico.y" /* yacc.c:1646  */
    {
    adicionaFilho(no_aux, criaNo(IDN, atomo));
    no_aux_parametros = no_aux;	// lista de parametros dentro da funcao
    no_aux_comandos = no_aux;	// lista de comandos dentro da funcao
  }
#line 1830 "sintatico.c" /* yacc.c:1646  */
    break;

  case 76:
#line 476 "sintatico.y" /* yacc.c:1646  */
    { 
    adicionaFilho(no_aux, criaNo(PRO, ""));
    no_aux = no_aux->filho;
    no_aux_declaracao = no_aux;	// declaracao de variaveis dentro da procedimento
  }
#line 1840 "sintatico.c" /* yacc.c:1646  */
    break;

  case 77:
#line 481 "sintatico.y" /* yacc.c:1646  */
    {
    adicionaFilho(no_aux, criaNo(IDN, atomo));
    no_aux_parametros = no_aux;	// lista de parametros dentro de procedimento
    no_aux_comandos = no_aux;	// lista de comandos dentro de procedimento
  }
#line 1850 "sintatico.c" /* yacc.c:1646  */
    break;

  case 80:
#line 492 "sintatico.y" /* yacc.c:1646  */
    {
    no_aux = criaNo(LPA, ""); 
    adicionaFilho(no_aux_parametros, no_aux); 
    no_aux_parametros = no_aux;
  }
#line 1860 "sintatico.c" /* yacc.c:1646  */
    break;

  case 82:
#line 502 "sintatico.y" /* yacc.c:1646  */
    {
    adicionaFilho(no_aux, criaNo(PAR, ""));
    no_aux = no_aux->filho;
  }
#line 1869 "sintatico.c" /* yacc.c:1646  */
    break;

  case 83:
#line 506 "sintatico.y" /* yacc.c:1646  */
    {
    adicionaFilho(no_aux, criaNo(IDN, atomo));
  }
#line 1877 "sintatico.c" /* yacc.c:1646  */
    break;

  case 84:
#line 514 "sintatico.y" /* yacc.c:1646  */
    { 
    adicionaFilho(no_aux, criaNo(REF, "")); 
  }
#line 1885 "sintatico.c" /* yacc.c:1646  */
    break;

  case 85:
#line 517 "sintatico.y" /* yacc.c:1646  */
    { 
    adicionaFilho(no_aux, criaNo(VAL, ""));
  }
#line 1893 "sintatico.c" /* yacc.c:1646  */
    break;

  case 86:
#line 525 "sintatico.y" /* yacc.c:1646  */
    {
    adicionaFilho(no_aux, criaNo(CHP, ""));
    no_aux = no_aux->filho;
    adicionaFilho(no_aux, criaNo(IDN, atomo));
    no_aux_argumentos = no_aux;		// lista de argumentos na chamada procedimento
  }
#line 1904 "sintatico.c" /* yacc.c:1646  */
    break;

  case 88:
#line 536 "sintatico.y" /* yacc.c:1646  */
    {
    adicionaFilho(no_aux, criaNo(CHF, ""));
    no_aux = no_aux->filho;
    adicionaFilho(no_aux, criaNo(IDN, atomo));
    no_aux_argumentos = no_aux; 		// lista de argumentos na chamada funcao
  }
#line 1915 "sintatico.c" /* yacc.c:1646  */
    break;

  case 94:
#line 557 "sintatico.y" /* yacc.c:1646  */
    {
    arg = *atomo;
    no_aux = criaNo(LAR, ""); 
    adicionaFilho(no_aux_argumentos, no_aux); 
    no_aux_argumentos = no_aux;
  }
#line 1926 "sintatico.c" /* yacc.c:1646  */
    break;


#line 1930 "sintatico.c" /* yacc.c:1646  */
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
#line 565 "sintatico.y" /* yacc.c:1906  */


int yywrap() {

}

int main (void){
	yyparse();
	
	//Arvore Sintatica
  	geraarv(raiz); //geracao do codigo ENUM para criacao da arvore
  	printf("\n\n");


  	//MVS - Máquina Virtual Simples
  	geracod(raiz); // geracao do codigo para MVS
  	printf("\n");
}
