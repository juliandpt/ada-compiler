%{
#include <stdio.h>
int nc, np, nl;
%}
%option noyywrap 
%option yylineno

digito [0-9]
letra [a-zA-Z]
%%
--.+ {fprintf(yyout,"%-40s%-60s%-15d\n","COMENTARIO", yytext, yylineno);} 
\/\*(.|\n)+\*\/ {fprintf(yyout,"%-40s%-60s%-15d\n","COMENTARIO", yytext, yylineno);} 

\".+\" {fprintf(yyout,"%-40s%-60s%-15d\n","CADENA DE CARACTERES",yytext,yylineno);}
\'{letra}\' {fprintf(yyout,"%-40s%-60s%-15d\n","CARACTER",yytext,yylineno);}
[-+]?{digito}+ {fprintf(yyout,"%-40s%-60s%-15d\n","ENTERO",yytext,yylineno);}
[-+]?{digito}+.{digito}+ {fprintf(yyout,"%-40s%-60s%-15d\n","FLOAT",yytext,yylineno);}
(True)|(False) {fprintf(yyout,"%-40s%-60s%-15d\n","BOOLEAN",yytext,yylineno);}

while {fprintf(yyout,"%-40s%-60s%-15d\n","WHILE",yytext,yylineno);}
for {fprintf(yyout,"%-40s%-60s%-15d\n","FOR",yytext,yylineno);}
case {fprintf(yyout,"%-40s%-60s%-15d\n","CASE",yytext,yylineno);}
if {fprintf(yyout,"%-40s%-60s%-15d\n","IF",yytext,yylineno);}

\+ {fprintf(yyout,"%-40s%-60s%-15d\n","SUMA",yytext,yylineno);}
\- {fprintf(yyout,"%-40s%-60s%-15d\n","RESTA",yytext,yylineno);}
\* {fprintf(yyout,"%-40s%-60s%-15d\n","MULTIPLICACION",yytext,yylineno);}
\/ {fprintf(yyout,"%-40s%-60s%-15d\n","DIVISION",yytext,yylineno);}

\< {fprintf(yyout,"%-40s%-60s%-15d\n","MENOR",yytext,yylineno);}
\> {fprintf(yyout,"%-40s%-60s%-15d\n","MAYOR",yytext,yylineno);}
\/= {fprintf(yyout,"%-40s%-60s%-15d\n","IGUAL",yytext,yylineno);}
\<= {fprintf(yyout,"%-40s%-60s%-15d\n","MENOR O IGUAL",yytext,yylineno);}
\>= {fprintf(yyout,"%-40s%-60s%-15d\n","MAYOR O IGUAL",yytext,yylineno);}

(\{)|(\}) {fprintf(yyout,"%-40s%-60s%-15d\n","DELIMITADOR",yytext,yylineno);}
(\=)|(\:=) {fprintf(yyout,"%-40s%-60s%-15d\n","OPERADOR ASIGNACION",yytext,yylineno);}
(\()|(\)) {fprintf(yyout,"%-40s%-60s%-15d\n","PARENTESIS",yytext,yylineno);}
\; {fprintf(yyout,"%-40s%-60s%-15d\n","CARACTER FINAL SENTENCIA",yytext,yylineno);}
\: {fprintf(yyout,"%-40s%-60s%-15d\n","DOS PUNTOS",yytext,yylineno);}

(range)|(array) {fprintf(yyout,"%-40s%-60s%-15d\n","ARRAY",yytext,yylineno);}

(procedure)|(function)|(exception)|(begin)|(then)|(end)|(return) {fprintf(yyout,"%-40s%-60s%-15d\n","FUNCIONES Y PROCEDIMIENTOS",yytext,yylineno);}

{letra}({letra}|{digito})* {fprintf(yyout,"%-40s%-60s%-15d\n", "IDENTIFICADOR",yytext,yylineno);}

[[:space:]]+|\n {/*evitar que otros errores aparezcan*/}
. {fprintf(yyout,"%-40s%-60s%-15d\n", "ERROR ENCONTRADO",yytext,yylineno);}

%%
int main(int argc,char *argv[]) {
 
if ((yyin = fopen(argv[1], "rt")) == NULL) {
	printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
} else {
	if ((yyout = fopen( "./salida.txt", "wt" )) == NULL ) {
		printf("Error creando el fichero de salida.\n");
	} else {
		fprintf(yyout,"COMPILADORES Y LENGUAJES FORMALES\n\n\n");
		fprintf(yyout,"%-40s%-60s%-15s\n", "TOKEN","LEXEMA", "LINEA");
		fprintf(yyout,"%-40s%-60s%-15s\n", "-----","------", "------\n");
		yylex();
		printf("\nFichero salida.txt generado correctamente!!\n");
	}
}

fclose(yyin);

return 0;
}