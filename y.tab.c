/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "bison.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

extern int yylex();
extern int yyparse();
extern int yylineno;
extern FILE *yyin;
extern FILE *yyout;

void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
 }

char* ast_text = "ast.txt";

/* nodes in the abstract syntax tree */
struct ast {
	char*  nodetype;
	struct ast *l;
	struct ast *r;
};
struct numval {
	char* nodetype;
	double number;
};

struct strval {
	char* nodetype;
	char* str;
};

struct boo {
	char* nodetype;
	struct ast *l;
	struct ast *r;
};

struct flow {
	char* nodetype; /* type I or W */
	struct ast *cond; /* condition */
};

struct asign {
 	char* nodetype;
 	struct ast *as;
};

//Declaraciones de la tabla de simbolos

struct symb{    
	char* vname;    
	int vvali;   
	float vvalf;
	char* vvals;
	char* type; 
};
//Variables globales
int line_num = 1;

int size = 52;

int elementosOcupados = 0;

int numnodo = 0;

struct ast nodos[52];

struct symb tabla[52];

// aux
void write_file(char *filename, char *content);

// tabla simbolos
void initSymbolTable(struct symb *tabla, int inicio, int fin);

// nodos
void initNodeArray(struct ast *nodos, int inicio, int fin);

// funciones ast
struct ast *newast(char* nodetype, struct ast *l, struct ast *r);
struct ast *createNum(double d);
struct ast *createSTR(char* s);
struct ast *createBOOLVAR(char* s);
struct ast *createBOOL(char* nodetype, struct ast *l, struct ast *r);
struct ast *createFlow(struct ast *cond);
void insertElement(struct symb *tabla, int *size, int valor, char* svalor, float fvalor, char *variable, int *elementosOcupados, char* type );
struct ast *assignAST(struct ast *op);
// void retrieveElement(struct symb *tabla, int size, char* name);
int retrieveIntFromTable(struct symb *tabla, int size, char* name);
float retrieveFloatFromTable(struct symb *tabla, int size, char* name);
char* retrieveStringFromTable(struct symb *tabla, int size, char* name);
bool checkVarAndType(struct symb *tabla, int size, char* name, char* type);

void eval(struct ast a, int* size);
void printAST(struct ast nodos[], int i, int encontrado, int salida);

#line 170 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    PLUS = 260,
    MINUS = 261,
    MULTIPLY = 262,
    DIVIDE = 263,
    LEFT = 264,
    RIGHT = 265,
    OPEN = 266,
    CLOSE = 267,
    WHILE = 268,
    BOOL = 269,
    CASE = 270,
    INTEGERDEC = 271,
    FLOATDEC = 272,
    CHARDEC = 273,
    STRINGDEC = 274,
    BEG = 275,
    STR = 276,
    LOOP_ = 277,
    END = 278,
    IF = 279,
    THEN = 280,
    CHAR = 281,
    AND = 282,
    OR = 283,
    ELSE = 284,
    ELSEIF = 285,
    BOOLEAN_MIX = 286,
    PROCEDURE = 287,
    IS = 288,
    LESS = 289,
    MORE = 290,
    EQUAL = 291,
    GREATER_THAN = 292,
    LESSER_THAN = 293,
    NOT_EQUAL = 294,
    COMPARE = 295,
    COMMENT = 296,
    COLON = 297,
    SEMICOLON = 298,
    QUOTE = 299,
    NEWLINE = 300,
    QUIT = 301,
    TRUE = 302,
    FALSE = 303,
    TYPE = 304,
    RANGE = 305,
    DOTDOT = 306,
    OF = 307,
    COMMA = 308,
    WHEN = 309,
    FOR = 310,
    OTHERS = 311,
    ARROW = 312,
    VAR = 313,
    DECLINTEGER = 314,
    DECLFLOAT = 315,
    DECLBOOLEAN = 316,
    DECLARRAY = 317,
    DECLSTRING = 318
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define PLUS 260
#define MINUS 261
#define MULTIPLY 262
#define DIVIDE 263
#define LEFT 264
#define RIGHT 265
#define OPEN 266
#define CLOSE 267
#define WHILE 268
#define BOOL 269
#define CASE 270
#define INTEGERDEC 271
#define FLOATDEC 272
#define CHARDEC 273
#define STRINGDEC 274
#define BEG 275
#define STR 276
#define LOOP_ 277
#define END 278
#define IF 279
#define THEN 280
#define CHAR 281
#define AND 282
#define OR 283
#define ELSE 284
#define ELSEIF 285
#define BOOLEAN_MIX 286
#define PROCEDURE 287
#define IS 288
#define LESS 289
#define MORE 290
#define EQUAL 291
#define GREATER_THAN 292
#define LESSER_THAN 293
#define NOT_EQUAL 294
#define COMPARE 295
#define COMMENT 296
#define COLON 297
#define SEMICOLON 298
#define QUOTE 299
#define NEWLINE 300
#define QUIT 301
#define TRUE 302
#define FALSE 303
#define TYPE 304
#define RANGE 305
#define DOTDOT 306
#define OF 307
#define COMMA 308
#define WHEN 309
#define FOR 310
#define OTHERS 311
#define ARROW 312
#define VAR 313
#define DECLINTEGER 314
#define DECLFLOAT 315
#define DECLBOOLEAN 316
#define DECLARRAY 317
#define DECLSTRING 318

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 102 "bison.y"

	int eval;
	float fval;
	char* sval;

	struct atributos{
		int i;
		float f;
		int i2;
		float f2;
		char* operador;
		char* s;
		char *temp1;
		char *temp2;
		char *temp3;
		char* type;
		struct ast *a;
	}st;

#line 368 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   331

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  235

