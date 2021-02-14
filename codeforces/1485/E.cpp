#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const N = 2e5 + 10;
vector<vector<int>> dep;
vector<int> g[N], sub[N];

void dfs(int u, int p, int d){
    if (d + 1 > dep.size()) {
        dep.push_back(vector<int>());
    }
    // cout << "    d : " << d << " u : " << u << endl;
    dep[d].push_back(u);
    for (int v : g[u]){
        if (v == p) continue;
        sub[u].push_back(v);
        dfs(v, u, d + 1);
    }
}

void solve(){
    dep.clear();

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear(), sub[i].clear();

    for (int i = 2; i <= n; i++){
        int v;
        cin >> v;
        g[i].push_back(v);
        g[v].push_back(i);
    }
    vector<ll> val(n+1,0);
    for (int i = 2; i <= n; i++) cin >> val[i] ;

    dfs(1, -1, 0);

    auto cmp = [&val](int x, int y)->bool {
        return val[x] < val[y];
    };
    for (auto& v : dep) {
        sort(v.begin(), v.end(), cmp);
    }
    vector<vector<ll>> dp(n + 10, vector<ll> (3, -1e18));

    int d = dep.size() - 1;

    for (int lvl = d; lvl >= 0; lvl--){

        if (lvl == d){
            for (auto node : dep[lvl]){
                dp[node][0] = dp[node][1] = max(abs(val[node] - val[dep[lvl].front()]),
                    abs(val[node] - val[dep[lvl].back()])
                );
            }
        } else {
            vector<int> &cur = dep[lvl];
            for (auto node : cur){

                for (auto child : sub[node]) {
                    dp[node][0] = max(dp[node][0], max(dp[child][0], dp[child][1]));
                }
            }

            ll left = -1e18;
            for (auto node : cur) {
                left = max(left, dp[node][0] - val[node]);
                dp[node][1] = max(dp[node][1], left + val[node]);
            }
            
            ll right = -1e18;

            for (int i = cur.size() - 1; i >= 0; i--) {
                int node = cur[i];
                right = max(right, dp[node][0] + val[node]);
                dp[node][1] = max(dp[node][1], right - val[node]);
            }

            for (auto node : cur){
                ll mx_can = max(abs(val[node] - val[dep[lvl].front()]),
                    abs(val[node] - val[dep[lvl].back()])
                );

                for (auto child : sub[node]) {
                    dp[node][0] = max(dp[node][0], mx_can + max(dp[child][0], dp[child][1]));
                }
            }
        }
        

        // for (auto node : dep[lvl]) {
        //     cout << node << ": (" << dp[node][0] << ", " << dp[node][1] << ") " ;
        // }
        // cout << endl;
    }

    cout << dp[1][0] << "\n";

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}