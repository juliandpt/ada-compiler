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


void yyerror(const char* s);
%}

%union { 	
	int ival;
	float fval;
	char* sval;

	struct attributes{
    int i;
    float f;
    int i2;
    float f2;
    char* s;
    char *temp1;
    char *temp2;
    char *temp3;
    char* type;
    struct ast *a;
    struct asign *as;
	} st;
}
// TIPOS
%token<ival> INT
%token<fval> FLOAT
// TOKENS GENERALES
%token PLUS MINUS MULTIPLY DIVIDE // operadores
%token LEFT RIGHT OPEN CLOSE // parentesis/llaves
%token WHILE BOOL CASE INTEGERDEC FLOATDEC CHARDEC STRINGDEC BEG STR VAR_NAME LOOP_ END IF THEN CHAR AND OR ELSE ELSIF // palabras reservadas
%token LESS MORE EQUAL GREATER_THAN LESSER_THAN NOT_EQUAL COMPARE  // operadores logicos
%token COMMENT COLON SEMICOLON QUOTE //simbolos reservados
%token NEWLINE QUIT //cosas de flex
%token TRUE FALSE // operadores booleanos

// PRIORIDADES
%left PLUS MINUS
%left MULTIPLY DIVIDE

%type<sval> OPERATION
%type<sval> DECL
//%type<sval> ASIG

// Booleanos
%type<sval> BOOLEAN_OP
%type<sval> BOOLEAN_OPERATORS
%type<sval> BOOLEAN_MIX
%type<sval> BOOLEAN_VAR
%type<sval> BEGIN

// statements
%type<st> STMT
%type<st> IF_COND
%type<st> WLOOP
%type<st> COM

%start calculation

%%

calculation:
	| calculation line
;

line:
      STMT
;


STMT: 
	IF_COND {printf("%s", $1.a);}
	| OPERATION {printf("%s", $1.a);}
	| BOOLEAN_OP {printf("%s", $1.a);}
	| WLOOP {printf("%s", $1.a);}
	| COM  {printf("%s", $1.a);}
	// | error {yyerror; printf("Linea %d ",line_num); printf("Error en esta linea\n");}
	| BEGIN  {printf("%s", $1.a);}
;
	

;
// Operaciones aritmeticas
OPERATION: INT {$$ = "INTEGER";}
	| FLOAT {$$ = "FLOAT";}
	| OPERATION PLUS OPERATION { $$ = "Operacion aritmetica\n";} // suma
	| OPERATION MINUS OPERATION { $$ = "Operacion aritmetica\n";} // resta
	| OPERATION MULTIPLY OPERATION { $$ = "Operacion aritmetica\n";} // multiplicacion
	| OPERATION DIVIDE OPERATION { $$ = "Operacion aritmetica\n";} // division
	| LEFT OPERATION RIGHT { $$ = "Operacion aritmetica\n";} // operacion entre parentesis

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
	VAR_NAME BOOLEAN_OPERATORS VAR_NAME {$$="Operacion booleana variables\n";}
	| VAR_NAME BOOLEAN_OPERATORS INT {$$="Operacion booleana variable - numero\n";}
	| VAR_NAME BOOLEAN_OPERATORS STR {$$="Operacion booleana variable - string\n";}
	| VAR_NAME BOOLEAN_OPERATORS FLOAT {$$="Operacion booleana variable - float\n";}
	| INT BOOLEAN_OPERATORS INT {$$="Operacion booleana numero - numero\n";}
	| STR BOOLEAN_OPERATORS STR {$$="Operacion booleana string - string\n";}
	| FLOAT BOOLEAN_OPERATORS FLOAT {$$="Operacion booleana float - float\n";}
	| VAR_NAME COMPARE BOOLEAN_VAR {$$="Variable igual a True/False\n";}
;

COM:
	COMMENT {$$.s = "Comentario\n";}
;

IF_COND: 
	
	IF BOOLEAN_OP THEN {$$.s = "Sentencia IF\n";}

	| END IF SEMICOLON {$$.s = "End IF\n";}
	| ELSE {$$.s = "Else\n";}
	| ELSIF BOOLEAN_OP THEN {$$.s = "Elsif\n";}
;

WLOOP:
	WHILE BOOLEAN_OP LOOP_ {$$.s = "Bucle while\n";}
	| END LOOP_ SEMICOLON {$$.s="Fin de bucle\n";}
;

BEGIN:
	BEG {$$ = "Begin\n";}
	| END SEMICOLON {$$ = "End begin\n";}
;

%%

// int main(int argc, char *argv[]) {
//   if (argc == 1) {
//     yyparse();
//   }
// }

