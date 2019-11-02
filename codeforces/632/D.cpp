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

PLL base = {37,41};
PLL M = {1e9+21, 1e9+9};

int const N = 1e6 + 5;
int const LOG = 11;


int main(){

	ios::sync_with_stdio(false); cin.tie(0);

    int n,m;
    cin >> n >> m;

    vector < ll > v(n),f(m+1,0) ,cnt(m+1,0);

    for(int i = 0; i < n; i++) {
        cin >> v[i] ;
        if(v[i] <= m) f[v[i]]++;
    }
    for(int i = m; i >= 1; i--){
        for(int j = i; j <= m; j += i){
            cnt[j] += f[i] ;
        }
    }
    ll ans = 0, l = 1;

    for(int i = m; i >= 1; i--) {
        if(cnt[i] >= ans) {
            l = i, ans = cnt[i] ;
        }
    }

    cout << l << " " << ans << endl;

    for(int i = 0; i < n; i++) {
        if(l % v[i] == 0) cout << i+1 << " " ;

    }
    cout << endl;
    return 0;
}
