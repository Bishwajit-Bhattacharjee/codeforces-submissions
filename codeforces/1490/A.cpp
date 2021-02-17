#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int calc(ll a, ll b){
    if (a < b) swap(a, b);
    int cnt = 0;
    while (b * 2 < a) cnt++, b *= 2;

    return cnt;
}
void solve(){
    int n;
    cin >> n;
    vector < int > v(n), ans;
    for (auto &x : v) cin >> x;

    ll sol = 0;

    for (int i = 1; i < n; i++){
        sol += calc(v[i], v[i-1]);
    }
    cout << sol << "\n";

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}