#include <stdio.h>
#define stackEntry int
#include "stack.h"

void diplay(stackEntry e)
{
    printf("%d\n", e);
}
void insert(int e, stack *ps)
{
    if(stackempty(ps))
        push(e, ps);
    else
    {
        int e1;
        printf("fsas");
        pop(&e1, ps);
        insert(e, ps);
        push(e1, ps);
    }
    
}
void sort(stack  *ps)
{
    for (int i = 0; i < stacksize(ps); i++)
    {
        int e;
        pop(&e, ps);
        insert(e, ps);
    }
    
}


int main(void)
{
    stack s;
    push(2, &s);
    push(1, &s);
    push(5, &s);
    prints(&s, &diplay);
    sort(&s);
    prints(&s, &diplay);
    return 0;
}   