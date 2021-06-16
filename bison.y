%{
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
   fprintf (stderr, "%s\n", s);
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
struct ast *createBOOL(char* nodetype, struct ast *l, struct ast *r);
struct ast *createFlow(struct ast *cond);
void insertElement(struct symb *tabla, int *size, int valor, char* svalor, float fvalor, char *variable, int *elementosOcupados, char* type );
struct ast *assignAST(struct ast *op);
// void retrieveElement(struct symb *tabla, int size, char* name);
int retrieveIntFromTable(struct symb *tabla, int size, char* name);
float retrieveFloatFromTable(struct symb *tabla, int size, char* name);
char* retrieveStringFromTable(struct symb *tabla, int size, char* name);
bool checkVarAndType(struct symb *tabla, int size, char* name, char* type);

void eval(struct ast a, int* size);
void printAST(struct ast nodos[], int i, int encontrado, int salida);
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
%token<sval> PLUS MINUS MULTIPLY DIVIDE // operadores
%token LEFT RIGHT OPEN CLOSE // parentesis/llaves
%token WHILE BOOL CASE INTEGERDEC FLOATDEC CHARDEC STRINGDEC BEG STR LOOP_ END IF THEN CHAR AND OR ELSE ELSEIF BOOLEAN_MIX PROCEDURE IS// palabras reservadas
%token LESS MORE EQUAL GREATER_THAN LESSER_THAN NOT_EQUAL COMPARE  // operadores logicos
%token COMMENT COLON SEMICOLON QUOTE //simbolos reservados
%token NEWLINE QUIT //cosas de flex
%token TRUE FALSE // operadores booleanos
%token TYPE RANGE DOTDOT OF COMMA
%token WHEN FOR OTHERS ARROW

// PRIORIDADES
%left PLUS MINUS
%left MULTIPLY DIVIDE

%type<st> OPERATION
%type<st> OPERATION2

%type<st> DECL
%type<sval> THEN
%type<sval> ELSE
%type<st> INT
%type<fval> FLOAT
%token<sval> VAR

%token DECLINTEGER DECLFLOAT DECLBOOLEAN DECLARRAY DECLSTRING
//%type<sval> ASIG

// Booleanos
%type<st> BOOLEAN_OP
%type<st> BOOLEAN_OPERATORS
%type<st> BOOLEAN_MIX
%type<st> BOOLEAN_VAR
%type<sval> BEGIN
%type<st> TRUE FALSE

// statements
%type<st> IF_COND
%type<sval> WLOOP
%type<sval> COM
%type<st> VAR_NAME

%type<sval> PROCLINE
%type<sval> CONTENT
%type<st> STRING
%type<sval> STR

%type<st> OPERATOR

%start PROCLINE

%%

PROCLINE:
		PROCEDURE VAR_NAME IS ADDCONTENT END VAR_NAME SEMICOLON {printf("%s", "procline");}
;

ADDCONTENT:	ADDCONTENT CONTENT | ;

AUXINT: COMMA INT {}
	| {}
;

DECL: VAR_NAME COLON DECLINTEGER COLON EQUAL VAR_NAME SEMICOLON 
	{$$.s = "Declaracion de variable Integer igual a variable"; 
	if(checkVarAndType(tabla, size, $6.s,"integer")) {
			insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s), "", 0.0, $1.s, &elementosOcupados, "integer" );
			$$.a = assignAST($6.a);
		}
	} //variable : Integer := VARIABLE + ARIT ;
	| VAR_NAME COLON DECLINTEGER COLON EQUAL VAR_NAME OPERATOR VAR_NAME SEMICOLON {
			$$.s = "Declaracion de variable Integer igual a variable integer + variable integer"; 
			if(checkVarAndType(tabla, size, $6.s, "integer") && checkVarAndType(tabla, size, $8.s, "integer")) {
				if(strcmp($7.operador, "+") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) + retrieveIntFromTable(tabla, size, $8.s), "", 0.0, $1.s, &elementosOcupados, "integer" ); }
				if(strcmp($7.operador, "-") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) - retrieveIntFromTable(tabla, size, $8.s), "", 0.0, $1.s, &elementosOcupados, "integer" ); }
				if(strcmp($7.operador, "*") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) * retrieveIntFromTable(tabla, size, $8.s), "", 0.0, $1.s, &elementosOcupados, "integer" ); }
				if(strcmp($7.operador, "/") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) / retrieveIntFromTable(tabla, size, $8.s), "", 0.0, $1.s, &elementosOcupados, "integer" ); }
				$$.a = newast($7.operador, $6.a, $8.a);
			}
		}
	| VAR_NAME COLON DECLINTEGER COLON EQUAL VAR_NAME OPERATOR OPERATION SEMICOLON {
			$$.s = "Declaracion de variable Integer igual a variable integer + operacion"; 
			if(checkVarAndType(tabla, size, $6.s, "integer")) {
				if(strcmp($7.operador, "+") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) + $8.i, "", 0.0, $1.s, &elementosOcupados, "integer" ); }
				if(strcmp($7.operador, "-") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) - $8.i, "", 0.0, $1.s, &elementosOcupados, "integer" ); }
				if(strcmp($7.operador, "*") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) * $8.i, "", 0.0, $1.s, &elementosOcupados, "integer" ); }
				if(strcmp($7.operador, "/") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) / $8.i, "", 0.0, $1.s, &elementosOcupados, "integer" ); }
				$$.a = newast($7.operador, $6.a, $8.a);
			}
		}
	| VAR_NAME COLON DECLINTEGER COLON EQUAL OPERATION OPERATOR VAR_NAME SEMICOLON {
			$$.s = "Declaracion de variable Integer igual a operacion + variable integer"; 
			if(checkVarAndType(tabla, size, $6.s, "integer")) {
				if(strcmp($7.operador, "+") == 0) { insertElement(tabla, &size, $8.i + retrieveIntFromTable(tabla, size, $6.s), "", 0.0, $1.s, &elementosOcupados, "integer" ); }
				if(strcmp($7.operador, "-") == 0) { insertElement(tabla, &size, $8.i - retrieveIntFromTable(tabla, size, $6.s), "", 0.0, $1.s, &elementosOcupados, "integer" ); }
				if(strcmp($7.operador, "*") == 0) { insertElement(tabla, &size, $8.i * retrieveIntFromTable(tabla, size, $6.s), "", 0.0, $1.s, &elementosOcupados, "integer" ); }
				if(strcmp($7.operador, "/") == 0) { insertElement(tabla, &size, $8.i / retrieveIntFromTable(tabla, size, $6.s), "", 0.0, $1.s, &elementosOcupados, "integer" ); }
				$$.a = newast($7.operador, $6.a, $8.a);
			}
		}
	| VAR_NAME COLON DECLINTEGER COLON EQUAL OPERATION SEMICOLON {
			$$.s = "Declaracion de variable Integer igual a operacion aritmetica"; 
			insertElement(tabla, &size, $6.i, "", 0.0, $1.s, &elementosOcupados, "integer" );
			$$.a = assignAST($6.a);
	 	}

	| VAR_NAME COLON DECLINTEGER SEMICOLON {
		
	}

	| VAR_NAME COLON DECLFLOAT COLON EQUAL VAR_NAME SEMICOLON {
			{$$.s = "Declaracion de variable Float igual a variable float"; 
				if(checkVarAndType(tabla, size, $6.s,"float")) {
					insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, $6.s), $1.s, &elementosOcupados, "float" );
					$$.a = assignAST($6.a);
				}
			}
		} //variable : Float := cosas ;
	| VAR_NAME COLON DECLFLOAT COLON EQUAL VAR_NAME OPERATOR VAR_NAME SEMICOLON {}
	| VAR_NAME COLON DECLFLOAT COLON EQUAL VAR_NAME OPERATOR OPERATION2 SEMICOLON {}
	| VAR_NAME COLON DECLFLOAT COLON EQUAL OPERATION2 OPERATOR VAR_NAME SEMICOLON {} //ignore ARIT OP VAR
	| VAR_NAME COLON DECLFLOAT COLON EQUAL OPERATION2 SEMICOLON 
	{$$.s = "Declaracion de variable Float igual a operacion aritmetica";
	insertElement(tabla, &size, 0, "", $6.f, $1.s, &elementosOcupados, "float" );
	$$.a = assignAST($6.a);}
	| VAR_NAME COLON DECLFLOAT SEMICOLON {}

	| VAR_NAME COLON DECLBOOLEAN COLON EQUAL VAR_NAME SEMICOLON {}
	| VAR_NAME COLON DECLBOOLEAN COLON EQUAL VAR_NAME BOOLEAN_OP VAR_NAME SEMICOLON {}
	| VAR_NAME COLON DECLBOOLEAN COLON EQUAL VAR_NAME BOOLEAN_OP INT SEMICOLON {}
	| VAR_NAME COLON DECLBOOLEAN COLON EQUAL VAR_NAME BOOLEAN_OP FLOAT SEMICOLON {}
	| VAR_NAME COLON DECLBOOLEAN COLON EQUAL INT BOOLEAN_OP VAR_NAME SEMICOLON {}
	| VAR_NAME COLON DECLBOOLEAN COLON EQUAL FLOAT BOOLEAN_OP VAR_NAME SEMICOLON {}
	| VAR_NAME COLON DECLBOOLEAN COLON EQUAL BOOL SEMICOLON {}
	| VAR_NAME COLON DECLBOOLEAN COLON EQUAL BOOLEAN_VAR SEMICOLON {}
	| VAR_NAME COLON DECLBOOLEAN SEMICOLON {}
	| VAR_NAME COLON DECLSTRING COLON EQUAL VAR_NAME SEMICOLON {
			{$$.s = "Declaracion de variable String igual a variable String"; 
				if(checkVarAndType(tabla, size, $6.s,"string")) {
					insertElement(tabla, &size, 0, retrieveStringFromTable(tabla, size, $6.s), 0.0, $1.s, &elementosOcupados, "string" );
					$$.a = assignAST($6.a);
				}
			}
		}
	| VAR_NAME COLON DECLSTRING COLON EQUAL STRING SEMICOLON 
		{
			$$.s = "Declaracion con string";
			insertElement(tabla, &size, 0, $6.s, 0.0, $1.s, &elementosOcupados, "string" );
			$$.a = assignAST($6.a);
		}
	| VAR_NAME COLON DECLSTRING SEMICOLON {$$.s = "Declaracion de variable String";}

	| VAR_NAME COLON EQUAL VAR_NAME SEMICOLON {} //variable : Integer := VARIABLE + ARIT ;
	| VAR_NAME COLON EQUAL VAR_NAME OPERATOR VAR_NAME SEMICOLON {}
	| VAR_NAME COLON EQUAL VAR_NAME OPERATOR OPERATION SEMICOLON {$$.s = "Variable igual a Variable operacion con operacion aritmetica";}
	| VAR_NAME COLON EQUAL VAR_NAME OPERATOR OPERATION2 SEMICOLON {}
	| VAR_NAME COLON EQUAL OPERATION OPERATOR VAR_NAME SEMICOLON {}
	| VAR_NAME COLON EQUAL OPERATION2 OPERATOR VAR_NAME SEMICOLON {}
	| VAR_NAME COLON EQUAL OPERATION SEMICOLON {}
	| VAR_NAME COLON EQUAL OPERATION2 SEMICOLON {}
	| VAR_NAME COLON EQUAL VAR_NAME BOOLEAN_OP VAR_NAME SEMICOLON {}
	| VAR_NAME COLON EQUAL VAR_NAME BOOLEAN_OP INT SEMICOLON {}
	| VAR_NAME COLON EQUAL VAR_NAME BOOLEAN_OP FLOAT SEMICOLON {}
	| VAR_NAME COLON EQUAL INT BOOLEAN_OP VAR_NAME SEMICOLON {}
	| VAR_NAME COLON EQUAL FLOAT BOOLEAN_OP VAR_NAME SEMICOLON {}
	| VAR_NAME COLON EQUAL BOOLEAN_OP SEMICOLON {}
	| VAR_NAME COLON EQUAL BOOLEAN_VAR SEMICOLON {}
	| VAR_NAME COLON EQUAL STRING SEMICOLON {}

	| TYPE VAR_NAME IS RANGE INT DOTDOT INT SEMICOLON {}
	| TYPE VAR_NAME IS DECLARRAY LEFT INT DOTDOT INT RIGHT OF VAR_NAME SEMICOLON {}
	| VAR_NAME COLON VAR_NAME COLON EQUAL LEFT INT AUXINT RIGHT SEMICOLON {}

	// variable : Integer ;
	// variable := 3 + 3 ;
	// variable : Integer := 3 + 3 ;
