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
const int MX = 2e5 + 10 ;

ll power(ll base, ll pow)
{
    ll ret = 1LL;
    for(int i = 1; i <= pow; i++)
        ret *= base;
    return ret;

}
ll method(ll num)
{
    // does not work for 0 :'(
    ll digit = 0;
    ll tmp = num;
    if(num == 0)
        return 0;
    while(tmp!=0)
    {
        tmp/= 10;
        digit++;
    }
    if(digit == 1)
        return 1;
    ll divi = power(10,digit-1);

    ll ret = 0;
    for(int i = 1; i < digit; i++)
    {
        ret += power(10,i-1);
    }
    if(num/divi != 1)
    {
        ret += power(10,digit-1);
    }
    else
    {
        ret += (num % divi + 1) ;
    }
    return ret ;

}

double dp[1010][1010];
bool vis[1010][1010];

ll n, l, r;
double pr[1010];
int k;

double DP(int whr,int one)
{

    if(one*100  >= k*n )
        return 1;
    if(whr == n)
        return 0;
    double &ret = dp[whr][one] ;
    if(vis[whr][one])
        return ret;
    vis[whr][one] = 1;
    ret = 0;
    ret = pr[whr]*DP(whr+1,one+1) + (1-pr[whr])*DP(whr+1,one);
    return ret;

}
int main()
{
   // clock_t z = clock() ;
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif // OLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0) ;

    memset(vis,0,sizeof vis);

    cin >> n ;
    for(int i = 0;i < n;i++)
    {
        ll l, r;
        cin >> l >> r;
        ll way = method(r) - method(l-1) ;
        pr[i] = way*1.0 / (r-l+1) ;
    }
    cin >> k;



    cout << fixed <<  setprecision(13) << DP(0,0) << endl;

   // printf("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
