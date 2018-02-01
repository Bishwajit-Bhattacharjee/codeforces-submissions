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
const int MX = 2e3 + 10 ;

ll dp[MX][MX];
ll dp1[MX];
ll dp2[MX];

string s;

ll isPalin(int i,int j)
{
    if(i > j ) return 1;
    ll &ret = dp[i][j] ;

    if(ret != -1)return ret;

    if(s[i] == s[j]) return ret = isPalin(i+1,j-1);
    return ret = 0;
}

ll DP(int from)
{

    if(from >= s.size()) return 0;
    ll &ret = dp2[from];
    if(ret != -1) return ret;

    ret = dp1[from] ;
    ret = ret + DP(from + 1);
    return ret;


}
int main()
{
    cin >> s;
    memset(dp,-1,sizeof dp);
    memset(dp2,-1,sizeof dp2);

    for(int i =0 ; i < s.size(); i++) {
        dp1[i] = 0;
        for(int j = i ; j < s.size();j++){
            dp1[i] += isPalin(i,j) ;
        }
    }
    DP(0);
    ll ans = 0;

    for(int i =0 ; i < s.size(); i++){
        for(int j = i; j < s.size();j++){
            if(isPalin(i,j)){
                ans += DP(j+1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
