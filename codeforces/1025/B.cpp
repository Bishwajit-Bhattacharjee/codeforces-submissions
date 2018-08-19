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
const int MX = 2e5 + 10;
vector < int > prime;
bool mark[MX] ;

void sieve()
{
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
vector < PII > v;
vector < int > chk;

void f(int num)
{
    for(auto x : prime)
    {
        int cnt = 0;
        while(num % x == 0) num /= x, cnt++;
        if(cnt > 0 )
            chk.pb(x);
    }
    if(num > 1 )
        chk.pb(num);

}
int main()
{
    FAST;
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    sieve();

    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        v.pb(PII(a,b));
    }
    f(v[0].F);
    f(v[0].S);

    int ans = -1;
    //cout << chk.size() << endl;
    for(auto x : chk)
    {
        bool can = 1;
        for(int i =0 ; i < n  && can ; i++)
        {
            if(v[i].F % x != 0 and v[i].S % x != 0) 
                can = 0;
        }
        if(can)
        {
            cout << x << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0 ;
}
