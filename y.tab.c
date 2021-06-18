/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

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
int operateInt(char* operator, int left, int right);
float operateFloat(char* operator, float left, float right);

bool checkVarAndType(struct symb *tabla, int size, char* name, char* type);
bool searchVar(struct symb *tabla, int size, char* name);
int compare(char* operator, float left, float right);

void eval(struct ast a, int* size);
void printAST(struct ast nodos[], int i, int encontrado, int salida);

#line 182 "y.tab.c"

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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    PLUS = 260,                    /* PLUS  */
    MINUS = 261,                   /* MINUS  */
    MULTIPLY = 262,                /* MULTIPLY  */
    DIVIDE = 263,                  /* DIVIDE  */
    LEFT = 264,                    /* LEFT  */
    RIGHT = 265,                   /* RIGHT  */
    OPEN = 266,                    /* OPEN  */
    CLOSE = 267,                   /* CLOSE  */
    WHILE = 268,                   /* WHILE  */
    BOOL = 269,                    /* BOOL  */
    CASE = 270,                    /* CASE  */
    INTEGERDEC = 271,              /* INTEGERDEC  */
    FLOATDEC = 272,                /* FLOATDEC  */
    CHARDEC = 273,                 /* CHARDEC  */
    STRINGDEC = 274,               /* STRINGDEC  */
    BEG = 275,                     /* BEG  */
    STR = 276,                     /* STR  */
    LOOP_ = 277,                   /* LOOP_  */
    END = 278,                     /* END  */
    IF = 279,                      /* IF  */
    THEN = 280,                    /* THEN  */
    CHAR = 281,                    /* CHAR  */
    AND = 282,                     /* AND  */
    OR = 283,                      /* OR  */
    ELSE = 284,                    /* ELSE  */
    ELSEIF = 285,                  /* ELSEIF  */
    PROCEDURE = 286,               /* PROCEDURE  */
    IS = 287,                      /* IS  */
    LESS = 288,                    /* LESS  */
    MORE = 289,                    /* MORE  */
    EQUAL = 290,                   /* EQUAL  */
    GREATER_THAN = 291,            /* GREATER_THAN  */
    LESSER_THAN = 292,             /* LESSER_THAN  */
    NOT_EQUAL = 293,               /* NOT_EQUAL  */
    COMPARE = 294,                 /* COMPARE  */
    COMMENT = 295,                 /* COMMENT  */
    COLON = 296,                   /* COLON  */
    SEMICOLON = 297,               /* SEMICOLON  */
    QUOTE = 298,                   /* QUOTE  */
    NEWLINE = 299,                 /* NEWLINE  */
    QUIT = 300,                    /* QUIT  */
    TRUE = 301,                    /* TRUE  */
    FALSE = 302,                   /* FALSE  */
    TYPE = 303,                    /* TYPE  */
    RANGE = 304,                   /* RANGE  */
    DOTDOT = 305,                  /* DOTDOT  */
    OF = 306,                      /* OF  */
    COMMA = 307,                   /* COMMA  */
    WHEN = 308,                    /* WHEN  */
    FOR = 309,                     /* FOR  */
    OTHERS = 310,                  /* OTHERS  */
    ARROW = 311,                   /* ARROW  */
    VAR = 312,                     /* VAR  */
    DECLINTEGER = 313,             /* DECLINTEGER  */
    DECLFLOAT = 314,               /* DECLFLOAT  */
    DECLBOOLEAN = 315,             /* DECLBOOLEAN  */
    DECLARRAY = 316,               /* DECLARRAY  */
    DECLSTRING = 317               /* DECLSTRING  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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
#define PROCEDURE 286
#define IS 287
#define LESS 288
#define MORE 289
#define EQUAL 290
#define GREATER_THAN 291
#define LESSER_THAN 292
#define NOT_EQUAL 293
#define COMPARE 294
#define COMMENT 295
#define COLON 296
#define SEMICOLON 297
#define QUOTE 298
#define NEWLINE 299
#define QUIT 300
#define TRUE 301
#define FALSE 302
#define TYPE 303
#define RANGE 304
#define DOTDOT 305
#define OF 306
#define COMMA 307
#define WHEN 308
#define FOR 309
#define OTHERS 310
#define ARROW 311
#define VAR 312
#define DECLINTEGER 313
#define DECLFLOAT 314
#define DECLBOOLEAN 315
#define DECLARRAY 316
#define DECLSTRING 317

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 113 "bison.y"

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

#line 381 "y.tab.c"

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
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_PLUS = 5,                       /* PLUS  */
  YYSYMBOL_MINUS = 6,                      /* MINUS  */
  YYSYMBOL_MULTIPLY = 7,                   /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 8,                     /* DIVIDE  */
  YYSYMBOL_LEFT = 9,                       /* LEFT  */
  YYSYMBOL_RIGHT = 10,                     /* RIGHT  */
  YYSYMBOL_OPEN = 11,                      /* OPEN  */
  YYSYMBOL_CLOSE = 12,                     /* CLOSE  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_BOOL = 14,                      /* BOOL  */
  YYSYMBOL_CASE = 15,                      /* CASE  */
  YYSYMBOL_INTEGERDEC = 16,                /* INTEGERDEC  */
  YYSYMBOL_FLOATDEC = 17,                  /* FLOATDEC  */
  YYSYMBOL_CHARDEC = 18,                   /* CHARDEC  */
  YYSYMBOL_STRINGDEC = 19,                 /* STRINGDEC  */
  YYSYMBOL_BEG = 20,                       /* BEG  */
  YYSYMBOL_STR = 21,                       /* STR  */
  YYSYMBOL_LOOP_ = 22,                     /* LOOP_  */
  YYSYMBOL_END = 23,                       /* END  */
  YYSYMBOL_IF = 24,                        /* IF  */
  YYSYMBOL_THEN = 25,                      /* THEN  */
  YYSYMBOL_CHAR = 26,                      /* CHAR  */
  YYSYMBOL_AND = 27,                       /* AND  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_ELSE = 29,                      /* ELSE  */
  YYSYMBOL_ELSEIF = 30,                    /* ELSEIF  */
  YYSYMBOL_PROCEDURE = 31,                 /* PROCEDURE  */
  YYSYMBOL_IS = 32,                        /* IS  */
  YYSYMBOL_LESS = 33,                      /* LESS  */
  YYSYMBOL_MORE = 34,                      /* MORE  */
  YYSYMBOL_EQUAL = 35,                     /* EQUAL  */
  YYSYMBOL_GREATER_THAN = 36,              /* GREATER_THAN  */
  YYSYMBOL_LESSER_THAN = 37,               /* LESSER_THAN  */
  YYSYMBOL_NOT_EQUAL = 38,                 /* NOT_EQUAL  */
  YYSYMBOL_COMPARE = 39,                   /* COMPARE  */
  YYSYMBOL_COMMENT = 40,                   /* COMMENT  */
  YYSYMBOL_COLON = 41,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 42,                 /* SEMICOLON  */
  YYSYMBOL_QUOTE = 43,                     /* QUOTE  */
  YYSYMBOL_NEWLINE = 44,                   /* NEWLINE  */
  YYSYMBOL_QUIT = 45,                      /* QUIT  */
  YYSYMBOL_TRUE = 46,                      /* TRUE  */
  YYSYMBOL_FALSE = 47,                     /* FALSE  */
  YYSYMBOL_TYPE = 48,                      /* TYPE  */
  YYSYMBOL_RANGE = 49,                     /* RANGE  */
  YYSYMBOL_DOTDOT = 50,                    /* DOTDOT  */
  YYSYMBOL_OF = 51,                        /* OF  */
  YYSYMBOL_COMMA = 52,                     /* COMMA  */
  YYSYMBOL_WHEN = 53,                      /* WHEN  */
  YYSYMBOL_FOR = 54,                       /* FOR  */
  YYSYMBOL_OTHERS = 55,                    /* OTHERS  */
  YYSYMBOL_ARROW = 56,                     /* ARROW  */
  YYSYMBOL_VAR = 57,                       /* VAR  */
  YYSYMBOL_DECLINTEGER = 58,               /* DECLINTEGER  */
  YYSYMBOL_DECLFLOAT = 59,                 /* DECLFLOAT  */
  YYSYMBOL_DECLBOOLEAN = 60,               /* DECLBOOLEAN  */
  YYSYMBOL_DECLARRAY = 61,                 /* DECLARRAY  */
  YYSYMBOL_DECLSTRING = 62,                /* DECLSTRING  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_PROCLINE = 64,                  /* PROCLINE  */
  YYSYMBOL_ADDCONTENT = 65,                /* ADDCONTENT  */
  YYSYMBOL_AUXOPER = 66,                   /* AUXOPER  */
  YYSYMBOL_TYPEDECLARATION = 67,           /* TYPEDECLARATION  */
  YYSYMBOL_DECL = 68,                      /* DECL  */
  YYSYMBOL_AUXCOMPLETO = 69,               /* AUXCOMPLETO  */
  YYSYMBOL_CONTENT = 70,                   /* CONTENT  */
  YYSYMBOL_OPERATOR = 71,                  /* OPERATOR  */
  YYSYMBOL_OPERAND = 72,                   /* OPERAND  */
  YYSYMBOL_OPERATION = 73,                 /* OPERATION  */
  YYSYMBOL_BOOLEAN_OPERATORS = 74,         /* BOOLEAN_OPERATORS  */
  YYSYMBOL_AUX_BOOLEAN_OP = 75,            /* AUX_BOOLEAN_OP  */
  YYSYMBOL_BOOLEAN_MIX = 76,               /* BOOLEAN_MIX  */
  YYSYMBOL_BOOLEAN_OP = 77,                /* BOOLEAN_OP  */
  YYSYMBOL_COM = 78,                       /* COM  */
  YYSYMBOL_IF_COND = 79,                   /* IF_COND  */
  YYSYMBOL_WLOOP = 80,                     /* WLOOP  */
  YYSYMBOL_VAR_NAME = 81,                  /* VAR_NAME  */
  YYSYMBOL_STRING = 82                     /* STRING  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   198

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   317


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   194,   194,   203,   203,   210,   229,   265,   301,   338,
     357,   360,   367,   390,   410,   418,   433,   504,   513,   523,
     532,   540,   541,   545,   546,   547,   548,   549,   550,   554,
     555,   556,   557,   561,   562,   566,   571,   587,   603,   619,
     635,   640,   641,   642,   643,   644,   645,   649,   650,   655,
     664,   677,   695,   729,   762,   784,   785,   797,   798,   802,
     806,   807,   808,   809,   814,   815,   824,   828
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "PLUS",
  "MINUS", "MULTIPLY", "DIVIDE", "LEFT", "RIGHT", "OPEN", "CLOSE", "WHILE",
  "BOOL", "CASE", "INTEGERDEC", "FLOATDEC", "CHARDEC", "STRINGDEC", "BEG",
  "STR", "LOOP_", "END", "IF", "THEN", "CHAR", "AND", "OR", "ELSE",
  "ELSEIF", "PROCEDURE", "IS", "LESS", "MORE", "EQUAL", "GREATER_THAN",
  "LESSER_THAN", "NOT_EQUAL", "COMPARE", "COMMENT", "COLON", "SEMICOLON",
  "QUOTE", "NEWLINE", "QUIT", "TRUE", "FALSE", "TYPE", "RANGE", "DOTDOT",
  "OF", "COMMA", "WHEN", "FOR", "OTHERS", "ARROW", "VAR", "DECLINTEGER",
  "DECLFLOAT", "DECLBOOLEAN", "DECLARRAY", "DECLSTRING", "$accept",
  "PROCLINE", "ADDCONTENT", "AUXOPER", "TYPEDECLARATION", "DECL",
  "AUXCOMPLETO", "CONTENT", "OPERATOR", "OPERAND", "OPERATION",
  "BOOLEAN_OPERATORS", "AUX_BOOLEAN_OP", "BOOLEAN_MIX", "BOOLEAN_OP",
  "COM", "IF_COND", "WLOOP", "VAR_NAME", "STRING", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
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
     315,   316,   317
};
#endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-6)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -27,   -48,    23,   -76,    16,   -76,   -76,    27,   -76,   -76,
      13,    13,    -3,    13,   -76,    13,   -76,   -76,   -76,   -76,
     -76,   -76,   120,   -76,   -13,   -76,   -76,   -76,   110,    85,
       8,   134,     7,    10,    30,    39,    40,   -76,   -13,    57,
     171,   171,   171,   171,   -76,   -76,   -76,   -76,   -76,   -76,
       4,    13,    13,   -15,     4,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   171,    18,    18,   -76,   -76,   182,   -76,
     -76,   -76,    13,   -76,   -76,    -4,    21,    34,   182,   -76,
     176,   -76,    41,   127,   -76,    72,    63,   -76,    64,   -76,
      65,   -76,   -76,   171,   171,   171,   171,   -48,   -76,   -76,
     -76,   -76,     4,    13,   -18,     4,   -76,   182,   -76,    70,
     103,   -76,    71,    73,    74,   186,   190,   -76,   -76,   -76,
     -76,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    66,     0,     1,     4,     0,    33,    34,
       0,     0,     0,     0,    61,     0,    59,    57,    58,    28,
       3,    35,     0,    25,    24,    27,    23,    26,    56,     0,
       0,    56,     0,     0,     0,     0,     0,    47,    48,     0,
       0,     0,     0,     0,    43,    42,    44,    45,    46,    41,
       0,     0,     0,     0,     0,    40,    55,    64,    65,    63,
       2,    60,    62,     0,    36,    37,    38,    39,    51,    53,
      49,    50,     0,    10,    11,     0,     0,     0,    52,    54,
       0,    22,     0,     9,    21,    56,     0,    17,     0,    20,
       0,    13,    16,    29,    30,    31,    32,     0,    29,    30,
      31,    32,     0,     0,     0,     0,     8,     7,     6,     0,
      56,    67,     0,     0,     0,     9,     5,    15,    14,    18,
      19,    12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,   -76,     2,   -76,   -76,   -76,   -76,   -75,   -76,
      -8,   -17,   -14,   113,    17,   -76,   -76,   -76,    -1,   -76
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     7,    81,    77,    19,    82,    20,    97,    21,
      22,    54,    36,    37,    38,    25,    26,    27,    31,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       4,    39,    29,   111,     1,    50,    28,     8,     9,     3,
     102,    35,    50,    63,    51,    52,     8,     9,    56,    33,
      72,    34,    10,     5,    24,    42,    43,    30,    32,    57,
       8,     9,    64,    65,    66,    67,    10,    86,    87,     3,
      11,   102,    68,    73,    74,    75,    78,    76,     6,    69,
      12,    13,    58,    79,     3,    80,    14,    15,    84,    17,
      18,     3,    88,    89,    83,    61,    50,    16,    70,    71,
       3,    85,    59,    17,    18,    90,    91,    98,    99,   100,
     101,    60,    62,    92,     3,    64,    65,    66,    67,   109,
      40,    41,    42,    43,   107,    55,   106,   115,   103,   104,
     105,   108,   110,   112,   116,    44,    45,   114,    46,    47,
      48,    49,   117,   119,    -5,   120,   121,     0,    44,    45,
      23,    46,    47,    48,    49,    40,    41,    42,    43,     0,
       0,     0,    93,    94,    95,    96,    44,    45,     0,    46,
      47,    48,    49,    44,    45,   118,    46,    47,    48,    49,
       0,    53,     0,    44,    45,     0,    46,    47,    48,    49,
      44,    45,     0,    46,    47,    48,    49,    44,    45,     0,
      46,    47,    48,    49,     8,     9,     0,     0,     0,     0,
      63,    40,    41,    42,    43,     0,    55,    40,    41,    42,
      43,    93,    94,    95,    96,    98,    99,   100,   101
};

static const yytype_int8 yycheck[] =
{
       1,    15,    10,    21,    31,    22,     7,     3,     4,    57,
      85,    12,    29,     9,    27,    28,     3,     4,    10,    22,
      35,    24,     9,     0,     7,     7,     8,    10,    11,    22,
       3,     4,    40,    41,    42,    43,     9,    41,    42,    57,
      13,   116,    50,    58,    59,    60,    54,    62,    32,    50,
      23,    24,    42,    54,    57,    63,    29,    30,    72,    46,
      47,    57,    41,    42,    72,    25,    83,    40,    51,    52,
      57,    72,    42,    46,    47,    41,    42,     5,     6,     7,
       8,    42,    25,    42,    57,    93,    94,    95,    96,   103,
       5,     6,     7,     8,   102,    10,    97,   105,    35,    35,
      35,   102,   103,   104,   105,    33,    34,   105,    36,    37,
      38,    39,    42,    42,    42,    42,    42,    -1,    33,    34,
       7,    36,    37,    38,    39,     5,     6,     7,     8,    -1,
      -1,    -1,     5,     6,     7,     8,    33,    34,    -1,    36,
      37,    38,    39,    33,    34,    42,    36,    37,    38,    39,
      -1,    41,    -1,    33,    34,    -1,    36,    37,    38,    39,
      33,    34,    -1,    36,    37,    38,    39,    33,    34,    -1,
      36,    37,    38,    39,     3,     4,    -1,    -1,    -1,    -1,
       9,     5,     6,     7,     8,    -1,    10,     5,     6,     7,
       8,     5,     6,     7,     8,     5,     6,     7,     8
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    31,    64,    57,    81,     0,    32,    65,     3,     4,
       9,    13,    23,    24,    29,    30,    40,    46,    47,    68,
      70,    72,    73,    76,    77,    78,    79,    80,    81,    73,
      77,    81,    77,    22,    24,    81,    75,    76,    77,    75,
       5,     6,     7,     8,    33,    34,    36,    37,    38,    39,
      74,    27,    28,    41,    74,    10,    10,    22,    42,    42,
      42,    25,    25,     9,    73,    73,    73,    73,    73,    81,
      77,    77,    35,    58,    59,    60,    62,    67,    73,    81,
      73,    66,    69,    73,    75,    81,    41,    42,    41,    42,
      41,    42,    42,     5,     6,     7,     8,    71,     5,     6,
       7,     8,    71,    35,    35,    35,    81,    73,    81,    75,
      81,    21,    81,    82,    66,    73,    81,    42,    42,    42,
      42,    42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    66,    66,    66,    66,
      67,    67,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    69,    69,    70,    70,    70,    70,    70,    70,    71,
      71,    71,    71,    72,    72,    73,    73,    73,    73,    73,
      73,    74,    74,    74,    74,    74,    74,    75,    75,    76,
      76,    77,    77,    77,    77,    77,    77,    77,    77,    78,
      79,    79,    79,    79,    80,    80,    81,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     2,     0,     1,     3,     3,     3,     1,
       1,     1,     7,     4,     7,     7,     5,     4,     7,     7,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       3,     1,     3,     3,     3,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

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

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

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

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  case 2: /* PROCLINE: PROCEDURE VAR_NAME IS ADDCONTENT END VAR_NAME SEMICOLON  */
#line 194 "bison.y"
                                                                        {
			if(strcmp((yyvsp[-5].st).s, (yyvsp[-1].st).s) == 0){
				printf("procedure comienza y termina con el mismo nombre\n");
			} else {
				printf("procedure NO comienza y termina con el mismo nombre\n");
			}
		}
