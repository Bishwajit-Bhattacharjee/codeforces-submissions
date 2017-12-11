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

int const MX = 2e3+10;
int ara[MX] ;

int main()
{
    int n ;
    cin >> n ;
    int gd = 0;
    int one = 0;
    for(int i =0 ; i < n ; i++){
        scanf("%d",&ara[i]) ;
        gd = gcd(gd , ara[i]) ;
        if(ara[i] == 1) one++;
    }
    if(one) {
        cout << n - one << endl;
        return 0;
    }
    if(gd > 1 ) {
        cout << "-1" << endl;
        return 0;
    }
    int ans = INT_MAX ;
    for(int i = 0 ; i < n ;i++)
    {
        int tmp = ara[i] ;
        for(int j = i+1 ; j < n ; j++){
            tmp = gcd(tmp , ara[j]);
            if(tmp == 1 ){
            ans  = min(ans , j - i  + n - 1 ) ;
           }
        }

    }
    cout << ans << endl;
}