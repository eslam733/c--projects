#include <iostream>
using namespace std;
#include "stack.h"
void p(int s)
{
    cout << s << endl;
}
int main(void)
{
    stack<int, 2> s;
    s.push(2);
    s.push(3);
    s.prints(&p);
    return 0;
}