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
/*const int MX = 2e5 + 10;
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
}*/


int const MX = 1e6 + 10;
int seg[4*MX] ;
int v[MX] ;

void build(int node,int l , int r )
{
    if(l == r ) {
        seg[node] = v[l] ;
        return ;

    }

    int mid = (l + r) / 2 ;

    build(node * 2, l, mid);
    build(node*2 + 1, mid + 1, r) ;
    seg[node] = seg[node*2] xor seg[node*2 + 1] ;

}

void update(int node, int l, int r, int id, int val)
{
    if(l > id or r < id ) 
        return ;
    if(l == id and id == r) 
    {
        seg[node] = val;
        return ;
    }
    int mid = (l + r) / 2 ;

    update(node * 2, l, mid, id, val);
    update(node*2 + 1, mid + 1, r, id, val) ;

    seg[node] = seg[node*2] xor seg[node*2 + 1] ;
}

int query(int node,int l, int r,int ql, int qr) 
{
    if(l > qr or r < ql ) 
        return 0;

    if(ql <= l and r <= qr) 
        return seg[node];

    //int ret = 0;
    int mid = (l + r ) / 2;

    return query(node*2,l,mid,ql,qr) xor query(node*2 + 1, mid+1,r,ql,qr) ;

}
int main()
{
   #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
//       freopen("out.txt","w",stdout);
   #endif

    FAST;
    
    int n;
    cin >> n;
    vector < int > pref(n+1,0);
    
    memset(seg,0,sizeof seg) ;

    for(int i = 1; i <= n; i++)
        cin >> v[i], pref[i] = pref[i-1] xor v[i];
    build(1,1,n);

    int m;
    cin >> m;

    vector < pair <PII, int > > qr(m+1);

    for(int i = 1; i <= m ;i ++)
    {
        int l,r;
        cin >> l >> r;
        qr[i] = {{r,l},i};

    }

    sort(qr.begin()+1,qr.end());
    //vector < int > lastSeen(n+1,-1);
    map < int, int > lastSeen;
    int id = 1;
    vector < int > ans(m+1);

    for(int rr = 1; rr <= n; rr++)
    {
        if(lastSeen.count(v[rr])){
            update(1,1,n,lastSeen[v[rr]],0);
        }
        update(1,1,n,rr,v[rr]);
        lastSeen[v[rr]] = rr;

        while(id <= m and qr[id].F.F == rr ){
            int L = qr[id].F.S;
            int R = qr[id].F.F;

            ans[qr[id].S] = ( query(1,1,n,L,R) xor pref[R] ) xor pref[L-1] ;
            id++;
        }
    }

    for(int i = 1; i <= m; i++)
        cout << ans[i] << endl;

    return 0 ;
}