#line 1668 "y.tab.c"
    break;

  case 5: /* AUXOPER: VAR_NAME  */
#line 210 "bison.y"
                 {
		if(!searchVar(tabla, size, (yyvsp[0].st).s)) { 
			if(strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "integer")==0) {
				(yyval.st).i = retrieveIntFromTable(tabla, size, (yyvsp[0].st).s);
				(yyval.st).type = "integer";
				(yyval.st).a = assignAST((yyvsp[0].st).a);
				(yyval.st).error = "empty";
			} else if(strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "float")==0) {
				(yyval.st).f = retrieveFloatFromTable(tabla, size, (yyvsp[0].st).s);
				(yyval.st).type = "float";
				(yyval.st).a = assignAST((yyvsp[0].st).a);
				(yyval.st).error = "empty";
			} else {
				(yyval.st).error = "Variable de tipo incorrecto";
			}
			
		} else {yyerror("Variable not declared");}
	
	}
#line 1692 "y.tab.c"
    break;

  case 6: /* AUXOPER: VAR_NAME OPERATOR VAR_NAME  */
#line 229 "bison.y"
                                     {
		if(!searchVar(tabla, size, (yyvsp[-2].st).s) && !searchVar(tabla, size, (yyvsp[0].st).s)) { 
			if(strcmp(getVarType(tabla, size, (yyvsp[-2].st).s), "integer")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "integer")==0) {

				(yyval.st).i = operateInt((yyvsp[-1].st).operador, retrieveIntFromTable(tabla, size, (yyvsp[-2].st).s), retrieveIntFromTable(tabla, size, (yyvsp[0].st).s));
				(yyval.st).type = "integer";
				(yyval.st).a = assignAST(newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-2].st).s), "float")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "integer")==0) {

				(yyval.st).f = operateFloat((yyvsp[-1].st).operador, retrieveFloatFromTable(tabla, size, (yyvsp[-2].st).s), (float)retrieveIntFromTable(tabla, size, (yyvsp[0].st).s));
				(yyval.st).type = "float";
				(yyval.st).a = assignAST(newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-2].st).s), "integer")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "float")==0) {
				
				(yyval.st).f = operateFloat((yyvsp[-1].st).operador, (float)retrieveIntFromTable(tabla, size, (yyvsp[-2].st).s), retrieveFloatFromTable(tabla, size, (yyvsp[0].st).s));
				(yyval.st).type = "float";
				(yyval.st).a = assignAST(newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else if(strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "float")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "float")==0) {
				
				(yyval.st).f = operateFloat((yyvsp[-1].st).operador, retrieveFloatFromTable(tabla, size, (yyvsp[-2].st).s), retrieveFloatFromTable(tabla, size, (yyvsp[0].st).s));
				(yyval.st).type = "float";
				(yyval.st).a = assignAST(newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else {
				(yyval.st).error = "Variable de tipo incorrecto";
			}
			
		} else {yyerror("Variable not declared");}
	}
