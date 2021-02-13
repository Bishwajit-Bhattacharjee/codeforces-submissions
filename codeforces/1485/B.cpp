#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n, q, k;
    cin >> n >> q >> k;

    vector<ll> a(n), sum(n+10, 0);
    for (auto &x : a) cin >> x;

    for (int i = 1; i + 1 < n; i++){
        sum[i] = sum[i-1] + a[i+1] - a[i-1] - 2;
    }



    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l == r) {
            cout << k - 1 << "\n"; continue;
        }
        ll ans = sum[r-1] - sum[l] ;
        ans += max(0LL, k - a[r-1] - 1);
        ans += max(0LL, a[l+1] - 2);
        cout << ans << "\n";
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}