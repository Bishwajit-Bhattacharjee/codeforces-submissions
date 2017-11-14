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
int dx[]= {0,0,-1, -1, -1,1, 1, 1} ;
int dy[] = {-1, 1, 1,0 , -1, 1, 0 ,-1} ;

int const MX = 1<<18 ;
ll ara[MX] ;
ll seg[MX * 4] ;

void build(int pos , int ss, int se ,int lvl )
{
    if(ss == se )
    {
        seg[pos] = ara[ss] ;
        return ;
    }
    int mid = (ss + se) / 2 ;
    build(pos* 2, ss, mid , lvl + 1) ;
    build(pos * 2 + 1 , mid + 1, se , lvl + 1 ) ;
    (lvl&1)?(seg[pos] = seg[pos* 2] | seg[pos*2 + 1]) : (seg[pos]  = seg[pos * 2 ] ^ seg[pos* 2 + 1 ] );

}

void update(int pos , int ss, int se , int us , int ue , int lvl , int val)
{
    if(us > se or ue < ss  ) return ;
    if(us <= ss and ue >= se ) {
        seg[pos] = val ;
        return ;
    }
    int mid = (ss + se) / 2 ;
    update(pos* 2, ss, mid , us , ue, lvl + 1, val ) ;
    update(pos * 2 + 1 , mid + 1, se , us , ue, lvl + 1, val ) ;
    (lvl&1)?(seg[pos] = seg[pos* 2] | seg[pos*2 + 1]) : (seg[pos]  = seg[pos * 2 ] ^ seg[pos* 2 + 1 ] );

}

//ll query(int pos , int ss ,int se , int qs, int qe )
//{
//    if(qs > se or qe < ss) return 0LL;
//    if(qs <= ss and qe >= se )
//        return seg[pos] ;
//    int mid = (ss + se) / 2;
//    return query(2*pos , ss, mid, qs, qe) + query(2*pos + 1, mid + 1, se , qs , qe) ;
//
//}
int main()
{
   int n  , m ;
   cin >> n >> m ;
   for(int i = 1 ; i <= (1<< n ) ; i++)
   {
       scanf("%lld",&ara[i]) ;
   }
   build(1 ,1 , (1<< n), n % 2 );
   for(int i = 1; i <= m ; i++)
   {
       int p , v;
       scanf("%d %d", &p , &v ) ;
       update(1, 1, 1<< n, p, p, n % 2, v) ;
       printf("%lld\n", seg[1]) ;
   }

   return 0 ;
}
