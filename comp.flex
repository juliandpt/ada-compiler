%{
#include <stdio.h>
#include "y.tab.h"
int nc, np, nl;
%}
%option noyywrap 
%option yylineno

string (\".+\")
char (\'.{1}\')
variable_name ([a-zA-Z])+([a-zA-Z]|[0-9]|[_])*
procedure (procedure|PROCEDURE)
is (is|IS)
end (end|END)
fnum ([0-9])+[\,|\.]([0-9])+
inum ([0-9])+
bool (bool|boolean)
end (end|END)
int (integer)
stringd (String)
character (character)
float (float)
while (while|WHILE)
false (false|FALSE)
true (true|TRUE)
and (and|AND)
or (or|OR)
if (if|IF)
is (is|IS)
then (then|THEN)
%%
[ \t]	;
{true}  {return TRUE;} //funciona por algun motivo, hay que poner esto arriba del todo
"procedure" {return PROCEDURE;}
"is" {return IS;}
{then}  {return THEN;}
{if}  	{return IF;}
{false} {return FALSE;}
{char}  {yylval.sval = strdup(yytext);return CHAR;}
{bool}  {return BOOL;}
{and} 	{return AND;}
{or} 	{return OR;}
{int} 	{return INTEGERDEC;}
{end} {return END;}
{float} {return FLOATDEC;}
{character} {return CHARDEC;}
{stringd} {return STRINGDEC;}
{fnum}	{yylval.fval = atof(yytext); return FLOAT;}
{inum}	{yylval.eval = atoi(yytext); return INT;}
{string}  {yylval.sval = strdup(yytext);return STR;}
{variable_name}  {yylval.sval = strdup(yytext);return VAR;}
{is} {return IS;}
{end} {return END;}
"\n"    {return NEWLINE;}
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
