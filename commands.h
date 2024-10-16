#ifndef COMMANDS_H
#define COMMANDS_H

#define operation(operation, stk, sign)   \
    int a = StackPopV(stk);               \
    int b = StackPopV(stk);               \
                                          \
    int operation = a sign b;             \
                                          \
    StackPush(stk, operation);            \

void add(Stack* stk);

void sub(Stack* stk);

void mul(Stack* stk);

void div(Stack* stk);

#endif
