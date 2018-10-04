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

int const MX = 1e6 + 10;

ll dig(ll n)
{
    ll s = 0;
    while(n)
    {
        s += (n % 10);
        n /= 10;
    }
    return s;
}

int main()
{
   #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
//       freopen("out.txt","w",stdout);
       
   #endif

    FAST;
    int n,m;
    cin >> n >> m;

    vector < ll > x(n),y(m);
    vector < ll > tmpX(n+1,1e17),tmpY(m+1,1e17);

    for(int i =0 ; i < n; i++)
        cin >> x[i];
    for(int j = 0; j < m; j++)
        cin >> y[j] ;

    vector < ll > yp;

    for(int i = 0; i < m; i++)
    {
        ll tmp = 0;
        for(int j = i; j < m; j++){
            tmp += y[j] ;
            //yp.pb(tmp);
            tmpY[(j-i+1)] = min(tmpY[j-i+1],tmp);
        }
    }
    //sort(all(yp));
    ll matha ;
    cin >> matha;

    for(int i =0 ; i < n; i++)
    {
        ll tmp = 0;

        for(int j = i; j < n; j++)
        {
            tmp += x[j] ;
            tmpX[(j-i+1)] = min(tmpX[j-i+1],tmp);
        }
    }
    ll ans = 0;

    for(ll len1 = 1; len1 <= n; len1++)
    {
        for(ll len2 = 1; len2 <= m; len2++)
        {
            if(tmpX[len1]*tmpY[len2] <= matha){
                ans = max(ans,len1*len2);
            }
        }
    }
    cout << ans << endl;

    return 0;
}