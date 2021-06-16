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
	printf("\x1b[1;31m");
	printf("%s\t Line %d\n", s, yylineno);
	printf("\x1b[0m");
	// fprintf (stderr, "%s\n", s);
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
	bool vbool;
	bool assigned;
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
struct ast *createFlow(struct ast *cond);
void insertElement(struct symb *tabla, int *size, int valor, char* svalor, float fvalor, char *variable, bool bvalor, int *elementosOcupados, char* type, bool assigned );
struct ast *assignAST(struct ast *op);
// void retrieveElement(struct symb *tabla, int size, char* name);
int retrieveIntFromTable(struct symb *tabla, int size, char* name);
float retrieveFloatFromTable(struct symb *tabla, int size, char* name);
char* retrieveStringFromTable(struct symb *tabla, int size, char* name);
bool retrieveBoolFromTable(struct symb *tabla, int size, char* name);
char* getVarType(struct symb *tabla, int size, char* name);

bool checkVarAndType(struct symb *tabla, int size, char* name, char* type);
bool searchVar(struct symb *tabla, int size, char* name);
int compare(char* operator, float left, float right);

void eval(struct ast a, int* size);
void printAST(struct ast nodos[], int i, int encontrado, int salida);

#line 179 "y.tab.c"

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
#line 111 "bison.y"

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
		char* error;
		int boo;
	}st;

#line 379 "y.tab.c"

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
#define YYLAST   394

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  217

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
       0,   188,   188,   197,   197,   199,   200,   203,   210,   221,
     232,   243,   249,   255,   264,   275,   286,   297,   301,   306,
     315,   329,   334,   343,   349,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   368,   369,   370,   378,   379,   380,   381,   382,   383,
     387,   388,   389,   390,   394,   395,   396,   397,   398,   399,
     403,   404,   405,   406,   407,   408,   413,   414,   415,   416,
     417,   418,   422,   423,   434,   435,   436,   437,   438,   454,
     455,   456,   457,   458,   462,   466,   467,   468,   469,   474,
     475,   484,   488
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

#define YYPACT_NINF (-94)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -20,   -44,    41,   -94,     3,   -94,   -94,   198,   -94,   -94,
      17,    17,    83,    17,   -94,    17,   -94,   -94,   -44,   -94,
     -94,   300,   307,   -94,   -94,   -94,   -94,   322,   286,   293,
      53,   342,    54,    39,    48,    59,    90,    92,    88,    34,
      34,    34,    34,   -94,   -94,   -94,   -94,   -94,   -94,    19,
      99,    99,    99,    99,    19,   312,    19,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -15,    34,    -3,    -3,
     -94,   -94,    97,    44,   360,   -94,    99,    26,    26,   -94,
     -94,    44,   360,   -94,    -2,    23,    36,    67,    71,    80,
      44,   360,   -94,   127,   124,   378,   384,    17,    17,   -94,
     -94,   -94,    89,   225,    91,   103,   160,   104,   113,   -94,
     114,   -94,   115,   -94,   121,   -94,   122,   109,   158,   -44,
     -44,    34,    34,    34,    34,   -94,   -44,    99,    99,    99,
      99,   -94,   -44,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
      19,    27,   -94,    29,    35,    17,   -18,   153,   167,   120,
     130,   131,   137,   139,   171,   183,   141,   143,   149,   150,
     229,   235,   243,   247,   161,   315,   162,   163,   205,   166,
     207,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -44,   -94,    29,   -94,   -44,   -94,    35,   -94,
     -94,   -94,   -94,   164,   -94,   203,   172,   268,   176,   177,
     274,   180,   221,   215,   186,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   201,   -44,   -94,   202,   -94
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    91,     0,     1,     4,     0,    54,    60,
       0,     0,     0,     0,    86,     0,    46,    84,     0,    49,
       3,     0,     0,    45,    48,    44,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,    67,    69,    70,    71,    66,     0,
       0,     0,     0,     0,     0,     0,     0,    59,    65,    83,
      89,    90,    88,     2,    85,    87,     0,     0,    55,    56,
      57,    58,     0,    74,    75,    79,     0,    61,    62,    63,
      64,    76,    77,    81,     0,     0,     0,     0,     0,     0,
      78,    80,    82,     0,     0,     0,     0,    54,    60,    92,
      72,    73,     0,     0,     0,     0,     0,     0,     0,    12,
       0,    18,     0,    21,     0,    24,     0,     0,     0,     0,
       0,    50,    51,    52,    53,    31,     0,    50,    51,    52,
      53,    32,     0,    39,    38,    50,    51,    52,    53,    25,
       0,     0,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,    37,    29,    30,    27,    28,    26,    34,    35,
      33,    11,     0,     7,     0,    17,     0,    13,     0,    20,
      19,    22,    23,     6,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     9,     8,    16,    15,
      14,     5,     0,     0,    43,     0,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,   -94,   -94,   -94,   -94,   -93,    32,     8,   -13,
     -94,    14,   -94,   -94,   -94,    -1,   100
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,   203,    19,    20,   126,    21,    22,    56,
     104,    23,    24,    25,    26,    31,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       4,    97,    98,    99,    41,    42,    27,    10,    49,    54,
     132,    35,     1,   140,     3,    49,    54,    38,    29,    99,
       8,     9,     8,     9,    30,    32,    10,    36,    72,    37,
     157,   158,     8,    52,    53,    93,     6,     8,    67,     9,
       3,     5,    28,    67,    76,   100,   101,    94,    75,    39,
      40,    41,    42,    83,    89,    92,     3,    74,    77,    78,
      79,    80,    82,    59,    91,   108,   109,   182,   184,   186,
     188,    68,    69,    70,    71,     3,    60,     3,   110,   111,
      96,    73,    61,   106,    96,     3,    81,     3,    90,    49,
      54,    62,   103,     3,   121,   122,   123,   124,   105,    95,
       8,     9,    63,     9,    95,    33,    72,    34,    76,   112,
     113,   119,   120,   114,   115,    64,   102,    65,   150,   151,
     141,    66,   116,    43,    44,   152,    45,    46,    47,    48,
     117,   153,   125,   118,   133,    77,    78,    79,    80,   156,
     159,     3,   161,   163,   165,   166,   134,   142,   155,   143,
     144,   145,   162,    68,    69,    70,    71,   146,   147,   164,
     148,   149,   168,     8,     9,   135,   136,   137,   138,    10,
     169,   170,   154,   171,   172,   160,    39,    40,    41,    42,
     173,   196,   174,   198,   177,   199,   178,   201,    50,    51,
      52,    53,   179,   180,    43,    44,   200,    45,    46,    47,
      48,     8,     9,   139,   189,   191,   192,    10,   193,   194,
     195,    11,   215,   204,   175,   205,   197,   202,     3,   207,
     208,    12,    13,   210,   211,   212,   176,    14,    15,    16,
     127,   128,   129,   130,   121,   122,   123,   124,   213,    17,
     135,   136,   137,   138,   214,   216,   167,    18,   127,   128,
     129,   130,   135,   136,   137,   138,     3,     0,     0,    43,
      44,     0,    45,    46,    47,    48,     0,     0,   131,     0,
       0,     0,   181,    39,    40,    41,    42,     0,   183,    50,
      51,    52,    53,     0,     0,     0,   185,     0,     0,     0,
     187,    39,    40,    41,    42,     0,    57,     0,    50,    51,
      52,    53,     0,    58,     0,    39,    40,    41,    42,     0,
       0,   206,    50,    51,    52,    53,     0,   209,     0,     0,
      43,    44,     0,    45,    46,    47,    48,    43,    44,     0,
      45,    46,    47,    48,    43,    44,     0,    45,    46,    47,
      48,    43,    44,     0,    45,    46,    47,    48,    84,    43,
      44,     0,    45,    46,    47,    48,    43,    44,   190,    45,
      46,    47,    48,     0,    55,    50,    51,    52,    53,     0,
       3,    85,    86,    87,     0,    88,    43,    44,     0,    45,
      46,    47,    48,    39,    40,    41,    42,     0,    57,    50,
      51,    52,    53,     0,    58
};

