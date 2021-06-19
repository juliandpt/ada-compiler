#!/bin/bash
rm ast.txt
rm mips.txt
flex comp.flex
bison -dy bison.y
gcc lex.yy.c y.tab.c -o analiza
./analiza test.txt > output.txt