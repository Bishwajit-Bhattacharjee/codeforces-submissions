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

//*****************************************
int main()
{
    int n ;
    cin >> n;
    map < PII , int > m;
    int a[2010], b[2010];
    for(int i =0 ;i < n; i++){
        scanf("%d %d", &a[i], &b[i]);
        
    }
    
    for(int i =0 ; i < n; i++){
        for(int j = i+ 1 ; j < n; j++){
            m[{a[i] + a[j] , b[i] + b[j]}]++;
        }
    }
    
    ll ans = 0LL;
    for(const auto& i : m){
      //  cout << "pair" << i.F.F << ' ' << i.F.S << "pair"  << ' ' << i.S << endl;
      //  cout << i.S << endl;
        ll tmp = (ll)i.S ;
        
        ans += (tmp > 1)? (tmp * (tmp -1) / 2) : 0; 
        
    }
   cout << ans << endl;
    return 0;
}