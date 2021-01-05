#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;

    vector<ll> dp(n+2, 0), v(n+1);

    for(int i = 1; i <= n; i++) cin >> v[i];
    ll ans = 0;

    for (int i = n; i > 0; i--) {
        dp[i] = v[i] ;
        if( i + v[i] <= n)dp[i] += dp[i + v[i]];
        ans = max(ans, dp[i]);
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