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
const int MX = 1e6+ 10;

//vector < int > divi[MX];

ll nc2(int num)
{
    if(num < 0 ) return 0;
    return 1LL*num * (num-1)/2 ;
}
ll cnt(ll num)
{
    if(num < 10 ) return num;
    ll t = 1;
    while(num != 0) {
        ll tmp = num % 10 ;
        if(tmp) t *= tmp;
        num /= 10 ;
    }
    return cnt(t);
}
priority_queue < ll > pq;
typedef pair < double ,double >  PBB;

double dist(PBB a, PBB b)
{
    return sqrt( (a.F - b.F) *(a.F - b.F) + (a.S - b.S) *(a.S - b.S) );

}
int main()
{
    //clock_t z = clock();
   // READ;
    double R, x1,y1,x2,y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;

    if(dist({x1,y1},{x2,y2}) > R){
        printf("%.10f %.10f %.10f\n",x1,y1,R);
    }
    else {
        if(x1==x2 and y1 == y2){
            printf("%.10f %.10f %.10f\n",x1,y1 + R/2,R/2);
            return 0;
        }
        double dst = dist({x1,y1},{x2,y2});
        double rad = (R + dst) / 2;
        double x = x1 *(dst + R) - R * x2;
        x /= dst;
        double y = y1*(dst+R)- R * y2;
        y /= dst;
        x = (x + x2) /2 ;
        y = (y + y2) /2 ;
        printf("%.10f %.10f %.10f\n",x,y,rad);

    }


    //printf("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
