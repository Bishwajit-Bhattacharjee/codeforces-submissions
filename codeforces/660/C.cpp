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
int const mx = 3 *  1e5 + 10;
int sum[mx ] ;
int n, k ;
typedef struct {
    bool f;
    int idx;
}ret;



ret can(int len)
{

    for(int i = 1 ; i + len - 1 <= n ; i++){
        if((len - (sum[i + len - 1] - sum[i - 1]) ) <= k ){
           // printf("can : %d %d\n",sum[i + len - 1] - sum[i - 1] , k );
            return (ret){true, i } ;
        }
    }
    return (ret){false , -1} ;
}

int main()
{
    cin >> n >> k;
    
    int a[mx] ;
    
    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
        sum[i] = sum[ i - 1 ] + (a[i] == 1 ) ;
    }
    //cout << sum[7] - sum[3] << endl;
    int lo = 0 , hi = n ;
    ret tmp ;
    int strt ;
    while(lo < hi ){
        int mid  = ( lo + hi + 1) / 2;
        tmp = can(mid );
        
        if(tmp.f){
            lo = mid ;
            strt = tmp.idx ;
        }
        else {
            hi  = mid - 1; 
        }
    }
    cout << lo << endl;
   // cout << strt << endl;
    for(int i = 1; i <= n ; i++ ){
        if(i >= strt && i <= strt + lo - 1){
            printf("1 ");
            
        }
        else {
            printf("%d ", a[i]);
        }
    }
    
    return 0;
}


