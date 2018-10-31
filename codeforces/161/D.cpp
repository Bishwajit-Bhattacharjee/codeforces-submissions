#include <bits/stdc++.h>
using namespace std;
int const MX = 5e4 + 5;
typedef long long int ll;
ll dp[MX][505];
int n,k;
vector < int > g[MX];
ll ans;
//ll dist[MX];

void dfs(int r, int p, int lvl)
{
    //dist[r] = lvl;
    dp[r][0] = 1;

    for(auto u : g[r])
    {
        if(u == p)  continue;
        //cout << r << endl;
        dfs(u,r,lvl+1);
        for(int kk = 1; kk <= k; kk++)
        {
            dp[r][kk] += dp[u][kk-1];
        }
        //cout <<  " matha " << r << " "  << dp[r][2] << endl;
        //cout << r << " " << dp[r][2] << endl;
    }

    ll tot = 0;
    for(int kk = 1; kk <= k; kk++)
    {
        ll can = (kk == k);

        for(auto u : g[r]){
            if(u == p ) continue;
            tot +=  can * dp[u][kk-1];
            can += dp[u][k-kk-1] ;
        }
    }
    ans += tot;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;

    for(int i = 0; i < n - 1; i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1,0);
    cout << ans << endl;
    return 0;
}
