#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const N = 5050;
int const MOD = 1e9 + 7;

ll dp[N][N], to[N][N];
ll cum[N];


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;

    vector < int > a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) dp[i][0] = 1;


    for (int kk = 1; kk <= k; kk++) {
        for (int i = 1; i <= n; i++){
            dp[i][kk] = dp[i+1][kk-1] + dp[i-1][kk-1];
            dp[i][kk] %= MOD;
        }
    }


    for (int kk = 0; kk <= k; kk++){
        for (int i = 1; i <= n; i++) {
            cum[kk] = (cum[kk] + dp[i][kk]) % MOD;
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += dp[i][k] , sum %= MOD;

    vector <ll> cnt(n+1, 0);

    for (int now = 1; now <= n; now++) {
        for (int pos = 0; pos <= k; pos++){
            cnt[now] += dp[now][pos] * dp[now][k-pos] ;
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