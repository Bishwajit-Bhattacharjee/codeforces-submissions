#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()
int const N = 3e5 + 10;
vector<int> g[N];


void solve(){
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= m; i++) g[i].clear();

    vector<int> ans(m+1, -1), cnt(n+1, 0);

    for (int i = 1; i <= m; i++){
        int k;
        cin >> k;
        vector<int> poss(k);
        for(auto &x : poss) cin >> x;

        if (k == 1) {
            ans[i] = poss.front();
            cnt[poss.front()]++;
        }
        g[i] = poss;
    }

    for (int i = 1; i <= n; i++){
        if (cnt[i] > (m+1)/2) {
            cout << "NO\n"; return;
        }
    }

    for (int i = 1; i <= m; i++){
        if (g[i].size() == 1) continue;

        sort(all(g[i]), [&cnt](int a, int b)->bool{
            return cnt[a] < cnt[b];
        });

        int cur = g[i][0];
        cnt[cur]++;
        ans[i] = cur;
        if (cnt[cur] > (m+1)/2){
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";

    for (int i = 1; i <= m; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
