#!/bin/bash
rm ./output/\*.txt
flex ./src/comp.flex
bison -dy ./src/bison.y
mv lex.yy.c ./src
mv y.tab.c ./src
mv y.tab.h ./src
gcc ./src/lex.yy.c ./src/y.tab.c -o ./ejecutable/ejecutable
./ejecutable/ejecutable $1 > ./prueba/pruebaCorrecta1/output.txt
mv ast.txt ./output
mv mips.txt ./output