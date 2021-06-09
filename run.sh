#!/bin/bash
rm ast.txt
rm output.txt
flex comp.flex
bison -dy bison.y
gcc lex.yy.c y.tab.c -o analiza
./analiza "$1" "$2"