#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k;
ll ara[60] ;
ll mask;
int dp[60][60];
bool can(int id, int div ,ll mask)
{
    if(id >= n or div >= k)
    {
        return (id == n && div == k) ;
    }
    int &ret = dp[id][div] ;
    if(ret != -1)
        return ret;
    ll now = 0;
    ret = 0 ;
    for(int i = id ; i < n;i++)
    {
        now += ara[i] ;
        if((now & mask) == mask)
        {
            ret |= can(i+1,div + 1, mask);
        }
    }
    return ret;

}
int main()
{
    cin >> n >> k;
    for(int i = 0; i < n;i++)
    {
        cin >>ara[i] ;

    }

    ll ans = 0LL;
    for(int i = 58; i >=0 ; i--)
    {
        mask = ans;
        memset(dp,-1,sizeof dp) ;
        if(can(0,0,mask|(1LL<< i)))
        {
            ans |= (1LL << i) ;

        }
    }
    cout << ans << endl;
    return 0;
}
