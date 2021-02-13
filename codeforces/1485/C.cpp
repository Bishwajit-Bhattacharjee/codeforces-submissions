#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll x, y;
    cin >> x >> y;

    ll ans = 0;
    for (ll p = 1; p * p <= x; p++) {
        ll b = max( 0LL, (x / p) - 1) ;
        b = min(b, y);
        b = max(0LL, b - p);
        ans += b;
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