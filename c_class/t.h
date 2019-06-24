#include <iostream>
using namespace std;

class t
{
    course *arr[20];
    int cont;
public:
    t(){
        cont = 0;
    }
    void addcourse(course * c1)
    {
        arr[cont] = c1;
        cont++;
    }
    void del(course *c1)
    {
        for (int i = 0; i < cont; i++)
        {
            if(arr[i] == c1)
            {
                arr[i] = arr[cont - 1];
                arr[cont - 1] = NULL;
                cont--;
            }
        }
        
    }
    void printc()
    {
        for (int i = 0; i < cont; i++)
        {
            arr[i]->print();
        }
        
    }
};
