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

int const up =   1e6 + 10 ;
int const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const MX =   5 * 1e5 + 10;
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


ll bigmod(ll base, ll pow)
{
    if(pow == 0) return (1 % mod);
    ll x = bigmod(base, pow/2 );
    x = ( x * x ) % mod;
    if(pow % 2 == 1)
         x = (x * base) % mod;
    return x;
}
bool isprime(ll n)
{
    for(ll i = 2 ;  i * i <= n ; i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
}
   ll n, m , k;

ll can(ll mid)
{
    ll ret = 0LL;
    for(int i = 1; i <= n ; i++){
        ret += min(m , ((mid -1)/ i)) ;
    }
    return ret;
}

int main()
{
   cin >> n >> m >> k ;
   ll lo = 1, hi = n * m ;
   ll ans = 1;
   while(lo < hi){
    ll mid = (lo + hi + 1) / 2;
    ll tmp = can(mid);
    if(tmp >= k)
        hi = mid -1 ;
    else
    {
        ans = mid;
        lo = mid;
    }
   }
   //if(isprime(ans) && ans > n && ans > m) ans++;
   cout << ans << endl;
return 0;

}
