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

ll
x[MX] ;
ll a[MX];
ll b[MX];
ll s1,s2;
int n;

bool valid()
{
    ll t1 =0  , t2= 0;

    for(int i = 0 ;i < n/2 + 1; i++){
        t1 += a[x[i]], t2 += b[x[i]];
    }
    return (t1 * 2 > s1 and t2 * 2 > s2) ;
}
int main()
{
    //clock_t z = clock();
   // READ;
    cin >> n;
    for(int i = 0; i< n;i++) scanf("%d",&a[i]), s1 += a[i];
    for(int i = 0 ; i <n;i++) scanf("%d",&b[i]) , s2 += b[i];

    for(int i = 0 ; i < n;i++)
        x[i] = i ;
    int cnt = 0;
    while(!valid()){
        random_shuffle(x,x + n) ;
        cnt ++;
       // cout << cnt << endl;
    }

    printf("%d\n",n/2 + 1) ;
    for(int i = 0 ; i < n/2 + 1; i++)
        printf("%d ",x[i] + 1) ;
    //printf("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}