;

CONTENT: 
	IF_COND  {printf("Contenido: %s\t Linea: %d\n", $1.s, yylineno); if(!$1.a){ ;} else {eval(*$1.a, &size);};}
	| BOOLEAN_OP  {printf("%s", $1.s);}
	| BOOLEAN_MIX  {printf("%s", $1.s);}
	| WLOOP  {printf("%s", $1);}
	| COM  {printf("Contenido: %s\t Linea: %d\n", $1, yylineno); }
	| DECL {printf("Contenido: %s\t Linea: %d\n", $1.s, yylineno); if(!$1.a){ ;} else {eval(*$1.a, &size);};}
;

OPERATOR:
	PLUS {$$.operador = "+";}
	| MINUS {$$.operador = "-";}
	| MULTIPLY {$$.operador = "*";}
	| DIVIDE {$$.operador = "/";}
;
	
OPERATION: 
	INT	{$$.i = $1.i; $$.a = createNum($1.i);}
	|	OPERATION PLUS OPERATION	{$$.i = $1.i + $3.i; $$.a = newast("+",$1.a,$3.a);}
	| OPERATION MINUS OPERATION	{$$.i = $1.i - $3.i; $$.a = newast("-",$1.a,$3.a);}
	| OPERATION MULTIPLY OPERATION	{$$.i = $1.i * $3.i; $$.a = newast("*",$1.a,$3.a);}
	| OPERATION DIVIDE OPERATION	{$$.i = $1.i / $3.i; $$.a = newast("/",$1.a,$3.a);}
	| LEFT OPERATION RIGHT {$$.i = $2.i;}
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
	COMPARE {$$.s = "IGUAL";$$.operador = "+";}
	| MORE {$$.s = "MAYOR";$$.operador = ">";}
	| LESS {$$.s = "MENOR";$$.operador = "<";}
	| GREATER_THAN {$$.s = "MAYOR IGUAL";$$.operador = ">=";}
	| LESSER_THAN {$$.s = "MENOR IGUAL";$$.operador = "<=";}
	| NOT_EQUAL {$$.s = "DESIGUAL";$$.operador = "!=";}