#line 1733 "y.tab.c"
    break;

  case 7: /* AUXOPER: VAR_NAME OPERATOR OPERATION  */
#line 265 "bison.y"
                                      {
		if(!searchVar(tabla, size, (yyvsp[-2].st).s)) { 
			if(strcmp(getVarType(tabla, size, (yyvsp[-2].st).s), "integer")==0 && strcmp((yyvsp[0].st).type, "integer")==0) {

				(yyval.st).i = operateInt((yyvsp[-1].st).operador, retrieveIntFromTable(tabla, size, (yyvsp[-2].st).s), (yyvsp[0].st).i);
				(yyval.st).type = "integer";
				(yyval.st).a = assignAST(newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-2].st).s), "float")==0 && strcmp((yyvsp[0].st).type, "integer")==0) {

				(yyval.st).f = operateFloat((yyvsp[-1].st).operador, retrieveFloatFromTable(tabla, size, (yyvsp[-2].st).s), (float)(yyvsp[0].st).i);
				(yyval.st).type = "float";
				(yyval.st).a = assignAST(newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-2].st).s), "integer")==0 && strcmp((yyvsp[0].st).type, "float")==0) {
				
				(yyval.st).f = operateFloat((yyvsp[-1].st).operador, (float)retrieveIntFromTable(tabla, size, (yyvsp[-2].st).s), (yyvsp[0].st).f);
				(yyval.st).type = "float";
				(yyval.st).a = assignAST(newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else if(strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "float")==0 && strcmp((yyvsp[0].st).type, "float")==0) {
				
				(yyval.st).f = operateFloat((yyvsp[-1].st).operador, retrieveFloatFromTable(tabla, size, (yyvsp[-2].st).s), (yyvsp[0].st).f);
				(yyval.st).type = "float";
				(yyval.st).a = assignAST(newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else {
				(yyval.st).error = "Variable de tipo incorrecto";
			}
			
		} else {yyerror("Variable not declared");}
	}
#line 1774 "y.tab.c"
    break;

  case 8: /* AUXOPER: OPERATION OPERATOR VAR_NAME  */
#line 301 "bison.y"
                                      {
		if(!searchVar(tabla, size, (yyvsp[0].st).s)) { 

			if(strcmp((yyvsp[-2].st).type, "integer")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "integer")==0) {

				(yyval.st).i = operateInt((yyvsp[-1].st).operador, (yyvsp[-2].st).i, retrieveIntFromTable(tabla, size, (yyvsp[0].st).s));
				(yyval.st).type = "integer";
				(yyval.st).a = assignAST(newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else if(strcmp((yyvsp[-2].st).type, "float")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "integer")==0) {

				(yyval.st).f = operateFloat((yyvsp[-1].st).operador, (yyvsp[-2].st).f, (float)retrieveIntFromTable(tabla, size, (yyvsp[0].st).s));
				(yyval.st).type = "float";
				(yyval.st).a = assignAST(newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else if(strcmp((yyvsp[-2].st).type, "integer")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "float")==0) {
				
				(yyval.st).f = operateFloat((yyvsp[-1].st).operador, (float)(yyvsp[-2].st).i, retrieveFloatFromTable(tabla, size, (yyvsp[0].st).s));
				(yyval.st).type = "float";
				(yyval.st).a = assignAST(newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else if(strcmp((yyvsp[-2].st).type, "float")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "float")==0) {
				
				(yyval.st).f = operateFloat((yyvsp[-1].st).operador, (yyvsp[-2].st).f, retrieveFloatFromTable(tabla, size, (yyvsp[0].st).s));
				(yyval.st).type = "float";
				(yyval.st).a = assignAST(newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else {
				(yyval.st).error = "Variable de tipo incorrecto";
			}
			
		} else {yyerror("Variable not declared");}
	}
#line 1816 "y.tab.c"
    break;

  case 9: /* AUXOPER: OPERATION  */
#line 338 "bison.y"
                    {
		if(strcmp((yyvsp[0].st).type, "integer")==0) {
			(yyval.st).i = (yyvsp[0].st).i;
			(yyval.st).type = "integer";
			(yyval.st).a = assignAST((yyvsp[0].st).a);
			(yyval.st).error = "empty";
		} else if(strcmp((yyvsp[0].st).type, "float")==0) {
			(yyval.st).f = (yyvsp[0].st).f;
			(yyval.st).type = "float";
			(yyval.st).a = assignAST((yyvsp[0].st).a);
			(yyval.st).error = "empty";
		} else {
			(yyval.st).error = "Variable de tipo incorrecto";
		}
			
	}
#line 1837 "y.tab.c"
    break;

  case 10: /* TYPEDECLARATION: DECLINTEGER  */
#line 357 "bison.y"
                    {
		(yyval.st).type = "integer";
	}
#line 1845 "y.tab.c"
    break;

  case 11: /* TYPEDECLARATION: DECLFLOAT  */
#line 360 "bison.y"
                    {
		(yyval.st).type = "float";
	}
#line 1853 "y.tab.c"
    break;

  case 12: /* DECL: VAR_NAME COLON TYPEDECLARATION COLON EQUAL AUXOPER SEMICOLON  */
#line 367 "bison.y"
                                                                     {
		(yyval.st).s = "Declaracion de variable Integer o Float";
		if(strcmp((yyvsp[-1].st).error, "empty")==0){
			(yyval.st).error = (yyvsp[-1].st).error;
			if(strcmp((yyvsp[-4].st).type, "integer")==0 && strcmp((yyvsp[-1].st).type, "integer")==0){
				insertElement(tabla, &size, (yyvsp[-1].st).i, "", 0.0, (yyvsp[-6].st).s, false, &elementosOcupados, "integer", true );
				(yyval.st).a = (yyvsp[-1].st).a;
			} else if(strcmp((yyvsp[-4].st).type, "float")==0 && strcmp((yyvsp[-1].st).type, "float")==0){
				insertElement(tabla, &size, 0, "", (yyvsp[-1].st).f, (yyvsp[-6].st).s, false, &elementosOcupados, "float", true );
				(yyval.st).a = (yyvsp[-1].st).a;
			} else if(strcmp((yyvsp[-4].st).type, "float")==0 && strcmp((yyvsp[-1].st).type, "integer")==0){
				insertElement(tabla, &size, 0, "", (float)(yyvsp[-1].st).i, (yyvsp[-6].st).s, false, &elementosOcupados, "float", true );
				(yyval.st).a = (yyvsp[-1].st).a;
			} else {
				(yyval.st).error = "Error diferente tipo de variable (int, float)";
			}

		} else {
			(yyval.st).error = (yyvsp[-1].st).error;
		}
		
	}
#line 1880 "y.tab.c"
    break;

  case 13: /* DECL: VAR_NAME COLON TYPEDECLARATION SEMICOLON  */
#line 390 "bison.y"
                                                   {
		(yyval.st).s = "Declaracion de variable Integer o Float vacia";
		if(strcmp((yyvsp[-1].st).type, "integer")==0){
			if (searchVar(tabla, size, (yyvsp[-3].st).s)) {
				(yyval.st).error = "empty";
				insertElement(tabla, &size, 0, "", 0.0, (yyvsp[-3].st).s, false, &elementosOcupados, "integer", false );
			} else {
				(yyval.st).error = "Variable already declared";
			}
		} else if(strcmp((yyvsp[-1].st).type, "float")==0){ 
			if (searchVar(tabla, size, (yyvsp[-3].st).s)) {
				(yyval.st).error = "empty";
				insertElement(tabla, &size, 0, "", 0.0, (yyvsp[-3].st).s, false, &elementosOcupados, "float", false );
			} else {
				(yyval.st).error = "Variable already declared";
			}	
		}
	}
#line 1903 "y.tab.c"
    break;

  case 14: /* DECL: VAR_NAME COLON DECLBOOLEAN COLON EQUAL VAR_NAME SEMICOLON  */
#line 410 "bison.y"
                                                                    {
			if(searchVar(tabla, size, (yyvsp[-6].st).s) && checkVarAndType(tabla, size, (yyvsp[-1].st).s, "boolean")) {
				(yyval.st).error = "empty";
				insertElement(tabla, &size, 0, "", 0.0, (yyvsp[-6].st).s, retrieveBoolFromTable(tabla, size, (yyvsp[-1].st).s), &elementosOcupados, "boolean", true );
				(yyval.st).a = assignAST((yyvsp[-1].st).a);
			} else {(yyval.st).error = "Variable declared or wrong type";}
			(yyval.st).s = "Declaracion de variable Boolean a operacion booleana";
		}
#line 1916 "y.tab.c"
    break;

  case 15: /* DECL: VAR_NAME COLON DECLBOOLEAN COLON EQUAL AUX_BOOLEAN_OP SEMICOLON  */
#line 418 "bison.y"
                                                                          {
			if(strcmp((yyvsp[-1].st).error,"empty") == 0 ){
				// printf("no errors bool decl with bool op");
				if(searchVar(tabla, size, (yyvsp[-6].st).s)) {
					(yyval.st).error = "empty";
					insertElement(tabla, &size, 0, "", 0.0, (yyvsp[-6].st).s, (yyvsp[-1].st).boo ? true : false, &elementosOcupados, "boolean", true );
					(yyval.st).a = assignAST((yyvsp[-1].st).a);
				} else {(yyval.st).error = "Variable declared or wrong type";}
			} else {
				(yyval.st).error = (yyvsp[-1].st).error;
			}
			
			(yyval.st).s = "Declaracion de variable Boolean a operacion booleana";
		}
#line 1935 "y.tab.c"
    break;

  case 16: /* DECL: VAR_NAME COLON EQUAL AUXCOMPLETO SEMICOLON  */
#line 433 "bison.y"
                                                        {// variable := ALGO ;
		//NO IMPLEMENTADO variable_int1 := variable_int1 + 1;
		// SE PUEDEN USAR TODAS LAS GRAMÁTICAS EXTRAS QUE HE CREADO AUXILIARES
		// UNA QUE ENVUELVA TODAS
		(yyval.st).s = "asignación de variable a cualquier cosa";
		if(strcmp((yyvsp[-1].st).error,"empty") == 0 ) {
			(yyval.st).error = (yyvsp[-1].st).error;
			if(strcmp(getVarType(tabla, size, (yyvsp[-4].st).s), "integer")==0 && strcmp((yyvsp[-1].st).type, "integer")==0) {
				
				insertElement(tabla, &size, (yyvsp[-1].st).i, "", 0.0, (yyvsp[-4].st).s, false, &elementosOcupados, "integer", true );
				(yyval.st).a = assignAST((yyvsp[-1].st).a);

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-4].st).s), "float")==0 && strcmp((yyvsp[-1].st).type, "integer")==0) {

				insertElement(tabla, &size, 0, "", (float)(yyvsp[-1].st).i, (yyvsp[-4].st).s, false, &elementosOcupados, "float", true );
				(yyval.st).a = assignAST((yyvsp[-1].st).a);

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-4].st).s), "float")==0 && strcmp((yyvsp[-1].st).type, "float")==0) {

				insertElement(tabla, &size, 0, "", (yyvsp[-1].st).f, (yyvsp[-4].st).s, false, &elementosOcupados, "float", true );
				(yyval.st).a = assignAST((yyvsp[-1].st).a);

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-4].st).s), "boolean")==0 && strcmp((yyvsp[-1].st).type, "boolean")==0) {

				insertElement(tabla, &size, 0, "", 0.0, (yyvsp[-4].st).s, (yyvsp[-1].st).boo ? true : false, &elementosOcupados, "boolean", true );
				(yyval.st).a = assignAST((yyvsp[-1].st).a);

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-4].st).s), "string")==0 && strcmp((yyvsp[-1].st).type, "string")==0) {

				insertElement(tabla, &size, 0, (yyvsp[-1].st).s, 0.0, (yyvsp[-4].st).s, false, &elementosOcupados, "string", true );
				(yyval.st).a = assignAST((yyvsp[-1].st).a);

			} else if(strcmp((yyvsp[-1].st).type, "var")==0) {

				if(strcmp(getVarType(tabla, size, (yyvsp[-4].st).s), "integer")==0 && strcmp((yyvsp[-1].st).type, "integer")==0) {

					insertElement(tabla, &size, (yyvsp[-1].st).i, "", 0.0, (yyvsp[-4].st).s, false, &elementosOcupados, "integer", true );
					(yyval.st).a = assignAST((yyvsp[-1].st).a);

				} else if(strcmp(getVarType(tabla, size, (yyvsp[-4].st).s), "float")==0 && strcmp((yyvsp[-1].st).type, "integer")==0) {

					insertElement(tabla, &size, 0, "", (float)(yyvsp[-1].st).i, (yyvsp[-4].st).s, false, &elementosOcupados, "float", true );
					(yyval.st).a = assignAST((yyvsp[-1].st).a);

				} else if(strcmp(getVarType(tabla, size, (yyvsp[-4].st).s), "float")==0 && strcmp((yyvsp[-1].st).type, "float")==0) {

					insertElement(tabla, &size, 0, "", (yyvsp[-1].st).f, (yyvsp[-4].st).s, false, &elementosOcupados, "float", true );
					(yyval.st).a = assignAST((yyvsp[-1].st).a);

				} else if(strcmp(getVarType(tabla, size, (yyvsp[-4].st).s), "boolean")==0 && strcmp((yyvsp[-1].st).type, "boolean")==0) {

					insertElement(tabla, &size, 0, "", 0.0, (yyvsp[-4].st).s, (yyvsp[-1].st).boo ? true : false, &elementosOcupados, "boolean", true );
					(yyval.st).a = assignAST((yyvsp[-1].st).a);

				} else if(strcmp(getVarType(tabla, size, (yyvsp[-4].st).s), "string")==0 && strcmp((yyvsp[-1].st).type, "string")==0) {

					insertElement(tabla, &size, 0, (yyvsp[-1].st).s, 0.0, (yyvsp[-4].st).s, false, &elementosOcupados, "string", true );
					(yyval.st).a = assignAST((yyvsp[-1].st).a);

				} else {
					(yyval.st).error = "Invalid assignation type";
				}
			} else {
				(yyval.st).error = "Invalid assignation type";
			}
		} else {
			(yyval.st).error = (yyvsp[-1].st).error;
		}
	}
