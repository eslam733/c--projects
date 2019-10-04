#include <bits/stdc++.h>
using namespace std;

void heapfiy(int n, int i, int arr [])
{
    int l = i*2+1;
    int r = i*2+2;
    int max = i;
    if(arr[l] < arr[max] && l < n) max = l;
    if(arr[r] < arr[max] && r < n) max = r;

    if(max != i) 
    {
        int temp = arr[max];
        arr[max] = arr[i];
        arr[i] = temp;
        heapfiy(n, max, arr);
    }
    
}

void bulidheap(int arr[], int n)
{
    for (int i = n/2 - 1; i > -1; i--)
    {
        heapfiy( n, i, arr);
    }
    
}
void heapsort(int arr[], int n)
{
    bulidheap(arr, n);
    for (int i = n-1; i > -1; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heapfiy(i, 0, arr);
    }
    
}
int main()
{
    int arr[] = {8,5,3,2,8,5,43};
    int n = sizeof(arr)/sizeof(int);
    heapsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}