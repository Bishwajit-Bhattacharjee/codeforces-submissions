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

enum Color {BLACK, GREY, WHITE};

int const N = 4e5 + 10;
Color col[N];
bool vis[N];
set <int> inf, multi;
vector<int> g[N];
int ans[N];

void dfs1(int u){
	col[u] = GREY;
	for (auto v: g[u]){
		if (col[v] == BLACK){
			multi.insert(v);
		}
		else if (col[v] == GREY){
			inf.insert(v);
		}
		else {
			dfs1(v);
		}
	}
	col[u] = BLACK;
}

void dfs2(int u, int val){
	vis[u] = 1;
	ans[u] = val;
	for (auto v : g[u]){
		if(!vis[v]) dfs2(v, val);
	}
}

void solve(){
	inf.clear(); multi.clear();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) g[i].clear();
	fill(col, col + n + 1, WHITE);

	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
	}
	dfs1(1);

	fill(vis, vis+n+1, false);

	for (auto x : inf){
		if (!vis[x]) dfs2(x, -1);
	}	


	for (auto x : multi){
		if(!vis[x]) dfs2(x, 2);
	}

	for (int i = 1; i <= n; i++){
		if (vis[i]) continue;
		if (col[i] == WHITE) ans[i] = 0;
		else if (col[i] == BLACK) ans[i] = 1;
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
