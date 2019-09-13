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
    push(3, &t);
    push(2, &t);
    push(1, &t);
    push(11, &t);
    push(5, &t);
    push(4, &t);
    cout <<deletet(&t, 3) << endl;
    cout << sizetree(&t);
    return 0;
} 