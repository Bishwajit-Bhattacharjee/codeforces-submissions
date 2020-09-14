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

int const N = 2e5 ;
int n,k,m;
vector<int> g[N] ;
bool vis[N] ;
int d[N] ;
vector<int> cycle, path, col[2];
bool found = 0;
void dfs(int u,int pr, int dep){
	if(found) return ;
	col[dep&1].push_back(u);
	vis[u] = 1;
	d[u] = path.size();
	path.push_back(u);
	int deep = -1;
	for(int v : g[u]){
		if(d[v] != -1 and v != pr and deep < d[v]) deep = d[v];
	}
	if(deep != -1){
		found = 1;
		for(int i = deep; i < path.size(); i++){
			cycle.push_back(path[i]);
		}
		// while( path.back() != path[deep]) cycle.push_back(path.back()), path.pop_back();
		// cycle.push_back(path[deep]);
		return;
	}

	for(int v : g[u]){
		if(v == pr) continue;
		if(found) return;
		dfs(v, u, dep + 1);
	}
	if(!found)path.pop_back();
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >>  k;
	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	memset(d, -1, sizeof d);
	dfs(1, -1, 0);
	if(cycle.size()){
		if(cycle.size() <= k) {
			cout << "2\n";
			cout << cycle.size() << '\n';
			for(auto x : cycle) cout << x << " ";
			cout << '\n';
		}
		else {
			cout << "1\n";
			// cout << cycle.size() / 2 << '\n';
			int cnt = 0;
			for(int i = 1; cnt * 2 < k and i < cycle.size(); i += 2) cout << cycle[i] << " " , cnt++;
			cout << '\n';
		}
	}
	else {
		if(col[0].size() > col[1].size()) swap(col[0], col[1] );
		cout << "1" << '\n';
		int cnt = 0;
		for(auto x : col[1]) {
			if(cnt * 2 >= k) continue;
			cout << x << " ";
			cnt++;
		}
		cout << '\n';
	}
	return 0;
}