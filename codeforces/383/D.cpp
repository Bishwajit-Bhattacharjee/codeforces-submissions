/// HK 108 Times
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std ;
#define ll long long
#define pb push_back
typedef pair <int,int>  PII ;
vector < PII > given ;
vector < pair < int , PII >  >  edge  ;
typedef pair < ll, ll > PLL ;
#define all(x) (x).begin() , (x).end()
#define F first
#define S second
//#define DEBUG(x) cout <<" #(x) <<
#define READ freopen("in.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout)
#define FAST ios_base::sync_with_stdio(false)
#define ll long long
#define MOD 1000000007
#define endl '\n'


ll bigmod(ll base, ll pow, ll mod = MOD )
{
        if(!pow)
                return 1 ;
        ll lat = bigmod(base, pow/ 2, mod);
        lat = (lat * lat ) % mod;

        if(pow & 1)
                lat = (lat * base) % mod;
        return lat;

}

int const MX = 1e3 + 3;
int ara[MX] ;
#define OFFSET 10000
int dp[MX][22000][2] ;
int n;
ll DP(int i , int tot, bool take)
{
    if(i == n )
    {
        return (tot == 0) && (!take) ;
    }
    int &ret = dp[i][tot + OFFSET][take] ;
    if(ret != -1)
        return ret;

    ret = 0;
    if(take)
    {
        ret = DP(i+1,tot + ara[i], take ) + DP(i+1,tot - ara[i], take) ;
        if(ret >= MOD) 
            ret -= MOD ;
            
        ret += DP(i+1,tot + ara[i], !take ) ;
        if(ret >= MOD) 
            ret -= MOD;
            
        ret += DP(i+1,tot - ara[i], !take) ;
        if(ret >= MOD) 
            ret -= MOD ;
    }
    else
    {
        ret = DP(i+1,tot, take) ;
    }
    return ret;

}
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r",stdin);
#endif

    memset(dp,-1,sizeof dp);
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> ara[i] ;

    }

    ll ans = 0LL;

    for(int i = 0 ; i < n; i++)
    {
        ans = ans + DP(i,0,1) ;
        if(ans >= MOD)
            ans -= MOD ;
    }
    cout << ans << endl;

    return 0;
}