#line 2009 "y.tab.c"
    break;

  case 17: /* DECL: VAR_NAME COLON DECLBOOLEAN SEMICOLON  */
#line 504 "bison.y"
                                               {
			(yyval.st).s = "Declaracion de variable Boolean vacia";
			if (searchVar(tabla, size, (yyvsp[-3].st).s)) {
				(yyval.st).error = "empty";
				insertElement(tabla, &size, 0, "", 0.0, (yyvsp[-3].st).s, false, &elementosOcupados, "boolean", false );
			} else {
				(yyval.st).error = "Variable declared";
			}
		}
#line 2023 "y.tab.c"
    break;

  case 18: /* DECL: VAR_NAME COLON DECLSTRING COLON EQUAL VAR_NAME SEMICOLON  */
#line 513 "bison.y"
                                                                   {
			(yyval.st).s = "Declaracion de variable String igual a variable String"; 
			if(searchVar(tabla, size, (yyvsp[-6].st).s) && checkVarAndType(tabla, size, (yyvsp[-1].st).s,"string")) {
				(yyval.st).error = "empty";
				insertElement(tabla, &size, 0, retrieveStringFromTable(tabla, size, (yyvsp[-1].st).s), 0.0, (yyvsp[-6].st).s, false, &elementosOcupados, "string", true );
				(yyval.st).a = assignAST((yyvsp[-1].st).a);
			} else {
				(yyval.st).error = "Variable declared or wrong type";
			}
		}
