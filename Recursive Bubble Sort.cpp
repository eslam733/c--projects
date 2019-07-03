#include <iostream>
using namespace std;
void swap(int *p, int *p2)
{
    int *temp = p;
    *p = *p2;
    *p2 = *temp;
}
void bubblesort(int arr[], int n, int a)
{
    if(n == 1)
        return;
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
    }
    
    bubblesort(arr, n - 1, a+1);
}
int main(void)
{
    int arr[] = {5,4,3,2,1};
    bubblesort(arr, 5,0);
    for (int i = 0; i < 5; i++)
    {
        printf("%d", arr[i]);
    }
    

    return 0;
}