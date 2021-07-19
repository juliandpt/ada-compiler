rm ./output/*.txt
flex ./src/comp.flex
bison -dy ./src/bison.y
mv lex.yy.c ./src
mv y.tab.c ./src
mv y.tab.h ./src
gcc ./src/lex.yy.c ./src/y.tab.c -lm -o ./ejecutable/ejecutable
./ejecutable/ejecutable ./ejecutable/main.adb > ./output/output.txt
# mv ast.txt ./output
# mv mips.txt ./output