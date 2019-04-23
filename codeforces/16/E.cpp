#include <bits/stdc++.h>
using namespace std;
int const N = 18;
typedef long long int ll;
int const sz = (1<<N) + 100;
bool vis[sz];
double dp[sz] ;
int n;
double prob[N+1][N+1] ;
double DP(int mask)
{
    int on = __builtin_popcount(mask);
    if(on == n) return 1;
    if(vis[mask]) return dp[mask] ;
    dp[mask] = 0;
    vis[mask] = 1;
    int ways = (on+1)* on / 2;

    for(int i = 0; i < n; i++)
    {
        if(!(mask & (1<<i))) continue;
        for(int j = 0; j < n; j++)
        {
            if(mask&(1<<j)) continue;
            dp[mask] += 1.0/ways * prob[i][j] * DP(mask ^ (1<<j)) ;
        }
    }
    return dp[mask] ;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> prob[i][j] ;

    for(int i = 0; i < n; i++)
        cout << fixed << setprecision(9) << DP(1<<i) << " ";
    cout << endl;


    return 0;
}
