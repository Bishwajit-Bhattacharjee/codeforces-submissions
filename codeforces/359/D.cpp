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
int const MX = 3e5 + 10;


PII seg[MX][19] ;
int ara[MX] ;
int n;
void build()
{
    for(int i = 1; i <=n; i++)
    {
        seg[i][0].F = seg[i][0].S = ara[i];
        
        //for(int x = 0)
    }
    
    for(int i = 1; i < 19; i++)
    {
        for(int j = 1; (j + (1<<i) - 1) <= n; j++)
        {
            seg[j][i].F = min(seg[j + (1<<(i-1))][i-1].F,seg[j][i-1].F);
            seg[j][i].S = gcd(seg[j + (1<<(i-1))][i-1].S,seg[j][i-1].S);
        }
    }
}

PII query(int l,int r)
{
    int mn;
    
    int k = (log(r-l+1)/ log(2.0));
    mn = min(seg[l][k].F,seg[r-(1<<k)+1][k].F);
    
    int gd ;
    
    gd = gcd(seg[l][k].S, seg[r-(1<<k)+1][k].S);
    return {mn,gd};
    
}

bool can(int mid)
{
    for(int i = 1; i + mid-1 <= n;i++)
    {
        PII can = query(i,i+mid-1);
        /*if(mid == 2){
            cout << i << " " << can.F << " " << can.S << endl;

        }*/
        if(can.F == can.S )
        {
            return true;
        }
    }
    return false;
}
int main()
{
  /* #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       //freopen("out.txt","w",stdout);
       
   #endif*/

    FAST;
    
    cin >> n;

    for(int i = 1; i <= n;i++)
        cin >> ara[i];
        
    build();

    int lo = 1, hi = n;
    int ans = 0;
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        if(can(mid)){
            ans = max(ans,mid);
            //cout << lo << " " << hi << endl;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
        
    }
    //cout << ans << endl;
    
    vector < int > ls;
    for(int i = 1; i + ans - 1 <= n;i++)
    {
        PII c = query(i,i+ans-1);
        if(c.F == c.S){
            ls.pb(i);
        }
    }
    cout << ls.size() << " " << ans-1<< endl;

    for(auto x: ls)
        cout << x << " " ;
    cout << endl;


    //for(auto x)
    return 0;
}