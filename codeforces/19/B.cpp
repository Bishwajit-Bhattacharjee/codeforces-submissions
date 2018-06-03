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
ll t[2010],c[2010] ;
int n;
ll dp[2010][2010];

ll DP(int i,int tot)
{
    if(tot >= n)
        return 0;
    if(i == n )
    {
        if(tot < n )
            return (ll)1e17;
        else
            return 0;
    }
    ll &ret = dp[i][tot] ;
    if(ret != -1)
        return ret;

    ret = min(DP(i+1,tot),c[i] + DP(i+1,tot+t[i]));
    return ret;

}
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
#ifndef ONLINE_JUDGE
    freopen("in.txt","r", stdin) ;
#endif // ONLINE_JUDGE

    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> t[i] >> c[i] ,t[i]++;
    memset(dp,-1,sizeof dp) ;

    cout << DP(0,0) << endl;
    return 0;
}
