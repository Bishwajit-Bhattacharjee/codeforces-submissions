#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll dp[1<<19][20] ;
int edge[20][20];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m ;i++){
        int a, b;
        cin >> a >> b ;
        a--, b--;
        edge[a][b] = edge[b][a] = 1;
       // cout << a <<  b << endl;
    } //)

    for(int mask = 0; mask < (1<<n); mask++)
    {
        for(int i = 0; i < n; i++)
        {
            if(__builtin_popcount(mask) == 1 && (mask &(1<<i)))
                dp[mask][i] = 1;
            if(__builtin_popcount(mask) > 1 && (mask&(1<<i)))
            {
                if(__builtin_ctz(mask) != i)
                {
                    for(int j = 0;j < n; j++)
                    {
                        if(edge[i][j] && (mask&(1<<j)))
                        {
                            dp[mask][i] += dp[mask^(1<<i)][j] ;

                        }
                    }
                }
            }
        }
    }
   // cout << "eikhane" << endl;
    ll ans = 0;
    for(int mask = 0; mask < (1<<n) ; mask++)
    {
        if(__builtin_popcount(mask) < 3)
            continue;
        for(int i = 0; i < n; i++)
        {
            int first = __builtin_ctz(mask) ;
            if(edge[first][i])
                ans += dp[mask][i] ;
        }
    }
    cout << ans / 2 << endl;


}
