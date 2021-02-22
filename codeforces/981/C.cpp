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

vector < int > adj[MX] ;
vector < int > ans;
int cnt ;
int no;
void dfs(int node, int par)
{
    if(adj[node].size() == 1 && no != node)
    {
        ans.pb(node) ;
        return ;
    }
    for(int i = 0 ; i <  adj[node].size(); i++ )
    {
        int x = adj[node][i] ;
        if(x != par)
        {
            dfs(x, node);
        }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin) ;
    int n;
    cin >> n;
    for(int i =0 ; i + 1 < n; i++)
    {
        int a, b;
        scanf("%d %d",&a,&b) ;
        adj[a].pb(b) ;
        adj[b].pb(a) ;

    }
     no = 1;
    for(int i = 1; i <= n ; i++)
    {
        if(adj[i].size() > 2 )
        {
            cnt++;
            no = i;
        }
    }
    if(cnt > 1 )
    {
        return 0*puts("No");
    }
    dfs(no, -1) ;
    puts("Yes") ;
    cout << ans.size() << endl;
    for(int i =0 ; i < ans.size(); i++)
    {
        printf("%d %d\n", no ,ans[i] ) ;
    }
    return 0;
}