#line 2038 "y.tab.c"
    break;

  case 19: /* DECL: VAR_NAME COLON DECLSTRING COLON EQUAL STRING SEMICOLON  */
#line 523 "bison.y"
                                                                 {
			(yyval.st).s = "Declaracion con string";
			if(searchVar(tabla, size, (yyvsp[-6].st).s)) {
				(yyval.st).error = "empty"; 
				insertElement(tabla, &size, 0, (yyvsp[-1].st).s, 0.0, (yyvsp[-6].st).s, false, &elementosOcupados, "string", true );(yyval.st).a = assignAST((yyvsp[-1].st).a);
			} else {
				(yyval.st).error = "Variable declared or wrong type";
			}
		}
#line 2052 "y.tab.c"
    break;

  case 20: /* DECL: VAR_NAME COLON DECLSTRING SEMICOLON  */
#line 532 "bison.y"
                                              {
			(yyval.st).s = "Declaracion de variable String vacia";
			if (searchVar(tabla, size, (yyvsp[-3].st).s)) {
			(yyval.st).error = "empty";insertElement(tabla, &size, 0, "", 0.0, (yyvsp[-3].st).s, false, &elementosOcupados, "string", false );} else {(yyval.st).error = "Variable declared";}
		}
#line 2062 "y.tab.c"
    break;

  case 21: /* AUXCOMPLETO: AUX_BOOLEAN_OP  */
#line 540 "bison.y"
                       {(yyval.st) = (yyvsp[0].st);}
#line 2068 "y.tab.c"
    break;

  case 22: /* AUXCOMPLETO: AUXOPER  */
