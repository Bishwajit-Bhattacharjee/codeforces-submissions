#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

double INF = 1e100;
double EPS = 1e-12;
typedef long long int ll;

typedef pair < int,int > PII;
typedef pair < ll,ll > PLL;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

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

int const N = 2e5 + 5;
int const LOG = 31;
ll const MOD = 998244353;

ll bigmod(ll a, ll b)
{
	if(!b) return 1;
	ll x  = bigmod(a,b/2);

	x = (x * x)%MOD;
	if(b&1)
		x = (x * a) %MOD;
	return x;
}

ll inv(ll x)
{
	return bigmod(x%MOD,MOD-2);
}
int main(){

	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;

	if(n <= 2){
		cout << "No\n";
	}
	else {
		cout << "Yes\n";
		cout << "1 " << n << endl;

		cout << n-1 << " ";
		for(int i = 1; i < n; i++) cout << i << " ";
		cout << endl;
	}
	return 0;
}
