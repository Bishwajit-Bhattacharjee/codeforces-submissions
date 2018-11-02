#include <bits/stdc++.h>
using namespace std;
int const MX = 1010;
int const MOD =998244353;
int dp[MX];
int ara[MX] ;
int n;
int dp1[MX][MX] ;

int ncr(int n,int r)
{
    if( n < r) return 0;
    if(n == r)
        return 1;
    if(r == 0)
        return 1;
    int &ret = dp1[n][r] ;
    if(ret != -1)
        return ret;
    ret = (1LL* ncr(n-1,r) + ncr(n - 1,r - 1) ) % MOD;
    //ret %= MOD;
    return ret;
}
int DP(int i)
{
    if(i == n) {
        return 0;
    }
    if(i > n)return 1;
    if(dp[i] != -1)
        return dp[i];
    dp[i] = 0;
    if(ara[i] <= 0)
        return dp[i] ;
    int k = ara[i] + 1;
    for(int j = i + 1; j <= n; j++)
    {

        dp[i] = (1LL* dp[i] + 1LL * ncr(j - i,k-1) * DP(j+1)) % MOD;


    }
    return dp[i] ;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp1,-1,sizeof dp1);

    cin >> n;
    memset(dp,-1,sizeof dp);
    for(int i = 1; i <= n; i++)
        cin >> ara[i] ;
    int ans = 0;

    for(int i = 1; i <= n;i++)
        ans = (ans*1LL + DP(i)) % MOD;
    cout << ans << endl;

    return 0;
}
