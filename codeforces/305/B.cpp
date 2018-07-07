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
const int MX = 50000 + 10 ;

vector < ll > given;
vector < ll > created, created1;

void rec(ll p, ll q)
{
    created.pb(p/q) ;
    if(p % q == 0){
        if(p != q)
        {
            created1.pb(p/q-1);
            created1.pb(1);
        }
        return ;
    }
    created1.pb(p/q);

    rec(q,p%q) ;
}
int main()
{
//clock_t z = clock() ;
#ifdef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    FAST;
    cin.tie(0) ;
#endif // ONLINE_JUDGE
    int n;
    ll p, q ;
    cin >> p >> q;
    rec(p,q) ;
//    for(auto x: created1 )
//    {
//        cout << x <<" " ;
//    }
//    cout << endl;
    if(p < q)
    {
        return cout << "NO", 0 ;
    }
    cin >> n;
    for(int i =0 ; i < n; i++){
        ll tmp ;
        cin >> tmp ;
        given.pb(tmp) ;
    }

    bool f = 0;
    if(given.size() == created.size())
    {
        f = 1;
        for(int i =0 ; i< n; i++)
        {
            if(given[i] != created[i] )
            {
                f = 0; break;
            }
        }
    }
    bool f_1 = f ;
    f = 0;
    if(given.size() == created1.size())
    {
        f = 1;
        for(int i =0 ; i< n; i++)
        {
            if(given[i] != created1[i] )
            {
                f = 0; break;
            }
        }
    }
    f_1 |= f;
    f = f_1;

    if(f)
    {
        puts("YES");
    }
    else
        puts("NO") ;
    //return 0;
// printf("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
