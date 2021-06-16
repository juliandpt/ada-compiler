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

bool checkVarAndType(struct symb *tabla, int size, char* name, char* type);
bool searchVar(struct symb *tabla, int size, char* name);
int compare(char* operator, float left, float right);

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
		char* error;
		int boo;
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
		PROCEDURE VAR_NAME IS ADDCONTENT END VAR_NAME SEMICOLON {
			if(strcmp($2.s, $6.s) == 0){
				printf("de super puta madre socio");
			} else {
				printf("tonto");
			}
			printf("%s", "procline");}
;

ADDCONTENT:	ADDCONTENT CONTENT | ;

AUXINT: COMMA INT {}
	| {}
;

DECL: VAR_NAME COLON DECLINTEGER COLON EQUAL VAR_NAME SEMICOLON 
	{$$.s = "Declaracion de variable Integer igual a variable"; 
	if(searchVar(tabla, size, $1.s) && checkVarAndType(tabla, size, $6.s,"integer")) {
			insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s), "", 0.0, $1.s, false, &elementosOcupados, "integer", true );
			$$.a = assignAST($6.a);
		} else {yyerror("Variable declared or wrong type");}
	}
	| VAR_NAME COLON DECLINTEGER COLON EQUAL VAR_NAME OPERATOR VAR_NAME SEMICOLON {
			$$.s = "Declaracion de variable Integer igual a variable integer + variable integer"; 
			if(searchVar(tabla, size, $1.s) && checkVarAndType(tabla, size, $6.s, "integer") && checkVarAndType(tabla, size, $8.s, "integer")) {
				$$.error = "empty";
				if(strcmp($7.operador, "+") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) + retrieveIntFromTable(tabla, size, $8.s), "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				if(strcmp($7.operador, "-") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) - retrieveIntFromTable(tabla, size, $8.s), "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				if(strcmp($7.operador, "*") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) * retrieveIntFromTable(tabla, size, $8.s), "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				if(strcmp($7.operador, "/") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) / retrieveIntFromTable(tabla, size, $8.s), "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				$$.a = assignAST(newast($7.operador, $6.a, $8.a));
			} else {$$.error = "Variable declared or wrong type";}
		}
	| VAR_NAME COLON DECLINTEGER COLON EQUAL VAR_NAME OPERATOR OPERATION SEMICOLON {
			$$.s = "Declaracion de variable Integer igual a variable integer + operacion"; 
			if(searchVar(tabla, size, $1.s) && checkVarAndType(tabla, size, $6.s, "integer")) {
				$$.error = "empty";
				if(strcmp($7.operador, "+") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) + $8.i, "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				if(strcmp($7.operador, "-") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) - $8.i, "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				if(strcmp($7.operador, "*") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) * $8.i, "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				if(strcmp($7.operador, "/") == 0) { insertElement(tabla, &size, retrieveIntFromTable(tabla, size, $6.s) / $8.i, "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				$$.a = assignAST(newast($7.operador, $6.a, $8.a));
			} else {$$.error = "Variable declared or wrong type";}
		}
	| VAR_NAME COLON DECLINTEGER COLON EQUAL OPERATION OPERATOR VAR_NAME SEMICOLON {
			$$.s = "Declaracion de variable Integer igual a operacion + variable integer"; 
			if(searchVar(tabla, size, $1.s) && checkVarAndType(tabla, size, $6.s, "integer")) {
				$$.error = "empty";
				if(strcmp($7.operador, "+") == 0) { insertElement(tabla, &size, $8.i + retrieveIntFromTable(tabla, size, $6.s), "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				if(strcmp($7.operador, "-") == 0) { insertElement(tabla, &size, $8.i - retrieveIntFromTable(tabla, size, $6.s), "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				if(strcmp($7.operador, "*") == 0) { insertElement(tabla, &size, $8.i * retrieveIntFromTable(tabla, size, $6.s), "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				if(strcmp($7.operador, "/") == 0) { insertElement(tabla, &size, $8.i / retrieveIntFromTable(tabla, size, $6.s), "", 0.0, $1.s, false, &elementosOcupados, "integer", true ); }
				$$.a = assignAST(newast($7.operador, $6.a, $8.a));
			} else {$$.error = "Variable declared or wrong type";}
		}
	| VAR_NAME COLON DECLINTEGER COLON EQUAL OPERATION SEMICOLON {
			$$.s = "Declaracion de variable Integer igual a operacion aritmetica"; 
			if (searchVar(tabla, size, $1.s)) {
				$$.error = "empty";insertElement(tabla, &size, $6.i, "", 0.0, $1.s, false, &elementosOcupados, "integer", true );$$.a = assignAST($6.a);} else {$$.error = "Variable declared or wrong type";}
	 	}

	| VAR_NAME COLON DECLINTEGER SEMICOLON {
		$$.s = "Declaracion de variable Integer vacia";
		if (searchVar(tabla, size, $1.s)) {
				$$.error = "empty";insertElement(tabla, &size, 0, "", 0.0, $1.s, false, &elementosOcupados, "integer", false );} else {$$.error = "Variable declared";}
	}

	| VAR_NAME COLON DECLFLOAT COLON EQUAL VAR_NAME SEMICOLON {
			{$$.s = "Declaracion de variable Float igual a variable float"; 
				if(searchVar(tabla, size, $1.s) && checkVarAndType(tabla, size, $6.s,"float")) {
				$$.error = "empty";
					insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, $6.s), $1.s, false, &elementosOcupados, "float", true );
					$$.a = assignAST($6.a);
				} else {$$.error = "Variable declared or wrong type";}
			}
		}
	| VAR_NAME COLON DECLFLOAT COLON EQUAL VAR_NAME OPERATOR VAR_NAME SEMICOLON {
			$$.s = "Declaracion de variable float igual a variable float + variable float"; 
			if(searchVar(tabla, size, $1.s) && checkVarAndType(tabla, size, $6.s, "float") && checkVarAndType(tabla, size, $8.s, "float")) {
				$$.error = "empty";
				if(strcmp($7.operador, "+") == 0) { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, $6.s) + retrieveFloatFromTable(tabla, size, $8.s), $1.s, false, &elementosOcupados, "float", true ); }
				if(strcmp($7.operador, "-") == 0) { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, $6.s) - retrieveFloatFromTable(tabla, size, $8.s), $1.s, false, &elementosOcupados, "float", true ); }
				if(strcmp($7.operador, "*") == 0) { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, $6.s) * retrieveFloatFromTable(tabla, size, $8.s), $1.s, false, &elementosOcupados, "float", true ); }
				if(strcmp($7.operador, "/") == 0) { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, $6.s) / retrieveFloatFromTable(tabla, size, $8.s), $1.s, false, &elementosOcupados, "float", true ); }
				$$.a = assignAST(newast($7.operador, $6.a, $8.a));
			} else {$$.error = "Variable declared or wrong type";}
		}
	| VAR_NAME COLON DECLFLOAT COLON EQUAL VAR_NAME OPERATOR OPERATION2 SEMICOLON {
			$$.s = "Declaracion de variable float igual a variable float + operacion"; 
			if(searchVar(tabla, size, $1.s) && checkVarAndType(tabla, size, $6.s, "float")) {
				$$.error = "empty";
				if(strcmp($7.operador, "+") == 0) { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, $6.s) + $8.f, $1.s, false, &elementosOcupados, "float", true ); }
				if(strcmp($7.operador, "-") == 0) { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, $6.s) - $8.f, $1.s, false, &elementosOcupados, "float", true ); }
				if(strcmp($7.operador, "*") == 0) { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, $6.s) * $8.f, $1.s, false, &elementosOcupados, "float", true ); }
				if(strcmp($7.operador, "/") == 0) { insertElement(tabla, &size, 0, "", retrieveFloatFromTable(tabla, size, $6.s) / $8.f, $1.s, false, &elementosOcupados, "float", true ); }
				$$.a = assignAST(newast($7.operador, $6.a, $8.a));
			} else {$$.error = "Variable declared or wrong type";}
		}
	| VAR_NAME COLON DECLFLOAT COLON EQUAL OPERATION2 OPERATOR VAR_NAME SEMICOLON {
			$$.s = "Declaracion de variable float igual a operacion + variable float"; 
			if(searchVar(tabla, size, $1.s) && checkVarAndType(tabla, size, $6.s, "float")) {
				$$.error = "empty";
				if(strcmp($7.operador, "+") == 0) { insertElement(tabla, &size, 0, "", $8.f + retrieveFloatFromTable(tabla, size, $6.s), $1.s, false, &elementosOcupados, "float", true ); }
				if(strcmp($7.operador, "-") == 0) { insertElement(tabla, &size, 0, "", $8.f - retrieveFloatFromTable(tabla, size, $6.s), $1.s, false, &elementosOcupados, "float", true ); }
				if(strcmp($7.operador, "*") == 0) { insertElement(tabla, &size, 0, "", $8.f * retrieveFloatFromTable(tabla, size, $6.s), $1.s, false, &elementosOcupados, "float", true ); }
				if(strcmp($7.operador, "/") == 0) { insertElement(tabla, &size, 0, "", $8.f / retrieveFloatFromTable(tabla, size, $6.s), $1.s, false, &elementosOcupados, "float", true ); }
				$$.a = assignAST(newast($7.operador, $6.a, $8.a));
			} else {$$.error = "Variable declared or wrong type";}
		}
	| VAR_NAME COLON DECLFLOAT COLON EQUAL OPERATION2 SEMICOLON 
	{$$.s = "Declaracion de variable Float igual a operacion aritmetica";
	if(searchVar(tabla, size, $1.s)) {
				$$.error = "empty"; insertElement(tabla, &size, 0, "", $6.f, $1.s, false, &elementosOcupados, "float", true );$$.a = assignAST($6.a);} else {$$.error = "Variable declared or wrong type";}}
	| VAR_NAME COLON DECLFLOAT SEMICOLON {
		$$.s = "Declaracion de variable float vacia";
		if (searchVar(tabla, size, $1.s)) {
				$$.error = "empty";insertElement(tabla, &size, 0, "", 0.0, $1.s, false, &elementosOcupados, "float", false );} else {$$.error = "Variable declared";}
	}
	| VAR_NAME COLON DECLBOOLEAN COLON EQUAL VAR_NAME SEMICOLON {
			if(searchVar(tabla, size, $1.s) && checkVarAndType(tabla, size, $6.s, "boolean")) {
				printf("comeme los huevos");
				$$.error = "empty";
				insertElement(tabla, &size, 0, "", 0.0, $1.s, retrieveBoolFromTable(tabla, size, $6.s), &elementosOcupados, "boolean", true );
				$$.a = assignAST($6.a);
			} else {$$.error = "Variable declared or wrong type";}
			$$.s = "Declaracion de variable Boolean a operacion booleana";
		}
	| VAR_NAME COLON DECLBOOLEAN COLON EQUAL BOOLEAN_OP SEMICOLON {
			if(strcmp($6.error,"empty") == 0 ){
				if(searchVar(tabla, size, $1.s)) {
					printf("comeme los huevos2");
					$$.error = "empty";
					insertElement(tabla, &size, 0, "", 0.0, $1.s, $6.boo ? true : false, &elementosOcupados, "boolean", true );
					$$.a = assignAST($6.a);
				} else {$$.error = "Variable declared or wrong type";}
			} else {
				$$.error = $6.error;
			}
			
			$$.s = "Declaracion de variable Boolean a operacion booleana";
		}
	| VAR_NAME COLON DECLBOOLEAN SEMICOLON {
			$$.s = "Declaracion de variable Boolean vacia";
			if (searchVar(tabla, size, $1.s)) {
			$$.error = "empty";insertElement(tabla, &size, 0, "", 0.0, $1.s, false, &elementosOcupados, "boolean", false );} else {$$.error = "Variable declared";}
		}
	| VAR_NAME COLON DECLSTRING COLON EQUAL VAR_NAME SEMICOLON {
			{$$.s = "Declaracion de variable String igual a variable String"; 
				if(searchVar(tabla, size, $1.s) && checkVarAndType(tabla, size, $6.s,"string")) {
					$$.error = "empty";
					insertElement(tabla, &size, 0, retrieveStringFromTable(tabla, size, $6.s), 0.0, $1.s, false, &elementosOcupados, "string", true );
					$$.a = assignAST($6.a);
				} else {$$.error = "Variable declared or wrong type";}
			}
		}
	| VAR_NAME COLON DECLSTRING COLON EQUAL STRING SEMICOLON 
		{
			$$.s = "Declaracion con string";
			if(searchVar(tabla, size, $1.s)) {
				$$.error = "empty"; insertElement(tabla, &size, 0, $6.s, 0.0, $1.s, false, &elementosOcupados, "string", true );$$.a = assignAST($6.a);} else {$$.error = "Variable declared or wrong type";}
		}
	| VAR_NAME COLON DECLSTRING SEMICOLON {$$.s = "Declaracion de variable String";}

	| VAR_NAME COLON EQUAL VAR_NAME SEMICOLON {} 
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
	| BOOLEAN_OP  {printf("%s", "$1.s");}
	| BOOLEAN_MIX  {printf("%s", $1.s);}
	| WLOOP  {printf("%s", $1);}
	| COM  {printf("Contenido: %s\t Linea: %d\n", $1, yylineno); }
	| DECL {if(strcmp($1.error, "empty") == 0){printf("Contenido: %s\t Linea: %d\n", $1.s, yylineno); if(!$1.a){ ;} else {eval(*$1.a, &size);};} else {yyerror($1.error);}}
