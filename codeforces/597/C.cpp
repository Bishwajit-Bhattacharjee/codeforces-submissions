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
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
PLL,					// type long long
null_type,
less<PLL>,
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
//int const MX = 3e5 + 10;
/*
const int MX = 1e6 + 10;
vector < int > prime;
bool mark[MX] ;

void sieve()
{
    mark[1] = 1;
    mark[0] = 1;
    for(int i = 2; 1LL * i * i < MX; i++)
    {
        if(!mark[i]){
            //prime.pb(i);
            for(int j = 2 * i; j < MX; j += i )
            {
                mark[j] = 1;
            }

        }
    }
    for(int i = 2; i < MX; i++)
        if(!mark[i])
            prime.pb(i);
}
*/

int const MX = 1e5 + 10;

ll BIT[MX][15];
ll dp[MX][15];

ll query(int i,int kk)
{
    ll sum = 0;
    for(int x = i; x > 0 ; x -= (x & -x))
        sum += BIT[x][kk];
    return sum;
}
void update(int i,ll val,int kk)
{
    for(int x = i; x < MX; x += (x & -x))
        BIT[x][kk] += val;
}

int main()
{
    #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       //freopen("out.txt","w",stdout);
       
    #endif
    FAST;
    int n,k;
    cin >> n >> k;
    if(k + 1 > n)
        return cout << "0" << endl, 0;

    vector < PII > v(n+1);

    for(int i = 1; i <= n; i++)
        cin >> v[i].F, v[i].S = i;
    
    sort(v.begin()+1,v.end());

    for(int i = 1; i <= n;i++){

        update(v[i].S,1,1);
        dp[i][1] = 1;
        for(int j = 2; j <= k+1;j++){
            dp[i][j] = query(v[i].S -1,j-1);
            update(v[i].S,dp[i][j],j);
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++)
        ans = ans + dp[i][k+1] ;

    cout << ans << endl;

    return 0;

}
