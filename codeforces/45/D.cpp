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

int random(int l,int r)
{
    int range = r - l + 1;
    return l + (rand() % range ) ;
}
int main()
{
    int n;
    cin >> n;
    vector < pair < PII, int>  > ara(n);

    for(int i = 0; i < n; i++)
        cin >> ara[i].F.F >> ara[i].F.S, ara[i].S = i ;
   // cout << ara[0].S << endl;
    sort(all(ara)) ;
//    for(auto x : ara)
//    {
//        cout << x.F.F << endl;
//    }
    int id = 0;
    priority_queue < PII > pq;
    vector < int > ans(n) ;
    for(int cur = 1; cur <= (int)1e7 ; cur++)
    {
        while(ara[id].F.F <= cur && id < n )
        {
            pq.push({-1 * ara[id].F.S, -1 * ara[id].S});
            id++;
        }
        if(pq.empty())
            continue;

        PII top = pq.top();
        top.F *= -1;
        top.S *= -1;
        pq.pop();
        ans[top.S] = cur;
    }
    for(int i = 0 ; i < n; i++)
        cout << ans[i] << " " ;
    return 0;
}
