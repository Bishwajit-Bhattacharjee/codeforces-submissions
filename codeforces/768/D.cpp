#include <bits/stdc++.h>
using namespace std;
int const N = 1010;
typedef long long int ll;
double dp[N*10][N];
bool vis[N*10][N] ;
int n,k;
double P(int day,int left)
{
    if(left == 0) {
        return (day >= 0);
    }
    if(day == 0)
        return left == 0;

    if(vis[day][left])
        return dp[day][left] ;
    vis[day][left] = 1;

    dp[day][left] = 1.0* (k - left) / k * P(day-1,left) + 1.0*left/ k * P(day-1,left-1) ;
    return dp[day][left] ;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    //int n;
    int q;
    cin >> k >> q;
    memset(vis,0,sizeof vis);

    for(int i = 0; i < q; i++)
    {
        ll val;
        cin >> val;
        ll lo = 0, hi = N * 10 - 5;
        ll ans = hi;
        double need = 1.0 * val/ 2000;
        while(lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            if(P(mid,k) >= (need)) ans = min(ans,mid), hi = mid - 1;
            else
                lo = mid + 1;
        }
        cout << ans << '\n';
    }

    return 0;
}
