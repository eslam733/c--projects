#include <bits/stdc++.h>
const int N = 1e6 + 9, M = 1e7, OO = 0x3f3f3f3f;
#define IO() assert(freopen("in.in", "rt", stdin)), assert(freopen("out.out", "wt", stdout))
#define ll long long int
using namespace std;
#ifdef _LOCAL_DEFINE
template <typename... T>
void debug(T &... args)
{
    ((cerr << args << " "), ...);
    cerr << endl;
} 
#endif


struct COMPARE { 
  bool operator()(pair<string,int> const& P1, pair<string,int> const& P2) 
    { 
        
        return P2.second > P1.second;
        
        
    }  
};

//priority_queue<pair<string,int>,vector<pair<string,int>>,COMPARE >pq;
int merge(int *Arr, int start, int mid, int end) {
	int temp[end - start + 1];
    int cnt = 0;
	int i = start, j = mid+1, k = 0;

	while(i <= mid && j <= end) {
		if(Arr[i] <= Arr[j]) {
			temp[k++] = Arr[i++];
		}
		else {
			temp[k++] = Arr[j++];
            cnt += (1+mid) - i;
		}
	}

	while(i <= mid) {
		temp[k++] = Arr[i++];
	}

	while(j <= end) {
		temp[k++] = Arr[j++];
	}

	for(i = start; i <= end; i += 1) {
		Arr[i] = temp[i - start];
	}
    return cnt;
}


int mergeSort(int *Arr, int start, int end) {
    int cnt = 0;
	if(start < end) {
		int mid = (start + end) / 2;
		cnt += mergeSort(Arr, start, mid);
		cnt += mergeSort(Arr, mid+1, end);
		cnt += merge(Arr, start, mid, end);
	}
    return cnt;
}
int main()
{     
	int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    int cnt = mergeSort(arr, 0, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    cout << endl << cnt;
    
    //#ifdef _LOCAL_DEFINE
    cerr << clock()*1.0/CLOCKS_PER_SEC<<endl;
    //#endif
    return 0;
    
}