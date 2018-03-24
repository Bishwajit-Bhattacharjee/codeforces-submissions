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
const int MX = 1e5 + 10 ;

ll ara[MX] ;
    int n,u;

double calc(int i, int k)
{
    if(k - i < 2 ) return -1;
    return ( 1.0*ara[k] - ara[i+1]) / (1.0 * ara[k] - ara[i]) ;
}
double ts(int l, int h, int tk)
{
    if(l > h ) return -1;
    double ans = 0;
    while(l <= h)
    {
        int mid1 = l + (h-l) / 3;
        int mid2 = h - (h-l)  / 3;
        if(calc(tk, mid1) > calc(tk,mid2))
        {
            ans = max(ans , calc(tk, mid1) );

            h = mid2-1;
        }
        else if(fabs(calc(tk, mid1) - calc(tk,mid2)) < 1e-12)
        {
            ans = max(ans , calc(tk, mid1) );
            h = mid2-1;
            l = mid1 + 1;

        }
        else
        {
                        ans = max(ans , calc(tk, mid2) );

            l = mid1 + 1;
        }

    }
    return ans;
}
int main()
{
    //clock_t z = clock();
    cin >> n >> u;

    for(int i = 0;i < n;i++)
    {
        scanf("%lld",&ara[i]);

    }
//    while(ara[n] - ara[0] > u )
//    {
//        n--;
//    }
//    if(n < 2) {
//        puts("-1") ; return 0;
//    }
//    if(ara[n-1] - ara[0] > u )
//    {
//        puts("-1"); return 0;
//    }
    double ans = -1;
    for(int i = 0 ; i + 2< n; i++)
    {
        int id = upper_bound(ara, ara+n, ara[i] + u) - ara ;
        id--;
        ans = max(ans , ts(i + 2, id,i) ) ;
        //ans = max(ans,calc(i,id));
    }
    if(ans < 0 ) {
        puts("-1");
    }
    else
        printf("%.10f\n",ans);
    //printf("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
