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
const int MX = 1e6 + 10 ;
ll tmpMOD = 998244353;

int main()
{
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;

    ll ans  =0;
    for(int i = 0;i  < a.size() / 2 ;i++)
    {
       map < char,int > mp;
       mp[a[i]]++;
       mp[a[n-1-i]]++;
       mp[b[i]]++;
       mp[b[n-1-i]]++;
       if(mp.size() == 3 ){
            ans++;
            if(a[i] == a[n -1-i] )
                ans++;
       }
       if(mp.size() == 4 ) ans+= 2;
       if(mp.size() == 2)
       {
            if(a[i] == a[n-1-i] ){
                if(b[i] != b[n-1-i] )
                    ans++;
            }
            else if((int)a[i] + a[n-1-i] != (int)b[i] + b[n-1-i] )
                    ans++;
       }
       //cout << i + 1 << ' ' << ans << endl;

    }
    if( n & 1 )
        ans = ans + (a[n/2] != b[n/2]) ;
    cout << ans  << endl;
    return 0;
}
