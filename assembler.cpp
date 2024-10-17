#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "assembler.h"
#include "processor.h"

void assembler(FILE* command_txt)
{
    fopen_m("command.asm", asmcommand, "a");

    char cmd[100] = " ";
     int found_command = 0;

    while (fscanf(command_txt, "%s", cmd) == 1)
    {
        if (COMPARE(cmd, "push", PUSH))
        {
            ARGUMENT(command_txt, asmcommand);
            found_command = 1;
        }

        if (COMPARE(cmd, "add", ADD))
            found_command = 1;

        if (COMPARE(cmd, "pop", POP))
            found_command = 1;

        if (COMPARE(cmd, "sub", SUB))
            found_command = 1;

        if (COMPARE(cmd, "jmp", JMP))
        {
            ARGUMENT(command_txt, asmcommand);
            found_command = 1;
        }

        if (COMPARE(cmd, "mul", MUL))
            found_command = 1;

        if (COMPARE(cmd, "hlt", HLT))
            found_command = 1;

        if (!found_command)
        {
            printf("Unknown command: %s\n", cmd);
        }

    }

    fclose(asmcommand);
}

