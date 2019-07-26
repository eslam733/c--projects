#include <stdio.h>
#include <cstdlib>
typedef struct stacknode
{
    stackEntry entry;
    struct stacknode *next;
    
}stacknode;

typedef struct stack
{
    stacknode *top;
    int size;
}stack;


void createstack(stack *ps)
{
    ps->top = NULL;
    ps->size = 0;
}

void push(stackEntry e, stack *ps)
{
    stacknode *pn = (stacknode*)malloc(sizeof(stacknode));
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;
    ps->size++;
}

void pop(stackEntry *pe, stack *ps)
{
    *pe = ps->top->entry;
    stacknode *pn = ps->top;
    ps->top = pn->next;
    free(pn);
    ps->size--;
}

int stackempty(stack *ps)
{
    if(ps->top == NULL)
        return 1;
    else
    {
        return 0;
    }
    
}

int stackfull(stack *ps)
{
    return 0;
}

void clearstack(stack *ps)
{
    stacknode *pn = ps->top;
    while(pn)
    {
        pn = pn->next;
        free(ps->top);
        ps->top = pn;
    }
    ps->size = 0;
}

void prints(stack *ps, void(*pf)(stackEntry))
{
    int i = 0;
    for (stacknode *pn = ps->top; pn && i < ps->size; i++, pn = pn->next)
        (*pf)(pn->entry);
    
}
int stacksize(stack *ps)
{
    return ps->size;
}

