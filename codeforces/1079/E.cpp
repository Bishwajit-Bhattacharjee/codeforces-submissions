#include <bits/stdc++.h>
using namespace std;
int const MX = 105;
int ara[MX] ;
int dp[3][MX][MX*MX];
int cnt[MX] ;
int const mod = 1e9 + 21;

void MOD(int &a, int b)
{
    if(a >= b)
        a -= b;
}
int dp1[MX][MX];

int ncr(int n,int r)
{
    if(n < r)
        return 0;
    if(r == 0)
        return 1;
    int &ret = dp1[n][r];

    if(ret != -1)  return ret;

    ret = ncr(n-1,r) + ncr(n-1,r-1) ;
    return ret = (ret % mod);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    set < int > baal;
    memset(dp1,-1,sizeof dp1);

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> ara[i+1];
        sum += ara[i+1] ;
        cnt[ara[i+1]]++;
        baal.insert(ara[i+1]);

    }

    if(baal.size() <= 2)
        return cout << n << '\n', 0;

    memset(dp,0,sizeof dp);

    dp[0][0][0] = 1;
    dp[1][0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int k = 1; k <= i; k++)
        {
            for(int w = 1; w <= sum ; w++)
            {

                int tmp = dp[(i-1)&1][k][w] ;

                if(w >= ara[i])
                    tmp += dp[(i-1)&1][k-1][w-ara[i]];
                dp[i&1][k][w] = tmp;
                //cout << i << " " << k << " " << " " << w << " " << dp[i&1][k][w] << endl;
                MOD(dp[i&1][k][w],mod);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= 100; i++)
    {
        for(int j = 1; j <= cnt[i]; j++)
        {
            int tmp = i * j ;
           // cout << dp[n&1][j][tmp] << " " << ncr(cnt[i],j) << " " << cnt[i] << " " << j << endl;
            if(dp[n&1][j][tmp] == ncr(cnt[i],j))
                ans = max(ans, j);
        }
    }
    cout << ans << endl;

}
