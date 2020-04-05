#include <bits/stdc++.h>
using namespace std;
int const N = 2e5 + 100;
typedef long long int ll;
bool taken[N],vis[N];
ll dp[N] ;
vector <int> g[N] ;
vector<ll> cost(N,0);
bool dfs1(int u,int par){
    vis[u] = 1;
    for(int v : g[u]){
        if(v == par) continue;
        if(vis[v]){
            taken[u] = 1;
        }
        else
            taken[u] |= dfs1(v,u);
            //taken[]
    }
    return taken[u] ;
}

ll dfs2(int u,int par){
    vis[u] = 1;
    for(int v : g[u]){
        if(v == par) continue;
        if(!vis[v])dp[u] = max(dp[u],dfs2(v,u));
    }
    dp[u] += (!taken[u])*cost[u] ;
    return dp[u] ;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> cost[i] ;

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int s;
    cin >> s;
    dfs1(s,-1);
    memset(vis,0,sizeof vis);
    ll mx = dfs2(s,-1);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(taken[i]) ans += cost[i] ;
    }
    cout << ans + mx << endl;
    return 0;
}
