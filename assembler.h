#ifndef ASSEMBLER_H
#define ASSEMBLER_H

void assembler(FILE* command);

#define COMPARE(cmd, name, number) (strcmp(cmd, name) == 0 ? (fprintf(asmcommand, "%d ", number), 1) : 0)

#define ARGUMENT(txt_file, asm_file) { int arg = 0; \
    fscanf(txt_file, "%d", &arg);  \
    fprintf(asm_file, "%d ", arg); \
}
#endif
