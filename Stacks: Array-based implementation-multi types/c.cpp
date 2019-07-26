#include <iostream>
using namespace std;
#define maxstack 100
#define stackEntry char
#include "stack.h"

// void display(char e)
// {
//     cout << e << endl;
// }

int main(void)
{
    stack s;
    char i = 'e';
    char y;
    createstack(&s);
    
    push((void *)&i, &s, sizeof(i));
    
    pop((void *)&y, &s, sizeof(y));
    cout << y << endl;
    
    return 0;
}