#line 541 "bison.y"
                  {(yyval.st) = (yyvsp[0].st); }
#line 2074 "y.tab.c"
    break;

  case 23: /* CONTENT: IF_COND  */
#line 545 "bison.y"
                 {printf("Contenido: %s\t Linea: %d\n", (yyvsp[0].st).s, yylineno); if(!(yyvsp[0].st).a){ ;} else {eval(*(yyvsp[0].st).a, &size);};}
#line 2080 "y.tab.c"
    break;

  case 24: /* CONTENT: BOOLEAN_OP  */
#line 546 "bison.y"
                      {printf("%s", (yyvsp[0].st).s);}
#line 2086 "y.tab.c"
    break;

  case 25: /* CONTENT: BOOLEAN_MIX  */
#line 547 "bison.y"
                       {printf("%s", (yyvsp[0].st).s);}
#line 2092 "y.tab.c"
    break;

  case 26: /* CONTENT: WLOOP  */
#line 548 "bison.y"
                 {printf("%s", (yyvsp[0].sval));}
#line 2098 "y.tab.c"
    break;

  case 27: /* CONTENT: COM  */
#line 549 "bison.y"
               {printf("Contenido: %s\t Linea: %d\n", (yyvsp[0].sval), yylineno); }
#line 2104 "y.tab.c"
    break;

  case 28: /* CONTENT: DECL  */
#line 550 "bison.y"
               {if(strcmp((yyvsp[0].st).error, "empty") == 0){printf("Contenido: %s\t Linea: %d\n", (yyvsp[0].st).s, yylineno); if(!(yyvsp[0].st).a){ ;} else {eval(*(yyvsp[0].st).a, &size);};} else {yyerror((yyvsp[0].st).error);}}
#line 2110 "y.tab.c"
    break;

  case 29: /* OPERATOR: PLUS  */
#line 554 "bison.y"
             {(yyval.st).operador = "+";}
#line 2116 "y.tab.c"
    break;

  case 30: /* OPERATOR: MINUS  */
#line 555 "bison.y"
                {(yyval.st).operador = "-";}
#line 2122 "y.tab.c"
    break;

  case 31: /* OPERATOR: MULTIPLY  */
#line 556 "bison.y"
                   {(yyval.st).operador = "*";}
#line 2128 "y.tab.c"
    break;

  case 32: /* OPERATOR: DIVIDE  */
#line 557 "bison.y"
                 {(yyval.st).operador = "/";}
#line 2134 "y.tab.c"
    break;

  case 33: /* OPERAND: INT  */
#line 561 "bison.y"
            {(yyval.st).i = (yyvsp[0].eval); (yyval.st).type = "integer"; (yyval.st).error="empty"; (yyval.st).a = createNum((yyvsp[0].eval));}
#line 2140 "y.tab.c"
    break;

  case 34: /* OPERAND: FLOAT  */
#line 562 "bison.y"
                      {(yyval.st).f = (yyvsp[0].fval); (yyval.st).type = "float"; (yyval.st).error="empty"; (yyval.st).a = createNum((yyvsp[0].fval));}
#line 2146 "y.tab.c"
    break;

  case 35: /* OPERATION: OPERAND  */
#line 566 "bison.y"
                {
		(yyval.st).type = (yyvsp[0].st).type;
		(yyval.st).a = (yyvsp[0].st).a;
		if (strcmp("integer", (yyvsp[0].st).type) == 0) {(yyval.st).i = (yyvsp[0].st).i;} else {(yyval.st).f = (yyvsp[0].st).f;}
	}
#line 2156 "y.tab.c"
    break;

  case 36: /* OPERATION: OPERATION PLUS OPERATION  */
#line 571 "bison.y"
                                        {
			if(strcmp((yyvsp[-2].st).type, "float") == 0 && strcmp((yyvsp[0].st).type, "float") == 0) {
				(yyval.st).f = (yyvsp[-2].st).f + (yyvsp[0].st).f;
				(yyval.st).type = "float";
			} else if (strcmp((yyvsp[0].st).type, "float") == 0) {
				(yyval.st).f = (float)(yyvsp[-2].st).i + (yyvsp[0].st).f;
				(yyval.st).type = "float";
			} else if (strcmp((yyvsp[-2].st).type, "float") == 0) {
				(yyval.st).f = (yyvsp[-2].st).f + (float)(yyvsp[0].st).i;
				(yyval.st).type = "float";
			} else {
				(yyval.st).i = (yyvsp[-2].st).i + (yyvsp[0].st).i;
				(yyval.st).type = "integer";
			}
			(yyval.st).a = newast("+",(yyvsp[-2].st).a,(yyvsp[0].st).a);
		}
#line 2177 "y.tab.c"
    break;

  case 37: /* OPERATION: OPERATION MINUS OPERATION  */
#line 587 "bison.y"
                                        {
			if(strcmp((yyvsp[-2].st).type, "float") == 0 && strcmp((yyvsp[0].st).type, "float") == 0) {
				(yyval.st).f = (yyvsp[-2].st).f - (yyvsp[0].st).f;
				(yyval.st).type = "float";
			} else if (strcmp((yyvsp[0].st).type, "float") == 0) {
				(yyval.st).f = (float)(yyvsp[-2].st).i - (yyvsp[0].st).f;
				(yyval.st).type = "float";
			} else if (strcmp((yyvsp[-2].st).type, "float") == 0) {
				(yyval.st).f = (yyvsp[-2].st).f - (float)(yyvsp[0].st).i;
				(yyval.st).type = "float";
			} else {
				(yyval.st).i = (yyvsp[-2].st).i - (yyvsp[0].st).i;
				(yyval.st).type = "integer";
			}
			(yyval.st).a = newast("-",(yyvsp[-2].st).a,(yyvsp[0].st).a);
		}
#line 2198 "y.tab.c"
    break;

  case 38: /* OPERATION: OPERATION MULTIPLY OPERATION  */
#line 603 "bison.y"
                                        {
			if(strcmp((yyvsp[-2].st).type, "float") == 0 && strcmp((yyvsp[0].st).type, "float") == 0) {
				(yyval.st).f = (yyvsp[-2].st).f * (yyvsp[0].st).f;
				(yyval.st).type = "float";
			} else if (strcmp((yyvsp[0].st).type, "float") == 0) {
				(yyval.st).f = (float)(yyvsp[-2].st).i * (yyvsp[0].st).f;
				(yyval.st).type = "float";
			} else if (strcmp((yyvsp[-2].st).type, "float") == 0) {
				(yyval.st).f = (yyvsp[-2].st).f * (float)(yyvsp[0].st).i;
				(yyval.st).type = "float";
			} else {
				(yyval.st).i = (yyvsp[-2].st).i * (yyvsp[0].st).i;
				(yyval.st).type = "integer";
			}
			(yyval.st).a = newast("*",(yyvsp[-2].st).a,(yyvsp[0].st).a);
		}
#line 2219 "y.tab.c"
    break;

  case 39: /* OPERATION: OPERATION DIVIDE OPERATION  */
#line 619 "bison.y"
                                        {
			if(strcmp((yyvsp[-2].st).type, "float") == 0 && strcmp((yyvsp[0].st).type, "float") == 0) {
				(yyval.st).f = (yyvsp[-2].st).f / (yyvsp[0].st).f;
				(yyval.st).type = "float";
			} else if (strcmp((yyvsp[0].st).type, "float") == 0) {
				(yyval.st).f = (float)(yyvsp[-2].st).i / (yyvsp[0].st).f;
				(yyval.st).type = "float";
			} else if (strcmp((yyvsp[-2].st).type, "float") == 0) {
				(yyval.st).f = (yyvsp[-2].st).f / (float)(yyvsp[0].st).i;
				(yyval.st).type = "float";
			} else {
				(yyval.st).i = (yyvsp[-2].st).i / (yyvsp[0].st).i;
				(yyval.st).type = "integer";
			}
			(yyval.st).a = newast("/",(yyvsp[-2].st).a,(yyvsp[0].st).a);
		}
