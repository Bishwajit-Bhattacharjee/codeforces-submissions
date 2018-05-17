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
#define ull unsigned long long int

vector < int > g[MX] ;

int ans;

int vis[MX] ;
int cnt[MX] ;

int dfs(int nd)
{
    if(g[nd].size() == 1 && nd != 1 )
    {
        return cnt[nd] = 1;
    }
    vis[nd] = 1;

    for(auto x : g[nd])
    {
        if(!vis[x])
        {
            cnt[nd] += dfs(x) ;
        }
    }
    cnt[nd]++;
    return cnt[nd] ;

}

void dfs1(int n )
{

    vis[n] = 1;
    for(auto x : g[n])
    {
        if(!vis[x] )
        {
            dfs1(x);
        }
    }
    if(n != 1 && cnt[n] % 2 == 0)
        ans++;

}


int main()
{
    //clock_t z = clock();
    ios_base::sync_with_stdio(false) ;
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    string tmp = "";
    tmp += 'a';
    tmp += s ;
    tmp += 'a';
    bool f = 1;
    for(int i = 1; i + 1 < tmp.size(); i++)
    {
        if(tmp[i] == '1')
        {
            if(tmp[i-1] == '1' or tmp[i+1] == '1')
            {
                f = 0;
                break;
            }
        }
        else if(tmp[i] == '0')
        {
            if(tmp[i-1] != '1' and tmp[i+1] != '1' )
            {
                f = 0;
                break;
            }
        }
    }
    printf("%s",f?"yes":"no") ;
    //printf("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
