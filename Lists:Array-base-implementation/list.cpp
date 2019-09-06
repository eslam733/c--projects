#include <iostream>
using namespace std;
#include "list.h"
typedef struct Lists
{
    listEntry entry[maxlist];
    int size;
}lists;

void createlist(list *l)
{
    l->size = 0;
}
// 0 <= p <= size
void insert(list *l, listEntry e, int p)
{
    for (int i = size-1; i >= p; i--)
        l->entry[i+1] = l->entry[i];
    l->entry[p] = e;
    l->size++;
}

void del(list *l, listEntry *e, int p)
{
    for (int i = p+1; i < size; i--)
        l->entry[i-1] = l->entry[i];
    
    l->size--;
}

bool full(list *l)
{
    return (l->size == maxlist);
}

bool empty(list *l)
{
    return (l->size == 0);
}

void destory(list *l)
{
    l->size = 0;
}

void printl(list * l, (void)(*p)(listEntry))
{
    for (int i = 0; i < size; i++)
        (*p)(l->entry[i]);
    
}