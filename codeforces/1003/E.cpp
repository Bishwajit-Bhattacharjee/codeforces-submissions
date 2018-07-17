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
const int MX = 4e5 + 100 ;
vector < int > g[MX] ;
int dim[MX] ;
int deg[MX] ;
int vis[MX] ;
int main()
{
   // clock_t z = clock() ;
//#ifndef ONLINE_JUDGE
//    freopen("in.txt","r",stdin);
//#endif // ONLINE_JUDGE
    vector < PII > ans;
    int n,d,k ;
    cin >> n >> d >> k;
    if(d + 1 > n )
    {
        cout << "NO" << endl;
        exit(0) ;
    }
    for(int i = 1; i < d + 1; i++)
    {
        ans.pb({i,i+1}) ;
        deg[i]++;
        deg[i+1]++;
        if(deg[i] > k or deg[i+1] > k )
        {
            cout << "NO" << endl;
            exit(0) ;
        }
        vis[i] = vis[i+1] = 1;
        dim[i] = max(i-1,d+1- i) ;
        dim[i+1] = max(i+1-1,d+ 1 - i - 1) ;
    }
    int cur = 2;
    for(int i = d + 2; i <= n; i++)
    {
        while( (deg[cur] >= k or dim[cur] >= d or cur == (d + 1 ) or !vis[cur]) && cur <= n )
            cur++;
       // cout << cur << endl;
        if(cur == n + 1 )
        {
            break;
        }
        ans.pb({cur,i}) ;
        deg[i]++;
        deg[cur]++;
        dim[i] = dim[cur] + 1;
        vis[cur] =  vis[i] = 1;

    }
    if(ans.size() != n - 1 )
    {
        cout << "NO" ;
        exit(0) ;
    }
    puts("YES") ;
    for(auto x : ans)
    {
        printf("%d %d\n", x.F, x.S ) ;
    }
    //printf("%.10f\n", ans) ;

   // printf("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}