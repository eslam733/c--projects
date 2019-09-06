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

class num{
	private:
		int n;
	public:
		num(){};
		num(int n)
		{
			this->n = n;
		}
		int get(){return n;}
		num operator+(num x)
		{
			num nn;
			nn.n = n + x.n;
			return nn;
		}
		nun operator+=(num x)
		{
			n += x.n;
			return *this;
		}
		num operator-=(num x)
		{
			n -= x.n;
			return *this;
		}
		num operator++()
		{
			n++;
			return *this;
		}
		num operator++(int)
		{
			num tmp = *this;
			n++;
			return tmp;
		}
		bool operator!()
		{
			return (n==0);
		}
		num operator-()
		{
			n = -n;
			return *this;
		}
		static bool equl(num x, num y)
		{
			if(x.n == y.n) return true;
			else return false;
		}

};
int main()
{     
    num n1(0), n3;
	
	cout << !n1;
    //#ifdef _LOCAL_DEFINE
    cerr << clock()*1.0/CLOCKS_PER_SEC<<endl;
    //#endif
    return 0;
    
}