#line 2240 "y.tab.c"
    break;

  case 40: /* OPERATION: LEFT OPERATION RIGHT  */
#line 635 "bison.y"
                               {if(strcmp((yyvsp[-1].st).type, "float") == 0) {(yyval.st).f = (yyvsp[-1].st).f;} else {(yyval.st).i = (yyvsp[-1].st).i;}}
#line 2246 "y.tab.c"
    break;

  case 41: /* BOOLEAN_OPERATORS: COMPARE  */
#line 640 "bison.y"
                {(yyval.st).s = "IGUAL";(yyval.st).operador = "==";}
#line 2252 "y.tab.c"
    break;

  case 42: /* BOOLEAN_OPERATORS: MORE  */
#line 641 "bison.y"
               {(yyval.st).s = "MAYOR";(yyval.st).operador = ">";}
#line 2258 "y.tab.c"
    break;

  case 43: /* BOOLEAN_OPERATORS: LESS  */
#line 642 "bison.y"
               {(yyval.st).s = "MENOR";(yyval.st).operador = "<";}
#line 2264 "y.tab.c"
    break;

  case 44: /* BOOLEAN_OPERATORS: GREATER_THAN  */
#line 643 "bison.y"
                       {(yyval.st).s = "MAYOR IGUAL";(yyval.st).operador = ">=";}
#line 2270 "y.tab.c"
    break;

  case 45: /* BOOLEAN_OPERATORS: LESSER_THAN  */
#line 644 "bison.y"
                      {(yyval.st).s = "MENOR IGUAL";(yyval.st).operador = "<=";}
#line 2276 "y.tab.c"
    break;

  case 46: /* BOOLEAN_OPERATORS: NOT_EQUAL  */
#line 645 "bison.y"
                    {(yyval.st).s = "DESIGUAL";(yyval.st).operador = "!=";}
#line 2282 "y.tab.c"
    break;

  case 47: /* AUX_BOOLEAN_OP: BOOLEAN_MIX  */
#line 649 "bison.y"
                    {(yyval.st) = (yyvsp[0].st); (yyval.st).type = "boolean";}
#line 2288 "y.tab.c"
    break;

  case 48: /* AUX_BOOLEAN_OP: BOOLEAN_OP  */
#line 650 "bison.y"
                     {(yyval.st) = (yyvsp[0].st); (yyval.st).type = "boolean";}
#line 2294 "y.tab.c"
    break;

  case 49: /* BOOLEAN_MIX: BOOLEAN_OP AND BOOLEAN_OP  */
#line 655 "bison.y"
                                  {
		(yyval.st).s="Expresiones booleanas con AND\n";
		(yyval.st).error = "empty";
		if((yyvsp[-2].st).boo == (yyvsp[0].st).boo){
			(yyval.st).boo = 1;
		} else {
			(yyval.st).boo = 0;
		}
	}
#line 2308 "y.tab.c"
    break;

  case 50: /* BOOLEAN_MIX: BOOLEAN_OP OR BOOLEAN_OP  */
#line 664 "bison.y"
                                   {
		(yyval.st).s="Expresiones booleanas con OR\n";
		(yyval.st).error = "empty";
		if((yyvsp[-2].st).boo == 1 || (yyvsp[0].st).boo == 1){
			(yyval.st).boo = 1;
		} else {
			(yyval.st).boo = 0;
		}
	}
#line 2322 "y.tab.c"
    break;

  case 51: /* BOOLEAN_OP: OPERATION BOOLEAN_OPERATORS OPERATION  */
#line 677 "bison.y"
                                                                {
		(yyval.st).s = "INT OP BOOL INT";
		(yyval.st).error = "empty";
		if(strcmp((yyvsp[-2].st).type, "integer")==0 && strcmp((yyvsp[0].st).type, "integer")==0){	
			(yyval.st).boo = compare((yyvsp[-1].st).operador, (float)(yyvsp[-2].st).i, (float)(yyvsp[0].st).i);
			(yyval.st).a = newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a); 
		} else if(strcmp((yyvsp[0].st).type, "integer")==0){	
			(yyval.st).boo = compare((yyvsp[-1].st).operador, (yyvsp[-2].st).f, (float)(yyvsp[0].st).i);
			(yyval.st).a = newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a); 
		} else if(strcmp((yyvsp[-2].st).type, "integer")==0){	
			(yyval.st).boo = compare((yyvsp[-1].st).operador, (float)(yyvsp[-2].st).i, (yyvsp[0].st).f);
			(yyval.st).a = newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a); 
		} else {	
			(yyval.st).boo = compare((yyvsp[-1].st).operador, (yyvsp[-2].st).f, (yyvsp[0].st).f);
			(yyval.st).a = newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a); 
		}  
	}
#line 2344 "y.tab.c"
    break;

  case 52: /* BOOLEAN_OP: VAR_NAME BOOLEAN_OPERATORS OPERATION  */
#line 695 "bison.y"
                                                                {

		(yyval.st).s = "VAR OP BOOL INT";
		if(!searchVar(tabla, size, (yyvsp[-2].st).s)) { 
			(yyval.st).error = "empty";
			if(strcmp(getVarType(tabla, size, (yyvsp[-2].st).s), "integer")==0 && strcmp((yyvsp[0].st).type, "integer")==0) {

				(yyval.st).boo = compare((yyvsp[-1].st).operador, (float)retrieveIntFromTable(tabla, size, (yyvsp[-2].st).s), (float)(yyvsp[0].st).i);
				(yyval.st).a = assignAST(newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-2].st).s), "float")==0 && strcmp((yyvsp[0].st).type, "integer")==0) {

				(yyval.st).boo = compare((yyvsp[-1].st).operador, retrieveFloatFromTable(tabla, size, (yyvsp[-2].st).s), (float)(yyvsp[0].st).i);
				(yyval.st).a = assignAST(newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-2].st).s), "integer")==0 && strcmp((yyvsp[0].st).type, "float")==0) {
				
				(yyval.st).boo = compare((yyvsp[-1].st).operador, (float)retrieveIntFromTable(tabla, size, (yyvsp[-2].st).s), (yyvsp[0].st).f);
				(yyval.st).a = assignAST(newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-2].st).s), "float")==0 && strcmp((yyvsp[0].st).type, "float")==0) {
				
				(yyval.st).boo = compare((yyvsp[-1].st).operador, retrieveFloatFromTable(tabla, size, (yyvsp[-2].st).s), (yyvsp[0].st).f);
				(yyval.st).a = assignAST(newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));

			} else {

				(yyval.st).error = "Variable de tipo incorrecto";
			}
			
		} else {yyerror("Variable not declared");}

		}
#line 2382 "y.tab.c"
    break;

  case 53: /* BOOLEAN_OP: OPERATION BOOLEAN_OPERATORS VAR_NAME  */
#line 729 "bison.y"
                                                                {
			(yyval.st).s = "INT OP BOOL VAR";
			if(!searchVar(tabla, size, (yyvsp[0].st).s)) { 
				(yyval.st).error = "empty";
				if(strcmp((yyvsp[-2].st).type, "integer")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "integer")==0) {

					(yyval.st).boo = compare((yyvsp[-1].st).operador, (float)(yyvsp[-2].st).i, (float)retrieveIntFromTable(tabla, size, (yyvsp[0].st).s));
					(yyval.st).a = assignAST(newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));

				} else if(strcmp((yyvsp[-2].st).type, "float")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "integer")==0) {

					(yyval.st).boo = compare((yyvsp[-1].st).operador, (yyvsp[-2].st).f, (float)retrieveIntFromTable(tabla, size, (yyvsp[0].st).s));
					(yyval.st).a = assignAST(newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));

				} else if(strcmp((yyvsp[-2].st).type, "integer")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "float")==0) {
					
					(yyval.st).boo = compare((yyvsp[-1].st).operador, (float)(yyvsp[-2].st).i, retrieveFloatFromTable(tabla, size, (yyvsp[0].st).s));
					(yyval.st).a = assignAST(newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));

				} else if(strcmp((yyvsp[-2].st).type, "float")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "float")==0) {
					
					(yyval.st).boo = compare((yyvsp[-1].st).operador, (yyvsp[-2].st).f, retrieveFloatFromTable(tabla, size, (yyvsp[0].st).s));
					(yyval.st).a = assignAST(newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));

				} else {
					(yyval.st).error = "Variable de tipo incorrecto";
				}
			
			} else {
				yyerror("Variable not declared");
			}
		}
