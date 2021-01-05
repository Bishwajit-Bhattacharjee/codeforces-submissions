#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int const N = 3e5 + 10;
vector < int > g[N];
int d[N];
bool vis[N] ;

void bfs(int u) {
    d[u] = 0;
    vis[u] = 1;
    queue<int> q;
    q.push(u);

    while (q.size()) {
        int v = q.front(); q.pop();

        for (auto x : g[v]){
            if (vis[x]) continue;
            vis[x] = 1;
            d[x] = d[v] + 1;
            q.push(x);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    fill(vis + 1, vis + n + 1, 0);    

    bfs(1);

    vector <int> ord(n);
    for(int i = 0; i < n; i++) ord[i] = i + 1;

    sort(ord.begin(), ord.end(), 
        [](int l, int r)->bool {
            return d[l] > d[r];
        }
    );
    vector < int > dp(n+1, INT_MAX), dp1(n+1, INT_MAX);

    for (auto x : ord) {
        dp[x] = d[x];
        for (auto y : g[x]){
            if (d[y] > d[x]) dp[x] = min(dp[x], dp[y]);
        }
    }

    for (auto x : ord) {
        dp1[x] = dp[x];
        for (auto y : g[x]){
            if (d[y] <= d[x]) dp1[x] = min(dp1[x], dp[y]);
            if (d[y] > d[x]) dp1[x] = min(dp1[x], dp1[y]);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dp1[i] << " " ;
    }
    cout << "\n";

    for (int i = 0; i <= n; i++) {
        g[i].clear();
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