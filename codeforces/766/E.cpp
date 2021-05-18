#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int const N = 1e5 + 10;
int const M = 22;
vector<vector<int>> g;
int dp[N][M][2], val[N];
ll ans = 0;

void dfs(int u, int p, int XOR = 0){
    XOR ^= val[u];
    for (int i = 0; i < M; i++){
        if (XOR & (1<<i)) dp[u][i][1]++;
        else dp[u][i][0]++;
    }

    for (auto v : g[u]){
        if (v == p) continue;
        dfs(v, u, XOR);

        for (int i = 0; i < M; i++){

            ll c1 = (1LL * dp[u][i][0] * dp[v][i][1] + 1LL * dp[u][i][1] * dp[v][i][0]);
            ll c2 = (1LL * dp[u][i][0] * dp[v][i][0] + 1LL * dp[u][i][1] * dp[v][i][1]);

            ans += 1LL * (1LL<< i) * ((val[u] & (1<<i))?c2 : c1);
        }

        for (int i = 0; i < M; i++){
            dp[u][i][0] += dp[v][i][0];
            dp[u][i][1] += dp[v][i][1];
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    g.assign(n+1, vector<int>());
    
    for (int i = 1; i <= n; i++) cin >> val[i], ans += val[i];
    
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, -1, 0);

    cout << ans << endl;

    return 0;
}