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
// to generate a uniform random integer over a range (l,r), use 
// int x = uniform_int_distribution<int>(l,r)(rng);

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
	int n, l , r;
	cin >> n >> l >> r;

	vector<int> lc(n+1, 0), rc(n+1, 0);

	for (int i = 1; i <= l; i++){
		int c;
		cin >> c;
		lc[c]++;
	}
	for (int i = 1; i <= r; i++){
		int c;
		cin >> c;
		rc[c]++;
	}
	ll ans = 0;
	for (int i = 0; i <= n; i++){
		int mn = min(lc[i], rc[i]);
		lc[i] -= mn, rc[i] -= mn;
	}

	vector<vector<ll>> pl(2, vector<ll>()), pr(2, vector<ll>());

	for (int i = 0; i <= n; i++){
		if (lc[i]){
			pl[lc[i] & 1].push_back(lc[i] - (lc[i] & 1));
		}
		if (rc[i]){
			pr[rc[i] & 1].push_back(rc[i] - (rc[i] & 1));
		}
	}
	int ls = pl[1].size(), rs = pr[1].size();

	int mn = min(pl[1].size(), pr[1].size());
	ans += mn;
	ls -= mn, rs -= mn;

	assert(ls % 2 == 0 & rs % 2 == 0);

	ll tot_r = 0, tot_l = 0;

	for (int i = 0; i < 2; i++){
		for (auto x : pl[i]) tot_l += x;
	}

	for (int i = 0; i < 2; i++){
		for (auto x : pr[i]) tot_r += x;
	}


	if (ls == 0){
		if (tot_l >= rs){
			ans += (tot_l + rs + tot_r) / 2;
		}
		else {
			int mn = min(rs*1LL, tot_l);
			rs -= mn, tot_l -= mn;
			ans += mn + rs + tot_r / 2;

			// cout << mn << " " << rs << " " << tot_r << " " << tot_l << endl;

		}
	}
	else if (rs == 0){

		if (tot_r >= ls){
			ans += (tot_r + ls + tot_l) / 2;
		}
		else {
			int mn = min(ls*1LL, tot_r);
			ls -= mn, tot_r -= mn;
			ans += mn + ls + tot_l / 2;
		}
	}

	cout << ans << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
