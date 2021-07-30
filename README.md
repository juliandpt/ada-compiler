# Compilador Básico para Ada 2012

Compilador básico para el lenguaje Ada 2012 haciendo uso de FLEX y BISON.

## Instalación de los paquetes necesarios

Para ejecutarlo en linux es necesario instalar flex y bison

```bash
sudo apt install flex bison
```

Para ejecutarlo en MacOS es necesario instalar flex y bison

```zsh
brew install flex bison
```

### Estructura de carpetas necesaria

Para que la ejecución funcione es necesario mantener una correcta estructura de carpetas.

- <b>Actividad Grupal 6:</b> donde se encontrará el archivo a ejecutar `run.sh`
    - <b>otros:</b> donde se encontrarán los archivos compilados, incluido el archivo a ejecutar
    - <b>src:</b> donde se encontrarán los archivos de BISON y FLEX

### Ejecución
Ejecutar el archivo bash que compilará y correrá el archivo compilado

```bash
./run.sh
```

## Hito 1

ENUNCIADO:

Se definirá la gramática para el lenguaje indicado, y se procesará un programa válido,
indicándolo al terminar la ejecución. La funcionalidad que deberá tener este primer
programa válido será:
- Operaciones aritméticas con números enteros y reales
- Operaciones booleanas
- Un tipo de bucle (while, for, case, etc.).
- Sentencia if
- Comentarios
- Control de errores en las operaciones indicadas

Se indicará el resultado la compilación en un fichero de salida

TO-D0:
- [x] Operaciones aritméticas con números enteros y reales
- [x] Operaciones booleanas
- [x] Un tipo de bucle (while, for, case, etc.).
- [x] Sentencia if
- [x] Comentarios
- [x] Control de errores en las operaciones indicadas

## Hito 2

ENUNCIADO:

Se incorporarán controles semánticos al compilador y se generará código intermedio
mediante Árboles de Sintaxis Abstracta (ASA) y se enviará este código intermedio a un
fichero de salida.

Los controles semánticos consistirán en:
- La comprobación de tipos.
- El nombre del procedimiento es el mismo al principio y al final.
- Comprobación de que una variable existe antes de haber sido declarada.
- No se pueden utilizar variables no declaradas previamente.
- No se permitirán divisiones por 0.
- Controlar el ámbito de las variables.
- Comprobar que no existen funciones con el mismo nombre.
- Comprobar que la sentencia “return” existe (al menos una vez).
- Comprobar que el tipo devuelto es del mismo tipo que el especificado en la función.

Es recomendable generar código para ejecutable en ensamblador de MIPS y que se
validará en el emulador MARS (MIPS Assembly and Runtime Simulator) para las
funcionalidades del hito 1.

Se incorporarán las siguientes funcionalidades una vez genere código intermedio para
las funcionalidades del hito 1:
- Arrays de dos dimensiones. (2ª prioridad)
- Funciones (sólo function). (1ª prioridad)

TO-D0:
- [x] La comprobación de tipos.
- [x] El nombre del procedimiento es el mismo al principio y al final.
- [x] Comprobación de que una variable existe antes de haber sido declarada.
- [x] No se pueden utilizar variables no declaradas previamente.
- [x] No se permitirán divisiones por 0.
- [ ] Controlar el ámbito de las variables.
- [x] Comprobar que no existen funciones con el mismo nombre.
- [x] Comprobar que la sentencia “return” existe (al menos una vez).
- [x] Comprobar que el tipo devuelto es del mismo tipo que el especificado en la función.

## Hito 3

ENUNCIADO:

Una vez se supere el hito 2, se procederá a generar código para ejecutable en
ensamblador de MIPS y que se validará en el emulador MARS (MIPS Assembly and
Runtime Simulator) para aquellas funcionalidades como los arrays y las funciones en
caso de que no se haya finalizado con ellas en el anterior hito.
Se probarán programas escritos en Ada correctos e incorrectos.