#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int const M = 1e9 + 7;

int const N = 21;

ll bigmod(ll a,ll b)
{
    if(!b) return 1;

    ll x = bigmod(a,b/2) ;

    x = (x * x) % M;

    if(b & 1)
        x = (x * a) % M;
    return x;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    vector < ll > p(1<<N,1);

    for(int i = 1; i < (1<<N); i++) p[i] = (p[i-1]*2) % M;

    int n,m;
    cin >> n;

    vector < ll > dp(1<<N,0), v(n);

    for(int i = 0; i < n; i++) cin >> v[i] , dp[v[i]]++;

    for(int i = 0; i < N; i++)
    {
        for(int m = 0; m < (1<<N); m++)
        {
            if(!(m & (1<<i)))
                dp[m] += dp[m^(1<<i)] ;
            //dp[m] %= M;
        }
    }

    //cout << dp[(1<<N) - 1] << endl;


    for(int m = 0; m < (1<<N); m++)
        dp[m] = ( bigmod(2,dp[m]) - 1 + M) % M;

    ll ans = dp[0];

    //cout << ans << endl;

    int par = 0;

    for(int msk = 1; msk < (1<<N); msk++)
    {
        //cout << dp[m] << " ";
        if((__builtin_popcount(msk) & 1)  == par) {
            ans += dp[msk] ;
        }
        else
            ans -= dp[msk] ;

        ans %= M;
    }

    cout << (ans + M) % M << endl;

    return 0;
}
