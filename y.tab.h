/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 203 "y.tab.h"

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
