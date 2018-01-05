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
const int mod = 1e9 + 7 ;

// Order Statistic Tree

/* Special functions:

        find_by_order(k) --> returns iterator to the kth largest element counting from 0
        order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/
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

int main()
{
    int k ;
    cin >> k;
    ll isEven = 0 ;
    ll threeMod  = 1LL;
    ll ret = 2LL;
    bool hasOnlyOne = true ;
    for(int i = 1; i <= k; i++)
    {
        ll tmp ;
        scanf("%lld", &tmp) ;
        if(tmp != 1)
            hasOnlyOne = false ;
        if(tmp % 2 == 0)
            isEven = 1;

        ret = ( bigmod(ret,tmp)) ;
        //threeMod = ( bigmod(threeMod,tmp,3)) % 3 ;
      //  cout << ret << endl;
    }
    isEven ^= 1;
    if(hasOnlyOne) {
        cout << "0/1" << endl;
        return 0;
    }

    //isEven = (isEven * modinverse(2,2) ) % 2 ;
    ret = (ret * modinverse(2,mod)) % mod ;
   // threeMod = ( threeMod * modinverse(2, 3)) % 3 ;
    //cout << ret << endl;

    if(!isEven) {

       cout <<( (ret + 1 )  * modinverse(3,mod) ) % mod << '/' << ret ;

//        threeMod = (threeMod + 1 ) % 3 ;
//     //   assert(threeMod != 0) ;
//        if(!threeMod) {
//            cout << ( ( (ret+1)%mod ) * modinverse(3,mod) ) % mod << '/'
//            << ret << endl;
//        }
//        else {
//            cout <<  ( (ret+1)%mod ) << '/'
//            << ( ret * 3 ) % mod << endl;
//        }
    }
    else {

       cout << ((ret - 1+mod ) * modinverse(3,mod) ) % mod << '/' << ret ;

//        threeMod = (threeMod - 1 + 3 ) % 3 ;
//     //   assert(threeMod != 0) ;
//        if(!threeMod){
//            cout << ( ( (ret-1+mod)%mod ) * modinverse(3,mod) ) % mod << '/'
//            << ret << endl;
//        }
//        else {
//            cout <<  ( (ret-1+mod)%mod ) << '/'
//            << ( ret * 3 ) % mod << endl;
//        }
    }
    return 0 ;
}

