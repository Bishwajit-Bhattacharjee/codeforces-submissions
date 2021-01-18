#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll const M = 1'000'000'007LL;

void solve(){
    ll n;
    cin >> n;
    vector <ll> v(n), cnt(100, 0);

    for (auto &x : v) cin >> x;

    for (auto x : v) {
        for (int pos = 0; pos <= 60; pos++) {
            if ((1LL<<pos) & x) cnt[pos]++;
        }
    }
    vector <ll> po(70,1);


    for (int i = 1; i <= 60; i++) po[i] = (po[i-1] * 2) % M;
    ll ans = 0;

    for (auto mid : v) {

        ll y_tot = 0;
        for (ll y = 0; y < 60; y++){
            ll y_cnt = (mid &(1LL<<y))? n : cnt[y];
            y_cnt = (y_cnt * po[y]) % M;

            y_tot = (y_tot + y_cnt) % M;
        }
        for (ll x = 0; x < 60; x++) {
            if (!(mid & (1LL<<x))) continue;
            ll x_cnt = cnt[x] * po[x] % M;
            ans = (ans + x_cnt * y_tot) % M;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}