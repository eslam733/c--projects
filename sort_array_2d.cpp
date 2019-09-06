#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
// Bulbasaur
struct Interval 
{ 
    int start, end; 
}; 
bool compareInterval(Interval i1, Interval i2) 
{ 
    if((i1.start != i2.start))
        return (i1.start > i2.start); 
    else
    {
        return (i1.start == i2.start && i1.end < i2.end); 
    }
    
} 
bool compareInterval2(Interval i1, Interval i2) 
{ 
    return (i1.start == i2.start && i1.end < i2.end); 
} 
int main(void)
{
    int n, k; cin >> n >> k;
    struct Interval arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].start;
        cin >> arr[i].end;
        
    }
    
    sort(arr, arr+n, compareInterval); 
    //sort(arr, arr+n, compareInterval2); 
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i].start << " ";
    //     cout << arr[i].end << endl;
        
    // }
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[k-1].start == arr[i].start && arr[k-1].end == arr[i].end)
            cont++;
    }
    cout << cont;
    return 0;
}