#line 2419 "y.tab.c"
    break;

  case 54: /* BOOLEAN_OP: VAR_NAME BOOLEAN_OPERATORS VAR_NAME  */
#line 762 "bison.y"
                                                                {
			(yyval.st).s = "VAR OP BOOL VAR";
			if(!searchVar(tabla, size, (yyvsp[-2].st).s) && !searchVar(tabla, size, (yyvsp[0].st).s)) {
				(yyval.st).error = "empty";
				if((strcmp("integer", getVarType(tabla, size, (yyvsp[-2].st).s)) == 0) && (strcmp("integer", getVarType(tabla, size, (yyvsp[0].st).s)) == 0)){
					(yyval.st).boo = compare((yyvsp[-1].st).operador,	(float)retrieveIntFromTable(tabla, size, (yyvsp[-2].st).s), (float)retrieveIntFromTable(tabla, size, (yyvsp[0].st).s));
					(yyval.st).a=newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a);
				} else if((strcmp("float", getVarType(tabla, size, (yyvsp[-2].st).s))  == 0) && (strcmp("float", getVarType(tabla, size, (yyvsp[0].st).s))  == 0)){
					(yyval.st).boo = compare((yyvsp[-1].st).operador, retrieveFloatFromTable(tabla, size, (yyvsp[-2].st).s), retrieveFloatFromTable(tabla, size, (yyvsp[0].st).s));
					(yyval.st).a=newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a);
				} else if ((strcmp("integer", getVarType(tabla, size, (yyvsp[-2].st).s))  == 0) && (strcmp("float", getVarType(tabla, size, (yyvsp[0].st).s))  == 0)) {
					(yyval.st).boo = compare((yyvsp[-1].st).operador, (float)retrieveIntFromTable(tabla, size, (yyvsp[-2].st).s), retrieveFloatFromTable(tabla, size, (yyvsp[0].st).s));
					(yyval.st).a=newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a);
				} else if ((strcmp("float", getVarType(tabla, size, (yyvsp[-2].st).s))  == 0) && (strcmp("integer", getVarType(tabla, size, (yyvsp[0].st).s))  == 0)) {
					(yyval.st).boo = compare((yyvsp[-1].st).operador, retrieveFloatFromTable(tabla, size, (yyvsp[-2].st).s), (float)retrieveIntFromTable(tabla, size, (yyvsp[0].st).s));
					(yyval.st).a=newast((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a);
				} else {
					(yyval.st).error = "Esta variable tiene un tipo incorrecto";
				}  
				
			} else {(yyval.st).error = "Variable declared or wrong type";}
		}
#line 2446 "y.tab.c"
    break;

  case 55: /* BOOLEAN_OP: LEFT BOOLEAN_OP RIGHT  */
#line 784 "bison.y"
                                        {(yyval.st).s = "PARENTESIS BOOL PARENTESIS"; (yyval.st).boo = (yyvsp[-1].st).boo;}
#line 2452 "y.tab.c"
    break;

  case 56: /* BOOLEAN_OP: VAR_NAME  */
#line 785 "bison.y"
                   {
		(yyval.st).s = "PARENTESIS BOOL PARENTESIS";
		if(!searchVar(tabla, size, (yyvsp[0].st).s)){
			if(strcmp("boolean", getVarType(tabla, size, (yyvsp[0].st).s)) == 0){
				(yyval.st).boo = retrieveBoolFromTable(tabla, size, (yyvsp[0].st).s);
			} else {
				(yyval.st).error = "La variable no es un boolean";
			}
		} else {
			(yyval.st).error = "variable no declarada";
		}
	}
#line 2469 "y.tab.c"
    break;

  case 57: /* BOOLEAN_OP: TRUE  */
#line 797 "bison.y"
               {(yyval.st).boo=1; (yyval.st).a = createBOOLVAR("True");}
#line 2475 "y.tab.c"
    break;

  case 58: /* BOOLEAN_OP: FALSE  */
#line 798 "bison.y"
                {(yyval.st).boo=0; (yyval.st).a = createBOOLVAR("False");}
#line 2481 "y.tab.c"
    break;

  case 59: /* COM: COMMENT  */
#line 802 "bison.y"
                {(yyval.sval) = "Comentario\n";}
#line 2487 "y.tab.c"
    break;

  case 60: /* IF_COND: IF AUX_BOOLEAN_OP THEN  */
#line 806 "bison.y"
                                {(yyval.st).s = "IF BOOL THEN";}
#line 2493 "y.tab.c"
    break;

  case 61: /* IF_COND: ELSE  */
#line 807 "bison.y"
                                                {(yyval.st).s = "ELSE";}
#line 2499 "y.tab.c"
    break;

  case 62: /* IF_COND: ELSEIF AUX_BOOLEAN_OP THEN  */
#line 808 "bison.y"
                                        {(yyval.st).s = "ELSEIF BOOL THEN";}
#line 2505 "y.tab.c"
    break;

  case 63: /* IF_COND: END IF SEMICOLON  */
#line 809 "bison.y"
                                        {(yyval.st).s = "END IF SEMICOLON";}
#line 2511 "y.tab.c"
    break;

  case 64: /* WLOOP: WHILE BOOLEAN_OP LOOP_  */
#line 814 "bison.y"
                               {(yyval.sval) = "Bucle while\n";}
#line 2517 "y.tab.c"
    break;

  case 65: /* WLOOP: END LOOP_ SEMICOLON  */
#line 815 "bison.y"
                              {(yyval.sval)="Fin de bucle\n";}
#line 2523 "y.tab.c"
    break;

  case 66: /* VAR_NAME: VAR  */
#line 824 "bison.y"
            {(yyval.st).s = (yyvsp[0].sval); (yyval.st).a = createSTR((yyvsp[0].sval)); (yyval.st).type = "var";}
#line 2529 "y.tab.c"
    break;

  case 67: /* STRING: STR  */
#line 828 "bison.y"
            {(yyval.st).s = (yyvsp[0].sval); (yyval.st).a = createSTR((yyvsp[0].sval));}
#line 2535 "y.tab.c"
    break;


#line 2539 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 833 "bison.y"

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
	// printf("left: %f\n", left);
	// printf("right: %f\n", right);
	// printf("operator: %s\n", operator);
	
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
	} else {
		return -500;
	}
	
}

char* getVarType(struct symb *tabla, int size, char* name) {
	// printf("%s\n",name);
	for(int i = 0; i < size; i++) {
		if(strcmp(tabla[i].vname, "._empty") == 0){
			continue;
		} else if (strcmp(tabla[i].vname, name) == 0) {
			// printf("%s\n", tabla[i].type);
			return tabla[i].type;
		}
	}
}

// devuelve false si encuentra la variable
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
int operateInt(char* operator, int left, int right){
	if(strcmp(operator, "+")==0){
		return left + right;
	} else if(strcmp(operator, "-")==0){
		return left - right;
	} else if(strcmp(operator, "*")==0){
		return left * right;
	} else if(strcmp(operator, "/")==0){
		return left / right;
	} else {
		return -500;
	}
}

float operateFloat(char* operator, float left, float right){
	if(strcmp(operator, "+")==0){
		return left + right;
	} else if(strcmp(operator, "-")==0){
		return left - right;
	} else if(strcmp(operator, "*")==0){
		return left * right;
	} else if(strcmp(operator, "/")==0){
		return left / right;
	} else {
		return -500;
	}
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
