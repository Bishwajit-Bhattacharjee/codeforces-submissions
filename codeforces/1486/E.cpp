#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;

int const N = 2e5;
int const W = 52;
ll const INF = 1e17;
vector<PLL> g[N];
int n, m;
ll dist[W][N];

struct dat {
    ll dist;
    int node, last_val;
    dat(){}
    dat(ll a, int b, int c) {
        dist = a, node = b, last_val = c;
    }
};

void dijkastra(int src) {
    auto cmp = [](dat a, dat b)->bool {
        return a.dist > b.dist;
    };

    priority_queue <dat, vector<dat>, decltype(cmp) > pq(cmp);
    dist[0][src] = 0;
    pq.push(dat(0, src, 0));

    while (!pq.empty()) {
        dat top = pq.top(); pq.pop();
        if (dist[top.last_val][top.node] < top.dist) continue;

        for (auto [v, w] : g[top.node]) {
            ll cost = w*w + 2 * w * top.last_val + top.dist;
            ll nxt_w = (top.last_val == 0) ? w : 0;
            if (dist[nxt_w][v] > cost) {
                dist[nxt_w][v] = cost;
                pq.push(dat(cost, v, nxt_w));
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    for (int w = 0; w < W; w++){
        for (int i = 1; i <= n; i++) dist[w][i] = INF;
    }
   
    dijkastra(1);

    for (int i = 1; i <= n; i++){
        cout << ((dist[0][i] == INF)?-1 : dist[0][i]) << " ";
    }
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    t = 1;
    while(t--){
        solve();
    }
}
