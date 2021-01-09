#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const N = 5050;
int const MOD = 1e9 + 7;

ll dp[N][N];// to[N][N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;

    vector < int > a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) dp[0][i] = 1;


    for (int kk = 1; kk <= k; kk++) {
        for (int i = 1; i <= n; i++){
            dp[kk][i] = dp[kk-1][i-1] + dp[kk-1][i+1];
            if(dp[kk][i] >= MOD) dp[kk][i] -= MOD;
        }
    }

    vector <ll> cnt(n+1, 0);

    for (int pos = 0; pos <= k; pos++) {
        for (int now = 1; now <= n; now++){
            cnt[now] += dp[pos][now] * dp[k-pos][now] ;
            cnt[now] %= MOD;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += cnt[i] * a[i];
        ans %= MOD;
    }

    while (q--){
        int i, x;
        cin >> i >> x;
        ans = (ans - cnt[i] * a[i] + cnt[i] * x) % MOD;
        ans = (ans + MOD) % MOD;
        a[i] = x;
        cout << ans << "\n";
    }

}