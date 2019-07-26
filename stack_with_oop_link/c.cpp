#include <iostream>
using namespace std;
#include "stack.h"
void p(int s)
{
    cout << s << endl;
}
int main(void)
{
    stack<int> s;
    s.push(31);
    s.push(4);
    s.prints(&p);
    return 0;
}
