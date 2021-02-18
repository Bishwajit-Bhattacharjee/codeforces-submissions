#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;

void solve(){

    int n, m;
    cin >> n >> m;
    vector<ll> discs(n);
    ll tot = 0;
    vector < PLL > prefs;
    for (int i = 0; i < discs.size(); i++) {
        ll &x = discs[i];
        cin >> x;
        tot += x;
        if (prefs.empty() or prefs.back().first < tot) 
            prefs.emplace_back(tot, i);
    }

    sort(prefs.begin(), prefs.end());
    
    vector<ll> Q(m);
    for (int i = 0; i < m; i++) {
        cin >> Q[i];
    }

    for (auto x : Q) {
        if (prefs.back().first >= x) {
            int ans = lower_bound(prefs.begin(), prefs.end(), PLL(x, -1)) - prefs.begin();
            cout << prefs[ans].second <<  " ";
            continue;
        }
        if (tot <= 0) {
            cout << "-1 ";
            continue;
        }
        ll mx = prefs.back().first;
        ll cycles = (x -mx + tot - 1) / tot;
        ll ans = cycles * n;
        x -= cycles * tot;
        ll extra = lower_bound(prefs.begin(), prefs.end(), PLL(x, -1)) - prefs.begin();
        extra = prefs[extra].second;
        cout << ans + extra << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}