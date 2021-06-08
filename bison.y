%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern int yylex();
extern int yyparse();
extern int yylineno;
extern FILE *yyin;
extern FILE *yyout;

void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
 }

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
//Variables globales
int line_num = 1;

int size = 52;

int elementosOcupados = 0;

int numnodo = 0;

struct ast nodos[52];

//struct symb tabla[52];

// funciones ast
struct ast *newast(char* nodetype, struct ast *l, struct ast *r);
struct ast *createNum(double d);
struct ast *createSTR(char* s);
struct ast *createBOOLVAR(char* s);
struct ast *createBOOL(char* nodetype, struct ast *l, struct ast *r);

void eval(struct ast a, int* size);


%}
%locations

%union {
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

%type<st> OPERATION
%type<st> OPERATION2

%type<sval> DECL
%type<sval> THEN
%type<sval> ELSE
%type<eval> INT
%type<fval> FLOAT
%type<sval> PLUS MINUS MULTIPLY DIVIDE
//%type<sval> ASIG

// Booleanos
%type<sval> BOOLEAN_OP
%type<sval> BOOLEAN_OPERATORS
%type<sval> BOOLEAN_MIX
%type<st> BOOLEAN_VAR
%type<sval> BEGIN
%type<sval> TRUE FALSE

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
	| OPERATION NEWLINE {printf("%d\t%d\n", $1.i, yylineno-1); }
	| BOOLEAN_OP NEWLINE {printf("%s", $1);}
	| BOOLEAN_MIX NEWLINE {printf("%s", $1);}
	| WLOOP NEWLINE {printf("%s", $1);}
	| COM NEWLINE {printf("%s", $1);}
;
	
OPERATION: 
	INT	{$$.i = $1; $$.a = createNum($1);}
	|	OPERATION PLUS OPERATION	{$$.i = $1.i + $3.i; $$.a = newast($2,$1.a,$3.a);}
	| OPERATION MINUS OPERATION	{$$.i = $1.i - $3.i; $$.a = newast($2,$1.a,$3.a);}
	| OPERATION MULTIPLY OPERATION	{$$.i = $1.i * $3.i; $$.a = newast($2,$1.a,$3.a);}
	| OPERATION DIVIDE OPERATION	{$$.i = $1.i / $3.i; $$.a = newast($2,$1.a,$3.a);}
	| LEFT OPERATION RIGHT 	{$$.i = $2.i;}
;

OPERATION2: 
	FLOAT {$$.f = $1; $$.a = createNum($1);}
	|	OPERATION2 PLUS OPERATION2	{$$.f = $1.f + $3.f; $$.a = newast($2,$1.a,$3.a);}
	| OPERATION2 MINUS OPERATION2	{$$.f = $1.f - $3.f; $$.a = newast($2,$1.a,$3.a);}
	| OPERATION2 MULTIPLY OPERATION2	{$$.f = $1.f * $3.f; $$.a = newast($2,$1.a,$3.a);}
	| OPERATION2 DIVIDE OPERATION2	{$$.f = $1.f / $3.f; $$.a = newast($2,$1.a,$3.a);}
	| LEFT OPERATION2 RIGHT	{$$.f = $2.f;}
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
	TRUE {$$.s=$1; $$.a = createBOOLVAR($1);}
	| FALSE {$$.s=$1; $$.a = createBOOLVAR($1);}
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

int main(int argc,char *argv[]) {
 yyparse();
}

