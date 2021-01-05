#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll w, h, n;
    cin >> w >> h >> n;
    int cnt = 0;
    while (w % 2 == 0) cnt++, w /= 2;
    while (h % 2 == 0) cnt++, h /= 2;

    ll p = 1, c = 0;
    while (c < cnt and p < n) {
        p *= 2;
        c++;
    }
    cout << ( (p >= n)? "YES" : "NO" ) << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}