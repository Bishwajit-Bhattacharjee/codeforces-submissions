#include <bits/stdc++.h>
using namespace std;
int const N = 1010;
int const MOD = 1e9 + 7;
int dp[N][N] ;
int ncr(int n,int r)
{
    if(n < r)
        return 0;
    if(r == 0) return 1;
    if(dp[n][r] != -1) return dp[n][r];
    dp[n][r] = (ncr(n-1,r)+ ncr(n-1,r-1)) % MOD;
    return dp[n][r];
}

int main()
{
    int n,m ,k;
    memset(dp,-1,sizeof dp);
    cin >> n >>m >>  k;

    cout << (1LL*ncr(m-1,2*k)*ncr(n-1,2*k)) % MOD << endl;
    return 0;
}