static const yytype_int16 yycheck[] =
{
       1,     3,     4,    21,     7,     8,     7,     9,    21,    22,
     103,    12,    32,   106,    58,    28,    29,    18,    10,    21,
       3,     4,     3,     4,    10,    11,     9,    13,     9,    15,
       3,     4,     3,     7,     8,    50,    33,     3,     9,     4,
      58,     0,    10,     9,     9,    47,    48,    62,    49,     5,
       6,     7,     8,    54,    55,    56,    58,    49,    50,    51,
      52,    53,    54,    10,    56,    42,    43,   160,   161,   162,
     163,    39,    40,    41,    42,    58,    22,    58,    42,    43,
      72,    49,    43,    84,    76,    58,    54,    58,    56,   102,
     103,    43,    84,    58,     5,     6,     7,     8,    84,    67,
       3,     4,    43,     4,    72,    22,     9,    24,     9,    42,
      43,    97,    98,    42,    43,    25,    84,    25,   119,   120,
     106,    33,    42,    34,    35,   126,    37,    38,    39,    40,
       3,   132,    43,     9,    43,   127,   128,   129,   130,   140,
     141,    58,   143,   144,   145,   146,    43,    43,   140,    36,
      36,    36,   144,   121,   122,   123,   124,    36,    36,   145,
      51,     3,     9,     3,     4,     5,     6,     7,     8,     9,
       3,    51,   140,    43,    43,   143,     5,     6,     7,     8,
      43,   182,    43,   184,    43,   186,    43,   188,     5,     6,
       7,     8,    43,    43,    34,    35,   188,    37,    38,    39,
      40,     3,     4,    43,    43,    43,    43,     9,     3,    43,
       3,    13,   213,    10,    43,    43,   184,    53,    58,    43,
      43,    23,    24,    43,     3,    10,    43,    29,    30,    31,
       5,     6,     7,     8,     5,     6,     7,     8,    52,    41,
       5,     6,     7,     8,    43,    43,   146,    49,     5,     6,
       7,     8,     5,     6,     7,     8,    58,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    -1,    -1,    43,    -1,
      -1,    -1,    43,     5,     6,     7,     8,    -1,    43,     5,
       6,     7,     8,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      43,     5,     6,     7,     8,    -1,    10,    -1,     5,     6,
       7,     8,    -1,    10,    -1,     5,     6,     7,     8,    -1,
      -1,    43,     5,     6,     7,     8,    -1,    43,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    34,    35,    -1,
      37,    38,    39,    40,    34,    35,    -1,    37,    38,    39,
      40,    34,    35,    -1,    37,    38,    39,    40,    36,    34,
      35,    -1,    37,    38,    39,    40,    34,    35,    43,    37,
      38,    39,    40,    -1,    42,     5,     6,     7,     8,    -1,
      58,    59,    60,    61,    -1,    63,    34,    35,    -1,    37,
      38,    39,    40,     5,     6,     7,     8,    -1,    10,     5,
       6,     7,     8,    -1,    10
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    65,    58,    79,     0,    33,    66,     3,     4,
       9,    13,    23,    24,    29,    30,    31,    41,    49,    68,
      69,    71,    72,    75,    76,    77,    78,    79,    71,    72,
      75,    79,    75,    22,    24,    79,    75,    75,    79,     5,
       6,     7,     8,    34,    35,    37,    38,    39,    40,    73,
       5,     6,     7,     8,    73,    42,    73,    10,    10,    10,
      22,    43,    43,    43,    25,    25,    33,     9,    71,    71,
      71,    71,     9,    71,    72,    79,     9,    72,    72,    72,
      72,    71,    72,    79,    36,    59,    60,    61,    63,    79,
      71,    72,    79,    50,    62,    71,    72,     3,     4,    21,
      47,    48,    71,    72,    74,    75,    79,    80,    42,    43,
      42,    43,    42,    43,    42,    43,    42,     3,     9,    75,
      75,     5,     6,     7,     8,    43,    70,     5,     6,     7,
       8,    43,    70,    43,    43,     5,     6,     7,     8,    43,
      70,    75,    43,    36,    36,    36,    36,    36,    51,     3,
      79,    79,    79,    79,    71,    72,    79,     3,     4,    79,
      71,    79,    72,    79,    75,    79,    79,    80,     9,     3,
      51,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    70,    43,    70,    43,    70,    43,    70,    43,
      43,    43,    43,     3,    43,     3,    79,    71,    79,    79,
      72,    79,    53,    67,    10,    43,    43,    43,    43,    43,
      43,     3,    10,    52,    43,    79,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    67,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    69,    69,    69,    69,    69,    69,
      70,    70,    70,    70,    71,    71,    71,    71,    71,    71,
      72,    72,    72,    72,    72,    72,    73,    73,    73,    73,
      73,    73,    74,    74,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    76,    77,    77,    77,    77,    78,
      78,    79,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     2,     0,     2,     0,     7,     9,     9,
       9,     7,     4,     7,     9,     9,     9,     7,     4,     7,
       7,     4,     7,     7,     4,     5,     7,     7,     7,     7,
       7,     5,     5,     7,     7,     7,     7,     7,     5,     5,
       5,     8,    12,    10,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     1,     3,     3,     3,
       3,     1,     1
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
#line 188 "bison.y"
                                                                        {
			if(strcmp((yyvsp[-5].st).s, (yyvsp[-1].st).s) == 0){
				printf("de super puta madre socio");
			} else {
				printf("tonto");
			}
			printf("%s", "procline");}
#line 1852 "y.tab.c"
    break;

  case 5:
#line 199 "bison.y"
                  {}
#line 1858 "y.tab.c"
    break;

  case 6:
#line 200 "bison.y"
          {}
#line 1864 "y.tab.c"
    break;

  case 7:
#line 204 "bison.y"
        {(yyval.st).s = "Declaracion de variable Integer igual a variable"; 
	if(searchVar(tabla, size, (yyvsp[-6].st).s) && checkVarAndType(tabla, size, (yyvsp[-1].st).s,"integer")) {
			insertElement(tabla, &size, retrieveIntFromTable(tabla, size, (yyvsp[-1].st).s), "", 0.0, (yyvsp[-6].st).s, false, &elementosOcupados, "integer", true );
			(yyval.st).a = assignAST((yyvsp[-1].st).a);
		} else {yyerror("Variable declared or wrong type");}
	}
#line 1875 "y.tab.c"
    break;

  case 8:
#line 210 "bison.y"
                                                                                      {
			(yyval.st).s = "Declaracion de variable Integer igual a variable integer + variable integer"; 
			if(searchVar(tabla, size, (yyvsp[-8].st).s) && checkVarAndType(tabla, size, (yyvsp[-3].st).s, "integer") && checkVarAndType(tabla, size, (yyvsp[-1].st).s, "integer")) {
				(yyval.st).error = "empty";
				if(strcmp((yyvsp[-2].st).operador, "+") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, (yyvsp[-3].st).s) + retrieveIntFromTable(tabla, size, (yyvsp[-1].st).s), "", 0.0, (yyvsp[-8].st).s, false, &elementosOcupados, "integer", true ); }
				if(strcmp((yyvsp[-2].st).operador, "-") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, (yyvsp[-3].st).s) - retrieveIntFromTable(tabla, size, (yyvsp[-1].st).s), "", 0.0, (yyvsp[-8].st).s, false, &elementosOcupados, "integer", true ); }
				if(strcmp((yyvsp[-2].st).operador, "*") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, (yyvsp[-3].st).s) * retrieveIntFromTable(tabla, size, (yyvsp[-1].st).s), "", 0.0, (yyvsp[-8].st).s, false, &elementosOcupados, "integer", true ); }
				if(strcmp((yyvsp[-2].st).operador, "/") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, (yyvsp[-3].st).s) / retrieveIntFromTable(tabla, size, (yyvsp[-1].st).s), "", 0.0, (yyvsp[-8].st).s, false, &elementosOcupados, "integer", true ); }
				(yyval.st).a = assignAST(newast((yyvsp[-2].st).operador, (yyvsp[-3].st).a, (yyvsp[-1].st).a));
			} else {(yyval.st).error = "Variable declared or wrong type";}
		}
