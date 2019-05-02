#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 5050;
ll dp[N][N] ;
int const MOD = 998244353;

ll bigmod(ll a,ll b)
{
    if(b==0) return 1;
    ll x = bigmod(a,b/2);
    x = (x * x ) % MOD;
    if(b & 1) x = (a * x) % MOD;
    return x;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    vector < ll > inv(N);

    for(int i = 0; i < N; i++)
        inv[i] = bigmod(i,MOD-2);

    vector < int > cnt(N,0);
    int n, tmp;
    cin >> n;
    for(int i = 0;i < n; i++)
        cin >> tmp, cnt[tmp]++;

    ll ans = 0;
//    dp[n][0] = 1;
//    for(int i = n; i >= 1; i--){
//        for(int j = 0; j <= n - 2; j++)
//        {
//            ans = (ans + dp[i][j]*cnt[i]%MOD *(cnt[i]-1)%MOD * inv[n-j]%MOD * inv[n-j-1] % MOD) % MOD ;
//
//        }
//        for(int j = 0; j < n; j++){
//            dp[i-1][j] += dp[i][j] ; dp[i-1][j] %= MOD;
//            dp[i-1][j+1] += (dp[i][j] * cnt[i] % MOD * inv[n-j] % MOD ) ; dp[i-1][j+1] %= MOD;
//        }
//    }

    dp[1][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n - 2; j++)
        {
            ans = (ans + dp[i][j]*cnt[i]%MOD *(cnt[i]-1)%MOD * inv[n-j]%MOD * inv[n-j-1] % MOD) % MOD ;

        }
        for(int j = 0; j < n; j++){
            dp[i+1][j] += dp[i][j] ; dp[i+1][j] %= MOD;
            dp[i+1][j+1] += (dp[i][j] * cnt[i] % MOD * inv[n-j] % MOD ) ; dp[i+1][j+1] %= MOD;
        }
    }

    cout << ans << endl;
    return 0;
}
