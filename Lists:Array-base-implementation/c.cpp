#include <iostream>
using namespace std;
#define maxlist 10
#define listEntry int
#include "list.h"

void p(int e)
{
    cout << e << endl;
}
int main(void)
{
    list s; int e;
    createlist(&s);
    insert(&s, 4, 0);
    insert(&s, 5, 0);
    destory(&s);
    printl(&s, &p);
    return 0;
}