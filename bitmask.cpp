#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long int mask =  (1 << 20), cont, i, j;
    for ( i = 1; i < mask; i++)
    {
        cont = 1;
        for ( j = 1; j < mask ; )
        {
            if(i & j)printf("%d ", cont);
            cont++;
            j = j << 1;
        }
        printf("\n");
    }
    
    return 0;
}