#line 1891 "y.tab.c"
    break;

  case 9:
#line 221 "bison.y"
                                                                                       {
			(yyval.st).s = "Declaracion de variable Integer igual a variable integer + operacion"; 
			if(searchVar(tabla, size, (yyvsp[-8].st).s) && checkVarAndType(tabla, size, (yyvsp[-3].st).s, "integer")) {
				(yyval.st).error = "empty";
				if(strcmp((yyvsp[-2].st).operador, "+") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, (yyvsp[-3].st).s) + (yyvsp[-1].st).i, "", 0.0, (yyvsp[-8].st).s, false, &elementosOcupados, "integer", true ); }
				if(strcmp((yyvsp[-2].st).operador, "-") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, (yyvsp[-3].st).s) - (yyvsp[-1].st).i, "", 0.0, (yyvsp[-8].st).s, false, &elementosOcupados, "integer", true ); }
				if(strcmp((yyvsp[-2].st).operador, "*") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, (yyvsp[-3].st).s) * (yyvsp[-1].st).i, "", 0.0, (yyvsp[-8].st).s, false, &elementosOcupados, "integer", true ); }
				if(strcmp((yyvsp[-2].st).operador, "/") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, (yyvsp[-3].st).s) / (yyvsp[-1].st).i, "", 0.0, (yyvsp[-8].st).s, false, &elementosOcupados, "integer", true ); }
				(yyval.st).a = assignAST(newast((yyvsp[-2].st).operador, (yyvsp[-3].st).a, (yyvsp[-1].st).a));
			} else {(yyval.st).error = "Variable declared or wrong type";}
		}
#line 1907 "y.tab.c"
    break;

  case 10:
