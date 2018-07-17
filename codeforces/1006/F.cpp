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
#define MOD 1000000007
#define endl '\n'

// Order Statistic Tree

/* Special functions:

        find_by_order(k) --> returns iterator to the kth largest element counting from 0
        order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/
const int mod = 1e9 + 7 ;
typedef tree<
int,					// type long long
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
long long bigmod(long long p,long long e,long long M){
    if(e < 0 )
        return 0;
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
const int MX = 1e6 + 10 ;
map < PLL , ll > mp;
ll n,m, k;
ll ara[25][25] ;

ll mandist(PII x, PII y )
{
    return abs(x.F - y.F) + abs(x.S - y.S) ;

}
void go1(int i,int j, ll XOR)
{
    if(i < 1 or i > n or j < 1 or j > m )
        return ;
    if(mandist({1,1}, {i,j}) == mandist({1,1}, {n,m}) / 2 )
    {
        mp[{i,XOR^ara[i][j]}]++;
        return ;
    }
    go1(i,j+1,XOR ^ ara[i][j]) ;
    go1(i+1,j,XOR ^ ara[i][j]) ;
}
ll ans ;

void go2(int i,int j , ll XOR)
{
    if(i < 1 or i > n or j < 1 or j > m )
        return ;
    if(mandist({n,m}, {i,j}) == ( 1 + mandist({1,1}, {n,m}) ) / 2 )
    {
        if(mp.count({i,XOR^k}))
            ans += mp[{i,XOR^k}];
        return ;
    }
    go2(i-1,j, XOR ^ ara[i][j] ) ;
    go2(i,j-1,XOR ^ ara[i][j] ) ;
}
int main()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> ara[i][j] ;
    go1(1,1,0);
    go2(n,m,0) ;
    cout << ans << endl;
    return 0;
}
