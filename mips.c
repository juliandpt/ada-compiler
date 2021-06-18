#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *filename_data = "data.txt";
char *filename_text = "text.txt";

// mips structs
struct MipsVariables mipsVariables[100];
struct MipsValores mipsValores[100];

struct MipsVariables {
    char *type;
    char *name;
    int memoryPos;
    int intVal;
    char *stVal;
    double dVal;
    float fval;
};

struct MipsValores {
    int ival;
    float fval;
    double dval;
    int memoryPos;
    char *type;
    char *status;
};

// file writing
void clear_file(char *filename);
void write_file(char *filename, char *content);

// conversion aux functions
char *integer_to_string(int x);
char *float_to_string(float x);
char *double_to_string(double x);

// mips vars
void mipsVar_insert_mips_variable_declaration(char *type, char *varname, int val1, char *val2, float val3, double val4,
                                              char *filename);


// impementations ---------------
void mipsVar_insert_mips_variable_declaration(char *type, char *varname, int val1,
                                              char *val2, float val3, double val4, char *filename) {
    int i = 0;
    int encontrado = 0;
    while (i < st_mipsVarLength && encontrado == 0) {
        if (strcmp(mipsVariables[i].name, "._empty") == 0) {
            mipsVariables[i].name = varname;
            mipsVariables[i].type = type;
            mipsVariables[i].memoryPos = i;
            mipsVariables[i].intVal = val1;
            mipsVariables[i].stVal = val2;
            mipsVariables[i].fval = val3;
            mipsVariables[i].dVal = val4;
            mipsIns_load_instruction_variable(mipsVariables, filename, i);
            encontrado = 1;
        } else {
            i += 1;
        }
    }
}

void mipsIns_load_instruction_variable(char *filename, int index) {
    write_file(filename, "lw ");
    write_file(filename, mipsVar_assign_memory_pos(mipsVariables[index].memoryPos));
    write_file(filename, ",");
    write_file(filename, mipsVariables[index].name);
    write_file(filename, "\n");
}

char *mipsVar_assign_memory_pos(int i) {
    char *start = "$s";
    char *position = integer_to_string(i);
    char tmp[5000];
    strcpy(tmp, start);
    strcat(tmp, position);
    char *final = tmp;
    return final;
}

char *integer_to_string(int x) {
    char *buffer = malloc(sizeof(char) * sizeof(int) * 4 + 1);
    if (buffer) {
        sprintf(buffer, "%d", x);
    }
    return buffer;
}

char *float_to_string(float x) {
    char *buffer = malloc(sizeof(char) * sizeof(float) * 16 + 1);
    if (buffer) {
        sprintf(buffer, "%f", x);
    }
    return buffer;
}

char *double_to_string(double x) {
    char *buffer = malloc(sizeof(char) * sizeof(int) * 8 + 1);
    if (buffer) {
        sprintf(buffer, "%f", x);
    }
    return buffer;
}