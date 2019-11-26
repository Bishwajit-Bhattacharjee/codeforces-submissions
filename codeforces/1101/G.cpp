#include <bits/stdc++.h>
using namespace std;

double INF = 1e100;
double EPS = 1e-12;
typedef long long int ll;

typedef pair < int,int > PII;
typedef pair < ll,ll > PLL;
#define F first
#define S second
ostream& operator<<(ostream & os, PLL h)
{
	return os << "( " << h.F << ", " << h.S << " )" << endl;

}
PLL operator+ (PLL a, ll x)     {return {a.F + x, a.S + x} ;}
PLL operator- (PLL a, ll x)     {return {a.F - x, a.S - x} ;}
PLL operator* (PLL a, ll x)     {return {a.F * x, a.S * x} ;}
PLL operator+(PLL x, PLL y) { return {x.F + y.F,x.S + y.S} ;}
PLL operator-(PLL x,PLL y) { return {x.F - y.F, x.S - y.S} ;}
PLL operator*(PLL x,PLL y) { return {x.F * y.F , x.S * y.S} ;}
PLL operator%(PLL x,PLL y) { return {x.F % y.F, x.S % y.S} ;}

//PLL base = {37,41};
PLL M = {1e9+21, 1e9+9};

int const N = 1e6 + 5;
int const LOG = 31;
int sz;

int base[LOG] ;

void check(int n)
{
    for(int i = 0; i < LOG; i++)
    {
        if(!(n & (1LL<<i)))
            continue;
        if(base[i] == -1)
        {
            base[i] = n;
            sz++;
            break;
        }
        n ^= base[i] ;
    }
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);

    memset(base,-1,sizeof base);//)

    int n;
    cin >> n;

    vector < int > v(n);
    int XOR = 0;

    for(int i = 0; i < n; i++) cin >> v[i] , XOR ^= v[i] , check(v[i]);

    if(XOR == 0)
    {
        cout << "-1\n";
    }
    else
        cout << sz << endl;



    return 0;
}
