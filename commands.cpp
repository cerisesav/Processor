#include <stdlib.h>

#include "stack.h"
#include "commands.h"


void add(Stack* stk)
{
    operation(add, stk, +);
}

void sub(Stack* stk)
{
    operation(sub, stk, -);
}

void mul(Stack* stk)
{
    operation(mul, stk, *);
}

void div(Stack* stk)
{
    operation(div, stk, /);
}
