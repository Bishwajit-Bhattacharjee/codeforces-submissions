#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 10;
using PII = pair<int,int>;

int dep[N], lvl_cnt[N], sub[N];
vector <int> same_level[N], g[N];
int mx_lvl;
int const INF = 1e9;

void dfs(int u, int lvl = 1){
    dep[u] = lvl;
    sub[u] = 1;
    same_level[dep[u]].push_back(u);
    mx_lvl = max(mx_lvl, lvl);

    for (auto v : g[u]){
        dfs(v, lvl + 1);
        sub[u] += sub[v];
    }
}

map<int,int> coin_possible(vector<int> &coins, int amount){
    vector <int> dp(amount + 1, 0), cnt(amount + 1, 0), last(amount + 1, -1), req(amount + 1, -1);

    for (auto x : coins) {
        if (x <= amount) cnt[x]++;
    }
    dp[0] = 1;

    for (int denom = 1; denom <= amount; denom++) {
        if (!cnt[denom]) continue;

        vector<int> need_coin(amount + 1, INF);
        for (int i = 0; i <= amount; i++) {
            if (dp[i]) need_coin[i] = 0;
        }

        for (int m = 1; m <= amount; m++){
            if (dp[m]) {

            } else {
                if (m - denom >= 0 and dp[m - denom] and need_coin[m-denom] < cnt[denom]) {
                    dp[m] = 1;
                    need_coin[m] = 1 + need_coin[m - denom];
                    last[m] = denom, req[m] = need_coin[m];
                }
            }
        }
    }
    map <int,int> ret;

    if (dp[amount]) {
        int val = amount;
        while (val > 0){
            int take = last[val];
            ret[take] = req[val];
            val -= take * req[val];
        }
        return ret;
    } 
    ret[-1] = -1;
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n, x;
    cin >> n >> x;

    for (int i = 1; i < n; i++){
        int pr; cin >> pr;
        g[pr].push_back(i+1);
    }
    dfs(1);

    vector <int> lvls_cnt;

    for (int i = 1; i <= mx_lvl; i++) 
        if(same_level[i].size())
            lvls_cnt.push_back(same_level[i].size());

    map<int,int> soln = coin_possible(lvls_cnt, x);

    vector<int> assigned(n+1, 0);

    if (soln.size() == 1 && soln.begin()->first == -1) {
        cout << mx_lvl + 1 << endl;

        for (int d = 1; d <= mx_lvl; d++){
            sort(same_level[d].begin(), same_level[d].end(), [](int a, int b){
                return sub[a] < sub[b];
            });
        }
        vector <int> cols{n - x, x};
        int colored = 0, cur_col = 0;
        for (int d = 1; d <= mx_lvl; d++) {
            if (cols[cur_col] < cols[cur_col^1]) cur_col ^= 1;

            colored += same_level[d].size();

            while (cols[cur_col] > 0 && same_level[d].size()) {
                int cur = same_level[d].back();
                same_level[d].pop_back();
                assigned[cur] = cur_col;
                cols[cur_col]--;
            }

            if (same_level[d].size()){
                cur_col ^= 1;
                while (cols[cur_col] > 0 && same_level[d].size()) {
                    int cur = same_level[d].back();
                    same_level[d].pop_back();
                    assigned[cur] = cur_col;
                    cols[cur_col]--;
                }
            }
        }
        for (int i = 1; i <= n; i++){
            cout << ((assigned[i])? "a" : "b") ;
        }
        cout << "\n";
    } 
    else {

        // for (auto [k, v] : soln){
        //     cout << "map " << k << " " << v << endl;
        // }
        cout << *max_element(dep + 1, dep + n + 1) << "\n";

        for (int d = 1; d <= mx_lvl; d++){
            vector <int> &cur_level = same_level[d];

            if (soln[cur_level.size()]) {
                soln[cur_level.size()]--;
                for (auto x : cur_level) assigned[x] = 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << ((assigned[i])?"a":"b") ;
        }
        cout << "\n";
    }

    return 0;
}