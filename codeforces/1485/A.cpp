#include <bits/stdc++.h>
using namespace std;
using ll = long long int;


ll cnt(ll a, ll b) {
    if (a == 0) return 0;
    if (b == 1) {
        return 1e12;
    }
    return 1 + cnt(a/b, b);
}

void solve(){
    ll a, b;
    cin >> a >> b;
    ll ans = cnt(a, b);
    for (ll x = b; x <= b + 10000; x++) ans = min(ans, x - b + cnt(a, x));
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