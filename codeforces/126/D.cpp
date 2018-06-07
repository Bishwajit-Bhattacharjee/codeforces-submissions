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
vector < ll > fibs;
ll INF = 2e18 + 10 ;
ll dp[150][3] ;
vector<int>zeck(150);
ll ways(int now,int last)
{
    if(!now)
    {
        return zeck[now] + last <= 1;
    }
    ll &ret = dp[now][last];
    if(ret != -1)
        return ret;

    ret = 0;
    if(zeck[now] + last <= 1)
        ret += ways(now-1,0);
    if(!zeck[now-1] && (zeck[now]+last >= 1))
    {
        ret += ways(now-2,1) ;
    }
    return ret ;

}
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r",stdin);
#endif
    fibs.pb(1);// = 1;
    fibs.pb(2);//= 2;
    for(int i = 2; fibs[i-1] + fibs[i-2] <= INF; i++)
    {
        fibs.pb(fibs[i-1] + fibs[i-2] );
        //cout << fibs[i] << "  " << i << endl;
    }
    int t;
    cin >> t;

    while(t--)
    {
        memset(dp,-1,sizeof dp);
        fill(all(zeck),0);
        ll n;
        cin >> n;
        int cur = fibs.size() - 1;
       // cout << cur << endl;
        while(n > 0)
        {
         //   cout << cur << endl;
            if(n >= fibs[cur])
              zeck[cur] = 1,n -= fibs[cur--];
            else
                zeck[cur--] = 0;
        }

        cout << ways(fibs.size()-1,0) << endl;
    }

    return 0;
}
