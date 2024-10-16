#ifndef PROCESSOR_H
#define PROCESSOR_H

enum Commands {
    JMP = 0,
    PUSH = 1,
    ADD = 2,
    POP = 3,
    SUB = 4,
    MUL = 5,
    DIV = 6,
    JA,
    JAE,
    JB,
    JBE,
    JE,
    JNE,
    HLT = -666
};

#define fopen_m(file, name, type)   \
FILE *name = fopen(file, type);     \
                                    \
    if (name == NULL)               \
    {                               \
        fprintf(stderr, "Failed to open the file\n"); \
        assert(0);                  \
    }                               \

void read(Stack* stk);

void Run(int* code, Stack* stk, long size);

const long return_size_text(FILE *commands);

#endif
