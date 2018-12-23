#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 5;
vector<int> g[N];
int par[N], lev[N];
int sp[N][20];		// sparse table. i's 2^j th parent in sp[i][j]
int n;

void dfs(int u, int pr, int lv) {
	par[u] = pr;
	lev[u] = lv;
	for(int i=0; i<(int) g[u].size(); ++i) {
		int v = g[u][i];
		if(v != pr) dfs(v, u, lv+1);
	}
}

void lca_init() {
	dfs(1, -1, 0);
	memset(sp, -1, sizeof sp);
	for(int i=1; i<=n; ++i) sp[i][0] = par[i];

	for(int j=1; (1<<j) < n; ++j) {
		for(int i=1; i<=n; ++i) {
			if(sp[i][j-1] != -1) sp[i][j] = sp[sp[i][j-1]][j-1];
		}
	}
}

int lca(int u, int v) {
	if(lev[u] < lev[v]) swap(u, v);

	int logn = 0;
	while((1 << (1+logn)) <= n) ++logn;
	for(int i=logn; i>=0; --i) {
		if(lev[u] - (1<<i) >= lev[v]) u = sp[u][i];
	}
	if(u == v) return u;

	for(int i=logn; i>=0; --i) {
		if(sp[u][i] != -1 and sp[u][i] != sp[v][i]) {
			u = sp[u][i];
			v = sp[v][i];
		}
	}
	return par[u];
}
typedef pair < int , int > PII;
typedef long long int ll;
ll val[N] ;
ll ans[N];
map < PII, int > ind;
ll sub[N] ;

void dfs1(int u,int pr)
{
    for(auto v : g[u])
    {
        if(v == pr) continue;
        dfs1(v,u);
        ans[ind[{min(u,v),max(u,v)}]] = val[v];
        val[u] += val[v];

    }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for(int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v;
		if(u > v) swap(u,v);
		ind[{u,v}] = ind.size();
		//cout << ind[{u,v}] << endl;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	lca_init();
    int q;
    cin >> q;

    while(q--)
    {
        int a ,b;
        cin >> a >> b;
        int L = lca(a,b);
       // if(a > b ) swap(a,b);
        //ind[{a,b}] = ind.size();
        val[a]++,val[b]++,val[L] -= 2;

    }
    dfs1(1,-1);

    for(int i = 0; i < n - 1; i++)
        cout << ans[i] << " ";
    cout << endl;
	return 0;
}
