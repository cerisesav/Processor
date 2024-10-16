#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "stack.h"
#include "error.h"
#include "processor.h"
#include "commands.h"
#include "assembler.h"

void read(Stack* stk)
{
    fopen_m("commands.txt", file, "r");

    assembler(file);

    fopen_m("command.asm", asmcommand, "r");

    long size = return_size_text(asmcommand);
    int code[size];

    rewind(asmcommand);

    for (size_t i = 0; i < size; i++)
        fscanf(asmcommand, "%d", &code[i]);

    rewind(asmcommand);

    fclose(file);
    Run(code, stk, size);
}

void Run(int* code, Stack* stk, long size)
{
    int ip = 0;

    while (ip < size)
    {
        switch (code[ip])
        {
            case PUSH:
                StackPush(stk, code[ip+1]);
                ip += 2;
                break;

            case ADD:
                add(stk);
                ip += 1;
                break;

            case POP:
                StackPopV(stk);
                ip+=1;
                break;

            case HLT:
                ip+=1;
                break;

            case SUB:
                sub(stk);
                ip+=1;
                break;

            case MUL:
                mul(stk);
                ip+=1;
                break;

            case JMP:
                ip = code[ip+1];
                break;

            case JA:
                if (ip > StackPopV(stk))
                    ip = code[ip+1];
                else
                    ip += 2;
                break;

            case JAE:
                if (ip >= StackPopV(stk))
                    ip = code[ip+1];
                else
                    ip += 2;
                break;

            case JB:
                if (ip < StackPopV(stk))
                    ip = code[ip+1];
                else
                    ip += 2;
                break;

            case JBE:
                if (ip <= StackPopV(stk))
                    ip = code[ip+1];
                else
                    ip += 2;
                break;

            case JE:
                if (ip == StackPopV(stk))
                    ip = code[ip+1];
                else
                    ip += 2;
                break;

            case JNE:
                if (ip != StackPopV(stk))
                    ip = code[ip+1];
                else
                    ip += 2;
                break;

            default:
                printf("%d aoaooaoao ", code[ip]);
                ip += 1;
                break;
        }
    }

    StackDumpMacro(stk);
}



const long return_size_text(FILE *commands)
{
    size_t count = 0;
    int curDigit = 0;

    while(fscanf(commands, "%d", &curDigit) != EOF)
        count++;
    if(!feof(commands))
        puts("Errror!");
    return count;
}

