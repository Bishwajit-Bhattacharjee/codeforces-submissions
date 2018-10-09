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

int const MX = 1e5 + 10;

int seg[MX*4][21];
int ara[MX];
int lazy[MX*4][21];

void build(int pos,int l,int r)
{
    if(l == r)
    {
        int tmp = ara[l];
        for(int i = 0; i < 21;i++){
            seg[pos][i] = (tmp &(1LL << i)) > 0  ;
        }
        return ;
    }
    int mid = (l+r)/2;
    build(pos*2,l,mid);
    build(2*pos+1,mid+1,r);

    for(int i = 0; i < 21;i++)
    {
        seg[pos][i] = seg[2*pos][i] + seg[2*pos+1][i] ;
    }
}

void push(int pos,int bit,int l,int r)
{
    if(lazy[pos][bit] & 1){
        seg[pos][bit] = (r-l+1) - seg[pos][bit];
    }
    if(l != r){
        lazy[2*pos][bit] += lazy[pos][bit] ;
        lazy[2*pos+1][bit] += lazy[pos][bit] ;
    }
    lazy[pos][bit] = 0;
}
void update(int pos,int bit,int l,int r,int ul,int ur)
{
    if(lazy[pos][bit] != 0)
    {
        push(pos,bit,l,r);
    }
    if(ul <= l and r <= ur)
    {
        seg[pos][bit] = (r-l+1) - seg[pos][bit];
        if(l != r){
            lazy[2*pos][bit] ++;// lazy[pos][bit] ;
            lazy[2*pos+1][bit] ++;//lazy[pos][bit] ;
        }
        return;
    }
    if(l > ur or r < ul)
        return;
    int mid = (l+r) /2;

    update(2*pos,bit,l,mid,ul,ur);
    update(2*pos + 1,bit,mid+1,r,ul,ur);
    seg[pos][bit] = seg[2*pos][bit] + seg[2*pos+1][bit];
}
ll query(int pos,int bit,int l,int r,int ql,int qr)
{
    if(lazy[pos][bit] != 0)
    {
        push(pos,bit,l,r);
    }
    if(ql <= l and r <= qr)
        return seg[pos][bit];
    if(l > qr or r < ql)
        return 0;
    int mid = (l + r) / 2;
    return query( 2*pos,bit,l,mid,ql,qr)
        + query(2*pos+1,bit,mid+1,r,ql,qr) ;
}

int main()
{
    #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       //freopen("out.txt","w",stdout);
       
    #endif
    FAST;
    int n;
    cin >> n;

    for(int i = 1; i <= n;i++)
        cin >> ara[i] ;

    build(1,1,n);
    int m;
    cin >> m;
    while(m--)
    {
        int type,l,r;
        cin >> type >> l >> r;
        if(type == 1)
        {
            ll ans = 0;
            for(int i = 0; i < 21; i++){
                ans += (query(1,i,1,n,l,r) * (1LL << i));
            }
            cout << ans << endl;
        }
        else {
            int x;
            cin >> x;
            for(int i = 0; i < 21; i++){
                if(x & (1LL << i)){
                    update(1,i,1,n,l,r); 
                }
            }
            //update(1,1,n,l,r,x);
        }
    }
    return 0;
}
