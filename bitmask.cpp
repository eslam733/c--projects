#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int arr[] = {2, 3};
    long long int mask =  (1 << (sizeof(arr)/sizeof(int))), cont, i, j;
    for ( i = 1; i < mask; i++)
    {
        int cont = 0;
        for ( j = 1; j < mask ; )
        {
            if(i & j)printf("%d ", arr[cont]);
            cont++;
            j = j << 1;
        }
        printf("\n");
    }
    
    return 0;
}
