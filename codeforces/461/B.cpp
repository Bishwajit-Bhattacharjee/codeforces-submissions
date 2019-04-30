#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e5 + 10;
int const MOD = 1e9 + 7;
bool vis[N] ;
int b[N] ;
vector < int > g[N] ;

ll dp[N][3] ;

void dfs(int u)
{
    vis[u] = 1;
    dp[u][0] = 1 - b[u] ;
    dp[u][1] = b[u] ;

    for(auto v: g[u])
    {
        if(vis[v]) continue;
        int old[2] = {0};
        old[0] = dp[u][0] ;
        old[1] = dp[u][1] ;

        dp[u][0] = dp[u][1] = 0;

        dfs(v);

        /// taken node v
        dp[u][1] += old[0] * dp[v][1] ;
        dp[u][1] %= MOD;
        dp[u][1] += old[1] * dp[v][0] ;
        dp[u][1] %= MOD;

        dp[u][0] += old[0] * dp[v][0] ;
        dp[u][0] %= MOD;

        /// not taken

        dp[u][1] += old[1] * dp[v][1];
        dp[u][1] %= MOD;
        dp[u][0] += old[0] * dp[v][1] ;
        dp[u][0] %= MOD;

    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i + 1 < n; i++)
    {
        int tmp;
        cin >> tmp;
        g[i+1].push_back(tmp);
        g[tmp].push_back(i+1);
    }

    for(int i = 0; i < n; i++) cin >> b[i] ;

    dfs(0);
    cout << dp[0][1] << endl;

    return 0;
}
