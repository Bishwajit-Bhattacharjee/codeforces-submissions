#include <bits/stdc++.h>

using namespace std ;
int const MX = 4 * 1e5 + 100;
typedef long long int ll;
int const MOD = 1e9 + 7;

int dp[3][MX] ;
int r,g;

int main()
{
    cin >> r >> g;
    int h = 0;
    while(1LL*h*(h+1) / 2 <= (r+g))
        h++;
    h--;
    memset(dp, 0 ,sizeof dp) ;
    //cout << h << endl;

    dp[1][1] = (r >= 1) ;
    dp[1][0 ] = (g >= 1 );

    for(int i = 2; i <= h; i++)
    {
        for(int j = 0; j <= r; j++ )
        {
            int tt = i;

            int total_so_far = 1LL * tt*(tt+1) / 2 ;
            int used_g = max(0,total_so_far - j ) ;
           // int left_g = g - used_g ;
            
            int sum = 0;
            if(used_g <= g )
                sum =  dp[(i-1)&1][j]  ;
            if(j <= r && j >=  i )
                sum = sum + dp[(i-1)&1][j-i]  ;
                if(sum >= MOD ) sum -= MOD;
            dp[i&1][j]  = sum ;
            

        }
    }
    
    int sum = 0;
    for(int i = 0; i <= r; i++){
        sum = ( sum*1LL + dp[h&1][i]) ;
        if(sum >= MOD ) sum -= MOD;
     //  if(dp[h&1][i])printf("%d\n", sum);
    }
        
    cout << sum << endl;

    return 0;
}