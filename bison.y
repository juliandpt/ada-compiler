%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;

// Variables globales
int line_num = 1;

void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
 }

%}

%union { 	
	int ival;
	float fval;
	char* sval;

	// struct attributes{
  //   int i;
  //   float f;
  //   int i2;
  //   float f2;
  //   char* s;
  //   char *temp1;
  //   char *temp2;
  //   char *temp3;
  //   char* type;
  //   struct ast *a;
  //   struct asign *as;
	// } st;
}
// TIPOS
%token INT FLOAT
// TOKENS GENERALES
%token PLUS MINUS MULTIPLY DIVIDE // operadores
%token LEFT RIGHT OPEN CLOSE // parentesis/llaves
%token WHILE BOOL CASE INTEGERDEC FLOATDEC CHARDEC STRINGDEC BEG STR VAR_NAME LOOP_ END IF THEN CHAR AND OR ELSE ELSIF BOOLEAN_MIX // palabras reservadas
%token LESS MORE EQUAL GREATER_THAN LESSER_THAN NOT_EQUAL COMPARE  // operadores logicos
%token COMMENT COLON SEMICOLON QUOTE //simbolos reservados
%token NEWLINE QUIT //cosas de flex
%token TRUE FALSE // operadores booleanos

// PRIORIDADES
%left PLUS MINUS
%left MULTIPLY DIVIDE

%type<fval> OPERATION
%type<sval> DECL
%type<sval> THEN
%type<sval> ELSE
%type<ival> INT
%type<fval> FLOAT
//%type<sval> ASIG

// Booleanos
%type<sval> BOOLEAN_OP
%type<sval> BOOLEAN_OPERATORS
%type<sval> BOOLEAN_MIX
%type<sval> BOOLEAN_VAR
%type<sval> BEGIN

// statements
%type<sval> STMT
%type<sval> IF_COND
%type<sval> WLOOP
%type<sval> COM

%start calculation

%%

calculation:
	| calculation line
;

line:
      STMT
;


STMT: 
	IF_COND NEWLINE {printf("%s", $1);}
	| OPERATION NEWLINE {printf("%.2f", $1);}
	| BOOLEAN_OP NEWLINE {printf("%s", $1);}
	| BOOLEAN_MIX NEWLINE {printf("%s", $1);}
	| WLOOP NEWLINE {printf("%s", $1);}
	| COM NEWLINE {printf("%s", $1);}
;
	

;
// Operaciones aritmeticas
OPERATION: INT {$$ = $1;}
	| FLOAT {$$ = $1;}
	| OPERATION PLUS OPERATION { $$ = $1 + $3;} // suma
	| OPERATION MINUS OPERATION { $$ = $1 - $3;} // resta
	| OPERATION MULTIPLY OPERATION { $$ = $1 * $3;} // multiplicacion
	| OPERATION DIVIDE OPERATION { $$ = $1 / $3;} // division
	| LEFT OPERATION RIGHT { $$ = $2; } // operacion entre parentesis

;

// Expresiones booleanas
BOOLEAN_OPERATORS:
	COMPARE {$$ = "==\n";}
	| MORE {$$=">\n";}
	| LESS {$$== "<\n";}
	| GREATER_THAN {$$=">=\n";}
	| LESSER_THAN {$$="<=\n";}
	| NOT_EQUAL {$$="!=\n";}
;
// VARIABLES BOOLEANAS
BOOLEAN_VAR:
	TRUE {$$="True\n";}
	| FALSE {$$="False\n";}
;
/*
// Operaciones booleanas con and y or
BOOLEAN_MIX:
	BOOLEAN_OP AND BOOLEAN_OP {$$="Expresiones booleanas con AND\n";}
	BOOLEAN_OP OR BOOLEAN_OP {$$="Expresiones booleanas con OR\n";}
;
*/
// Operaciones booleanas
BOOLEAN_OP:
	OPERATION BOOLEAN_OPERATORS OPERATION {$$= "Operacion booleana int - int\n";}
;

COM:
	COMMENT {$$ = "Comentario\n";}
;

IF_COND: 
	IF "(" BOOLEAN_OP ")" THEN STMT ELSE STMT {$$ = "Sentencia IF\n";}

;

WLOOP:
	WHILE BOOLEAN_OP LOOP_ {$$ = "Bucle while\n";}
	| END LOOP_ SEMICOLON {$$="Fin de bucle\n";}
;

BEGIN:
	BEG {$$ = "Begin\n";}
	| END SEMICOLON {$$ = "End begin\n";}
;

%%

int main(int argc,char *argv[]) {
 yyparse();
}


