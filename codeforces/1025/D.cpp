#include <bits/stdc++.h>
using namespace std;
int const MX = 710;
int dp[2][MX][MX] ;
int gcd[MX][MX] ;
int n;
int ara[MX] ;

bool DP(bool type, int l, int r)
{
     int root ;
    if(!type)
        root = min(r + 1, n - 1);
    else
        root = max(l - 1, 0) ;

    if(l == r )
    {
        return gcd[root][l] > 1 ;        
    }
    if(l > r )
        return 1;

    int &ret = dp[type][l][r];

    if(ret != -1)
        return ret;
    ret = 0;
   
    for(int x = l; x <= r; x++)
    {
        if(gcd[root][x] > 1 )
        {
            ret |= (DP(0,l,x-1) and DP(1,x+1,r));
            if(ret)
                break;
        }
    }
    return ret;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,-1,sizeof dp) ;
    cin >> n;

    for(int i = 0; i < n;i++)
        cin >> ara[i];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            gcd[i][j] = __gcd(ara[i],ara[j]) ;
        }
    }

    bool ans = 0;
    for(int i = 0 ; i < n; i++)
    {
        if(DP(0,0,i-1) and DP(1,i+1,n-1)){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
