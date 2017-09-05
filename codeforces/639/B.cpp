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
int const MX = (1e5 + 10);

vector < PII > v ;

int main(){
    int n, d , h ;
    cin >> n >> d >> h ;
    if(n == 2){
        cout << "1 2 " << endl;
        return 0;
    }
    if(d == 1 or d > 2 * h ){
        puts("-1");
        return 0;
    }
    int id = 1, sec  ;
    if(h == 1){
        for(int i = 2; i <= n; i++){
            printf("1 %d\n",i );
        }
        return 0;
    }

    (h >= (d - h))? sec = 2 :sec = h + 2 ;

    for(int i = 1 ; i <= h; i++ ){
        v.pb({1 + i - 1 , 1 + i }); id++;
    }
    for(int i = 1; i <= d - h; i++){
        v.pb({(i == 1)? 1 : h + i  , h + 1 + i  }) ; id++ ;
    }
    id++ ;
    for( ; id <= n; id++){
        v.pb({sec, id});
    }
    for(auto i: v){
        printf("%d %d\n",i.F , i.S );
    }

    return 0;
}




