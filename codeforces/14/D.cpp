/// HK 108 Times
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std ;
#define ll long long
#define pb push_back
typedef pair <int,int>  PII ;
vector < PII > given ;
typedef pair < ll, ll > PLL ;
#define all(x) (x).begin() , (x).end()
#define F first
#define S second
//#define DEBUG(x) cout <<" #(x) <<
#define READ freopen("in.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout)
#define FAST ios_base::sync_with_stdio(false)
#define ll long long
#define MOD 1000000007
#define endl '\n'


ll bigmod(ll base, ll pow, ll mod = MOD )
{
        if(!pow)
                return 1 ;
        ll lat = bigmod(base, pow/ 2, mod);
        lat = (lat * lat ) % mod;

        if(pow & 1)
                lat = (lat * base) % mod;
        return lat;

}
int const MX = 220 ;
vector < int > G[MX];
int edge[MX][MX] ;

int dist[MX];
int n;
int len ;
int from;

void dfs(int node, int par, int lvl)
{
    dist[node] = lvl;
    if(len < lvl)
    {
        len  = lvl ;
        from = node;
    }

    for(auto i : G[node])
    {
        if(i != par && edge[node][i])
        {
            dfs(i, node, lvl + 1) ;
        }
    }
}
int dim(int node)
{
    from = 0;
    len = 0;
    memset(dist, 0, sizeof dist) ;
    dfs(node,-1,0);

    //int cur = *max_element(dist,dist + n);
    // - dist;

    //cout << cur << endl;
    //cout << cur << " " << node << endl;
    //cout << cur << endl;
    //from = 0;
    len = 0;
    memset(dist,0,sizeof dist) ;
    dfs(from,-1,0) ;
    return len ;
}
int main()
{
        //cout << ( 2 * bigmod(26,MOD -2) + 1 ) % MOD << endl
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cin >> n;
    vector < PII > V;
    for(int i = 1; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        edge[a][b] = edge[b][a] = 1;
        G[a].pb(b) ; G[b].pb(a);

        V.pb({a,b} ) ;
    }
    ll ans = INT_MIN;
    for(auto x : V)
    {
        edge[x.first][x.second] = edge[x.second][x.first] = 0;
        int u = x.F;
        int v = x.S;

       // cout << dim(u) << " " << dim(v) <<  endl;
        ll tmp = dim(u) * dim(v) ;
        //cout << tmp << endl;
        ans = max(ans, tmp) ;
//        G[u].pb(v) ;//}
//        G[v].pb(u) ;//}

        edge[x.first][x.second] = edge[x.second][x.first] = 1;
    }
    cout << ans << endl;
    return 0;

}
