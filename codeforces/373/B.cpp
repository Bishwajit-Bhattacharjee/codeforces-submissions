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

        find_by_order(k) --> returns iterator to the elements
                            //that has k elements less in the set

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
const int MX = 1e6 + 100;
ll can ;
ll w,m, k;

ll count(ll num)
{
    if(!num) return 0 ;

    int dig = 0;
    ll tmp = num;
    while(tmp != 0)
        tmp /= 10, dig++;
    ll tot = 0;
    ll pow = 1LL;
    for(int i = 1; i < dig; i++)
        tot += 9 * pow * i , pow *= 10 ;
    tot += (num - pow + 1) * dig ;
    return tot ;

}
bool possible(ll len)
{
    if(len == 0) return 1;
    ll num = m + len - 1;
    return (count(num) - count(m - 1) <= can) ;
}
int main()
{
//clock_t z = clock() ;
    FAST;
    cin.tie(0);
    cin >> w >> m >> k;
    can = (w/k) ;

   // cout << count(w) << " " << count(m) << " " << count(k) << endl;
    ll lo = 0, hi = 2e16 + 100;
    ll ans = -1;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2 ;
        if(possible(mid)){
            ans = max(ans, mid) ;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }

    cout << ans << endl;
// printf("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