#line 232 "bison.y"
                                                                                       {
			(yyval.st).s = "Declaracion de variable Integer igual a operacion + variable integer"; 
			if(searchVar(tabla, size, (yyvsp[-8].st).s) && checkVarAndType(tabla, size, (yyvsp[-3].st).s, "integer")) {
				(yyval.st).error = "empty";
				if(strcmp((yyvsp[-2].st).operador, "+") == 0) { insertElement(tabla, &size, (yyvsp[-1].st).i + retrieveIntFromTable(tabla, size, (yyvsp[-3].st).s), "", 0.0, (yyvsp[-8].st).s, false, &elementosOcupados, "integer", true ); }
				if(strcmp((yyvsp[-2].st).operador, "-") == 0) { insertElement(tabla, &size, (yyvsp[-1].st).i - retrieveIntFromTable(tabla, size, (yyvsp[-3].st).s), "", 0.0, (yyvsp[-8].st).s, false, &elementosOcupados, "integer", true ); }
				if(strcmp((yyvsp[-2].st).operador, "*") == 0) { insertElement(tabla, &size, (yyvsp[-1].st).i * retrieveIntFromTable(tabla, size, (yyvsp[-3].st).s), "", 0.0, (yyvsp[-8].st).s, false, &elementosOcupados, "integer", true ); }
				if(strcmp((yyvsp[-2].st).operador, "/") == 0) { insertElement(tabla, &size, (yyvsp[-1].st).i / retrieveIntFromTable(tabla, size, (yyvsp[-3].st).s), "", 0.0, (yyvsp[-8].st).s, false, &elementosOcupados, "integer", true ); }
				(yyval.st).a = assignAST(newast((yyvsp[-2].st).operador, (yyvsp[-3].st).a, (yyvsp[-1].st).a));
			} else {(yyval.st).error = "Variable declared or wrong type";}
		}
#line 1923 "y.tab.c"
    break;

  case 11:
#line 243 "bison.y"
                                                                     {
			(yyval.st).s = "Declaracion de variable Integer igual a operacion aritmetica"; 
			if (searchVar(tabla, size, (yyvsp[-6].st).s)) {
				(yyval.st).error = "empty";insertElement(tabla, &size, (yyvsp[-1].st).i, "", 0.0, (yyvsp[-6].st).s, false, &elementosOcupados, "integer", true );(yyval.st).a = assignAST((yyvsp[-1].st).a);} else {(yyval.st).error = "Variable declared or wrong type";}
	 	}
#line 1933 "y.tab.c"
    break;

  case 12:
#line 249 "bison.y"
                                               {
		(yyval.st).s = "Declaracion de variable Integer vacia";
		if (searchVar(tabla, size, (yyvsp[-3].st).s)) {
				(yyval.st).error = "empty";insertElement(tabla, &size, 0, "", 0.0, (yyvsp[-3].st).s, false, &elementosOcupados, "integer", false );} else {(yyval.st).error = "Variable declared";}
	}
#line 1943 "y.tab.c"
    break;

  case 13:
#line 255 "bison.y"
                                                                  {
			{(yyval.st).s = "Declaracion de variable Float igual a variable float"; 
				if(searchVar(tabla, size, (yyvsp[-6].st).s) && checkVarAndType(tabla, size, (yyvsp[-1].st).s,"float")) {
				(yyval.st).error = "empty";
					insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, (yyvsp[-1].st).s), (yyvsp[-6].st).s, false, &elementosOcupados, "float", true );
					(yyval.st).a = assignAST((yyvsp[-1].st).a);
				} else {(yyval.st).error = "Variable declared or wrong type";}
			}
		}
#line 1957 "y.tab.c"
    break;

  case 14:
#line 264 "bison.y"
                                                                                    {
			(yyval.st).s = "Declaracion de variable float igual a variable float + variable float"; 
			if(searchVar(tabla, size, (yyvsp[-8].st).s) && checkVarAndType(tabla, size, (yyvsp[-3].st).s, "float") && checkVarAndType(tabla, size, (yyvsp[-1].st).s, "float")) {
				(yyval.st).error = "empty";
				if(strcmp((yyvsp[-2].st).operador, "+") == 0) { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, (yyvsp[-3].st).s) + retrieveFloatFromTable(tabla, size, (yyvsp[-1].st).s), (yyvsp[-8].st).s, false, &elementosOcupados, "float", true ); }
				if(strcmp((yyvsp[-2].st).operador, "-") == 0) { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, (yyvsp[-3].st).s) - retrieveFloatFromTable(tabla, size, (yyvsp[-1].st).s), (yyvsp[-8].st).s, false, &elementosOcupados, "float", true ); }
				if(strcmp((yyvsp[-2].st).operador, "*") == 0) { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, (yyvsp[-3].st).s) * retrieveFloatFromTable(tabla, size, (yyvsp[-1].st).s), (yyvsp[-8].st).s, false, &elementosOcupados, "float", true ); }
				if(strcmp((yyvsp[-2].st).operador, "/") == 0) { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, (yyvsp[-3].st).s) / retrieveFloatFromTable(tabla, size, (yyvsp[-1].st).s), (yyvsp[-8].st).s, false, &elementosOcupados, "float", true ); }
				(yyval.st).a = assignAST(newast((yyvsp[-2].st).operador, (yyvsp[-3].st).a, (yyvsp[-1].st).a));
			} else {(yyval.st).error = "Variable declared or wrong type";}
		}
#line 1973 "y.tab.c"
    break;

  case 15:
#line 275 "bison.y"
                                                                                      {
			(yyval.st).s = "Declaracion de variable float igual a variable float + operacion"; 
			if(searchVar(tabla, size, (yyvsp[-8].st).s) && checkVarAndType(tabla, size, (yyvsp[-3].st).s, "float")) {
				(yyval.st).error = "empty";
				if(strcmp((yyvsp[-2].st).operador, "+") == 0) { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, (yyvsp[-3].st).s) + (yyvsp[-1].st).f, (yyvsp[-8].st).s, false, &elementosOcupados, "float", true ); }
				if(strcmp((yyvsp[-2].st).operador, "-") == 0) { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, (yyvsp[-3].st).s) - (yyvsp[-1].st).f, (yyvsp[-8].st).s, false, &elementosOcupados, "float", true ); }
				if(strcmp((yyvsp[-2].st).operador, "*") == 0) { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, (yyvsp[-3].st).s) * (yyvsp[-1].st).f, (yyvsp[-8].st).s, false, &elementosOcupados, "float", true ); }
				if(strcmp((yyvsp[-2].st).operador, "/") == 0) { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, (yyvsp[-3].st).s) / (yyvsp[-1].st).f, (yyvsp[-8].st).s, false, &elementosOcupados, "float", true ); }
				(yyval.st).a = assignAST(newast((yyvsp[-2].st).operador, (yyvsp[-3].st).a, (yyvsp[-1].st).a));
			} else {(yyval.st).error = "Variable declared or wrong type";}
		}
