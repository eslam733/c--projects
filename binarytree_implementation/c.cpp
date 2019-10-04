#include <bits/stdc++.h>
using namespace std;
#define vtree int
#include "tree.h"
void p(vtree v)
{
    printf("%d ", v);
}
int main()
{
    tree t;
    createtree(&t); 
    push(5, &t);
    push(4, &t);
    push(3, &t);
    push(6, &t);
    push(7, &t);
    level_or(&t, &p);
    return 0;
} 