;
// VARIABLES BOOLEANAS
BOOLEAN_VAR:
	TRUE {$$.s="True"; $$.a = createBOOLVAR("True");}
	| FALSE {$$.s="False"; $$.a = createBOOLVAR("False");}
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
	INT BOOLEAN_OPERATORS INT 			{$$.s = "INT OP BOOL INT";}
	| INT BOOLEAN_OPERATORS FLOAT 			{$$.s = "INT OP BOOL FLOAT";}
	| FLOAT BOOLEAN_OPERATORS INT 			{$$.s = "FLOAT OP BOOL INT";}
	| FLOAT BOOLEAN_OPERATORS FLOAT 			{$$.s = "FLOAT OP BOOL FLOAT";} //INT fuera
	| VAR_NAME BOOLEAN_OPERATORS INT 			{$$.s = "INT OP BOOL INT";}
	| INT BOOLEAN_OPERATORS VAR_NAME 			{$$.s = "INT OP BOOL INT";}
	| VAR_NAME BOOLEAN_OPERATORS FLOAT 			{$$.s = "FLOAT OP BOOL FLOAT";}
	| FLOAT BOOLEAN_OPERATORS VAR_NAME 			{$$.s = "FLOAT OP BOOL FLOAT";}
	| VAR_NAME BOOLEAN_OPERATORS VAR_NAME 			{$$.s = "VAR OP BOOL VAR";}
	| LEFT BOOLEAN_OP RIGHT 	{$$.s = "PARENTESIS BOOL PARENTESIS";}
