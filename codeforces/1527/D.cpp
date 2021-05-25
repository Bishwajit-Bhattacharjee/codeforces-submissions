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

int const N = 2e5 + 10;
vector<vector<int>> g;
ll par[N], sub[N];

ll nc2(ll n){
	return n * (n-1)/2;
}

void dfs(int u, int p){
	par[u] = p;
	sub[u] = 1;
	for (auto v : g[u]){
		if (v != p) {
			dfs(v, u);
			sub[u] += sub[v];
		}
	}
}

void solve(){
	int n;
	cin >> n;
	g.assign(n, vector<int>());

	for (int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(0,-1);

	vector<ll> ans(n+1, 0);
	ans[1] = nc2(n);

	for (int v : g[0]){
		ans[0] += nc2(sub[v]);
		ans[1] -= nc2(sub[v]);
	}
	vector<bool> mark(n+1, 0);
	mark[0] = 1;
	vector<int> chain;
	ll cur = n;

	for (int i = 1; i < n; i++){

		if (mark[i]){
			ans[i+1] = ans[i];
			ans[i] = 0; 
			continue;
		}

		int u = i;
		while (1){
			mark[u] = 1;
			if (mark[par[u]]) break;
			u = par[u];
		}

		if (par[u] == 0){
			if (chain.size() >= 2) break;
			chain.push_back(i);
			cur -= sub[u];
		}
		else {
			assert(chain.size() <= 2);
			u = par[u];
			bool conti = 0;
			for (int j = 0; j < chain.size(); j++){
				if (chain[j] == u){
					chain[j] = i;
					conti = 1;
					break;
				}
			}
			if (!conti){
				break;
			}
		}

		if (chain.size() == 1){
			ans[i+1] = sub[chain.front()] * cur;
			ans[i] -= ans[i+1];
		}
		else {
			ans[i+1] = sub[chain.front()] * sub[chain.back()];
			ans[i] -= ans[i+1];
		}
	}


	for (int i = 0; i <= n; i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
