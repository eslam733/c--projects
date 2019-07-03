#include <stdio.h>
#define maxstack 100
#define stackEntry char
#include "stack.h"

void display(stackEntry e)
{
    printf("e is %c\n", e);
}

int main(void)
{
    stack s;
    createstack(&s);
    int x;
    while(scanf("%c", &x) && x != 'z')
    {
        if(!stackfull(&s))
            push(x, &s);
        else
            printf("stack is full\n");
    }
    traversestack(&s, &display);
    return 0;
}