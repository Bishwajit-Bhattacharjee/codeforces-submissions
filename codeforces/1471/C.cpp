#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;

void solve(){
    int n, m;
    cin >> n >> m;

    ll ans = 0;
    set <PLL> prz; vector<ll>cost(m+1);
    vector<PLL> frnds(n);

    for (int i = 0; i < n; i++) {
        cin >> frnds[i].first;
        frnds[i].second = i+1;
    }
    for (int i = 1; i <= m; i++){
        ll tmp; cin >> tmp;
        prz.insert({tmp, i});
        cost[i] = tmp;
    }

    sort(frnds.begin(), frnds.end(), [](PLL a, PLL b)->bool {
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });

    for (auto &[k, pos] : frnds) {
        while(prz.size() and (*prz.begin()).second > k) 
            prz.erase(prz.begin());
        ll can1 = 1e17;
        if (prz.size()) {
            can1 = prz.begin()->first;
            prz.erase(prz.begin());
        }        
        ans += min(can1, cost[k]);
    }
    cout << ans << "\n";

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}