;

COM:
	COMMENT {$$ = "Comentario\n";}
;

IF_COND: 
	IF BOOLEAN_OP THEN	{$$.s = "IF BOOL THEN";}
	| ELSE  				{$$.s = "ELSE";}
    | ELSEIF BOOLEAN_OP THEN  	{$$.s = "ELSEIF BOOL THEN";}
	| END IF SEMICOLON 		{$$.s = "END IF SEMICOLON";}

;

WLOOP:
	WHILE BOOLEAN_OP LOOP_ {$$ = "Bucle while\n";}
	| END LOOP_ SEMICOLON {$$="Fin de bucle\n";}
;

BEGIN:
	BEG {$$ = "Begin\n";}
	| END SEMICOLON {$$ = "End begin\n";}
;

VAR_NAME:
	VAR {$$.s = $1; $$.a = createSTR($1);}
;

STRING:
	STR {$$.s = $1; $$.a = createSTR($1);}
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
    int status = -1;
    while (i < *size && status == -1) {
        if (strcmp(tabla[i].vname, nombre) == 0 && (strcmp(tabla[i].type, tipo) == 0 )) {
            status = i;
        }else if(strcmp(tabla[i].vname, nombre) == 0){ 
        	status = i;
        }else {
            i++;
        }
    }
    return status;
}


