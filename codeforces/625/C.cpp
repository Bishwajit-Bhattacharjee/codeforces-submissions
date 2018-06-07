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
const int MX = 2e5 + 10 ;
 vector < ll > adj[MX] ;
ll ara[MX] ;

int n;
int dp[MX][40] ;

bool DP(int i ,int left)
{
    if(left == 0)
        return (i <= n) ;
    if(i == n )
        return 0;

    int &ret = dp[i][left] ; //}
    if(ret != -1 )
        return ret;
    //ret = 0;
    ret = DP(i + 1, left);

    for(int x = 0 ; x < adj[i].size(); x++)
    {
        ll v = adj[i][x] ;
        ret |= DP(v, left-1);
    }
    return ret;

}
int main()
{
   // clock_t z = clock() ;
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0) ;

   // int n;
    int n, k ;
    cin >> n >> k;
    ll ans = 0LL;

    int ara[n+10][n+10];
    ordered_set st;
    for(int i= 1; i <= n*n; i++)
        st.insert(i) ;

//    ll ans = 0;
    int last = -1;
    for(int i = 1; i <= n;i++)
    {
        last = -1;
        for(int j = 1; j <= n;j++)
        {
            if(j != k)
            {
                int id = st.order_of_key(last);
                ara[i][j] = *st.find_by_order(id);
                st.erase(st.find_by_order(id)) ;
            }
            else
            {
                int sz = st.size();
                auto it = st.find_by_order(sz-n+k-1);
                ans += *it ;
                last = *it;
                //cout << *it << endl;//)
                ara[i][j] = *it;
                st.erase(it);

            }
        }
    }
    cout << ans << endl;
    for(int i = 1;i <= n; i++)
    {
        for(int j =1;j<=n;j++)
            cout <<ara[i][j] << " " ;
        cout << endl;
    }

   // printf("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