#line 1989 "y.tab.c"
    break;

  case 16:
#line 286 "bison.y"
                                                                                      {
			(yyval.st).s = "Declaracion de variable float igual a operacion + variable float"; 
			if(searchVar(tabla, size, (yyvsp[-8].st).s) && checkVarAndType(tabla, size, (yyvsp[-3].st).s, "float")) {
				(yyval.st).error = "empty";
				if(strcmp((yyvsp[-2].st).operador, "+") == 0) { insertElement(tabla, &size, 0, "", (yyvsp[-1].st).f + retrieveFloatFromTable(tabla, size, (yyvsp[-3].st).s), (yyvsp[-8].st).s, false, &elementosOcupados, "float", true ); }
				if(strcmp((yyvsp[-2].st).operador, "-") == 0) { insertElement(tabla, &size, 0, "", (yyvsp[-1].st).f - retrieveFloatFromTable(tabla, size, (yyvsp[-3].st).s), (yyvsp[-8].st).s, false, &elementosOcupados, "float", true ); }
				if(strcmp((yyvsp[-2].st).operador, "*") == 0) { insertElement(tabla, &size, 0, "", (yyvsp[-1].st).f * retrieveFloatFromTable(tabla, size, (yyvsp[-3].st).s), (yyvsp[-8].st).s, false, &elementosOcupados, "float", true ); }
				if(strcmp((yyvsp[-2].st).operador, "/") == 0) { insertElement(tabla, &size, 0, "", (yyvsp[-1].st).f / retrieveFloatFromTable(tabla, size, (yyvsp[-3].st).s), (yyvsp[-8].st).s, false, &elementosOcupados, "float", true ); }
				(yyval.st).a = assignAST(newast((yyvsp[-2].st).operador, (yyvsp[-3].st).a, (yyvsp[-1].st).a));
			} else {(yyval.st).error = "Variable declared or wrong type";}
		}
#line 2005 "y.tab.c"
    break;

  case 17:
#line 298 "bison.y"
        {(yyval.st).s = "Declaracion de variable Float igual a operacion aritmetica";
	if(searchVar(tabla, size, (yyvsp[-6].st).s)) {
				(yyval.st).error = "empty"; insertElement(tabla, &size, 0, "", (yyvsp[-1].st).f, (yyvsp[-6].st).s, false, &elementosOcupados, "float", true );(yyval.st).a = assignAST((yyvsp[-1].st).a);} else {(yyval.st).error = "Variable declared or wrong type";}}
#line 2013 "y.tab.c"
    break;

  case 18:
#line 301 "bison.y"
                                             {
		(yyval.st).s = "Declaracion de variable float vacia";
		if (searchVar(tabla, size, (yyvsp[-3].st).s)) {
				(yyval.st).error = "empty";insertElement(tabla, &size, 0, "", 0.0, (yyvsp[-3].st).s, false, &elementosOcupados, "float", false );} else {(yyval.st).error = "Variable declared";}
	}
#line 2023 "y.tab.c"
    break;

  case 19:
#line 306 "bison.y"
                                                                    {
			if(searchVar(tabla, size, (yyvsp[-6].st).s) && checkVarAndType(tabla, size, (yyvsp[-1].st).s, "boolean")) {
				printf("comeme los huevos");
				(yyval.st).error = "empty";
				insertElement(tabla, &size, 0, "", 0.0, (yyvsp[-6].st).s, retrieveBoolFromTable(tabla, size, (yyvsp[-1].st).s), &elementosOcupados, "boolean", true );
				(yyval.st).a = assignAST((yyvsp[-1].st).a);
			} else {(yyval.st).error = "Variable declared or wrong type";}
			(yyval.st).s = "Declaracion de variable Boolean a operacion booleana";
		}
#line 2037 "y.tab.c"
    break;

  case 20:
#line 315 "bison.y"
                                                                      {
			if(strcmp((yyvsp[-1].st).error,"empty") == 0 ){
				if(searchVar(tabla, size, (yyvsp[-6].st).s)) {
					printf("comeme los huevos2");
					(yyval.st).error = "empty";
					insertElement(tabla, &size, 0, "", 0.0, (yyvsp[-6].st).s, (yyvsp[-1].st).boo ? true : false, &elementosOcupados, "boolean", true );
					(yyval.st).a = assignAST((yyvsp[-1].st).a);
				} else {(yyval.st).error = "Variable declared or wrong type";}
			} else {
				(yyval.st).error = (yyvsp[-1].st).error;
			}
			
			(yyval.st).s = "Declaracion de variable Boolean a operacion booleana";
		}
#line 2056 "y.tab.c"
    break;

  case 21:
#line 329 "bison.y"
                                               {
			(yyval.st).s = "Declaracion de variable Boolean vacia";
			if (searchVar(tabla, size, (yyvsp[-3].st).s)) {
			(yyval.st).error = "empty";insertElement(tabla, &size, 0, "", 0.0, (yyvsp[-3].st).s, false, &elementosOcupados, "boolean", false );} else {(yyval.st).error = "Variable declared";}
		}
#line 2066 "y.tab.c"
    break;

  case 22:
#line 334 "bison.y"
                                                                   {
			{(yyval.st).s = "Declaracion de variable String igual a variable String"; 
				if(searchVar(tabla, size, (yyvsp[-6].st).s) && checkVarAndType(tabla, size, (yyvsp[-1].st).s,"string")) {
					(yyval.st).error = "empty";
					insertElement(tabla, &size, 0, retrieveStringFromTable(tabla, size, (yyvsp[-1].st).s), 0.0, (yyvsp[-6].st).s, false, &elementosOcupados, "string", true );
					(yyval.st).a = assignAST((yyvsp[-1].st).a);
				} else {(yyval.st).error = "Variable declared or wrong type";}
			}
		}
#line 2080 "y.tab.c"
    break;

  case 23:
#line 344 "bison.y"
                {
			(yyval.st).s = "Declaracion con string";
			if(searchVar(tabla, size, (yyvsp[-6].st).s)) {
				(yyval.st).error = "empty"; insertElement(tabla, &size, 0, (yyvsp[-1].st).s, 0.0, (yyvsp[-6].st).s, false, &elementosOcupados, "string", true );(yyval.st).a = assignAST((yyvsp[-1].st).a);} else {(yyval.st).error = "Variable declared or wrong type";}
		}
