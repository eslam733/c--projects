#include <bits/stdc++.h>
//#include "header.h"
const int N = 1e6 + 9, M = 1e7, OO = 0x3f3f3f3f, eps = 0.001;
#define IO() assert(freopen("in.in", "rt", stdin)), assert(freopen("out.out", "wt", stdout))
#define ll long long int
#define popcnt(a) __builtin_popcount(a) // count one in binary
#define GCD(a, b) __gcd(a, b)
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
using namespace std;
// template <typename... T>
// void debug(T &... args)
// {
//     ((cerr << args << " "), ...);
//     cerr << endl;
// }
 
 
 
// struct COMPARE { 
//   bool operator()(pair<string,ll> const& P1, pair<string,ll> const& P2) 
//     { 
        
//         return P1.second < P2.second;
        
        
//     }  
// };
//priority_queue<pair<string,ll>,vector<pair<string,ll>>,COMPARE >pq;

class num{
	private:
		int n, arr[5];
	public:
		num(){
            ar();
            
        };
        void ar()
        {
            for (int i = 0; i < 5; i++)
            {
                arr[i] = i;
            }
        }
		num(int n)
		{
			this->n = n;
            ar();
		}
		int get(){return n;}
		num operator+(num x)
		{
			num nn;
			nn.n = n + x.n;
			return nn;
		}
        num operator+(int x)
		{
			num nn;
			nn.n = n + x;
			return nn;
		}
       
		num operator+=(num x)
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
        bool operator==(num b)
        {
            return (this->n == b.n);
        }
        bool operator<=(num b)
        {
            return (this->n <= b.n);
        }
        bool operator>=(num b)
        {
            return (this->n >= b.n);
        }
        bool operator!=(num b)
        {
            return (this->n != b.n);
        }
		static bool equl(num x, num y)
		{
			return (x.n == y.n);
		}
        friend num operator+(int n, num c1)
        {
            num c3;
            c3.n = c1.n + n;
            return c3;
        }
        friend istream& operator>>(istream &input, num& c1)
        {
            input >> c1.n;
            return input;
            
        }
        friend ostream& operator<<(ostream &output, num& c1)
        {
            output << c1.n;
            return output;
        }
        operator int()
        {
            return (int)n;
        }
        int operator[](int x)
        {
            return arr[x];
        }
};


int main()
{     
    
    num x;
    cout << x[2];
    cerr << clock()*1.0/CLOCKS_PER_SEC<<endl;
    return 0;
    
}
