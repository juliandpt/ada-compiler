/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
#line 112 "./src/bison.y"

	int eval;
	float fval;
	char* sval;

	struct atributos{
		int i;
		float f;
		int boo;
		char* s;
		char* operador;
		char* type;
		struct ast *a;
		char* error;
	}st;

#line 208 "y.tab.h"

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
