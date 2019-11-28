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


int main(){

	ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll a,b;
        cin >> a >> b;
        if((a+b)%3 != 0) cout << "NO\n";
        else{
            ll x = (a+b)/3;

            ll xx = a - x;
            if(xx < 0){
                cout << "NO\n";
            }
            else {
                ll yy = (b-xx);
                if(yy % 2 or yy < 0){
                    cout << "NO\n";
                }
                else {
                    cout << "YES\n";
                }
            }
        }

    }
    return 0;
}