#define YYUNDEFTOK  2
#define YYMAXUTOK   318


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   177,   177,   180,   180,   182,   183,   186,   193,   203,
     213,   214,   219,   221,   229,   230,   231,   232,   236,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   255,
     261,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   280,   281,   282,
     290,   291,   292,   293,   294,   295,   299,   300,   301,   302,
     306,   307,   308,   309,   310,   311,   315,   316,   317,   318,
     319,   320,   325,   326,   327,   328,   329,   330,   334,   335,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     359,   363,   364,   365,   366,   371,   372,   381,   385
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "LEFT", "RIGHT", "OPEN", "CLOSE", "WHILE", "BOOL",
  "CASE", "INTEGERDEC", "FLOATDEC", "CHARDEC", "STRINGDEC", "BEG", "STR",
  "LOOP_", "END", "IF", "THEN", "CHAR", "AND", "OR", "ELSE", "ELSEIF",
  "BOOLEAN_MIX", "PROCEDURE", "IS", "LESS", "MORE", "EQUAL",
  "GREATER_THAN", "LESSER_THAN", "NOT_EQUAL", "COMPARE", "COMMENT",
  "COLON", "SEMICOLON", "QUOTE", "NEWLINE", "QUIT", "TRUE", "FALSE",
  "TYPE", "RANGE", "DOTDOT", "OF", "COMMA", "WHEN", "FOR", "OTHERS",
  "ARROW", "VAR", "DECLINTEGER", "DECLFLOAT", "DECLBOOLEAN", "DECLARRAY",
  "DECLSTRING", "$accept", "PROCLINE", "ADDCONTENT", "AUXINT", "DECL",
  "CONTENT", "OPERATOR", "OPERATION", "OPERATION2", "BOOLEAN_OPERATORS",
  "BOOLEAN_VAR", "BOOLEAN_OP", "COM", "IF_COND", "WLOOP", "VAR_NAME",
  "STRING", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318
};
# endif

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -24,   -43,    19,   -68,   -11,   -68,   -68,   191,   268,   268,
      17,    17,     3,    17,   -68,    17,   -68,   -68,   -43,   -68,
     -68,   -68,   -68,   -68,   -68,   256,   -68,   -68,   -68,   -68,
     -68,   -68,    33,    42,    28,   268,     8,    16,    26,    47,
      38,    83,    72,   222,    80,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -46,    20,
       5,    97,   109,   112,    70,   -68,   -68,   -68,   116,   128,
      95,    95,    31,   -68,   -68,   -68,   164,   203,    82,   118,
     141,   121,   130,   -68,   147,   -68,   150,   -68,   152,   -68,
     154,   126,   195,   -43,   -43,   268,   268,   306,   312,     9,
       9,     9,     9,   -68,   -43,    24,    24,    24,    24,   -68,
     -43,   -68,   -68,   -68,   -68,   -68,   -68,   -68,    98,   124,
     -68,   107,   158,   110,   -19,   196,   200,   155,   174,   176,
       9,     9,     9,     9,   -68,    24,    24,    24,    24,   -68,
     -68,     9,   166,   166,   -68,   -68,   184,   -68,    24,   194,
     194,   -68,   -68,   185,   209,   218,   228,   186,   188,   202,
     204,   236,   245,   249,   257,    17,    17,   205,   216,    68,
     217,   227,   234,   233,   235,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -43,   -68,   107,   -68,
     -43,   -68,   158,   -43,   -43,   -68,   -68,   -68,   138,   -68,
     -68,   224,   -68,   229,   241,   261,   243,   244,   267,   246,
     254,   258,   266,   272,   278,   275,   289,   271,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     281,   -43,   -68,   282,   -68
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    97,     0,     1,     4,     0,     0,     0,
       0,     0,     0,     0,    92,     0,    52,    90,     0,    55,
       3,    51,    54,    50,    53,     0,    74,    73,    75,    76,
      77,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    85,    82,    83,
      87,    89,    95,    96,    94,     2,    91,    93,     0,     0,
       0,     0,     0,     0,     0,    84,    86,    88,     0,     0,
      60,    66,     0,    98,    78,    79,     0,     0,     0,     0,
       0,     0,     0,    12,     0,    18,     0,    27,     0,    30,
       0,     0,     0,     0,     0,    60,    66,     0,     0,    56,
      57,    58,    59,    37,     0,    56,    57,    58,    59,    38,
       0,    45,    44,    56,    57,    58,    59,    31,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,     0,     0,     0,     0,    71,
      60,     0,    61,    62,    63,    64,     0,    66,     0,    67,
      68,    69,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,    43,    35,    36,    33,
      34,    32,    40,    41,    39,    11,     0,     7,     0,    17,
       0,    13,     0,     0,     0,    25,    26,    19,     0,    28,
      29,     6,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,     9,
       8,    16,    15,    14,    23,    24,    21,    22,    20,     5,
       0,     0,    49,     0,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -68,   -68,   -68,   -68,   -67,   -45,   -56,    35,
     206,    -6,   -68,   -68,   -68,    -1,   207
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,   216,    19,    20,   104,    97,    98,    32,
      78,    34,    22,    23,    24,    35,    81
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       4,    21,    73,    77,    68,    36,    25,    40,     1,    41,
     110,    39,   140,   118,    76,     3,    69,    42,   141,     5,
       8,     9,     6,    70,    71,    37,    10,    38,   147,    72,
      52,    47,    50,   148,    95,    96,    45,    46,    51,     3,
      72,    73,    64,    67,    33,    48,    49,    82,    83,   149,
     150,   151,   152,    79,   142,   143,   144,   145,    80,    53,
      44,     3,   156,    56,    93,    94,   163,    74,    75,    54,
      44,     8,     9,   155,   119,     3,   161,    10,     3,   149,
     150,   151,   152,    65,    66,   142,   143,   144,   145,     3,
      55,     3,   128,   129,   186,   188,   190,   192,     8,     9,
       3,   140,   147,   146,    10,    58,    33,   154,    57,   153,
     140,   197,    90,   165,   166,    44,   141,   157,   160,    91,
     162,   164,   169,   170,   167,   111,     3,   158,   159,    26,
      27,    33,    28,    29,    30,    31,   208,    92,     3,    84,
      85,   212,   213,   205,     8,     9,   113,   114,   115,   116,
      10,    86,    87,     3,    88,    89,     3,    74,    75,   193,
     194,   112,   147,   198,   120,     3,   121,   148,     3,    99,
     100,   101,   102,   132,   133,    26,    27,   126,    28,    29,
      30,    31,     3,   122,   117,   204,   123,   206,   124,   207,
     125,   209,   210,   211,     8,     9,     3,   214,   127,     3,
      10,   137,   138,   173,    11,   172,   174,   103,   105,   106,
     107,   108,   140,   147,    12,    13,     3,   175,   154,   176,
      14,    15,    16,   130,   131,   132,   133,   177,   178,   181,
     233,   182,    17,   135,   136,   137,   138,   201,   203,   217,
      18,    99,   100,   101,   102,   183,   109,   184,   195,     3,
     113,   114,   115,   116,   105,   106,   107,   108,    59,   196,
     199,   179,   113,   114,   115,   116,   130,   131,   132,   133,
     200,   180,   135,   136,   137,   138,   202,   215,   229,   185,
       3,    60,    61,    62,   218,    63,   220,   221,   187,   223,
      26,    27,   189,    28,    29,    30,    31,   224,    43,   230,
     191,   225,    26,    27,   219,    28,    29,    30,    31,   226,
     222,   130,   131,   132,   133,   227,   134,   135,   136,   137,
     138,   228,   139,   231,   232,   234,     0,     0,     0,   168,
       0,   171
};

