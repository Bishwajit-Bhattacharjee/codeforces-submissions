//HK HK HK HK HK 108 times
#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define FOR(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a %b == 0)?(a/b):(a/b)+1
#define F first
#define S second
int const MX = 2e5 ;
int const mod = 1000000007 ;

using namespace std;

 long long bigmod(long long p,long long e,long long M){
    long long ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
 ll modinverse(ll a,ll M){return bigmod(a,M-2,M);}

// ************************************************************** GLOBAL VARIABLES *******************************************



 //******************************************************************************************************************************
ll bigmod(ll base, ll pow){
   if(pow == 0) return (1 % mod);
    ll x = bigmod(base, pow/2 );
    x = ( x * x ) % mod;
    if(pow % 2 == 1)
         x = (x * base) % mod;
    return x;
}
struct sphr
{
    ll v , idx ;
    bool operator<(const sphr &rhs)
    {
        if(v == rhs.v) return (idx > rhs.idx) ;
        return v < rhs.v ;
    }
};

ll vol[MX];
sphr pr[MX] ;
ll tree[MX * 4] ;
void update(int pos , int s , int e, int upos, ll val )
{
    if(upos > e or upos < s )
        return ;
    if(s == e and s == upos ) {
        tree[pos] = val ;
        return ;
    }

    int mid = (s + e) / 2 ;
    update(pos * 2 , s, mid , upos , val) ;
    update(pos * 2 + 1 , mid + 1, e, upos , val) ;
    tree[pos] = max(tree[2 * pos ] , tree[2 * pos + 1 ]) ;
}
ll query(int pos, int s, int e , int qs,int qe)
{
    if(qs > qe) return 0 ;
    if(qs > e || qe < s ) return 0 ;
    if(qs <= s && qe >= e) return tree[pos] ;
    int mid = (s + e )/ 2 ;
    ll can1 = query(pos*2 , s , mid , qs, qe) ;
    ll can2 = query(pos*2 + 1, mid + 1 , e , qs, qe) ;
    return max(can1 ,can2) ;

}

int main()
{
    int n ;
    cin >> n ;

    for(int i= 1 ; i <= n ;i++) {
        ll r , h ;
        scanf("%lld %lld",&r,&h);
        vol[i] = r*r*h ;
        pr[i].v = vol[i] ;
        pr[i].idx = i ;
    }

    sort(pr+1, pr + n + 1) ;
    ll ans[MX] ;
    for(int i = 1; i <= n;i++){
        ll tmp = query(1,1, n ,1 , pr[i].idx -1 ) ; // handle when qs > qe
        update(1,1,n , pr[i].idx , tmp + pr[i].v ) ;
        ans[i] = tmp + pr[i].v ;
    }
    ll fans = 0LL;
    for(int i = 1; i <= n; i++)
        fans = max(fans , ans[i]) ;
    printf("%.10f\n", (double)acos(-1.0) * fans) ;

  //  cout << fans << endl;
    return 0 ;
}