#line 2090 "y.tab.c"
    break;

  case 24:
#line 349 "bison.y"
                                              {(yyval.st).s = "Declaracion de variable String";}
#line 2096 "y.tab.c"
    break;

  case 25:
#line 351 "bison.y"
                                                  {}
#line 2102 "y.tab.c"
    break;

  case 26:
#line 352 "bison.y"
                                                                    {}
#line 2108 "y.tab.c"
    break;

  case 27:
#line 353 "bison.y"
                                                                     {(yyval.st).s = "Variable igual a Variable operacion con operacion aritmetica";}
#line 2114 "y.tab.c"
    break;

  case 28:
#line 354 "bison.y"
                                                                      {}
#line 2120 "y.tab.c"
    break;

  case 29:
#line 355 "bison.y"
                                                                     {}
#line 2126 "y.tab.c"
    break;

  case 30:
#line 356 "bison.y"
                                                                      {}
#line 2132 "y.tab.c"
    break;

  case 31:
#line 357 "bison.y"
                                                   {}
#line 2138 "y.tab.c"
    break;

  case 32:
#line 358 "bison.y"
                                                    {}
#line 2144 "y.tab.c"
    break;

  case 33:
#line 359 "bison.y"
                                                                      {}
#line 2150 "y.tab.c"
    break;

  case 34:
#line 360 "bison.y"
                                                                 {}
#line 2156 "y.tab.c"
    break;

  case 35:
#line 361 "bison.y"
                                                                   {}
#line 2162 "y.tab.c"
    break;

  case 36:
#line 362 "bison.y"
                                                                 {}
#line 2168 "y.tab.c"
    break;

  case 37:
#line 363 "bison.y"
                                                                   {}
#line 2174 "y.tab.c"
    break;

  case 38:
#line 364 "bison.y"
                                                    {}
#line 2180 "y.tab.c"
    break;

  case 39:
#line 365 "bison.y"
                                                     {}
#line 2186 "y.tab.c"
    break;

  case 40:
#line 366 "bison.y"
                                                {}
#line 2192 "y.tab.c"
    break;

  case 41:
#line 368 "bison.y"
                                                          {}
#line 2198 "y.tab.c"
    break;

  case 42:
#line 369 "bison.y"
                                                                                     {}
#line 2204 "y.tab.c"
    break;

  case 43:
#line 370 "bison.y"
                                                                              {}
#line 2210 "y.tab.c"
    break;

  case 44:
#line 378 "bison.y"
                 {printf("Contenido: %s\t Linea: %d\n", (yyvsp[0].st).s, yylineno); if(!(yyvsp[0].st).a){ ;} else {eval(*(yyvsp[0].st).a, &size);};}
#line 2216 "y.tab.c"
    break;

  case 45:
#line 379 "bison.y"
                      {printf("%s", "$1.s");}
#line 2222 "y.tab.c"
    break;

  case 46:
#line 380 "bison.y"
                       {printf("%s", (yyvsp[0].st).s);}
#line 2228 "y.tab.c"
    break;

  case 47:
#line 381 "bison.y"
                 {printf("%s", (yyvsp[0].sval));}
#line 2234 "y.tab.c"
    break;

  case 48:
#line 382 "bison.y"
               {printf("Contenido: %s\t Linea: %d\n", (yyvsp[0].sval), yylineno); }
#line 2240 "y.tab.c"
    break;

  case 49:
#line 383 "bison.y"
               {if(strcmp((yyvsp[0].st).error, "empty") == 0){printf("Contenido: %s\t Linea: %d\n", (yyvsp[0].st).s, yylineno); if(!(yyvsp[0].st).a){ ;} else {eval(*(yyvsp[0].st).a, &size);};} else {yyerror((yyvsp[0].st).error);}}
#line 2246 "y.tab.c"
    break;

  case 50:
#line 387 "bison.y"
             {(yyval.st).operador = "+";}
#line 2252 "y.tab.c"
    break;

  case 51:
#line 388 "bison.y"
                {(yyval.st).operador = "-";}
#line 2258 "y.tab.c"
    break;

  case 52:
#line 389 "bison.y"
                   {(yyval.st).operador = "*";}
#line 2264 "y.tab.c"
    break;

  case 53:
#line 390 "bison.y"
                 {(yyval.st).operador = "/";}
#line 2270 "y.tab.c"
    break;

  case 54:
#line 394 "bison.y"
                {(yyval.st).i = (yyvsp[0].st).i; (yyval.st).a = createNum((yyvsp[0].st).i);}
#line 2276 "y.tab.c"
    break;

  case 55:
