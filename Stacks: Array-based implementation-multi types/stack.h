#include <iostream>
#include <string.h>
using namespace std;
typedef struct stack
{
    int top;
    void *entry[maxstack];
}stack;

void createstack(stack *ps)
{
    ps->top = 0;
}

void push(void * e,stack *ps, int z)
{
    void * ptr = malloc(z);
    memcpy(ptr, e, z);
    ps->entry[ps->top++] = ptr;
}
int stackempty(stack *ps)
{
    return !ps->top;
}
void pop(void *pe, stack *ps, int z)
{   
    memcpy(pe, ps->entry[--ps->top], z);
    free(ps->entry[ps->top]);
}

void stacktop(void *pe, stack *ps, int z)
{
    memcpy(pe, ps->entry[ps->top-1], z);
}

int stacksize(stack *ps)
{
    return ps->top;
}

void clearstack(stack *ps)
{
    ps->top = 0;
}


// void traversestack(stack *ps, void (*pf)(char), int z)
// {
//     int i = ps->top;
//     if(sizeof(z) == 1)
//         i--;
//     for (i; i > 0; i--)
//         (*pf)(ps->entry[i-1]);
    
// }

int stackfull(stack *ps)
{
    return ps->top >= maxstack;
}