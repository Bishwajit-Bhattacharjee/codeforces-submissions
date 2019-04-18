#include <bits/stdc++.h>

using namespace std;
typedef pair < int,int >  PII;
int const N = 50;
typedef long long int ll;

ll dp[N][N][N] ;

ll DP(int a, int b, int k)
{
    if(a < 0 or b < 0 or a * b < k) 
        return 1e12;
    if(a * b == k or k == 0 )
        return 0;
        
    ll &ret = dp[a][b][k] ;
    if(ret != -1)
        return ret;
    
    ret = 1e13;
    
    for(int x = 1; x < a; x++)
    {
        
        for(int kk = 0; kk <= k; kk++)
            ret = min(ret, b * b + DP(x,b,kk) + DP(a-x,b,k - kk)) ;
    }
    for(int y = 1; y < b; y++)
    {
        for(int kk = 0; kk <= k; kk++)
        {
            ret = min(ret, a * a + DP(a,y,kk) + DP(a,b - y, k - kk)) ;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(dp,-1,sizeof dp);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m, k;
        cin >> n >> m >> k;
        cout << DP(n,m,k) << '\n';
    }
    return 0;
}