void insertElement(struct symb *tabla, int *size, int valor, char* svalor, float fvalor, char *variable, int *elementosOcupados, char* type ) {
	int status = 0;
	
    status = buscarValor(tabla, variable, type, size);

    if(status != -1){
    	if (strcmp(type, "integer") == 0){
	        		tabla[status].vname = variable;
	        		tabla[status].vvali = valor;
	        		tabla[status].type = type;
	            } else if (strcmp(type, "float") == 0) {
	                tabla[status].vname = variable;
	                tabla[status].vvalf = fvalor;
	                tabla[status].type = type;
	            } else if (strcmp(type, "string") == 0) {
	                tabla[status].vname = variable;
	                tabla[status].vvals = svalor;
	                tabla[status].type = type;
	            }        	
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
	            }        	
	            
	            *elementosOcupados = *elementosOcupados + 1;
	            encontrado = 1;
	        } else {
	            i++;
	        }
	    }
    }
     
}

// void retrieveElement(struct symb *tabla, int size, char* name) {
// 	int elementIndex = -1;
// 	for(int i = 0; i < size; i++) {
// 		if(strcmp(tabla[i].vname, name) == 0) {
// 			elementIndex = i;
// 			break;
// 		}
// 	}
// 	printf("%s", tabla[elementIndex].vvals);

// 	//return tabla[elementIndex];
// };

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
		printf("Nombre %s ",tabla[b].vname);
		printf("INT %i ",tabla[b].vvali);
		printf("FLOAT %f ",tabla[b].vvalf);
		printf("STRING %s ",tabla[b].vvals);
		printf("TIPO %s ",tabla[b].type);
		printf("\n");

	}
	printAST(nodos,0,0,0);
}