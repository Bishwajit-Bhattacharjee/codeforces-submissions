#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int const N = 3e5 + 10;
vector < int > g[2][N];
int dist[2][N];
int vis[N];
int dp[2][N];

void bfs(int u, int pos){

    vis[u] = 1;
    dist[pos][u] = 0;
    queue < int > q;
    q.push(u);
    while (q.size()) {
        int v = q.front(); q.pop();
        for (auto x : g[0][v]) {
            if (vis[x]) continue;
            vis[x] = 1;
            dist[pos][x] = dist[pos][v] + 1;
            q.push(x);
        }
    }

}

int DP(int u, int st) {
    int &ret = dp[st][u];
    if (ret != -1) return ret;

    ret = dist[0][u];

    assert(ret != -1);

    if (ret == -1) ret = INT_MAX;

    for (auto x : g[0][u]) {

        if (dist[0][u] < dist[0][x]) {
            ret = min(ret, DP(x, st));
        }
        else {
            if(st)
                ret = min(ret, DP(x, 0));
        }
    }
    return ret;
}

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[0][u].push_back(v);
        g[1][v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        vis[i] = 0; dist[0][i] = -1;
    }    
    bfs (1, 0);

    for (int i = 0; i <= n; i++) dp[0][i] = dp[1][i] = -1;

    for (int i = 1; i <= n; i++) {
        cout << DP(i, 1) << " ";
    }
    cout << "\n";
    // for (int i = 1; i <= n; i++) {
    //     int ans = dist[1][i];
    //     if (ans == -1) ans = INT_MAX;

    //     for (auto x : g[0][i]) {
    //         if (dist[0][i] < dist[0][x]) {
    //             ans = min(ans, dist[1][x]);
    //         }
    //     }
    //     cout << ans << " ";
    //     // assert(ans != INT_MAX);
    // }

    // cout << "\n";

    for (int i = 0; i <= n; i++) {
        g[0][i].clear(), g[1][i].clear();
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}