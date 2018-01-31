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
const int MX = 1e5 + 10;

bool isLucky(int n) {
    while(n != 0){
        int dig = n % 10;
        if(dig != 4 and dig != 7)
            return false;
        n /= 10;
    }
    return true;
}
ll fact[MX];
ll ncr(ll n, ll r)
{
    if(n < 0 or r < 0 ) return 0;

    if(n < r) return 0;
    ll t1 = modinverse(fact[r],mod);
    ll t2 = modinverse(fact[n-r],mod);
    ll ret = (((fact[n] * 1LL*t1) % mod) * t2) % mod;
    return ret;

    //return (fact[n]
}
map < ll , int > mp;
vector < ll > lucky;

void backtrack(ll cr)
{
    if(cr != 0 ) lucky.pb(cr);

    if(cr > (int)(1e9 + 100) )
        return;
    backtrack(4 + 10 * cr) ;
    backtrack(7 +10 * cr) ;
}
ll dp[2100][2100] ;
int cnt = 0;
int k;
ll DP(int id, int tkn)
{
    if(id == lucky.size()) {
        return ncr(cnt, k - tkn);

    }
    ll &ret = dp[id][tkn];
    if(ret != -1)
        return ret;
    if(!mp.count(lucky[id])) {
        ret = DP(id+1, tkn) ;
    }

    else {
        ret = ( mp[lucky[id]] * DP(id+1, tkn + 1) ) % MOD;
        ret = (ret +  DP(id+1, tkn )) % MOD;
    }
  //  cout << lucky[id] << " " << ret << endl;
    return ret;
}

int main()
{
    backtrack(0);
    sort(all(lucky));
    fact[0]  = 1;
    for(int i = 1 ; i < MX; i++)
        fact[i] = (fact[i-1] * i) % MOD ;

    int n;
    cin >> n >> k;
    int  tmp;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++){
        scanf("%d",&tmp);

        if(isLucky(tmp)){

            mp[tmp]++;
        }
        else
            cnt++;
    }
    ll ans = 0LL;
   // cout << cnt << endl;
   // cout << lucky.size() << endl;
    cout << DP(0,0) << endl;

    return 0;
}
