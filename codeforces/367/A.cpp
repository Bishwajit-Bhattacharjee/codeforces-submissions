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
/*const int MX = 2e5 + 10;
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
}*/


int const MX = 2e5 + 10;

int cnt[MX][3];

int main()
{
   #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
//       freopen("out.txt","w",stdout);
       
   #endif
 
    FAST;
    
    string s;
    cin >> s;

    for(int i = 1; i <= s.size(); i++)
    {
        for(int j = 0; j < 3; j++)
            cnt[i][j] = cnt[i-1][j];
        cnt[i][s[i-1]-'x']++;
    }

    int m;
    cin >> m;
    while(m--)
    {
        int l,r;
        cin >> l >> r;
        int len =  r - l + 1;
        int ara[3] ;

        for(int i = 0; i < 3; i++)
            ara[i] = cnt[r][i] - cnt[l-1][i] ;
        sort(ara,ara + 3,greater<int>());
        bool f = 0;
        
        if(len % 3 == 0)
        {
            f = (ara[0] == ara[1] and ara[1] == ara[2] and ara[2] == (len/3));

        }
        else if(len % 3 == 1)
        {
            f = (ara[0] == ((len/3) + 1) and ara[1] == ara[2]);
        }
        else
        {
            f = (ara[0] == (len/3 + 1) and ara[1] == (len/3 + 1) and ara[2] == (len/3));
        }


        if(len < 3 ) 
            f = 1;
        
        if(f){
            cout << "YES" << endl;
        }
        else 
            cout << "NO" << endl;
    }
    return 0 ;
}
