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
    ELSIF = 285,
    BOOLEAN_MIX = 286,
    IS = 287,
    LESS = 288,
    MORE = 289,
    EQUAL = 290,
    GREATER_THAN = 291,
    LESSER_THAN = 292,
    NOT_EQUAL = 293,
    COMPARE = 294,
    COMMENT = 295,
    COLON = 296,
    SEMICOLON = 297,
    QUOTE = 298,
    NEWLINE = 299,
    QUIT = 300,
    TRUE = 301,
    FALSE = 302,
    PROCEDURE = 303,
    VAR = 304
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
#define ELSIF 285
#define BOOLEAN_MIX 286
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
#define PROCEDURE 303
#define VAR 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 90 "bison.y"

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

#line 175 "y.tab.h"

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
