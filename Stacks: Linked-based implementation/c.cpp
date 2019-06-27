#include <stdio.h>
#define maxstack 6
#define stackEntry int
#include "stack.h"

void display(stackEntry e)
{
    printf("e is %d\n", e);
}

int main(void)
{
    stack s;
    createstack(&s);
    int x;
    while(scanf("%d", &x) && x != 'z')
    {
        if(!stackfull(&s))
            push(x, &s);
        else
            printf("stack is full\n");
    }
    pop(&x, &s);
   
    printf("%d\n",stacksize(&s));
    return 0;
}