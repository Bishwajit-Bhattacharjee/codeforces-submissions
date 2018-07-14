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
bool done[MX];
int ara[MX] ;
int XOR(int num)
{
    int ret = 0;
    bool one = 0;
    for(int i = 30; i >=0 ; i--)
    {
        if(one){
            if((1<<i)&num){
                ret  = ret;
            }
            else
                ret ^= (1 << i ) ;
        }
        else if(num & (1<<i)){
            one = 1;
        }

    }
    return ret;
}
int main()
{
    FAST;
    cin.tie(0) ;
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++)
    {
        ara[i] = i;

    }
    vector < int > v(n+1);
    ll ans = 0;

    for(int i = n; i >= 0; i--)
    {
        if(!done[i]){
            int com = XOR(ara[i]) ;
            ans += 2 * (com ^ ara[i] );
            v[ara[i]] = com;
            v[com] = ara[i];
            done[ara[i]] = done[com] = 1;
        }
    }
    cout << ans << endl;
    for(auto x : v)
        cout << x << " " ;

    return 0;
}
