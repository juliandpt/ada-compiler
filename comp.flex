%{
#include <stdio.h>
#include "y.tab.h"
int nc, np, nl;
%}
%option noyywrap 
%option yylineno

bool (bool|boolean)
false (false|FALSE)
true (true|TRUE)

variable_name ([a-zA-Z|0-9|_|])+
string (\".+\")
fnum ([0-9])+[\,|\.]([0-9])+
inum ([0-9])+
procedure (procedure|procedure)
range (range|RANGE)
while (while|WHILE)
for (for|FOR)
case (case|CASE)
when (when|WHEN)
is (is|IS)
others (others|OTHERS)
end (end|END)
loop (loop|LOOP)
of (of|OF)
type (type|TYPE)

and (and|AND)
or (or|OR)

if (if|IF)
else (else|ELSE)
elseif (elseif|ELSEIF)
then (then|THEN)

%%

[ \t]	;
"\n"		{}
{true}  {return TRUE;} //funciona por algun motivo, hay que poner esto arriba del todo
{procedure} {return PROCEDURE;}
{is} {return IS;}
{end} {return END;}
{range} {return RANGE;}
{case}  {return CASE;}
{when}  {return WHEN;}
{then}  {return THEN;}
{if}  	{return IF;}
{false} {return FALSE;}
{bool}  {return BOOL;}
"Boolean" {return DECLBOOLEAN;}
{and} 	{return AND;}
{or} 	{return OR;}
"Integer" {return DECLINTEGER;}
"Float" {return DECLFLOAT;}
{fnum}	{yylval.fval = atof(yytext); return FLOAT;}
{inum}	{yylval.eval = atoi(yytext); return INT;}
{string}  {yylval.sval = strdup(yytext);return STR;}
"String" {return DECLSTRING;}
"array" {return DECLARRAY;}
{while} {return WHILE;}
{for}   {return FOR;}
{others}  {return OTHERS;}
{type} {return TYPE;}
{variable_name}  {yylval.sval = strdup(yytext);return VAR;}
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
"--".*	{return COMMENT;}
">="    {return GREATER_THAN;}
"<="    {return LESSER_THAN;}
"!="    {return NOT_EQUAL;}
"=="    {return COMPARE;}
"=>"    {return ARROW;}
".."    {return DOTDOT;}
","     {return COMMA;}
%%