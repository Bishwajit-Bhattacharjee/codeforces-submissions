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
#define READ freopen("1004in.txt","r",stdin)
#define WRITE freopen("1004out.txt","w",stdout)
#define FAST ios_base::sync_with_stdio(false)
#define ll long long
#define MOD 1000000007

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
const int MX = 1e5 + 10;
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
double dp[1010][1010][3];
bool vis[1010][1010][3];

double DP(int w,int b,int pl)
{
    if(w + b <= 0) {
        return 0.0;
    }
    if(b <= 0){
        return (pl == 0);
    }
    if(w <= 0 ) {
        return 0.0;
    }
    if(vis[w][b][pl]) return dp[w][b][pl];
    double &ret = dp[w][b][pl];
    vis[w][b][pl] = 1;
    if(!pl){
        ret = (w*1.0/(b+w)) * 1.0 + (b*1.0)/(b+w)*(DP(w,b-1,!pl)) ;

    }
    else {
        ret = (b*1.0/(b+w)) * (((b-1)*1.0/(w+b-1))*DP(w,b-2,!pl) +
                               (w*1.0/(w+b-1))* DP(w-1,b-1,!pl)) ;
    }
    return ret;
}

int main()
{
    int w,b;
    cin >> w >> b;
    memset(vis,0,sizeof vis);

    printf("%.10f\n",DP(w,b,0)) ;

    return 0;
}
