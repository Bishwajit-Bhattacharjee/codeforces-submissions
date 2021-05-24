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
int const N = 1e5 + 10;
vector<vector<int>> g;
ll l[N], r[N];
int n;
ll dp[2][N];

void dfs(int u, int p){
	dp[0][u] = dp[1][u] = 0;

	for (auto v: g[u]){
		if (v == p) continue;
		dfs(v, u);
		dp[0][u] += max(abs(l[u] - l[v]) + dp[0][v], abs(l[u] - r[v]) + dp[1][v]);
		dp[1][u] += max(abs(r[u] - l[v]) + dp[0][v], abs(r[u] - r[v]) + dp[1][v]);
	}
}

void solve(){

	cin >> n;

	g.assign(n+1, vector<int>());

	for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];

	for (int i = 1; i <= n - 1; i++){
		int a , b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	// cout << "up" << endl;
	dfs(1,0);
	
	// cout << "down" << endl;

	cout << max(dp[0][1], dp[1][1]) << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