static const yytype_int16 yycheck[] =
{
       1,     7,    21,    59,    50,    11,     7,    13,    32,    15,
      77,    12,     3,    80,    59,    58,    62,    18,     9,     0,
       3,     4,    33,     3,     4,    22,     9,    24,     4,     9,
      22,    32,    33,     9,     3,     4,     3,     4,    10,    58,
       9,    21,    43,    44,     9,     3,     4,    42,    43,   105,
     106,   107,   108,    59,    99,   100,   101,   102,    59,    43,
      25,    58,   118,    25,    70,    71,   122,    47,    48,    43,
      35,     3,     4,   118,    80,    58,   121,     9,    58,   135,
     136,   137,   138,     3,     4,   130,   131,   132,   133,    58,
      43,    58,    93,    94,   161,   162,   163,   164,     3,     4,
      58,     3,     4,   104,     9,    33,    71,     9,    25,   110,
       3,    43,    42,     3,     4,    80,     9,   118,   119,     3,
     121,   122,   123,   124,    14,    43,    58,     3,     4,    34,
      35,    96,    37,    38,    39,    40,   192,     9,    58,    42,
      43,     3,     4,   188,     3,     4,     5,     6,     7,     8,
       9,    42,    43,    58,    42,    43,    58,    47,    48,   165,
     166,    43,     4,   169,    43,    58,    36,     9,    58,     5,
       6,     7,     8,     7,     8,    34,    35,    51,    37,    38,
      39,    40,    58,    36,    43,   186,    36,   188,    36,   190,
      36,   192,   193,   194,     3,     4,    58,   198,     3,    58,
       9,     7,     8,     3,    13,     9,    51,    43,     5,     6,
       7,     8,     3,     4,    23,    24,    58,    43,     9,    43,
      29,    30,    31,     5,     6,     7,     8,    43,    43,    43,
     231,    43,    41,     5,     6,     7,     8,     3,     3,    10,
      49,     5,     6,     7,     8,    43,    43,    43,    43,    58,
       5,     6,     7,     8,     5,     6,     7,     8,    36,    43,
      43,    43,     5,     6,     7,     8,     5,     6,     7,     8,
      43,    43,     5,     6,     7,     8,    43,    53,     3,    43,
      58,    59,    60,    61,    43,    63,    43,    43,    43,    43,
      34,    35,    43,    37,    38,    39,    40,    43,    42,    10,
      43,    43,    34,    35,    43,    37,    38,    39,    40,    43,
      43,     5,     6,     7,     8,    43,    10,     5,     6,     7,
       8,    43,    10,    52,    43,    43,    -1,    -1,    -1,   123,
      -1,   124
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    65,    58,    79,     0,    33,    66,     3,     4,
       9,    13,    23,    24,    29,    30,    31,    41,    49,    68,
      69,    75,    76,    77,    78,    79,    34,    35,    37,    38,
      39,    40,    73,    73,    75,    79,    75,    22,    24,    79,
      75,    75,    79,    42,    73,     3,     4,    79,     3,     4,
      79,    10,    22,    43,    43,    43,    25,    25,    33,    36,
      59,    60,    61,    63,    79,     3,     4,    79,    50,    62,
       3,     4,     9,    21,    47,    48,    71,    72,    74,    75,
      79,    80,    42,    43,    42,    43,    42,    43,    42,    43,
      42,     3,     9,    75,    75,     3,     4,    71,    72,     5,
       6,     7,     8,    43,    70,     5,     6,     7,     8,    43,
      70,    43,    43,     5,     6,     7,     8,    43,    70,    75,
      43,    36,    36,    36,    36,    36,    51,     3,    79,    79,
       5,     6,     7,     8,    10,     5,     6,     7,     8,    10,
       3,     9,    71,    71,    71,    71,    79,     4,     9,    72,
      72,    72,    72,    79,     9,    71,    72,    79,     3,     4,
      79,    71,    79,    72,    79,     3,     4,    14,    74,    79,
      79,    80,     9,     3,    51,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    70,    43,    70,    43,
      70,    43,    70,    75,    75,    43,    43,    43,    75,    43,
      43,     3,    43,     3,    79,    71,    79,    79,    72,    79,
      79,    79,     3,     4,    79,    53,    67,    10,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,     3,
      10,    52,    43,    79,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    67,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      69,    69,    69,    69,    69,    69,    70,    70,    70,    70,
      71,    71,    71,    71,    71,    71,    72,    72,    72,    72,
      72,    72,    73,    73,    73,    73,    73,    73,    74,    74,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      76,    77,    77,    77,    77,    78,    78,    79,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     2,     0,     2,     0,     7,     9,     9,
       9,     7,     4,     7,     9,     9,     9,     7,     4,     7,
       9,     9,     9,     9,     9,     7,     7,     4,     7,     7,
       4,     5,     7,     7,     7,     7,     7,     5,     5,     7,
       7,     7,     7,     7,     5,     5,     5,     8,    12,    10,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     1,     3,     3,     3,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 177 "bison.y"
                                                                        {printf("%s", "procline");}
#line 1829 "y.tab.c"
    break;

  case 5:
#line 182 "bison.y"
                  {}
#line 1835 "y.tab.c"
    break;

  case 6:
#line 183 "bison.y"
          {}
#line 1841 "y.tab.c"
    break;

  case 7:
#line 187 "bison.y"
        {(yyval.st).s = "Declaracion de variable Integer igual a variable"; 
	if(checkVarAndType(tabla, size, (yyvsp[-1].st).s,"integer")) {
			insertElement(tabla, &size, retrieveIntFromTable(tabla, size, (yyvsp[-1].st).s), "", 0.0, (yyvsp[-6].st).s, &elementosOcupados, "integer" );
			(yyval.st).a = assignAST((yyvsp[-1].st).a);
		}
	}
#line 1852 "y.tab.c"
    break;

  case 8:
#line 193 "bison.y"
                                                                                      {
			(yyval.st).s = "Declaracion de variable Integer igual a variable integer + variable integer"; 
			if(checkVarAndType(tabla, size, (yyvsp[-3].st).s, "integer") && checkVarAndType(tabla, size, (yyvsp[-1].st).s, "integer")) {
				if(strcmp((yyvsp[-2].st).operador, "+") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, (yyvsp[-3].st).s) + retrieveIntFromTable(tabla, size, (yyvsp[-1].st).s), "", 0.0, (yyvsp[-8].st).s, &elementosOcupados, "integer" ); }
				if(strcmp((yyvsp[-2].st).operador, "-") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, (yyvsp[-3].st).s) - retrieveIntFromTable(tabla, size, (yyvsp[-1].st).s), "", 0.0, (yyvsp[-8].st).s, &elementosOcupados, "integer" ); }
				if(strcmp((yyvsp[-2].st).operador, "*") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, (yyvsp[-3].st).s) * retrieveIntFromTable(tabla, size, (yyvsp[-1].st).s), "", 0.0, (yyvsp[-8].st).s, &elementosOcupados, "integer" ); }
				if(strcmp((yyvsp[-2].st).operador, "/") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, (yyvsp[-3].st).s) / retrieveIntFromTable(tabla, size, (yyvsp[-1].st).s), "", 0.0, (yyvsp[-8].st).s, &elementosOcupados, "integer" ); }
				(yyval.st).a = newast((yyvsp[-2].st).operador, (yyvsp[-3].st).a, (yyvsp[-1].st).a);
			}
		}
