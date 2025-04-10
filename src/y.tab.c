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
#line 1 "./src/bison.y"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>    
#include <string.h>
#include <math.h>
#include "symtab.h"
#include "AST.h"

extern FILE *yyin;
extern FILE *yyout;

int globalError =0;
int globalContadorNum =0;
int globalContadorOper =0;
int globalBoolCond = 0;
char globalSignCond;
char *globalTipo;


//-----NUMEROS-----

add_SymNum ( char *sym_name, int sym_val, char *sym_type ) {  
symrec *s;
   s = getsymNum (sym_name,sym_val);
   if (s == 0){
        s = putsymNum (sym_name,sym_val, sym_type);
        printf( "%s no esta definida, es %d. (tipo=%s)\n", sym_name, sym_val, sym_type );
   }else {
          printf( "%s ya esta definida, es %d. (tipo=%s)\n", sym_name, sym_val, sym_type );
   }
}

Update_SymNum( char *sym_name, int sym_val ){ 
symrec *act;

  if ( getsymNum( sym_name, sym_val ) == 0 ) {
     printf( "%s no esta en la lista, es %d\n", sym_name, sym_val );
  }else{
     act = updatesymNum( sym_name, sym_val); 
     printf( "%s se actualiza a: %d\n", act->name, act->num );
  }
}

//-----TEXTOS-----

add_SymText ( char *sym_name, char *sym_text, char *sym_type ) {  
symrec *s;
   s = getsymText (sym_name,sym_text);
   if (s == 0){
        s = putsymText (sym_name,sym_text, sym_type);
        printf( "%s no esta definida, es %s. (tipo=%s) \n", sym_name, sym_text, sym_type );
   }else {
          printf( "%s ya esta definida, es %s. (tipo=%s) \n", sym_name, sym_text, sym_type );
   }
}

Update_SymText( char *sym_name, char *sym_text  ){ 
symrec *act;

  if ( getsymText( sym_name, sym_text ) == 0 ) {
     printf( "%s no esta en la lista, es %d\n", sym_name, sym_text );
  }else{
     act = updatesymText( sym_name, sym_text); 
     printf( "%s se actualiza a: %s\n", act->name, act->text );
  }
}





#line 143 "y.tab.c"

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
    MAS = 258,
    MENOS = 259,
    POR = 260,
    DIV = 261,
    PAR_I = 262,
    PAR_D = 263,
    IF = 264,
    THEN = 265,
    MAYOR_Q = 266,
    MENOR_Q = 267,
    ELSE = 268,
    SALTOLINEA = 269,
    PROCEDURE = 270,
    IS = 271,
    END = 272,
    BEGINN = 273,
    DOSPUNTOS = 274,
    INTEGER = 275,
    FLOAT = 276,
    STRING = 277,
    BOOLEAN = 278,
    IDENTIFICADORSIMB = 279,
    PIZQ_COM = 280,
    DOSPUNTOS_IGUAL = 281,
    PDECH_COM = 282,
    PUTLINE = 283,
    ENDIF = 284,
    TRUE = 285,
    FALSE = 286,
    COMENTARIO = 287,
    WHILE = 288,
    LOOP = 289,
    ENDLOOP = 290,
    IGUAL = 291,
    FOR = 292,
    IN = 293,
    RANGO = 294,
    FUNCION = 295,
    RETURN = 296,
    SEMICOLON = 297,
    NUMENTERO = 298,
    NUMREAL = 299,
    IDENTIFICADOR = 300
  };
#endif
/* Tokens.  */
#define MAS 258
#define MENOS 259
#define POR 260
#define DIV 261
#define PAR_I 262
#define PAR_D 263
#define IF 264
#define THEN 265
#define MAYOR_Q 266
#define MENOR_Q 267
#define ELSE 268
#define SALTOLINEA 269
#define PROCEDURE 270
#define IS 271
#define END 272
#define BEGINN 273
#define DOSPUNTOS 274
#define INTEGER 275
#define FLOAT 276
#define STRING 277
#define BOOLEAN 278
#define IDENTIFICADORSIMB 279
#define PIZQ_COM 280
#define DOSPUNTOS_IGUAL 281
#define PDECH_COM 282
#define PUTLINE 283
#define ENDIF 284
#define TRUE 285
#define FALSE 286
#define COMENTARIO 287
#define WHILE 288
#define LOOP 289
#define ENDLOOP 290
#define IGUAL 291
#define FOR 292
#define IN 293
#define RANGO 294
#define FUNCION 295
#define RETURN 296
#define SEMICOLON 297
#define NUMENTERO 298
#define NUMREAL 299
#define IDENTIFICADOR 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 85 "./src/bison.y"

        int number;
        double numberf;
        char *string;
	struct {
     		char *tipo;
    		int valor;
    		double valord;
    		char *texto;
 		int booleanCond;
		struct ast *a;
		struct flow *f;
		struct fncall *fun;
  		} snum;

