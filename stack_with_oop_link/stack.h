#include <iostream>
using namespace std;

template< class Typ>


class stack
{
private:

    typedef struct Stacknode
    {
        Typ entry;
        struct Stacknode *next;
        
    }stacknode;

    stacknode *top;
    int size;
public:
    stack(){
        size = 0;
        top = NULL;
    }
    void push(Typ n)
    {
        stacknode *pn = (stacknode *) malloc(sizeof(stacknode));
        pn->entry = n;
        pn->next = top;
        top = pn;
        size++;
    }
    Typ pop()
    {
        stacknode *pn = top;
        Typ n = top->entry;
        top = top->next;
        free(pn);
        size--;
        return n;
    }
    
    void clear()
    {
        stacknode *pn = top;
        while(pn)
        {
            pn = pn->next;
            free(top);
            top = pn;
        }
        size = 0;
    }

    bool empty()
    {
        return size == 0;
    }

    bool full()
    {
        return 0;
    }

    void prints(void (*fp)(Typ))
    {
        int i = 0;
        for (stacknode *pn = top; pn && i < size; i++, pn = pn->next)
            (*fp)(pn->entry);
        
    }
};
