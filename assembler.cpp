#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "assembler.h"
#include "processor.h"

void assembler(FILE* command)
{
    fopen_m("command.asm", asmcommand, "a");

    char cmd[100] = " ";

    while (fscanf(command, "%s", cmd) == 1)
    {

        if (strcmp(cmd, "push") == 0)
        {
            fputs("1 ", asmcommand);

            int arg = 0;

            fscanf(command, "%d", &arg);
            fprintf(asmcommand, "%d ", arg);

        }
        else if (strcmp(cmd, "add") == 0)
        {
            fputs("2 ", asmcommand);
        }

        else if (strcmp(cmd, "pop") == 0)
        {
            fputs("3 ", asmcommand);
        }

        else if (strcmp(cmd, "sub") == 0)
        {
            fputs("4 ", asmcommand);
        }

        else if (strcmp(cmd, "jmp") == 0)
        {
            fputs("0 ", asmcommand);
        }

        else if (strcmp(cmd, "mul") == 0)
        {
            fputs("5 ", asmcommand);
        }

        else if (strcmp(cmd, "hlt") == 0)
        {
            fputs("-666 ", asmcommand);
        }
    }

    fclose(asmcommand);
}