;

OPERATOR:
	PLUS {$$.operador = "+";}
	| MINUS {$$.operador = "-";}
	| MULTIPLY {$$.operador = "*";}
	| DIVIDE {$$.operador = "/";}
;
	
OPERATION: 
	INT	{$$.i = $1.i; $$.a = createNum($1.i);}
	| OPERATION PLUS OPERATION	{$$.i = $1.i + $3.i; $$.a = newast("+",$1.a,$3.a);}
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
	COMPARE {$$.s = "IGUAL";$$.operador = "==";}
	| MORE {$$.s = "MAYOR";$$.operador = ">";}
	| LESS {$$.s = "MENOR";$$.operador = "<";}
	| GREATER_THAN {$$.s = "MAYOR IGUAL";$$.operador = ">=";}
	| LESSER_THAN {$$.s = "MENOR IGUAL";$$.operador = "<=";}
	| NOT_EQUAL {$$.s = "DESIGUAL";$$.operador = "!=";}
;
// VARIABLES BOOLEANAS
BOOLEAN_VAR:
	TRUE {$$.boo=1; $$.a = createBOOLVAR("True");}
	| FALSE {$$.boo=0; $$.a = createBOOLVAR("False");}
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
	OPERATION BOOLEAN_OPERATORS OPERATION 			{$$.s = "INT OP BOOL INT";$$.boo = compare($2.operador, (float)$1.i, (float)$3.i); $$.a=newast($2.operador, $1.a, $3.a); }
	| OPERATION BOOLEAN_OPERATORS OPERATION2 			{$$.s = "INT OP BOOL FLOAT";$$.boo = compare($2.operador, (float)$1.i, $3.f); $$.a=newast($2.operador, $1.a, $3.a);}
	| OPERATION2 BOOLEAN_OPERATORS OPERATION 			{$$.s = "FLOAT OP BOOL INT";$$.boo = compare($2.operador, $1.f, (float)$3.i); $$.a=newast($2.operador, $1.a, $3.a);}
	| OPERATION2 BOOLEAN_OPERATORS OPERATION2 			{$$.s = "FLOAT OP BOOL FLOAT"; $$.boo = compare($2.operador, $1.f, $3.f); $$.a=newast($2.operador, $1.a, $3.a);}
	| VAR_NAME BOOLEAN_OPERATORS OPERATION 			{
			$$.s = "VAR OP BOOL INT";
			if(!searchVar(tabla, size, $1.s)) {
				$$.error = "empty";
				if(strcmp("integer", getVarType(tabla, size, $1.s)) == 0){
					$$.boo = compare($2.operador, (float)retrieveIntFromTable(tabla, size, $1.s), (float)$3.i);
					$$.a=newast($2.operador, $1.a, $3.a);
				} else if(strcmp("float", getVarType(tabla, size, $1.s))  == 0){
					$$.boo = compare($2.operador, retrieveFloatFromTable(tabla, size, $1.s), (float)$3.i);
					$$.a=newast($2.operador, $1.a, $3.a);
				} else {
					$$.error = "Esta variable tiene un tipo incorrecto";
				}  
				
			} else {$$.error = "Variable declared or wrong type";}
		}
	| OPERATION BOOLEAN_OPERATORS VAR_NAME 			{$$.s = "INT OP BOOL INT";$$.boo = compare($2.operador, (float)$1.i, (float)$3.i); $$.a=newast($2.operador, $1.a, $3.a);}
	| VAR_NAME BOOLEAN_OPERATORS OPERATION2 			{$$.s = "FLOAT OP BOOL FLOAT";$$.boo = compare($2.operador, (float)$1.i, $3.f); $$.a=newast($2.operador, $1.a, $3.a);}
	| OPERATION2 BOOLEAN_OPERATORS VAR_NAME 			{$$.s = "FLOAT OP BOOL FLOAT";$$.boo = compare($2.operador, $1.f, (float)$3.i); $$.a=newast($2.operador, $1.a, $3.a);}
	| VAR_NAME BOOLEAN_OPERATORS VAR_NAME 			{$$.s = "VAR OP BOOL VAR";$$.boo = compare($2.operador, (float)$1.i, (float)$3.i); $$.a=newast($2.operador, $1.a, $3.a);}
	| LEFT BOOLEAN_OP RIGHT 	{$$.s = "PARENTESIS BOOL PARENTESIS"; }
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
	}  
	
}

char* getVarType(struct symb *tabla, int size, char* name) {
	printf("%s\n",name);
	for(int i = 0; i < size; i++) {
		if(strcmp(tabla[i].vname, "._empty") == 0){
			continue;
		} else if (strcmp(tabla[i].vname, name) == 0) {
			printf("%s\n", tabla[i].type);
			return tabla[i].type;
		}
	}
}

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