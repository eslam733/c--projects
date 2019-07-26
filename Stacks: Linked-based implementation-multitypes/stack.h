#include <stdio.h>
#include <cstdlib>
#include <string.h>
typedef struct stacknode
{
    void * entry;
    struct stacknode *next = NULL;
    
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

void push(void * e, stack *ps, int z)
{
    stacknode *pn = (stacknode*)malloc(sizeof(stacknode));
    void * ptr = malloc(z);
    memcpy(ptr, e, z);
    pn->entry = ptr;
    pn->next = ps->top;
    ps->top = pn;
    ps->size++;
}

void pop(void *pe, stack *ps, int z)
{
    memcpy(pe, ps->top->entry, z);
    free(ps->top->entry);
    stacknode *pn = ps->top;
    ps->top = pn->next;
    free(pn);
    ps->size--;
}

int stackempty(stack *ps)
{
    return ps->top == NULL;
    
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
        free(ps->top->entry);
        free(ps->top);
        ps->top = pn;
    }
    ps->size = 0;
}

// void prints(stack *ps, void(*pf)(stackEntry))
// {
//     int i = 0;
//     for (stacknode *pn = ps->top; pn && i < ps->size; i++, pn = pn->next)
//         (*pf)(pn->entry);
    
// }
int stacksize(stack *ps)
{
    return ps->size;
}

