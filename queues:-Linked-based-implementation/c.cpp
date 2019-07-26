#include <iostream>
using namespace std;
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
    push(2, &q);
    push(3, &q);
    push(4, &q);
    push(5, &q);
    push(6, &q);
    push(7, &q);
    push(2, &q);
    push(3, &q);
    push(4, &q);
    push(5, &q);
    push(6, &q);
    push(7, &q);
    push(2, &q);
    push(3, &q);
    push(4, &q);
    push(5, &q);
    push(6, &q);
    push(7, &q);
    push(2, &q);
    push(3, &q);
    push(4, &q);
    push(5, &q);
    push(6, &q);
    qprint(&q, &print);
    return 0;
}