#line 1867 "y.tab.c"
    break;

  case 9:
#line 203 "bison.y"
                                                                                       {
			(yyval.st).s = "Declaracion de variable Integer igual a variable integer + operacion"; 
			if(checkVarAndType(tabla, size, (yyvsp[-3].st).s, "integer")) {
				if(strcmp((yyvsp[-2].st).operador, "+") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, (yyvsp[-3].st).s) + (yyvsp[-1].st).i, "", 0.0, (yyvsp[-8].st).s, &elementosOcupados, "integer" ); }
				if(strcmp((yyvsp[-2].st).operador, "-") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, (yyvsp[-3].st).s) - (yyvsp[-1].st).i, "", 0.0, (yyvsp[-8].st).s, &elementosOcupados, "integer" ); }
				if(strcmp((yyvsp[-2].st).operador, "*") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, (yyvsp[-3].st).s) * (yyvsp[-1].st).i, "", 0.0, (yyvsp[-8].st).s, &elementosOcupados, "integer" ); }
				if(strcmp((yyvsp[-2].st).operador, "/") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, (yyvsp[-3].st).s) / (yyvsp[-1].st).i, "", 0.0, (yyvsp[-8].st).s, &elementosOcupados, "integer" ); }
				(yyval.st).a = newast((yyvsp[-2].st).operador, (yyvsp[-3].st).a, (yyvsp[-1].st).a);
			}
		}
#line 1882 "y.tab.c"
    break;

  case 10:
#line 213 "bison.y"
                                                                                       {}
#line 1888 "y.tab.c"
    break;

  case 11:
#line 215 "bison.y"
        {(yyval.st).s = "Declaracion de variable Integer igual a operacion aritmetica"; 
	insertElement(tabla, &size, (yyvsp[-1].st).i, "", 0.0, (yyvsp[-6].st).s, &elementosOcupados, "integer" );
	 (yyval.st).a = assignAST((yyvsp[-1].st).a);}
#line 1896 "y.tab.c"
    break;

  case 12:
#line 219 "bison.y"
                                               {}
#line 1902 "y.tab.c"
    break;

  case 13:
#line 221 "bison.y"
                                                                  {
			{(yyval.st).s = "Declaracion de variable Float igual a variable float"; 
				if(checkVarAndType(tabla, size, (yyvsp[-1].st).s,"float")) {
					insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, (yyvsp[-1].st).s), (yyvsp[-6].st).s, &elementosOcupados, "float" );
					(yyval.st).a = assignAST((yyvsp[-1].st).a);
				}
			}
		}
#line 1915 "y.tab.c"
    break;

  case 14:
#line 229 "bison.y"
                                                                                    {}
#line 1921 "y.tab.c"
    break;

  case 15:
#line 230 "bison.y"
                                                                                      {}
#line 1927 "y.tab.c"
    break;

  case 16:
#line 231 "bison.y"
                                                                                      {}
#line 1933 "y.tab.c"
    break;

  case 17:
#line 233 "bison.y"
        {(yyval.st).s = "Declaracion de variable Float igual a operacion aritmetica";
	insertElement(tabla, &size, 0, "", (yyvsp[-1].st).f, (yyvsp[-6].st).s, &elementosOcupados, "float" );
	(yyval.st).a = assignAST((yyvsp[-1].st).a);}
#line 1941 "y.tab.c"
    break;

  case 18:
#line 236 "bison.y"
                                             {}
#line 1947 "y.tab.c"
    break;

  case 19:
#line 238 "bison.y"
                                                                    {}
#line 1953 "y.tab.c"
    break;

  case 20:
#line 239 "bison.y"
                                                                                        {}
#line 1959 "y.tab.c"
    break;

  case 21:
#line 240 "bison.y"
                                                                                   {}
#line 1965 "y.tab.c"
    break;

  case 22:
#line 241 "bison.y"
                                                                                     {}
#line 1971 "y.tab.c"
    break;

  case 23:
#line 242 "bison.y"
                                                                                   {}
#line 1977 "y.tab.c"
    break;

  case 24:
#line 243 "bison.y"
                                                                                     {}
#line 1983 "y.tab.c"
    break;

  case 25:
#line 244 "bison.y"
                                                                {}
#line 1989 "y.tab.c"
    break;

  case 26:
#line 245 "bison.y"
                                                                       {}
#line 1995 "y.tab.c"
    break;

  case 27:
#line 246 "bison.y"
                                               {}
#line 2001 "y.tab.c"
    break;

  case 28:
#line 247 "bison.y"
                                                                   {
			{(yyval.st).s = "Declaracion de variable String igual a variable String"; 
				if(checkVarAndType(tabla, size, (yyvsp[-1].st).s,"string")) {
					insertElement(tabla, &size, 0, retrieveStringFromTable(tabla, size, (yyvsp[-1].st).s), 0.0, (yyvsp[-6].st).s, &elementosOcupados, "string" );
					(yyval.st).a = assignAST((yyvsp[-1].st).a);
				}
			}
		}
#line 2014 "y.tab.c"
    break;

  case 29:
#line 256 "bison.y"
                {
			(yyval.st).s = "Declaracion con string";
			insertElement(tabla, &size, 0, (yyvsp[-1].st).s, 0.0, (yyvsp[-6].st).s, &elementosOcupados, "string" );
			(yyval.st).a = assignAST((yyvsp[-1].st).a);
		}
#line 2024 "y.tab.c"
    break;

  case 30:
#line 261 "bison.y"
                                              {(yyval.st).s = "Declaracion de variable String";}
#line 2030 "y.tab.c"
    break;

  case 31:
#line 263 "bison.y"
                                                  {}
#line 2036 "y.tab.c"
    break;

  case 32:
#line 264 "bison.y"
                                                                    {}
#line 2042 "y.tab.c"
    break;

  case 33:
#line 265 "bison.y"
                                                                     {(yyval.st).s = "Variable igual a Variable operacion con operacion aritmetica";}
#line 2048 "y.tab.c"
    break;

  case 34:
#line 266 "bison.y"
                                                                      {}
#line 2054 "y.tab.c"
    break;

  case 35:
#line 267 "bison.y"
                                                                     {}
#line 2060 "y.tab.c"
    break;

  case 36:
#line 268 "bison.y"
                                                                      {}
#line 2066 "y.tab.c"
    break;

  case 37:
#line 269 "bison.y"
                                                   {}
#line 2072 "y.tab.c"
    break;

  case 38:
#line 270 "bison.y"
                                                    {}
#line 2078 "y.tab.c"
    break;

  case 39:
#line 271 "bison.y"
                                                                      {}
#line 2084 "y.tab.c"
    break;

  case 40:
#line 272 "bison.y"
                                                                 {}
#line 2090 "y.tab.c"
    break;

  case 41:
#line 273 "bison.y"
                                                                   {}
#line 2096 "y.tab.c"
    break;

  case 42:
#line 274 "bison.y"
                                                                 {}
#line 2102 "y.tab.c"
    break;

  case 43:
#line 275 "bison.y"
                                                                   {}
#line 2108 "y.tab.c"
    break;

  case 44:
#line 276 "bison.y"
                                                    {}
#line 2114 "y.tab.c"
    break;

  case 45:
#line 277 "bison.y"
                                                     {}
#line 2120 "y.tab.c"
    break;

  case 46:
#line 278 "bison.y"
                                                {}
#line 2126 "y.tab.c"
    break;

  case 47:
#line 280 "bison.y"
                                                          {}
#line 2132 "y.tab.c"
    break;

  case 48:
#line 281 "bison.y"
                                                                                     {}
#line 2138 "y.tab.c"
    break;

  case 49:
#line 282 "bison.y"
                                                                              {}
#line 2144 "y.tab.c"
    break;

  case 50:
#line 290 "bison.y"
                 {printf("Contenido: %s\t Linea: %d\n", (yyvsp[0].st).s, yylineno); if(!(yyvsp[0].st).a){ ;} else {eval(*(yyvsp[0].st).a, &size);};}
#line 2150 "y.tab.c"
    break;

  case 51:
#line 291 "bison.y"
                      {printf("%s", (yyvsp[0].st).s);}
#line 2156 "y.tab.c"
    break;

  case 52:
#line 292 "bison.y"
                       {printf("%s", (yyvsp[0].st).s);}
#line 2162 "y.tab.c"
    break;

  case 53:
#line 293 "bison.y"
                 {printf("%s", (yyvsp[0].sval));}
#line 2168 "y.tab.c"
    break;

  case 54:
#line 294 "bison.y"
               {printf("Contenido: %s\t Linea: %d\n", (yyvsp[0].sval), yylineno); }
#line 2174 "y.tab.c"
    break;

  case 55:
#line 295 "bison.y"
               {printf("Contenido: %s\t Linea: %d\n", (yyvsp[0].st).s, yylineno); if(!(yyvsp[0].st).a){ ;} else {eval(*(yyvsp[0].st).a, &size);};}
#line 2180 "y.tab.c"
    break;

  case 56:
#line 299 "bison.y"
             {(yyval.st).operador = "+";}
#line 2186 "y.tab.c"
    break;

  case 57:
#line 300 "bison.y"
                {(yyval.st).operador = "-";}
#line 2192 "y.tab.c"
    break;

  case 58:
#line 301 "bison.y"
                   {(yyval.st).operador = "*";}
#line 2198 "y.tab.c"
    break;

  case 59:
#line 302 "bison.y"
                 {(yyval.st).operador = "/";}
#line 2204 "y.tab.c"
    break;

  case 60:
#line 306 "bison.y"
                {(yyval.st).i = (yyvsp[0].st).i; (yyval.st).a = createNum((yyvsp[0].st).i);}
#line 2210 "y.tab.c"
    break;

  case 61:
