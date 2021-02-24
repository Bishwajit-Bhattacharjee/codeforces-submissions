#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

ll can(ll n, ll p) {
    return (p + n - 1) / n * n - p;
}
void solve(){
    ll p, a, b, c;
    cin >> p >> a >> b >> c;
    cout << min(can(a, p), min(can(b, p), can(c, p))) << "\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}