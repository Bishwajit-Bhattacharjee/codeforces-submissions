
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

int const MX = 1e5 + 10;
int dis[MX] ;
int goods[MX] ;
int main()
{
   int m , n ;
   cin >> m ;
   for(int i = 0; i < m ;i++)
        scanf("%d", &dis[i]) ;
   cin >> n ;
   for(int i = 0 ; i < n ; i++)
       scanf("%d",&goods[i]) ;
   sort(dis, dis + m) ;
   sort(goods,goods+ n, greater< int> () ) ;
   int ans = 0;
   for(int i = 0 ; i < n; )
   {
       for(int cnt = 1 ; cnt <= dis[0] and i < n ; cnt++){
            ans += goods[i++] ;

       }
       i += 2 ;
   }
   cout  << ans << endl;
   return 0;
}
