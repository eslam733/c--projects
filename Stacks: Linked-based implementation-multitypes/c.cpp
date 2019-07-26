#include <stdio.h>
#define stackEntry int
#include "stack.h"

void diplay(stackEntry e)
{
    printf("%d\n", e);
}


int main(void)
{
    stack s;
    createstack(&s);
    int x = 2321, y;
    push((void *)&x, &s, sizeof(x));
    x =312;
    push((void *)&x, &s, sizeof(x));
    printf("%d", stackempty(&s)); 
    x = 44;
    push((void *)&x, &s, sizeof(x));
          
    clearstack(&s);  
    printf("%d", stackempty(&s));
    return 0;
}   