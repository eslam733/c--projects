#include <stdio.h>
#define entrylist int
#include "list.h"

void diplay(entrylist e)
{
    printf("%d\n", e);
}


int main(void)
{
    list l;
    createlist(&l);
    int e;
    insert(0, 4, &l);
    insert(1, 5, &l);
    insert(2, 6, &l);
    insert(3, 7, &l);
    prints(&l, &diplay);
    printf("\n");
    replace(0, 378912, &l);
    prints(&l, &diplay);
    printf("\n");
    printf("%d", getitem(2, &l));
    return 0;
}             