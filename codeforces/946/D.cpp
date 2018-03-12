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

pair < ll , ll > ara[100];


int n , m , k;
string g[510];
vector < int > ad[510];
int dp1[510][510];
ll dp[510][510];

ll DP(int id, int baad)
{
    if(id == n) return 0;
    ll &ret = dp[id][baad];
    if(ret !=-1) return ret;
    ret = 10000000LL;

    for(int i = 0;i <= baad; i++){
        ret = min(ret, dp1[id][i] + DP(id+1, baad - i));
    }
    return ret;
}
int main()
{
    //clock_t z = clock();
   // READ;
    cin >> n >> m >> k;
    memset(dp,-1,sizeof dp);

    for(int i = 0 ; i< n;i++){
        cin >> g[i];
    }
    for(int i = 0 ; i< n;i++){
        for(int j = 0 ; j < g[i].size(); j++){
            if(g[i][j] == '1') ad[i].pb(j); // one based indexed
        }
    }



    for(int i = 0; i< n;i++){
        for(int j = 0; j <= k; j++){
            if(j >= ad[i].size()){
                dp1[i][j] = 0;
            }
            else if(j + 1 == ad[i].size()){
                dp1[i][j] = 1;
            }
            else {
                dp1[i][j] = INT_MAX;
                for(int x = 0 ; x <= j;x++){
                    int rgt = j - x ;

                   // dp1[i][j] = min(dp1[i][j], max(0,ad[i][ad[i].size()-rgt-((rgt==0)?1:2)] - ad[i][x] + 1));
                    int tmpID = ad[i].size() - rgt -1;

                    dp1[i][j] = min(dp1[i][j], ad[i][tmpID] - ad[i][x] + 1 );
                }
            }
        }
    }

    cout << DP(0,k) << endl;
    //printf("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
