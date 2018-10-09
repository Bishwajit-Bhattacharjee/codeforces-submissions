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

int const MX = 2e5 + 10;
int Map[MX] ;
vector < int > Pair[MX];
vector < PII > QList[MX];
ll BIT[MX];

ll query(int i)
{
    ll sum = 0;
    for(int x = i; x > 0 ; x -= (x & -x))
        sum += BIT[x];
    return sum;
}
void update(int i,int val)
{
    for(int x = i; x < MX; x += (x & -x))
        BIT[x] += val;
}

int main()
{
    #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       //freopen("out.txt","w",stdout);
       
    #endif
    FAST;
    int n,m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        Map[tmp] = i;
    }
    for(int a = 1; a <= n; a++)
    {
        int aa = Map[a];
        for(int b = a; b <= n; b += a){
            int bb = Map[b] ;
            Pair[max(aa,bb)].pb(min(aa,bb));
        }
    }
    vector < int > ans(m+1);
    for(int i = 1; i <= m;i++)
    {
        int l,r;
        cin >> l >> r;
        QList[r].push_back({l,i});
    }

    for(int i = 1; i <= n; i++)
    {
        for(auto left: Pair[i]){
            update(left,1);
        }
        ll tmp = query(i);
        for(auto pr: QList[i]){
            ans[pr.S] = tmp - query(pr.F - 1);
        }
    }
    for(int i =1; i <= m; i++)
        cout << ans[i] << endl;

    return 0;

}
