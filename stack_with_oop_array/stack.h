#include <iostream>
using namespace std;

template< class Typ, int MaxStack >
class stack
{
private:
    int top;
    Typ entry[MaxStack];
public:
    stack(){
        top = 0;
    }
    void push(Typ n)
    {
        entry[top++] = n;
    }
    Typ pop()
    {
        return entry[--top];
    }
    
    void clear()
    {
        top = 0;
    }

    bool empty()
    {
        return top == 0;
    }

    bool full()
    {
        return top == MaxStack;
    }

    void prints(void (*fp)(Typ))
    {
        for (int i = top-1; i >= 0; i--)
            (*fp)(entry[i]);
        
    }
};
