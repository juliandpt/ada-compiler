#!/bin/bash
rm *.txt
flex comp.flex
bison -dy bison.y
gcc lex.yy.c y.tab.c -o analiza
./analiza main.adb > output.txt