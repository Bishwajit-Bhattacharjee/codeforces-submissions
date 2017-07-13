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

int main()
{
    int n;
    int a[110];
    cin >> n;
    for(int i =0 ; i < n; i++){
        scanf("%d", &a[i]);
    }
    int mx = *max_element(a, a + n);

    int if1 , if2;
    for(int i =0 ; i < n; i++){
        if(a[i] == mx)
            {
                if1 = i; break;
            }
    }
    for(int i = 0 ;  i < n; i++){
        if(a[i] == mx) {
            if2 = i;
        }
    }
    int t = a[if1];
    for(int i = if1 ; i <= if2 ; i++){
              if(a[i] != t){
                puts("no");
                return 0;
              }
    }
    for(int i = 0; i < if1; i++){
        if(a[i] >= a[i+1])
        {
            puts("no");
            return 0;
        }

    }
    for(int i = if2 ; i < n - 1; i++){
        if(a[i] <=  a[i+1]){
                puts("no");
            return 0;
        }
    }
    puts("yes");

return 0;

}




