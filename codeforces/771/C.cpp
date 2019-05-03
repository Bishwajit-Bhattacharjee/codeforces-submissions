#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 3e5 + 10;
vector < int > g[N] ;
ll dist[N][6] ;
ll dp[N][6] ;
ll ans;
ll sub[N] ;
int n, k;
void dfs(int u,int par)
{
    sub[u] = dp[u][0] = 1;

    for(int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i] ;
        if(v == par) continue;
        dfs(v,u);
        for(int x = 0; x < k; x++){
            for(int y = 0;y < k;y++)
            {
                int rem = x + y + 1;
                rem %= k;
                ans += (k - rem)%k *1LL*dp[v][y] * dp[u][x] ;
            }
        }
        for(int x = 0; x < k; x++)
        {
            dp[u][(x+1)%k] += dp[v][x] ;
        }
        sub[u] += sub[v];
    }
    ans += 1LL * sub[u] * (n - sub[u]);

}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0 ;i < n - 1; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1);
    assert(ans % k == 0);
    cout << ans / k << endl;
    return 0;
}
