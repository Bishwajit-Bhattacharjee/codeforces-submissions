#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    k -= a[0];
    ll g = 0;
    for (int i = 1; i < n; i++) a[i] -= a[0] , g = gcd(g, a[i]);

    cout << ((k % g == 0)? "YES" : "NO") << "\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}