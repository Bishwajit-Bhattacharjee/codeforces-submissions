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
int const N = 1'010;

ll comb[N][N];

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	
	comb[0][0] = 1;
	for (int n = 1; n < N; n++){
		comb[n][0] = comb[n][n] = 1;
		for (int r = 1; r < n; r++){
			comb[n][r] = comb[n-1][r-1] + comb[n-1][r];
			if (comb[n][r] >= MOD) comb[n][r] -= MOD;
		}
	}
	int t; cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		vector <int> v(n);
		for (auto &x : v) cin >> x;
		map<int,int, greater<int> > cnt;
		for (auto x : v) cnt[x]++;
		ll ans = 1LL;

		ll taken = 0;
		for (auto [key, val] : cnt) {
			int cur_take = min(k - taken, 1LL*val);
			ans = (ans * comb[val][cur_take]) % MOD;
			taken += cur_take;
			assert(taken <= k);	
			if (taken == k) break;
		}
		cout << ans << "\n";
	}
	return 0;
}
