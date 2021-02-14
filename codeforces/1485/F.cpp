#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

ll const M = 1'000'000'007;

void solve(){
    int n;
    cin >> n;
    vector<ll> b(n);
    
    for(auto &x : b) cin >> x;

    map <ll, ll> cnt;
    ll offset = 0;
    cnt[0] = 1;
    ll ans = 0, tot_map_cnt = 1;
    ll cnt_here, cnt_pref;

    for (int i = 0; i < n; i++){
        cnt_here = tot_map_cnt;
        cnt_pref = (tot_map_cnt - cnt[-offset] + M) % M;
        offset += b[i];
        cnt[b[i] - offset] += cnt_pref;
        cnt[b[i] - offset] %= M;
        tot_map_cnt += cnt_pref;
        tot_map_cnt %= M;
    }

    cout << (cnt_pref + cnt_here) % M << "\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}