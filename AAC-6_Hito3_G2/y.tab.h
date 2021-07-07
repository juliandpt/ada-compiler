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
    NUMENTERO = 297,
    NUMREAL = 298,
    IDENTIFICADOR = 299
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
#define NUMENTERO 297
#define NUMREAL 298
#define IDENTIFICADOR 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 86 "prueba.y"

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

#line 161 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
