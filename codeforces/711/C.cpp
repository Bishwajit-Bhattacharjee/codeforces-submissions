#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const MX = 110;
ll dp[MX][MX][MX];
ll P[MX][MX];
ll color[MX] ;
ll n,m,k;
//int vis[MX][MX][MX];

ll DP(int pos, int last,int bty)
{
    if(pos == (n+1) ){
        //cout <<
        if(bty + 1 == k)
            return 0;
        return (1e16);
    }
    ll &r = dp[pos][last][bty];
    if(r != -1)
        return r;

    if(color[pos] != 0){
        r = DP(pos+1,color[pos], (bty + (color[pos] != last and (last != (MX-1)))));
        return r;
    }

    r = 1e16;
    for(int i = 1; i <= m; i++)
    {
        r = min(r,P[pos][i] + DP(pos+1,i,(bty + (i != last and (last != (MX - 1)))))) ;
    }
    return r;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp,-1,sizeof dp);

    cin >> n >> m >> k;
    for(int i = 1; i <= n;i++)
        cin >> color[i];
    for(int i = 1; i <= n;i++)
        for(int j = 1; j <= m; j++)
            cin >> P[i][j] ;
    color[n+1] = -1;

    ll doo = DP(1,MX - 1,0);
    if(doo > 1e15){
        cout << "-1" << endl;
    }
    else
        cout << doo << endl;

    return 0;
}
