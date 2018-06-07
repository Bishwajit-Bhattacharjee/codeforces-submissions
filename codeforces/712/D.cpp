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
    ll lat = bigmod(base, pow / 2, mod);
    lat = (lat * lat ) % mod;

    if(pow & 1)
            lat = (lat * base) % mod;
    return lat;

}

int const MX = 3*100*1000 + 110;
ll save[MX] ;

ll INV(ll val)
{
    return bigmod(val,MOD-2) ;
}
ll fact[MX] ;
ll inverse[MX] ;

ll ncr(ll n, ll r)
{
    if(n < r)
        return 0LL;
    if(n < 0 or r < 0 )
        return 0LL;
    ll ret =  fact[n]*inverse[r] % MOD ;
    ret = ret * inverse[n-r] % MOD ;
    return ret;
}
int a,b,k,t;

ll ways(ll num)
{
   
    num += ( k*t);
    assert(num+a+b+10 >= 0) ;
    ll &ret = save[num+a+b+10] ;
    if(ret != -1)
        return ret;
        
    ret = 0LL;
    if(num <= 2*k)
    {
        return ret = ncr(num+t-1,t-1) ;
    }
    for(int i = 0; i <= t; i++)
    {
        ll tmp = (ncr(t,i)*ncr(num-(2*k+1)*i+t-1,t-1)) % MOD ;
        if(i&1)
        {
            ret = (ret + MOD - tmp) % MOD ;
        }
        else
            ret = (ret + tmp) % MOD ;
    }
    return ret;
}
int main()
{

    cin >> a >> b >> k >> t;
    fact[0] = 1;
    for(int i = 1; i < MX; i++)
        fact[i] = ( fact[i-1] * 1LL*i) % MOD;

    for(int i = 0;i < MX; i++)
        inverse[i] = INV(fact[i]) ;
    memset(save,-1,sizeof save) ;
    ll ans = 0LL;
    ll cum = 0LL;
    ll mini = min(a-k*t, b-k*t) ;
    ll maxi = max(a,b) + k*t ;
    for(int i = mini ; i <= maxi ; i++)
    {
        ll tmp_way = ways(i-a) ;
       // cout << "number : ways  " << i << "  " << tmp_way << endl;
        if(i >= (a-k*t) && i <= (a+k*t))
        {
         //   cout << i << " " << tmp_way << "  " << cum <<  endl;

            ans = (ans + tmp_way*cum) % MOD ;

        }
        if(i >= (b- k*t)&&(i <= (b+k*t)))
        {
            tmp_way = ways(i-b) ;
            cum = (cum + tmp_way) % MOD;
        }
    }
    cout << ans << endl;
}