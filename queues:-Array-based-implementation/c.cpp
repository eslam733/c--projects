#include <iostream>
using namespace std;
#define maxqueue 6
#define queueEntry int
#include "queue.h"
void print(queueEntry e)
{
    cout << e << endl;
}
int main(void)
{
    queue q; int e;
    createqueue(&q);
    for (int i = 0; !(queuefull(&q)); i++)
    {
        push(i, &q);
    }
    pop(&e, &q);
    pop(&e, &q);
    pop(&e, &q);
    pop(&e, &q);
    qprint(&q, &print);
    return 0;
}