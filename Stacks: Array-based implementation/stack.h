#include <stdio.h>

typedef struct stack
{
    int top;
    stackEntry entry[maxstack];
}stack;

void createstack(stack *ps)
{
    ps->top = 0;
}
int stackfull(stack *ps)
{
    return ps->top >= maxstack;
}
void push(stackEntry e,stack *ps)
{
    ps->entry[ps->top++] = e;
}
int stackempty(stack *ps)
{
    return !ps->top;
}
void pop(stackEntry *pe, stack *ps)
{
    *pe = ps->entry[--ps->top];
}

void stacktop(stackEntry *pe, stack *ps)
{
    *pe = ps->entry[ps->top-1];
}

int stacksize(stack *ps)
{
    return ps->top;
}

void clearstack(stack *ps)
{
    ps->top = 0;
}


void traversestack(stack *ps, void (*pf)(stackEntry))
{
    int i = ps->top;
    if(sizeof(stackEntry) == 1)
        i--;
    for (i; i > 0; i--)
        (*pf)(ps->entry[i-1]);
    
}