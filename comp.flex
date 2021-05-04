%{
#include <stdio.h>
#include "y.tab.h"
int nc, np, nl;
%}
%option noyywrap 
%option yylineno

string (\".+\")
char (\'.{1}\')
fnum ([0-9])+[\,|\.]([0-9])+
inum ([0-9])+
bool (bool|boolean)
int (integer)
stringd (String)
character (character)
float (float)
while (while|WHILE)
false (false|FALSE)
true (true|TRUE)
and (and|AND)
or (or|OR)
if(if|IF)
then (then|THEN)
%%
[ \0]	; // ignore all null
[ \n]   ; // ignore all whitespace
{true}  {return TRUE;} //funciona por algun motivo, hay que poner esto arriba del todo
{then}  {return THEN;}
{if}  	{return IF;}
{false} {return FALSE;}
{char}  {return CHAR;}
{bool}  {return BOOL;}
{and} 	{return AND;}
{or} 	{return OR;}
{int} 	{return INTEGERDEC;}
{float} {return FLOATDEC;}
{character} {return CHARDEC;}
{stringd} {return STRINGDEC;}
{fnum}	{yylval.fval = atof(yytext); return FLOAT;}
{inum}	{yylval.ival = atoi(yytext); return INT;}
{string}  {return STR;}
":"		{return COLON;}
";"		{return SEMICOLON;}
"{"		{return OPEN;}
"}"		{return CLOSE;}
"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return MULTIPLY;}
"/"		{return DIVIDE;}
"("		{return LEFT;}
")"		{return RIGHT;}
"<"		{return LESS;}
">"		{return MORE;}
"="		{return EQUAL;}
"--"	{return COMMENT;}
">="    {return GREATER_THAN;}
"<="    {return LESSER_THAN;}
"!="    {return NOT_EQUAL;}
"=="    {return COMPARE;}

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