#line 301 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

#define YYUNDEFTOK  2
#define YYMAXUTOK   300


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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   118,   122,   125,   128,   134,   145,   149,
     153,   154,   157,   164,   168,   172,   176,   182,   183,   186,
     227,   235,   236,   237,   238,   240,   241,   245,   260,   275,
     322,   371,   423,   478,   502,   526,   547,   554,   560,   581,
     586,   597,   614,   615,   616,   617,   618,   622,   640,   643
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAS", "MENOS", "POR", "DIV", "PAR_I",
  "PAR_D", "IF", "THEN", "MAYOR_Q", "MENOR_Q", "ELSE", "SALTOLINEA",
  "PROCEDURE", "IS", "END", "BEGINN", "DOSPUNTOS", "INTEGER", "FLOAT",
  "STRING", "BOOLEAN", "IDENTIFICADORSIMB", "PIZQ_COM", "DOSPUNTOS_IGUAL",
  "PDECH_COM", "PUTLINE", "ENDIF", "TRUE", "FALSE", "COMENTARIO", "WHILE",
  "LOOP", "ENDLOOP", "IGUAL", "FOR", "IN", "RANGO", "FUNCION", "RETURN",
  "SEMICOLON", "NUMENTERO", "NUMREAL", "IDENTIFICADOR", "$accept",
  "programa", "cuerpo", "inicio", "fin", "nombreI", "nombreF",
  "sentencias", "comienzo", "declaraciones", "declaracion", "tipo",
  "sentencia", "expr", "sentencia_if", "calc", "funcion", "nombreFuncion",
  "Fun", "factor", "bucle_while", "bucle_for", "rangos", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF (-78)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -10,   -34,    36,   -78,    10,   -78,     7,   -78,    -7,   -78,
      31,    32,    58,   -78,    -4,    34,   -78,   -15,   -78,   -78,
     -78,   -78,    41,   -78,   -78,   -78,    72,   -78,   -78,    75,
      73,    51,   -78,    73,   113,    44,    68,    86,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   126,    56,   136,   -78,
     -78,   -78,   -78,   -78,    71,   -78,   104,   120,    75,    73,
      73,    73,    73,    99,    73,    73,    73,    87,   111,   113,
      -7,   -78,   -78,   -78,     9,    91,   -78,    35,    35,    -5,
      -5,    75,    23,    23,    23,    92,    75,    96,   112,    -6,
     -78,   -78,   131,   -78,   135,   113,   138,   114,    -7,    24,
      30,   -78,    75,    -4,   139,   117,   118,   140,   145,    75,
     -78,   -78,    45,   152,   153,   127,   150,    59,   -78,   157,
     -78,    75,   159,    65,   129,   161,   -78,   160,   134,   -78
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     6,     0,     1,     0,     4,
       0,     0,     0,    11,     0,     0,     3,     0,    13,    14,
      15,    16,     0,     7,     5,     9,     0,    10,    12,     0,
       0,     0,    23,     0,     0,     0,     0,     8,    18,    20,
      26,    24,    25,    36,    37,    38,     0,     0,     0,    45,
      46,    42,    43,    44,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,    37,    38,     0,     0,    17,    29,    30,    31,
      32,     0,    33,    34,    35,     0,     0,     0,     0,     0,
      19,    22,     0,    21,     0,     0,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    47,     0,     0,     0,     0,     0,     0,    48,     0,
      28,     0,     0,     0,     0,     0,    41,     0,     0,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   108,
     -17,    76,   -77,   -57,   -78,    62,   -78,   -78,   -78,   -47,
     -78,   -78,   -78
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    16,     6,    24,    11,    26,    12,
      13,    22,    37,    38,    39,    46,    40,    56,   125,    54,
      41,    42,    88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      27,    76,    97,    25,    92,     1,    64,    65,    98,    94,
      75,     5,    59,    60,    61,    62,    18,    19,    20,    21,
      64,    65,    87,     9,     8,   107,    59,    60,    61,    62,
      10,    66,   114,    30,    64,    65,     7,   104,    10,    30,
      61,    62,    76,    76,   122,    66,    64,    65,   101,    15,
      14,    90,    31,   105,    30,    76,    32,    33,    31,    66,
      76,    34,    32,    33,    35,   106,    76,    34,    30,    36,
      35,    66,    17,    31,    30,    36,    47,    32,    33,    23,
     115,    27,    34,    28,    30,    35,    29,    31,   120,    55,
      36,    32,    33,    31,    57,    48,    34,    32,    33,    35,
      58,    67,    34,    31,    36,    35,   124,    32,    33,    69,
      36,    70,    34,    81,    85,    35,    43,    44,    45,    74,
      36,    77,    78,    79,    80,    86,    82,    83,    84,    59,
      60,    61,    62,    91,    93,    95,    63,    64,    65,    59,
      60,    61,    62,    49,    50,    99,    96,    64,    65,   100,
      49,    50,   102,   109,   112,   103,    51,    52,    53,   110,
     111,   113,    66,    71,    72,    73,   116,   117,   119,   118,
      68,   121,    66,   123,   126,   127,   129,   128,    89,   108
};

