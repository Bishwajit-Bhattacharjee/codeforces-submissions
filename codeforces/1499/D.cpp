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

int const N = 2e7 + 10;
vector < bool > marks;
int pf[N];


void sieve()
{
	for (int i = 1; i < N; i++) pf[i] = i;
	marks.resize(N, 0);

	for (int i = 2; i < N; i++){
		if (!marks[i]){
			for (int j = i; j < N; j += i){
				pf[j] = i;
				if (i != j) marks[j] = 1;
			}
		}
	}
}

ll cnt(ll x){
	ll ret = 1;

	while (x > 1) {
		int cur = pf[x];
		int c = 0;
		while (x % cur == 0) x /= cur, c++;
		ret *= 2;
	}
	return ret;
}

void solve(){
	ll c, d, x;
	cin >> c >> d >> x;

	vector<ll> divs;

	for (ll i = 1; i*i <= x; i++){
		if (x % i == 0){
			divs.push_back(i);
			if (i * i != x) divs.push_back(x/i);
		}
	}
	ll ans = 0;

	for (auto g : divs){
		if ((x + g * d) % c != 0) continue;
		ll l = (x + g*d) / c;
		if (l < g || l % g != 0) continue;

		ans += cnt(l/g);
	}
	cout << ans << '\n';
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	sieve();

	int t;
	cin >> t;
	while (t--) solve();		
	return 0;
}
