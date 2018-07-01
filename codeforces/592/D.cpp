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
vector < pair < int , PII >  >  edge  ;
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
int const MX = 2e5 + 10;
int mark[MX] ;
vector < int > G[MX];
int mini[MX] ;

void dfs(int node, int par, int dist)
{
    mini[node] = dist;

    for(auto x: G[node])
    {
        if(x != par)
        {
            dfs(x, node, dist + 1 );
        }
    }
}
int m;
int ans;
int dfs1(int node, int par)
{
    int sub = mark[node] ;
    for(auto x: G[node])
    {
        if(x != par)
        {
            sub += dfs1(x, node) ;
        }
    }
    if(min(sub,m - sub) > 0 )
        ans++;
    return sub;
}
int main()
{
        //cout << ( 2 * bigmod(26,MOD -2) + 1 ) % MOD << endl
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    int n;
    cin >> n >> m;
    for(int i = 1; i + 1 <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].pb(b) ;
        G[b].pb(a) ;

    }
    int tmp = -1;
    for(int i = 1; i <= m;i++)
    {
        int x;
        cin >> x;
        mark[x] = 1;
        tmp = x;
    }
    dfs(tmp , -1, 0) ;

   // memset(mini, 0, sizeof mini);
    int tmp_id = INT_MAX;
    int maxi_val = INT_MIN;
    for(int i = 1; i <= n; i++)
    {
        if(mark[i])
        {
            if(maxi_val < mini[i])
            {
                tmp_id = i;
                maxi_val = mini[i] ;

            }
            else if(maxi_val == mini[i])
                tmp_id = min(tmp_id, i) ;
        }
    }
    int ss = tmp_id;

    memset(mini, 0,sizeof mini) ;
    dfs(tmp_id, -1,0);

    tmp_id = INT_MAX;
    maxi_val = INT_MIN;
    for(int i = 1; i <= n; i++)
    {
        if(mark[i])
        {
            if(maxi_val < mini[i])
            {
                tmp_id = i;
                maxi_val = mini[i] ;

            }
            else if(maxi_val == mini[i])
                tmp_id = min(tmp_id, i) ;
        }
    }
    int dim = INT_MIN;
    for(int i = 1; i <= n; i++)
    {
        if(mark[i])
            dim = max(dim, mini[i]) ;
    }
    dfs1(1,-1) ;
    cout << min(ss, tmp_id) << endl;
    cout << ans * 2 - dim << endl;
    return 0;

}
