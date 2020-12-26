#include <bits/stdc++.h>
using namespace std;
using PII = pair <int,int>;
using ll = long long int;
int const N = 2e5 + 10;
vector < int > g[N];
map < PII, int > mp; 
bool vis[N];
vector < int > cycle, tmp;
bool dfs_cycle(int u, int p){
    vis[u] = 1;
    tmp.push_back(u);
    // cout << "dfs " << u << endl;

    bool done = false;
    for (int v : g[u]){
        if (v == p) continue;
        if (vis[v]) {
            // cout << "V " << v << endl;
            // for (auto x : tmp) {
            //     cout << x << " " ;
            // }
            // cout << endl;
            // cout << "u " << u << endl;
            while (tmp.size() and tmp.back() != v) {
                // cout << tmp.back() << endl;
                cycle.push_back(tmp.back());
                tmp.pop_back();
            }
            // cout << "cycle : " << endl;
            // for (auto x : cycle) cout << x << " " ;
            // cout << endl;

            cycle.push_back(v);

            return true;
        }
        else {
            done |= dfs_cycle(v, u);
        }
        if (done) return true;
    }
    if (done) return true;

    if(tmp.size())tmp.pop_back();
    return false;
}

int sub[N] ;

void dfs(int u){
    vis[u] = 1;
    sub[u] = 1;
    for (int v : g[u]){
        if (vis[v] or mp.count({u,v})) continue;
        dfs(v);
        sub[u] += sub[v];
    }
}

void solve(){
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    fill(vis, vis + n + 1, 0);
    tmp.clear();
    cycle.clear();

    dfs_cycle(1, -1);

    for (int i = 0; i < cycle.size(); i++){
        mp[{cycle[i], cycle[(i+1) % cycle.size()]}] = 1;
        mp[{ cycle[(i+1) % cycle.size()], cycle[i]}] = 1;
    }
 
    fill(vis, vis + n + 1, 0);

    ll ans = 0;
    ll prev = 0;

    for (int i = 1; i <= n; i++){
        if (!vis[i]) {
            dfs(i);
            ans += 1LL * sub[i] * (sub[i] - 1) / 2;
            ans += 2LL * sub[i] * prev;
            prev += sub[i] ;
        }
    }
    cout << ans << "\n";

    for (int i = 1; i <= n; i++) g[i].clear();
    cycle.clear();
    fill(vis, vis + n + 1, 0);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        mp.clear();
        solve();
    }
}