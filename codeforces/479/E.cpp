#include <bits/stdc++.h>
using namespace std;
int const N = 5e3 + 5;
int const MOD = 1e9 + 7;
int dp[N][N];
int psum[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,a,b,k;
    cin >> n >> a >> b >> k;

    dp[0][a] = 1;
    for(int i = 1; i <= n; i++)
        psum[0][i] = ( psum[0][i-1] + dp[0][i] ) % MOD;

    for(int K = 1; K <= k; K++)
    {
        for(int nn = 1; nn <= n; nn++)
        {
            int &ret = dp[K][nn] ;
            int from , to ;
            if(b > nn ){
                from = 1;
                to = nn + (abs(b-nn-1))/2 ;
                //cout << nn << " " << from << " " << to << endl;
                ret =  ( 1LL*psum[K-1][to] - psum[K-1][from-1] - dp[K-1][nn] + 2 * MOD) % MOD;
            }
            else if(nn > b)
            {
                from = nn - (abs(nn-b-1))/2;
                to = n;
                //cout << nn << " " << from << " " << to << endl;
                ret =  ( 1LL*psum[K-1][to] - psum[K-1][from-1] - dp[K-1][nn] + 2 * MOD) % MOD;
            }
            else {
                dp[K][nn] = 0;
            }
            psum[K][nn] = (psum[K][nn-1] + dp[K][nn] ) % MOD;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
    //    int ans = 0;
        ans = (ans + dp[k][i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}
