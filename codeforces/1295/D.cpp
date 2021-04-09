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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define F first
#define S second
#define all(v) (v).begin(),(v).end()

ostream& operator<<(ostream & os, PLL h){
	return os << "( " << h.F << ", " << h.S << " )" << endl;

}
PLL operator+ (PLL a, ll x)     {return {a.F + x, a.S + x} ;}
PLL operator- (PLL a, ll x)     {return {a.F - x, a.S - x} ;}
PLL operator* (PLL a, ll x)     {return {a.F * x, a.S * x} ;}
PLL operator+(PLL x, PLL y) { return {x.F + y.F,x.S + y.S} ;}
PLL operator-(PLL x,PLL y) { return {x.F - y.F, x.S - y.S} ;}
PLL operator*(PLL x,PLL y) { return {x.F * y.F , x.S * y.S} ;}
PLL operator%(PLL x,PLL y) { return {x.F % y.F, x.S % y.S} ;}


ll const MOD = 1e9 + 7;

ll bigmod(ll a, ll b){
	if(!b) return 1;
	ll x  = bigmod(a,b/2);

	x = (x * x)%MOD;
	if(b&1)
		x = (x * a) %MOD;
	return x;
}

vector < ll > primes;
vector < bool > marks;

void sieve(int n)
{
    marks.resize(n+10,0);
	marks[1] = 1;
	for(int i = 2; i < n; i++){
		if(!marks[i]){
			for(int j = 2*i; j < n; j += i){
				marks[j] = 1;
			}
			primes.push_back(i);
		}
	}
}

void solve(){
	ll a, m;
	cin >> a >> m;
	ll g = gcd(a, m);

	ll mp = m / g;
	vector <ll> pd;

	for (auto x : primes){
		if (x * x > mp) break;
		if (mp % x == 0){
			while (mp % x == 0) mp /= x;
			pd.push_back(x);
		}
	}
	if (mp > 1) pd.push_back(mp);

	ll ans = 0;

	for (int msk = 0; msk < (1LL << (int)pd.size()); msk++){
		ll divi = 1;
		for (int i = 0; i < pd.size(); i++){
			if (msk & (1<<i)) divi *= pd[i];
		}
		ll down = g * divi;
		ll cnt = (a + m - 1)/ down - (a-1)/ down;

		if (__builtin_popcount(msk) & 1) ans -= cnt;
		else ans += cnt;
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	sieve(1e6);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
