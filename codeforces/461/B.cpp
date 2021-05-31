#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int const N = 1e5 + 10;
ll const M = 1e9 + 7;
vector<vector<int>> g;
int isBlack[N];
vector<vector<ll>> dp;


void dfs(int u, int p){
    dp[u][1] = isBlack[u];
    dp[u][0] = 1 - isBlack[u];

    for (auto v : g[u]){
        if (v == p) continue;
        vector<ll> cpy(dp[u]);
        dfs(v, u);

        dp[u][0] = cpy[0] * dp[v][1] ;
        dp[u][1] = cpy[1] * dp[v][1] ;
    
        dp[u][0] %= M, dp[u][1] %= M;

        dp[u][0] += cpy[0] * dp[v][0] % M;
        dp[u][0] %= M;

        dp[u][1] += cpy[1] * dp[v][0] % M;
        dp[u][1] %= M;

        dp[u][1] += cpy[0] * dp[v][1] % M;
        dp[u][1] %= M;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    g.assign(n+1, vector<int>());
    dp.assign(n+1, vector<ll>(2, 0));
    
    for (int i = 0; i + 1< n; i++){
        int p;
        cin >> p;
        g[p].push_back(i+1);
        g[i+1].push_back(p);
    }

    for (int i = 0; i < n; i++) cin >> isBlack[i];

    dfs(0, -1);

    cout << dp[0][1] << "\n";

    return 0;
}