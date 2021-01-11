#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n, x;
    cin >> n >> x;
    vector <ll> v(n);

    ll sum = 0;
    for (auto &y : v) cin >> y, sum += y;

    ll mn = (sum + x - 1) / x, mx = 0;

    for (auto y : v) mx += (y + x - 1) / x;

    cout << mn << " " << mx << "\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}