static const yytype_int8 yycheck[] =
{
      17,    58,     8,    18,    81,    15,    11,    12,    14,    86,
      57,    45,     3,     4,     5,     6,    20,    21,    22,    23,
      11,    12,    69,    16,    14,   102,     3,     4,     5,     6,
      45,    36,   109,     9,    11,    12,     0,    13,    45,     9,
       5,     6,    99,   100,   121,    36,    11,    12,    95,    17,
      19,    42,    28,    29,     9,   112,    32,    33,    28,    36,
     117,    37,    32,    33,    40,    35,   123,    37,     9,    45,
      40,    36,    14,    28,     9,    45,    25,    32,    33,    45,
      35,    98,    37,    42,     9,    40,    14,    28,    29,    45,
      45,    32,    33,    28,    26,    33,    37,    32,    33,    40,
      14,    45,    37,    28,    45,    40,    41,    32,    33,    38,
      45,     7,    37,    14,    27,    40,    43,    44,    45,    57,
      45,    59,    60,    61,    62,    14,    64,    65,    66,     3,
       4,     5,     6,    42,    42,    39,    10,    11,    12,     3,
       4,     5,     6,    30,    31,    14,    34,    11,    12,    14,
      30,    31,    14,    14,    14,    41,    43,    44,    45,    42,
      42,    16,    36,    43,    44,    45,    14,    14,    18,    42,
      34,    14,    36,    14,    45,    14,    42,    17,    70,   103
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    47,    48,    49,    45,    51,     0,    14,    16,
      45,    53,    55,    56,    19,    17,    50,    14,    20,    21,
      22,    23,    57,    45,    52,    18,    54,    56,    42,    14,
       9,    28,    32,    33,    37,    40,    45,    58,    59,    60,
      62,    66,    67,    43,    44,    45,    61,    25,    61,    30,
      31,    43,    44,    45,    65,    45,    63,    26,    14,     3,
       4,     5,     6,    10,    11,    12,    36,    45,    34,    38,
       7,    43,    44,    45,    61,    65,    59,    61,    61,    61,
      61,    14,    61,    61,    61,    27,    14,    65,    68,    55,
      42,    42,    58,    42,    58,    39,    34,     8,    14,    14,
      14,    65,    14,    41,    13,    29,    35,    58,    57,    14,
      42,    42,    14,    16,    58,    35,    14,    14,    42,    18,
      29,    14,    58,    14,    41,    64,    45,    14,    17,    42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    55,    56,    57,    57,    57,    57,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    62,
      63,    64,    65,    65,    65,    65,    65,    66,    67,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     4,     3,     2,     1,     1,     5,     1,
       3,     1,     4,     1,     1,     1,     1,     3,     1,     4,
       1,     5,     4,     1,     1,     1,     1,     8,    11,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,    17,
       1,     2,     1,     1,     1,     1,     1,     8,    10,     3
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 106 "./src/bison.y"
                 {
 	// fprintf(yyout, ".data\n");
	// dataOper($$.a);
 	// fprintf(yyout, ".text\n");
	// textIf(globalSignCond,$$.f);
	// textWhile(globalSignCond, $$.f);

	printf("TODO OK\n"); 
	fprintf(yyout, "TODO OK\n");
}
#line 1576 "y.tab.c"
    break;

  case 4:
#line 122 "./src/bison.y"
                             {printf("Inicio -> procedure\n");}
#line 1582 "y.tab.c"
    break;

  case 5:
#line 125 "./src/bison.y"
                 {fprintf(yyout, "Final -> end\n");}
#line 1588 "y.tab.c"
    break;

  case 6:
#line 128 "./src/bison.y"
                       {
	//fprintf(yyout, "Nombre Inicio\n");
	add_SymText ( "Nombre", (yyvsp[0].string), "string" );}
#line 1596 "y.tab.c"
    break;

  case 7:
#line 134 "./src/bison.y"
                       {
	//fprintf(yyout, "Nombre Final\n");

	if (strcmp((yyvsp[0].string), getvalsymText("Nombre")) == 0) {
		printf("CORRECTO - Coinciden los nombres\n");
	} else {
		printf("ERROR - No es igual el nombre del inicio y el del final\n");
	}
}
#line 1610 "y.tab.c"
    break;

  case 8:
#line 145 "./src/bison.y"
                                                                   {printf("sentencias");}
#line 1616 "y.tab.c"
    break;

  case 9:
#line 149 "./src/bison.y"
                 {printf("begin\n");}
#line 1622 "y.tab.c"
    break;

  case 12:
#line 157 "./src/bison.y"
                                                    { 
	printf("Se declara la variable: %s \n", (yyvsp[-3].string));
	(yyval.snum).texto = (yyvsp[-3].string); add_SymText ( (yyval.snum).texto, (yyval.snum).texto, globalTipo);
}
#line 1631 "y.tab.c"
    break;

  case 13:
#line 164 "./src/bison.y"
              {
	globalTipo= "entero";
	fprintf(yyout, "Declaracion -> int\n");
	}
#line 1640 "y.tab.c"
    break;

  case 14:
#line 168 "./src/bison.y"
             {
	globalTipo= "float";
	//fprintf(yyout, "Declaracion -> float\n");
	}
#line 1649 "y.tab.c"
    break;

  case 15:
#line 172 "./src/bison.y"
              {
	globalTipo= "string";
	//fprintf(yyout, "Declaracion -> string\n");
	}
#line 1658 "y.tab.c"
    break;

  case 16:
#line 176 "./src/bison.y"
               {
	globalTipo= "boolean";
	//fprintf(yyout, "Declaracion -> boolean\n");
	}
#line 1667 "y.tab.c"
    break;

  case 19:
#line 186 "./src/bison.y"
                                                   {
	if (globalBoolCond == 0) {
		globalBoolCond =0;
 		fprintf(yyout, "..............................................\n");
 		fprintf(yyout, ".data\n");
		dataOper((yyvsp[-1].snum).a);
 		fprintf(yyout, ".text\n");
		textOper((yyvsp[-1].snum).a);
 		fprintf(yyout, "..............................................\n");
		globalContadorNum =0;
		globalContadorOper =0;
		globalBoolCond =0;


	}

	//printTree($3.a, 10);

	printf("Condicion: %d \n", (yyval.snum).booleanCond);


	(yyval.snum).texto= (yyvsp[-3].string);

	if (globalError ==0) { //No hay errores
		if (getvalsymText((yyval.snum).texto) == 0 ) {
			printf("ERROR - No se ha declarado la variable: %s \n", (yyval.snum).texto);

		} else {
			printf("CORRECTO - Se ha declarado la variable: %s \n", (yyval.snum).texto);
	 		add_SymNum((yyvsp[-3].string), eval((yyvsp[-1].snum).a), globalTipo);
			Update_SymNum( (yyvsp[-3].string), eval((yyvsp[-1].snum).a) ); 
			printf("RESULTADO - De %s: %4.4g\n", (yyvsp[-3].string), eval((yyvsp[-1].snum).a));


		}
	} else { 
		globalError =0;
	}
		

      }
#line 1713 "y.tab.c"
    break;

  case 20:
#line 227 "./src/bison.y"
                     {
	//fprintf(yyout, "Sentencia IF\n");
	globalContadorNum = 0;
	//printf("IFFFFFO\n");
	//textOper($1.a);

	}
#line 1725 "y.tab.c"
    break;

  case 21:
#line 235 "./src/bison.y"
                                                         {printf("Put_Line\n");}
#line 1731 "y.tab.c"
    break;

  case 22:
#line 236 "./src/bison.y"
                                                      {printf("Asignacion\n");}
#line 1737 "y.tab.c"
    break;

  case 23:
#line 237 "./src/bison.y"
                  {printf("Comentario\n");}
#line 1743 "y.tab.c"
    break;

  case 24:
#line 238 "./src/bison.y"
                   { printf("Bucle WHILE\n");   //printf("WHILE - %4.4g\n", eval($1.f));
	}
#line 1750 "y.tab.c"
    break;

  case 25:
#line 240 "./src/bison.y"
                 {printf("Bucle FOR\n");}
#line 1756 "y.tab.c"
    break;

  case 26:
#line 241 "./src/bison.y"
               {printf("FUNCION\n");}
#line 1762 "y.tab.c"
    break;

  case 27:
#line 245 "./src/bison.y"
                                                                           {
		//$$.f = newflow('I', $2.f , $5.f, NULL); 
 		//fprintf(yyout, "IFFFFFFFFF\n");
 		fprintf(yyout, "..............................................\n");
 		fprintf(yyout, ".data\n");
		dataOper((yyvsp[-6].snum).a);
 		fprintf(yyout, ".text\n");
		textIf(globalSignCond,(yyvsp[-6].snum).f);
 		fprintf(yyout, "..............................................\n");
		globalContadorNum =0;
		globalContadorOper =0;
		globalBoolCond =0;

	}
#line 1781 "y.tab.c"
    break;

  case 28:
#line 260 "./src/bison.y"
                                                                                                  { 
		//$$.f = newflow('I', $2.f, $5.f, $9.f); 
 		fprintf(yyout, "..............................................\n");
 		fprintf(yyout, ".data\n");
		dataOper((yyvsp[-9].snum).a);
 		fprintf(yyout, ".text\n");
		textIf(globalSignCond,(yyvsp[-9].snum).f);
 		fprintf(yyout, "..............................................\n");
		globalContadorNum =0;
		globalContadorOper =0;
		globalBoolCond =0;
	}
#line 1798 "y.tab.c"
    break;

  case 29:
#line 275 "./src/bison.y"
                     { 
		printf("Suma\n");
		globalContadorOper = globalContadorOper + 1;

		if (globalError ==0) { //No hay errores
			if (((yyvsp[-2].snum).tipo == "entero") && ((yyvsp[0].snum).tipo == "entero")) {
				(yyval.snum).a = newast('+', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
				evalprint((yyval.snum).a);
				globalTipo = (yyvsp[-2].snum).tipo;
				contadorOperadores(globalContadorOper, (yyval.snum).a);
				printf("Suma (tipo=%s)\n", (yyval.snum).tipo);
			} 
			else if (((yyvsp[-2].snum).tipo == "real") && ((yyvsp[0].snum).tipo == "real")){
				(yyval.snum).a = newast('+', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
				evalprint((yyval.snum).a);
				globalTipo = (yyvsp[-2].snum).tipo;
				contadorOperadores(globalContadorOper, (yyval.snum).a);
				printf("Suma (tipo=%s)\n", (yyval.snum).tipo);
			} 
			else if (((yyvsp[-2].snum).tipo == "string")){
				(yyval.snum).a = newast('+', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
				evalprint((yyval.snum).a);
				globalTipo = (yyvsp[0].snum).tipo;
				contadorOperadores(globalContadorOper, (yyval.snum).a);
				printf("Suma (tipo=%s)\n", (yyval.snum).tipo);
			} 
			else if (((yyvsp[0].snum).tipo == "string")){
				(yyval.snum).a = newast('+', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
				evalprint((yyval.snum).a);
				globalTipo = (yyvsp[-2].snum).tipo;
				contadorOperadores(globalContadorOper, (yyval.snum).a);
				printf("Suma (tipo=%s)\n", (yyval.snum).tipo);
			}
			else if (((yyvsp[0].snum).tipo == "string") && ((yyvsp[-2].snum).tipo == "string")){
				(yyval.snum).a = newast('+', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
				evalprint((yyval.snum).a);
				globalTipo = (yyvsp[-2].snum).tipo;
				contadorOperadores(globalContadorOper, (yyval.snum).a);
				printf("Suma (tipo=%s)\n", (yyval.snum).tipo);
			}

		} else {
			printf("HAY ERRORES NO SE REALIZA LA SUMA\n");

		}

	}
#line 1850 "y.tab.c"
    break;

  case 30:
#line 322 "./src/bison.y"
                           { 
		printf("Resta\n");
		globalContadorOper = globalContadorOper + 1;

		if (globalError ==0) { //No hay errores
			if (((yyvsp[-2].snum).tipo == "entero") && ((yyvsp[0].snum).tipo == "entero")) {
				(yyval.snum).a = newast('-', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
				evalprint((yyval.snum).a);
				contadorOperadores(globalContadorOper, (yyval.snum).a);

				printf("Resta (tipo=%s)\n", (yyval.snum).tipo);
			} 
			else if (((yyvsp[-2].snum).tipo == "real") && ((yyvsp[0].snum).tipo == "real")){
				(yyval.snum).a = newast('-', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
				evalprint((yyval.snum).a);
				contadorOperadores(globalContadorOper, (yyval.snum).a);

				printf("Resta (tipo=%s)\n", (yyval.snum).tipo);
			} 
			else if (((yyvsp[-2].snum).tipo == "string")){
				(yyval.snum).a = newast('-', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
				evalprint((yyval.snum).a);
				contadorOperadores(globalContadorOper, (yyval.snum).a);

				printf("Resta (tipo=%s)\n", (yyval.snum).tipo);
			} 
			else if (((yyvsp[0].snum).tipo == "string")){
				(yyval.snum).a = newast('-', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
				evalprint((yyval.snum).a);
				contadorOperadores(globalContadorOper, (yyval.snum).a);

				printf("Resta (tipo=%s)\n", (yyval.snum).tipo);
			}
			else if (((yyvsp[0].snum).tipo == "string") && ((yyvsp[-2].snum).tipo == "string")){
				(yyval.snum).a = newast('-', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
				evalprint((yyval.snum).a);
				globalTipo = (yyvsp[-2].snum).tipo;
				contadorOperadores(globalContadorOper, (yyval.snum).a);

				printf("Resta (tipo=%s)\n", (yyval.snum).tipo);


			}
		}  else {
			printf("HAY ERRORES NO SE REALIZA LA RESTA\n");

		}

	}
#line 1904 "y.tab.c"
    break;

  case 31:
#line 371 "./src/bison.y"
                         { 
		printf("Multiplicacion\n");
		globalContadorOper = globalContadorOper + 1;

		if (globalError ==0) { //No hay errores
			if (((yyvsp[-2].snum).tipo == "entero") && ((yyvsp[0].snum).tipo == "entero")) {
				(yyval.snum).a = newast('*', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
				evalprint((yyval.snum).a);
				contadorOperadores(globalContadorOper, (yyval.snum).a);

				printf("Mult (tipo=%s)\n", (yyval.snum).tipo);
			} 
			else if (((yyvsp[-2].snum).tipo == "real") && ((yyvsp[0].snum).tipo == "real")){
				(yyval.snum).a = newast('*', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
				evalprint((yyval.snum).a);
				contadorOperadores(globalContadorOper, (yyval.snum).a);

				printf("Mult (tipo=%s)\n", (yyval.snum).tipo);
			} 
			else if (((yyvsp[-2].snum).tipo == "string")){
				(yyval.snum).a = newast('*', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
				evalprint((yyval.snum).a);
				contadorOperadores(globalContadorOper, (yyval.snum).a);

				printf("Mult (tipo=%s)\n", (yyval.snum).tipo);


			} 
			else if (((yyvsp[0].snum).tipo == "string")){
				(yyval.snum).a = newast('*', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
				evalprint((yyval.snum).a);
				contadorOperadores(globalContadorOper, (yyval.snum).a);

				printf("Mult (tipo=%s)\n", (yyval.snum).tipo);
			}
			else if (((yyvsp[0].snum).tipo == "string") && ((yyvsp[-2].snum).tipo == "string")){
				(yyval.snum).a = newast('*', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
				evalprint((yyval.snum).a);
				contadorOperadores(globalContadorOper, (yyval.snum).a);

				globalTipo = (yyvsp[-2].snum).tipo;
				printf("Mult (tipo=%s)\n", (yyval.snum).tipo);


			}
		} else {
			printf("HAY ERRORES NO SE REALIZA LA MULTIPLICACION\n");

		}

	}
#line 1960 "y.tab.c"
    break;

  case 32:
#line 423 "./src/bison.y"
                          {
		printf("Division\n");
		globalContadorOper = globalContadorOper + 1;

		if ((yyvsp[0].snum).valor == 0) { //No se puede dividir entre 0
			globalError =1;
		}

		if (globalError ==0) { //No hay errores
			if (((yyvsp[-2].snum).tipo == "entero") && ((yyvsp[0].snum).tipo == "entero")) {
				(yyval.snum).a = newast('/', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
				evalprint((yyval.snum).a);
				contadorOperadores(globalContadorOper, (yyval.snum).a);

				printf("Div (tipo=%s)\n", (yyval.snum).tipo);
			} 
			else if (((yyvsp[-2].snum).tipo == "real") && ((yyvsp[0].snum).tipo == "real")){
				(yyval.snum).a = newast('/', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
				evalprint((yyval.snum).a);
				contadorOperadores(globalContadorOper, (yyval.snum).a);

				printf("Div (tipo=%s)\n", (yyval.snum).tipo);
			} 
			else if (((yyvsp[-2].snum).tipo == "string")){
				(yyval.snum).a = newast('/', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
				evalprint((yyval.snum).a);
				contadorOperadores(globalContadorOper, (yyval.snum).a);

				printf("Div (tipo=%s)\n", (yyval.snum).tipo);


			} 
			else if (((yyvsp[0].snum).tipo == "string")){
				(yyval.snum).a = newast('/', (yyvsp[-2].snum).a,(yyvsp[0].snum).a);
				evalprint((yyval.snum).a);
				contadorOperadores(globalContadorOper, (yyval.snum).a);

				printf("Div (tipo=%s)\n", (yyval.snum).tipo);

			}
			else if (((yyvsp[0].snum).tipo == "string") && ((yyvsp[-2].snum).tipo == "string")){
				(yyval.snum).a = newast('/', (yyvsp[-2].snum).a,(yyvsp[0].snum).a); 
				evalprint((yyval.snum).a);
				globalTipo = (yyvsp[-2].snum).tipo;
				contadorOperadores(globalContadorOper, (yyval.snum).a);

				//printf("Div (tipo=%s)\n", $$.tipo);
			}
		}else {
			printf("HAY ERRORES NO SE REALIZA LA DIVISION\n");
		}

	}
#line 2018 "y.tab.c"
    break;

  case 33:
#line 478 "./src/bison.y"
                            {
		//printf("**Condicion MAYORQ\n");
		globalBoolCond = 1;

		if ((yyvsp[-2].snum).valor > (yyvsp[0].snum).valor) {
			(yyval.snum).booleanCond =1;
			(yyval.snum).f = (yyval.snum).booleanCond ;
			globalSignCond = '>';

			printf("CORRECTO - Es mayor\n");


		
		} else {
			(yyval.snum).booleanCond =0;
			(yyval.snum).f = (yyval.snum).booleanCond;
			globalSignCond = '>';

			printf("ERROR - No es mayor\n");

		
		}

	}
#line 2047 "y.tab.c"
    break;

  case 34:
#line 502 "./src/bison.y"
                            {
		printf("**Condicion MENORQ\n");
		globalBoolCond = 1;

			if ((yyvsp[-2].snum).valor < (yyvsp[0].snum).valor) {
				(yyval.snum).booleanCond =1;
				(yyval.snum).f = (yyval.snum).booleanCond;
				globalSignCond = '<';


				printf("CORRECTO - Es menor\n");

		
			} else {
				(yyval.snum).booleanCond =0;
				(yyval.snum).f = (yyval.snum).booleanCond;
				globalSignCond = '<';

				printf("ERROR - No es menor\n");

			}


	}
#line 2076 "y.tab.c"
    break;

  case 35:
#line 526 "./src/bison.y"
                          {
		printf("**Condicion IGUALQ\n");
		globalBoolCond = 1;

		if ((yyvsp[-2].snum).valor == (yyvsp[0].snum).valor) {
			printf("CORRECTO - Es igual\n");
			(yyval.snum).booleanCond = 1;
			(yyval.snum).f = (yyval.snum).booleanCond;
			globalSignCond = '=';

		
		} else {
			printf("ERROR - No es igual\n");
			(yyval.snum).booleanCond = 0;
			(yyval.snum).f = (yyval.snum).booleanCond;
			globalSignCond = '=';
		
		}

	}
#line 2101 "y.tab.c"
    break;

  case 36:
#line 547 "./src/bison.y"
                    { (yyval.snum).a = newnum((yyvsp[0].number));
		(yyval.snum).valor = (yyvsp[0].number);
		(yyval.snum).tipo = "entero";
		globalContadorNum = globalContadorNum +1;
		contadorNumeros(globalContadorNum, (yyval.snum).valor );
	}
#line 2112 "y.tab.c"
    break;

  case 37:
#line 554 "./src/bison.y"
                  {
		(yyval.snum).a= newnum((yyvsp[0].numberf));
		(yyval.snum).valord = (yyvsp[0].numberf); (yyval.snum).tipo = "real";


	}
#line 2123 "y.tab.c"
    break;

  case 38:
#line 560 "./src/bison.y"
                        {
		printf("variable\n");
		(yyval.snum).tipo = "string";

		if (getvalsymText((yyvsp[0].string)) == 0 ) {
			globalError = 1;
			printf("ERROR - Variable no existe: %s \n", (yyvsp[0].string));

		} else {
			globalError = 0;
			(yyval.snum).valor = getvalsymNum((yyvsp[0].string));
			(yyval.snum).a= newnum((yyval.snum).valor);
			globalContadorNum = globalContadorNum +1;
			contadorNumeros(globalContadorNum, (yyval.snum).valor );

			printf("CORRECTO - Variable si existe: %s \n", (yyvsp[0].string));		
		}
	}
#line 2146 "y.tab.c"
    break;

  case 39:
#line 581 "./src/bison.y"
                                                                                                                                                       {
	//$$.fun = newfunc($4.fun, $11.fun);
}
#line 2154 "y.tab.c"
    break;

  case 40:
#line 586 "./src/bison.y"
                             {
	if (getvalsymNum((yyvsp[0].string)) == 0 ) {
		add_SymNum((yyvsp[0].string), 1 , "string");
		printf("CORRECTO - No existe ninguna función con ese nombre\n");		
	} else {
		printf("ERROR - Existe ya una funcion con ese nombre\n");		
	}
	//fprintf(yyout, "Nombre funcion\n");
}
#line 2168 "y.tab.c"
    break;

  case 41:
#line 597 "./src/bison.y"
                          {

	if (getvalsymText((yyvsp[0].string)) == 0 ) {
		printf("ERROR - No se ha declarado la variable: %s \n", (yyvsp[0].string));
	} else {
		printf("Tiene al menos un return\n");
		if (strcmp(globalTipo, gettypesymText((yyvsp[0].string))) == 0) {
			printf("CORRECTO - Coincide el tipo de return\n");		
		} else {
			printf("ERROR - No coincide el tipo de return\n");		
		}
	}
}
#line 2186 "y.tab.c"
    break;

  case 47:
#line 622 "./src/bison.y"
                                                                               { 
		//$$.f = newflow('W', $2.f, $4.f, NULL);  
 		//fprintf(yyout, "WHILEEEEEE\n");
		printf("while\n");
 		fprintf(yyout, "..............................................\n");
 		fprintf(yyout, ".data\n");
		dataOper((yyvsp[-6].snum).f);
 		fprintf(yyout, ".text\n");
		textWhile(globalSignCond, (yyval.snum).f);
		globalContadorNum =0;
		globalContadorOper =0;
		globalBoolCond =0;

 		fprintf(yyout, "..............................................\n");

}
#line 2207 "y.tab.c"
    break;


#line 2211 "y.tab.c"

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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
#line 647 "./src/bison.y"

int main(int argc, char *argv[]) {

if (argc == 1) {
	yyparse();
}
if (argc == 2) {
	yyout = fopen( "./output/ada.txt", "wt" );

	yyin = fopen(argv[1], "rt");

	yyparse();
}

return 0;
}


yyerror()
{ 
}
