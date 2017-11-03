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
int const MX = 2e6+ 10 ;
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

bool vis[MX] ;
ll p , k ;
ll cnt ;
void dfs(int cur)
{
    ll tmp = 1LL;
    do{
       vis[(tmp*cur)% p] =1 ;
       tmp = (tmp * k ) % p ;

    }while(tmp != 1);

    //cnt++;
}
int main()
{
    while(cin >> p >> k) {


    ll ans ;
    memset(vis ,0 , sizeof vis);
    if(k == 0 ) ans = bigmod(p,p-1);
    else if(k == 1 ) ans = bigmod(p, p ) ;
    else {
         cnt = 0;
        for(ll i = 1; i < p ; i++){
            if(!vis[i]){
                dfs(i);cnt++;
            }
        }
        ans = bigmod(p,cnt);
    }
    cout << ans << endl ;
    }
    return 0 ;
}
