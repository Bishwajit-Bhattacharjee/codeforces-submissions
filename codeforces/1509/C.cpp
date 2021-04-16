#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

int const N = 2020;
ll dp[N][N];
ll s[N];
int n;
ll const INF = 1e17;

ll DP(int l, int r){
    if (l == 1 && r == n) return 0;

    ll &ret = dp[l][r];
    if (ret != -1) return ret;

    ret = INF;
    ll c1 = INF, c2 = INF;

    if (l > 1)
        c1 = DP(l-1, r) + s[r] - s[l-1];
    if (r < n)
        c2 = DP(l, r+1) + s[r+1] - s[l];

    return ret = min(c1, c2);
}

void solve(){
    memset(dp, -1, sizeof dp);
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> s[i] ;

    sort(s + 1, s + n + 1);
    ll ans = INF;
    for (int i = 1; i <= n; i++) 
        ans = min(ans, DP(i,i));
    cout << ans << '\n';

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    t = 1;
    while(t--){
        solve();
    }
}
