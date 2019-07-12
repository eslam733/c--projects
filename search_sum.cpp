#include <iostream>
#include <math.h>
using namespace std;

void bin(int *pr, int n, int num)
{
    int n1 = 0;
    while (num && n1 < n)
    {
        pr[n1] = (num & 1)? 1 : 0;
        n1++;
        num /= 2;
    }
    for (int i = n1; i < n; i++)
    {
        pr[i] = 0;
    }
    
    
}

int main(void)
{
    int n = 10, sum, j, poss = pow(2, 5)-1,arr[] = {6, 1, 1, 1, 1}, arr2[5];
    
    for (int i = 0; i < poss; i++)
    {
        sum = 0;
        bin(arr2, 5, i);
        for ( j = 4; j >= 0; j--)
        {
            if(arr[j] == 1)
            {
                sum += arr[i];
            }
        }
        if(sum == n)
        {
            cout << "YES";

            return 0;
        }
        
        
    }
    cout << "NO";


    return 0;
}