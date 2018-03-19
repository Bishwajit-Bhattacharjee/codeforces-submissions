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
#define DEBUG(x) cout << #x << ' ' << x << endl

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
const int MX = 1e6 + 10 ;
ll tree1[MX], first[MX];


void add(int id, int val)
{
    for(int i = id; i < MX; i += ( i & -i)){
        tree1[i] += val;
    }
}

ll getSum(int i)
{
    ll sum = 0;
    for(int x = i ; x > 0 ; x -= (x & -x) )
        sum += tree1[x];
    return sum;
}

int main()
{
    //clock_t z = clock();
    // READ;

    ios::sync_with_stdio(false);
    map < int, int > mp;
    int n;
    cin >> n;
    vector < int > v(n) ;//)
    for(int i =0 ; i < n ;i++)
        cin >> v[i] ;
    vector < int > newv(v) ;

    sort(all(newv)) ;

    for(int i = 0; i < newv.size(); i++)
    {
        mp[newv[i]] = i+1;
    }


    for(int i = n-1; i >= 0;i--)
    {
        int tmp = mp[v[i]];
        int tmp2 = getSum(tmp-1);
        first[i] = tmp2;
        //ans += 1LL* tmp2 *(tmp2 - 1) /2 ;
        add(tmp,1);
    }

    ll ans = 0;

    memset(tree1,0,sizeof tree1) ;

    for(int i = n - 1; i >= 0 ; i--)
    {
        int tmp = mp[v[i]];
        ll tmp2 = getSum(tmp - 1) ;
        ans += tmp2;
        add(tmp,first[i]) ;
    }


    cout << ans << endl;

    //printf("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