#line 395 "bison.y"
                                        {(yyval.st).i = (yyvsp[-2].st).i + (yyvsp[0].st).i; (yyval.st).a = newast("+",(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2282 "y.tab.c"
    break;

  case 56:
#line 396 "bison.y"
                                        {(yyval.st).i = (yyvsp[-2].st).i - (yyvsp[0].st).i; (yyval.st).a = newast("-",(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2288 "y.tab.c"
    break;

  case 57:
#line 397 "bison.y"
                                        {(yyval.st).i = (yyvsp[-2].st).i * (yyvsp[0].st).i; (yyval.st).a = newast("*",(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2294 "y.tab.c"
    break;

  case 58:
#line 398 "bison.y"
                                        {(yyval.st).i = (yyvsp[-2].st).i / (yyvsp[0].st).i; (yyval.st).a = newast("/",(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2300 "y.tab.c"
    break;

  case 59:
#line 399 "bison.y"
                               {(yyval.st).i = (yyvsp[-1].st).i;}
#line 2306 "y.tab.c"
    break;

  case 60:
#line 403 "bison.y"
              {(yyval.st).f = (yyvsp[0].fval); (yyval.st).a = createNum((yyvsp[0].fval));}
#line 2312 "y.tab.c"
    break;

  case 61:
#line 404 "bison.y"
                                                {(yyval.st).f = (yyvsp[-2].st).f + (yyvsp[0].st).f; (yyval.st).a = newast((yyvsp[-1].sval),(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2318 "y.tab.c"
    break;

  case 62:
#line 405 "bison.y"
                                        {(yyval.st).f = (yyvsp[-2].st).f - (yyvsp[0].st).f; (yyval.st).a = newast((yyvsp[-1].sval),(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2324 "y.tab.c"
    break;

  case 63:
#line 406 "bison.y"
                                                {(yyval.st).f = (yyvsp[-2].st).f * (yyvsp[0].st).f; (yyval.st).a = newast((yyvsp[-1].sval),(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2330 "y.tab.c"
    break;

  case 64:
#line 407 "bison.y"
                                        {(yyval.st).f = (yyvsp[-2].st).f / (yyvsp[0].st).f; (yyval.st).a = newast((yyvsp[-1].sval),(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2336 "y.tab.c"
    break;

  case 65:
#line 408 "bison.y"
                                {(yyval.st).f = (yyvsp[-1].st).f;}
#line 2342 "y.tab.c"
    break;

  case 66:
#line 413 "bison.y"
                {(yyval.st).s = "IGUAL";(yyval.st).operador = "==";}
#line 2348 "y.tab.c"
    break;

  case 67:
#line 414 "bison.y"
               {(yyval.st).s = "MAYOR";(yyval.st).operador = ">";}
#line 2354 "y.tab.c"
    break;

  case 68:
#line 415 "bison.y"
               {(yyval.st).s = "MENOR";(yyval.st).operador = "<";}
#line 2360 "y.tab.c"
    break;

  case 69:
#line 416 "bison.y"
                       {(yyval.st).s = "MAYOR IGUAL";(yyval.st).operador = ">=";}
#line 2366 "y.tab.c"
    break;

  case 70:
#line 417 "bison.y"
                      {(yyval.st).s = "MENOR IGUAL";(yyval.st).operador = "<=";}
#line 2372 "y.tab.c"
    break;

  case 71:
#line 418 "bison.y"
                    {(yyval.st).s = "DESIGUAL";(yyval.st).operador = "!=";}
#line 2378 "y.tab.c"
    break;

  case 72:
#line 422 "bison.y"
             {(yyval.st).boo=1; (yyval.st).a = createBOOLVAR("True");}
#line 2384 "y.tab.c"
    break;

  case 73:
#line 423 "bison.y"
                {(yyval.st).boo=0; (yyval.st).a = createBOOLVAR("False");}
#line 2390 "y.tab.c"
    break;

  case 74:
#line 434 "bison.y"
                                                                {(yyval.st).s = "INT OP BOOL INT";(yyval.st).boo = compare((yyvsp[-1].st).operador, (float)(yyvsp[-2].st).i, (float)(yyvsp[0].st).i); (yyval.st).a=newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a); }
#line 2396 "y.tab.c"
    break;

  case 75:
#line 435 "bison.y"
                                                                        {(yyval.st).s = "INT OP BOOL FLOAT";(yyval.st).boo = compare((yyvsp[-1].st).operador, (float)(yyvsp[-2].st).i, (yyvsp[0].st).f); (yyval.st).a=newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a);}
#line 2402 "y.tab.c"
    break;

  case 76:
#line 436 "bison.y"
                                                                        {(yyval.st).s = "FLOAT OP BOOL INT";(yyval.st).boo = compare((yyvsp[-1].st).operador, (yyvsp[-2].st).f, (float)(yyvsp[0].st).i); (yyval.st).a=newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a);}
#line 2408 "y.tab.c"
    break;

  case 77:
#line 437 "bison.y"
                                                                        {(yyval.st).s = "FLOAT OP BOOL FLOAT"; (yyval.st).boo = compare((yyvsp[-1].st).operador, (yyvsp[-2].st).f, (yyvsp[0].st).f); (yyval.st).a=newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a);}
#line 2414 "y.tab.c"
    break;

  case 78:
#line 438 "bison.y"
                                                                {
			(yyval.st).s = "VAR OP BOOL INT";
			if(!searchVar(tabla, size, (yyvsp[-2].st).s)) {
				(yyval.st).error = "empty";
				if(strcmp("integer", getVarType(tabla, size, (yyvsp[-2].st).s)) == 0){
					(yyval.st).boo = compare((yyvsp[-1].st).operador, (float)retrieveIntFromTable(tabla, size, (yyvsp[-2].st).s), (float)(yyvsp[0].st).i);
					(yyval.st).a=newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a);
				} else if(strcmp("float", getVarType(tabla, size, (yyvsp[-2].st).s))  == 0){
					(yyval.st).boo = compare((yyvsp[-1].st).operador, retrieveFloatFromTable(tabla, size, (yyvsp[-2].st).s), (float)(yyvsp[0].st).i);
					(yyval.st).a=newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a);
				} else {
					(yyval.st).error = "Esta variable tiene un tipo incorrecto";
				}  
				
			} else {(yyval.st).error = "Variable declared or wrong type";}
		}
#line 2435 "y.tab.c"
    break;

  case 79:
#line 454 "bison.y"
                                                                {(yyval.st).s = "INT OP BOOL INT";(yyval.st).boo = compare((yyvsp[-1].st).operador, (float)(yyvsp[-2].st).i, (float)(yyvsp[0].st).i); (yyval.st).a=newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a);}
#line 2441 "y.tab.c"
    break;

  case 80:
#line 455 "bison.y"
                                                                        {(yyval.st).s = "FLOAT OP BOOL FLOAT";(yyval.st).boo = compare((yyvsp[-1].st).operador, (float)(yyvsp[-2].st).i, (yyvsp[0].st).f); (yyval.st).a=newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a);}
#line 2447 "y.tab.c"
    break;

  case 81:
#line 456 "bison.y"
                                                                        {(yyval.st).s = "FLOAT OP BOOL FLOAT";(yyval.st).boo = compare((yyvsp[-1].st).operador, (yyvsp[-2].st).f, (float)(yyvsp[0].st).i); (yyval.st).a=newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a);}
#line 2453 "y.tab.c"
    break;

  case 82:
#line 457 "bison.y"
                                                                {(yyval.st).s = "VAR OP BOOL VAR";(yyval.st).boo = compare((yyvsp[-1].st).operador, (float)(yyvsp[-2].st).i, (float)(yyvsp[0].st).i); (yyval.st).a=newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a);}
#line 2459 "y.tab.c"
    break;

  case 83:
#line 458 "bison.y"
                                        {(yyval.st).s = "PARENTESIS BOOL PARENTESIS"; }
#line 2465 "y.tab.c"
    break;

  case 84:
#line 462 "bison.y"
                {(yyval.sval) = "Comentario\n";}
#line 2471 "y.tab.c"
    break;

  case 85:
#line 466 "bison.y"
                                {(yyval.st).s = "IF BOOL THEN";}
#line 2477 "y.tab.c"
    break;

  case 86:
#line 467 "bison.y"
                                                {(yyval.st).s = "ELSE";}
#line 2483 "y.tab.c"
    break;

  case 87:
#line 468 "bison.y"
                                {(yyval.st).s = "ELSEIF BOOL THEN";}
#line 2489 "y.tab.c"
    break;

  case 88:
#line 469 "bison.y"
                                        {(yyval.st).s = "END IF SEMICOLON";}
#line 2495 "y.tab.c"
    break;

  case 89:
#line 474 "bison.y"
                               {(yyval.sval) = "Bucle while\n";}
#line 2501 "y.tab.c"
    break;

  case 90:
#line 475 "bison.y"
                              {(yyval.sval)="Fin de bucle\n";}
#line 2507 "y.tab.c"
    break;

  case 91:
#line 484 "bison.y"
            {(yyval.st).s = (yyvsp[0].sval); (yyval.st).a = createSTR((yyvsp[0].sval));}
#line 2513 "y.tab.c"
    break;

  case 92:
#line 488 "bison.y"
            {(yyval.st).s = (yyvsp[0].sval); (yyval.st).a = createSTR((yyvsp[0].sval));}
#line 2519 "y.tab.c"
    break;


#line 2523 "y.tab.c"

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
#line 493 "bison.y"

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
    int elementIndex = -1;
    while (i < *size && elementIndex == -1) {
        if (strcmp(tabla[i].vname, nombre) == 0 && (strcmp(tabla[i].type, tipo) == 0 )) {
            elementIndex = i;
        }else if(strcmp(tabla[i].vname, nombre) == 0){ 
        	elementIndex = i;
        }else {
            i++;
        }
    }
    return elementIndex;
}


void insertElement(struct symb *tabla, int *size, int valor, char* svalor, float fvalor, char *variable, bool bvalor, int *elementosOcupados, char* type, bool assigned ) {
	int elementIndex = 0;
	
    elementIndex = buscarValor(tabla, variable, type, size);

    if(elementIndex != -1){
    	if (strcmp(type, "integer") == 0){
	        		tabla[elementIndex].vname = variable;
	        		tabla[elementIndex].vvali = valor;
	        		tabla[elementIndex].type = type;
	            } else if (strcmp(type, "float") == 0) {
	                tabla[elementIndex].vname = variable;
	                tabla[elementIndex].vvalf = fvalor;
	                tabla[elementIndex].type = type;
	            } else if (strcmp(type, "string") == 0) {
	                tabla[elementIndex].vname = variable;
	                tabla[elementIndex].vvals = svalor;
	                tabla[elementIndex].type = type;
	            } else if (strcmp(type, "boolean") == 0) {
									tabla[elementIndex].vname = variable;
	                tabla[elementIndex].vbool = bvalor;
	                tabla[elementIndex].type = type;
							}
			tabla[elementIndex].assigned = assigned; 	
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
	            } else if (strcmp(type, "boolean") == 0) {
	                tabla[i].vname = variable;
	                tabla[i].vbool = bvalor;
	                tabla[i].type = type;
	                *elementosOcupados = *elementosOcupados + 1;
	                encontrado = 1;
	            }        	
	            tabla[i].assigned = assigned; 
	            *elementosOcupados = *elementosOcupados + 1;
	            encontrado = 1;
	        } else {
	            i++;
	        }
	    }
    }
		
     
}

int compare(char* operator, float left, float right) {
	if(strcmp(operator,">") == 0){
		return left > right ? 1 : 0;
	} else if(strcmp(operator,"<") == 0){
		return left < right ? 1 : 0;
	} else if(strcmp(operator,">=") == 0){
		return left >= right ? 1 : 0;
	} else if(strcmp(operator,"<=") == 0){
		return left <= right ? 1 : 0;
	} else if(strcmp(operator,"==") == 0){
		return left == right ? 1 : 0;
	} else if(strcmp(operator,"!=") == 0){
		return left != right ? 1 : 0;
	}  
	
}

char* getVarType(struct symb *tabla, int size, char* name) {
	printf("%s\n",name);
	for(int i = 0; i < size; i++) {
		if(strcmp(tabla[i].vname, "._empty") == 0){
			continue;
		} else if (strcmp(tabla[i].vname, name) == 0) {
			printf("%s\n", tabla[i].type);
			return tabla[i].type;
		}
	}
}

bool searchVar(struct symb *tabla, int size, char* name) {
	int elementIndex = -1;
	for(int i = 0; i < size; i++) {
		if(strcmp(tabla[i].vname, "._empty") == 0){
			continue;
		} else if (strcmp(tabla[i].vname, name) == 0) {
			elementIndex = i;
			break;
		}
	}

	if (elementIndex != -1) {
		return false;
	}

	return true;
}

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

bool retrieveBoolFromTable(struct symb *tabla, int size, char* name) {
	int elementIndex = -1;
	for(int i = 0; i < size; i++) {
		if(strcmp(tabla[i].vname, name) == 0) {
			elementIndex = i;
			break;
		}
	}

	return tabla[elementIndex].vbool;
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
		printf("Nombre\t%s\t",tabla[b].vname);
		printf("INT\t%i\t",tabla[b].vvali);
		printf("FLOAT\t%f\t",tabla[b].vvalf);
		printf("STRING\t%s\t",tabla[b].vvals);
		printf("TIPO\t%s\t",tabla[b].type);
		printf("BOOLEAN\t%s\t",tabla[b].vbool ? "true" : "false");
		printf("ASSIGNED\t%s\t",tabla[b].assigned ? "true" : "false");
		printf("\n");

	}
	printAST(nodos,0,0,0);
}
