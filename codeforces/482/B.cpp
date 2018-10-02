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


int const MX = 2e5 + 10;

int ara[MX] ;
int bit[MX][31];

int seg[4*MX];

void build(int pos,int l,int r)
{
    if(l == r) 
    {
        seg[pos] = ara[l] ; return ;
    }
    int mid = (l + r ) / 2;
    build(pos*2, l, mid) ;
    build (pos*2 + 1 , mid + 1,r );
    seg[pos] = seg[pos*2] & seg[pos*2 + 1];

}
int query(int pos,int l, int r, int ql,int qr)
{
    if(ql <= l and r <= qr) 
        return seg[pos] ;

    if(l > qr or r < ql){
        return ((1<<30) - 1);
    }
    int mid = (l + r ) / 2;
    int c1 = query(pos*2, l, mid,ql,qr) ;
    int c2 = query(pos*2 + 1, mid+1, r,ql,qr) ;
//    build (pos*2 , mid + 1,r );
    //seg[pos] = seg[pos*2] & seg[pos*2 + 1];

    return c1 & c2;

}
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       //freopen("out.txt","w",stdout);
       
    #endif
    FAST;
    int n, m;
    cin >> n >> m;
    memset(bit,0,sizeof bit);
    memset(ara,0,sizeof ara);

    vector < tuple < int, int,int > > qrs;

    for(int i = 1; i <= m;i++)
    {
        int l,r,q;
        cin >> l >> r >> q;
        qrs.pb(make_tuple(l,r,q));
        for(int x = 0; x < 31; x++)
        {
            if(q & (1 << x)) {
                bit[r+1][x]--;
                bit[l][x]++;
            }
        }
    }

    for(int j = 0; j < 31; j++){
        for(int i = 1; i <= n; i++)
            bit[i][j] += bit[i-1][j];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 31; j++){
            if(bit[i][j]){
                ara[i] ^= (1<< j);
            }
        }
        //cout << ara[i] << endl;

    }
    build(1,1,n);

    for(auto x : qrs){
        int c1 = query(1,1,n,get<0>(x),get<1>(x));
        //cout << c1 << endl;

        if(c1 != get<2>(x)){
            return cout << "NO"<< endl, 0;

        }
    }
    cout << "YES"<< endl;

    for(int i = 1; i <= n; i++)
    {
        cout << ara[i] << " ";
    }
    return 0 ;
}
