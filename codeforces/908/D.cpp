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
#define READ freopen("in.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout)
#define FAST ios_base::sync_with_stdio(false)
#define ll long long
//#define M 100007
#define mod 1000000007
#define endl '\n'

long long bigmod(long long p,long long e,long long M){
    long long ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
ll modinverse(ll a,ll M){return bigmod(a,M-2,M);}
ll bigmod(ll base, ll pow)
{
    if(pow == 0) return (1 % mod);
    ll x = bigmod(base, pow/2 );
    x = ( x * x ) % mod;
    if(pow % 2 == 1)
         x = (x * base) % mod;
    return x;
}

// Order Statistic Tree

/* Special functions:

        find_by_order(k) --> returns iterator to the kth largest element counting from 0
        order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/

typedef tree<
int,					// type long long
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
const int MX = 1e5 + 10;

ll k , pa, pb,  p ;

ll dp[1010][1010] ;

ll one(ll tmp )
{
    ll cnt = ( 1LL *( (pb* tmp + pa) % mod)  ) % mod ;
    return (cnt * modinverse(p-pa, mod) ) % mod ;
}

ll E(ll ab, ll a )
{
    if(ab >= k ) return ab ;

    if(a == k && a ) {
        return one(ab + a ) ;
    }

    if(a == 0)
    {
        return E(ab, a + 1 ) ;
    }
    ll &ret = dp[ab][a] ;
    if(ret != -1) return ret ;

    ll cnt = ( pb * E(ab+a , a ) ) % mod;
    cnt = (cnt * modinverse(p,mod)) % mod;
    ll cnt1 = (pa * E(ab , a + 1) ) % mod ;
    cnt1 = (cnt1 * modinverse(p, mod) ) % mod ;
    return ret = (cnt + cnt1 ) % mod ;
}
int main()
{

    cin >> k >> pa >> pb ;
    p = pa + pb ;
    memset(dp, -1, sizeof dp) ;
    cout << E(0,0) << endl;

    return 0 ;
}
