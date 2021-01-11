#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;

void solve(){
    ll n, x;
    cin >> n >> x;

    vector <PLL> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first, v[i].second = 1;

    ll ans = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i].first % x == 0) {
            v.push_back({v[i].first/x, v[i].second * x});
        }
        else break;
    }

    for (auto &[a, b] : v) {
        ans += a * b;
        // cout << a << " " << b << endl;
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