#line 307 "bison.y"
                                                {(yyval.st).i = (yyvsp[-2].st).i + (yyvsp[0].st).i; (yyval.st).a = newast("+",(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2216 "y.tab.c"
    break;

  case 62:
#line 308 "bison.y"
                                        {(yyval.st).i = (yyvsp[-2].st).i - (yyvsp[0].st).i; (yyval.st).a = newast("-",(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2222 "y.tab.c"
    break;

  case 63:
#line 309 "bison.y"
                                        {(yyval.st).i = (yyvsp[-2].st).i * (yyvsp[0].st).i; (yyval.st).a = newast("*",(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2228 "y.tab.c"
    break;

  case 64:
#line 310 "bison.y"
                                        {(yyval.st).i = (yyvsp[-2].st).i / (yyvsp[0].st).i; (yyval.st).a = newast("/",(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2234 "y.tab.c"
    break;

  case 65:
#line 311 "bison.y"
                               {(yyval.st).i = (yyvsp[-1].st).i;}
#line 2240 "y.tab.c"
    break;

  case 66:
#line 315 "bison.y"
              {(yyval.st).f = (yyvsp[0].fval); (yyval.st).a = createNum((yyvsp[0].fval));}
#line 2246 "y.tab.c"
    break;

  case 67:
#line 316 "bison.y"
                                                {(yyval.st).f = (yyvsp[-2].st).f + (yyvsp[0].st).f; (yyval.st).a = newast((yyvsp[-1].sval),(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2252 "y.tab.c"
    break;

  case 68:
#line 317 "bison.y"
                                        {(yyval.st).f = (yyvsp[-2].st).f - (yyvsp[0].st).f; (yyval.st).a = newast((yyvsp[-1].sval),(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2258 "y.tab.c"
    break;

  case 69:
#line 318 "bison.y"
                                                {(yyval.st).f = (yyvsp[-2].st).f * (yyvsp[0].st).f; (yyval.st).a = newast((yyvsp[-1].sval),(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2264 "y.tab.c"
    break;

  case 70:
#line 319 "bison.y"
                                        {(yyval.st).f = (yyvsp[-2].st).f / (yyvsp[0].st).f; (yyval.st).a = newast((yyvsp[-1].sval),(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2270 "y.tab.c"
    break;

  case 71:
#line 320 "bison.y"
                                {(yyval.st).f = (yyvsp[-1].st).f;}
#line 2276 "y.tab.c"
    break;

  case 72:
#line 325 "bison.y"
                {(yyval.st).s = "IGUAL";(yyval.st).operador = "+";}
#line 2282 "y.tab.c"
    break;

  case 73:
#line 326 "bison.y"
               {(yyval.st).s = "MAYOR";(yyval.st).operador = ">";}
#line 2288 "y.tab.c"
    break;

  case 74:
#line 327 "bison.y"
               {(yyval.st).s = "MENOR";(yyval.st).operador = "<";}
#line 2294 "y.tab.c"
    break;

  case 75:
#line 328 "bison.y"
                       {(yyval.st).s = "MAYOR IGUAL";(yyval.st).operador = ">=";}
#line 2300 "y.tab.c"
    break;

  case 76:
#line 329 "bison.y"
                      {(yyval.st).s = "MENOR IGUAL";(yyval.st).operador = "<=";}
#line 2306 "y.tab.c"
    break;

  case 77:
#line 330 "bison.y"
                    {(yyval.st).s = "DESIGUAL";(yyval.st).operador = "!=";}
#line 2312 "y.tab.c"
    break;

  case 78:
#line 334 "bison.y"
             {(yyval.st).s="True"; (yyval.st).a = createBOOLVAR("True");}
#line 2318 "y.tab.c"
    break;

  case 79:
#line 335 "bison.y"
                {(yyval.st).s="False"; (yyval.st).a = createBOOLVAR("False");}
#line 2324 "y.tab.c"
    break;

  case 80:
#line 346 "bison.y"
                                                        {(yyval.st).s = "INT OP BOOL INT";}
#line 2330 "y.tab.c"
    break;

  case 81:
#line 347 "bison.y"
                                                        {(yyval.st).s = "INT OP BOOL FLOAT";}
#line 2336 "y.tab.c"
    break;

  case 82:
#line 348 "bison.y"
                                                        {(yyval.st).s = "FLOAT OP BOOL INT";}
#line 2342 "y.tab.c"
    break;

  case 83:
#line 349 "bison.y"
                                                                {(yyval.st).s = "FLOAT OP BOOL FLOAT";}
#line 2348 "y.tab.c"
    break;

  case 84:
#line 350 "bison.y"
                                                                {(yyval.st).s = "INT OP BOOL INT";}
#line 2354 "y.tab.c"
    break;

  case 85:
#line 351 "bison.y"
                                                                {(yyval.st).s = "INT OP BOOL INT";}
#line 2360 "y.tab.c"
    break;

  case 86:
#line 352 "bison.y"
                                                                {(yyval.st).s = "FLOAT OP BOOL FLOAT";}
#line 2366 "y.tab.c"
    break;

  case 87:
#line 353 "bison.y"
                                                                {(yyval.st).s = "FLOAT OP BOOL FLOAT";}
#line 2372 "y.tab.c"
    break;

  case 88:
#line 354 "bison.y"
                                                                {(yyval.st).s = "VAR OP BOOL VAR";}
#line 2378 "y.tab.c"
    break;

  case 89:
#line 355 "bison.y"
                                        {(yyval.st).s = "PARENTESIS BOOL PARENTESIS";}
#line 2384 "y.tab.c"
    break;

  case 90:
#line 359 "bison.y"
                {(yyval.sval) = "Comentario\n";}
#line 2390 "y.tab.c"
    break;

  case 91:
#line 363 "bison.y"
                                {(yyval.st).s = "IF BOOL THEN";}
#line 2396 "y.tab.c"
    break;

  case 92:
#line 364 "bison.y"
                                                {(yyval.st).s = "ELSE";}
#line 2402 "y.tab.c"
    break;

  case 93:
#line 365 "bison.y"
                                {(yyval.st).s = "ELSEIF BOOL THEN";}
#line 2408 "y.tab.c"
    break;

  case 94:
#line 366 "bison.y"
                                        {(yyval.st).s = "END IF SEMICOLON";}
#line 2414 "y.tab.c"
    break;

  case 95:
#line 371 "bison.y"
                               {(yyval.sval) = "Bucle while\n";}
#line 2420 "y.tab.c"
    break;

  case 96:
#line 372 "bison.y"
                              {(yyval.sval)="Fin de bucle\n";}
#line 2426 "y.tab.c"
    break;

  case 97:
#line 381 "bison.y"
            {(yyval.st).s = (yyvsp[0].sval); (yyval.st).a = createSTR((yyvsp[0].sval));}
#line 2432 "y.tab.c"
    break;

  case 98:
#line 385 "bison.y"
            {(yyval.st).s = (yyvsp[0].sval); (yyval.st).a = createSTR((yyvsp[0].sval));}
#line 2438 "y.tab.c"
    break;


#line 2442 "y.tab.c"

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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 390 "bison.y"

//FUNCIONES DE AST
struct ast *newast(char* nodetype, struct ast *l, struct ast *r) {
	struct ast *a = malloc(sizeof(struct ast));

	if(!a) {
		yyerror("out of space");
		exit(0);
	}
	a->nodetype = nodetype;
	a->l = l;
	a->r = r;
	return a;
}

struct ast *createSTR(char* s)
{
 	struct strval *a = malloc(sizeof(struct strval));
  	if(!a) {
 		yyerror("out of space");
 		exit(0);
 	}
 	a->nodetype = "String";
 	a->str = s;
 	return (struct ast *)a;
}

struct ast *createBOOL(char* nodetype, struct ast *l, struct ast *r) {

 struct boo *a = malloc(sizeof(struct boo));

 if(!a) {
 yyerror("out of space");
 exit(0);
 }
 a->nodetype = nodetype;
 a->l = l;
 a->r = r;
 return (struct ast *)a;
}

struct ast *createNum(double d)
{
 	struct numval *a = malloc(sizeof(struct numval));
  	if(!a) {
 		yyerror("out of space");
 		exit(0);
 	}
 	a->nodetype = "Constante";
 	a->number = d;
 	return (struct ast *)a;
}

struct ast *createBOOLVAR(char* s)
{
 	struct strval *a = malloc(sizeof(struct strval));
  	if(!a) {
 		yyerror("out of space");
 		exit(0);
 	}
 	a->nodetype = "Boolean var";
 	a->str = s;
 	return (struct ast *)a;
}

struct ast *createFlow(struct ast *cond){

	struct flow *a = malloc(sizeof(struct flow));

	if(!a) {
		yyerror("out of space");
		exit(0);
	}

	a->nodetype = "IF";
	a->cond = cond;

	return (struct ast *)a;
}

void eval(struct ast a, int* size){
	int i = 0;
	int encontrado = 0;
	while (i < *size && encontrado == 0){
		if((strcmp(nodos[i].nodetype, "._empty") == 0) && (strcmp(a.nodetype, "String") != 0) && (strcmp(a.nodetype, "Constante") != 0) ){
			nodos[i] = a;
			numnodo = numnodo +1;
			encontrado = 1;
		}else{
			i++;
		}
	}
}

struct ast *assignAST(struct ast *op){

	struct asign *a = malloc(sizeof(struct asign));
	if(!a) {
		yyerror("out of space");
		exit(0);
	}
	a->nodetype = "=";
	a->as = op;

	return (struct ast *)a;
}

void initSymbolTable(struct symb *tabla, int inicio, int fin) {
    for (int i = inicio; i < fin; i++) {
        tabla[i].vname = "._empty";
    }
}

void initNodeArray(struct ast *nodos, int inicio, int fin) {
    for (int i = inicio; i < fin; i++) {
        nodos[i].nodetype = "._empty";
    }
}

void printAST(struct ast nodos[], int i, int encontrado, int salida){
	struct ast temp[52];
	initNodeArray(temp,0,52);

	while(encontrado == 0 && salida == 0){
		if(strcmp(nodos[i].nodetype, "._empty") == 0){
			encontrado = 1;
			salida=1;
		}else{
			if(strcmp(nodos[i].nodetype, "IF") == 0){
				write_file(ast_text, "\n");
				write_file(ast_text, nodos[i].nodetype);
				write_file(ast_text, "\n");
				temp[0] = *nodos[i].l;
				printAST(temp,0,0,0);

			}else if(strcmp(nodos[i].nodetype, "WHILE") == 0){
					write_file(ast_text, "\n");
					write_file(ast_text, nodos[i].nodetype);
					write_file(ast_text, "\n");
					temp[0] = *nodos[i].l;
					printAST(temp,0,0,0);

			}else if((strcmp(nodos[i].nodetype, ">") == 0) || (strcmp(nodos[i].nodetype, "<") == 0) || (strcmp(nodos[i].nodetype, ">=") == 0) ||
						 (strcmp(nodos[i].nodetype, "<=") == 0) ||  (strcmp(nodos[i].nodetype, "!=") == 0) || (strcmp(nodos[i].nodetype, "==") == 0)){

				write_file(ast_text, nodos[i].nodetype);
				write_file(ast_text, "\n");
				temp[0] = *nodos[i].l; 
				printAST(temp,0,0,0);
				write_file(ast_text, "\n");
				temp[0] = *nodos[i].r; 
				printAST(temp,0,0,0);
				write_file(ast_text, "\n");
				salida = 1;
				

			}else if(strcmp(nodos[i].nodetype, "=") == 0){
				write_file(ast_text, "\n");
				write_file(ast_text, nodos[i].nodetype);
				write_file(ast_text, "\n");
				if((strcmp(nodos[i].l->nodetype, "+") == 0)||(strcmp(nodos[i].l->nodetype, "-") == 0)||(strcmp(nodos[i].l->nodetype, "/") == 0)||
				(strcmp(nodos[i].l->nodetype, "*") == 0)){

					temp[0] = *nodos[i].l;
					printAST(temp,0,0,0);


				}else{
					temp[0] = *nodos[i].l; 
					printAST(temp,0,0,0);

				}


			}else if((strcmp(nodos[i].nodetype, "+") == 0)||(strcmp(nodos[i].nodetype, "-") == 0)||(strcmp(nodos[i].nodetype, "/") == 0)||
				(strcmp(nodos[i].nodetype, "*") == 0)){

				write_file(ast_text, nodos[i].nodetype);
				write_file(ast_text, "\n");
				temp[0] = *nodos[i].l;
				printAST(temp,0,0,0);
				write_file(ast_text, "\n");
				temp[0] = *nodos[i].r;
				printAST(temp,0,0,0);
				write_file(ast_text, "\n");

			}else if(strcmp(nodos[i].nodetype, "String") == 0){

				write_file(ast_text, nodos[i].nodetype);
				write_file(ast_text, "\n");
				salida = 1;

			}else if(strcmp(nodos[i].nodetype, "Constante") == 0){
				write_file(ast_text, nodos[i].nodetype);
				write_file(ast_text, "\n");
				salida = 1;
				encontrado = 1;
			}			

		}
		i++;
	}
}

//FUNCIONES TABLA AUXILIAR DE SIMBOLOS
int buscarValor(struct symb *tabla, char *nombre, char *tipo, int *size) {
    int i = 0;
    int status = -1;
    while (i < *size && status == -1) {
        if (strcmp(tabla[i].vname, nombre) == 0 && (strcmp(tabla[i].type, tipo) == 0 )) {
            status = i;
        }else if(strcmp(tabla[i].vname, nombre) == 0){ 
        	status = i;
        }else {
            i++;
        }
    }
    return status;
}


void insertElement(struct symb *tabla, int *size, int valor, char* svalor, float fvalor, char *variable, int *elementosOcupados, char* type ) {
	int status = 0;
	
    status = buscarValor(tabla, variable, type, size);

    if(status != -1){
    	if (strcmp(type, "integer") == 0){
	        		tabla[status].vname = variable;
	        		tabla[status].vvali = valor;
	        		tabla[status].type = type;
	            } else if (strcmp(type, "float") == 0) {
	                tabla[status].vname = variable;
	                tabla[status].vvalf = fvalor;
	                tabla[status].type = type;
	            } else if (strcmp(type, "string") == 0) {
	                tabla[status].vname = variable;
	                tabla[status].vvals = svalor;
	                tabla[status].type = type;
	            }        	
    }else{

	    int i = 0;
	    int encontrado = 0;

	    while (i < *size && encontrado == 0) {

	        if (strcmp(tabla[i].vname, "._empty") == 0) {
	        	if (strcmp(type, "integer") == 0){
	        		tabla[i].vname = variable;
	        		tabla[i].vvali = valor;
	        		tabla[i].type = type;
	        		*elementosOcupados = *elementosOcupados + 1;
	        		encontrado = 1;
	            } else if (strcmp(type, "float") == 0) {
	                tabla[i].vname = variable;
	                tabla[i].vvalf = fvalor;
	                tabla[i].type = type;
	                *elementosOcupados = *elementosOcupados + 1;
	                encontrado = 1;
	            } else if (strcmp(type, "string") == 0) {
	                tabla[i].vname = variable;
	                tabla[i].vvals = svalor;
	                tabla[i].type = type;
	                *elementosOcupados = *elementosOcupados + 1;
	                encontrado = 1;
	            }        	
	            
	            *elementosOcupados = *elementosOcupados + 1;
	            encontrado = 1;
	        } else {
	            i++;
	        }
	    }
    }
     
}

// void retrieveElement(struct symb *tabla, int size, char* name) {
// 	int elementIndex = -1;
// 	for(int i = 0; i < size; i++) {
// 		if(strcmp(tabla[i].vname, name) == 0) {
// 			elementIndex = i;
// 			break;
// 		}
// 	}
// 	printf("%s", tabla[elementIndex].vvals);

// 	//return tabla[elementIndex];
// };

bool checkVarAndType(struct symb *tabla, int size, char* name, char* type) {
	int elementIndex = -1;
	for(int i = 0; i < size; i++) {
		if(strcmp(tabla[i].vname, "._empty") == 0){
			continue;
		} else if (strcmp(tabla[i].vname, name) == 0) {
			elementIndex = i;
			break;
		}
	}

	if (elementIndex == -1) {
		return false;
	}

	if (strcmp(tabla[elementIndex].type, type) != 0) {
		return false;
	}

	return true;
}

int retrieveIntFromTable(struct symb *tabla, int size, char* name) {
	int elementIndex = -1;
	for(int i = 0; i < size; i++) {
		if(strcmp(tabla[i].vname, name) == 0) {
			elementIndex = i;
			break;
		}
	}

	return tabla[elementIndex].vvali;
}

float retrieveFloatFromTable(struct symb *tabla, int size, char* name) {
	int elementIndex = -1;
	for(int i = 0; i < size; i++) {
		if(strcmp(tabla[i].vname, name) == 0) {
			elementIndex = i;
			break;
		}
	}

	return tabla[elementIndex].vvalf;
}

char* retrieveStringFromTable(struct symb *tabla, int size, char* name) {
	int elementIndex = -1;
	for(int i = 0; i < size; i++) {
		if(strcmp(tabla[i].vname, name) == 0) {
			elementIndex = i;
			break;
		}
	}

	return tabla[elementIndex].vvals;
}

void write_file(char *filename, char *content) {
    FILE *file;
    file = fopen(filename, "a");
    fprintf(file, "%s", content);
    fclose(file);
}

int main(int argc,char *argv[]) {
	initSymbolTable(tabla, 0, size);
	initNodeArray(nodos, 0, size);
	yyin = fopen(argv[1], "rt");
	yyout = fopen(argv[2], "wt" );
 	yyparse();
	printf("\nTabla de simbolos:");
	for(int b = 0; b < 52; b++){
		if(strcmp(tabla[b].vname, "._empty") == 0){
			break;
		}
		printf("\n");		
		printf("Nombre %s ",tabla[b].vname);
		printf("INT %i ",tabla[b].vvali);
		printf("FLOAT %f ",tabla[b].vvalf);
		printf("STRING %s ",tabla[b].vvals);
		printf("TIPO %s ",tabla[b].type);
		printf("\n");

	}
	printAST(nodos,0,0,0);
}
