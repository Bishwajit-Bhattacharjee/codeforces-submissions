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
using namespace std;
const int mod = 1e9 + 7 ;
long long bigmod(long long p,long long e,long long M){
    long long ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
 ll modinverse(ll a,ll M){return bigmod(a,M-2,M);}
ll bigmod(ll base, ll pow)
{
    if(pow == 0) return (1 % mod);
    ll x = bigmod(base, pow/2 );
    x = ( x * x ) % mod;
    if(pow % 2 == 1)
         x = (x * base) % mod;
    return x;
}
vector < int > prime;
int dp[71][(1<<19)+1];
ll pmod[100010] ;

int mask1[71] ;
int cnt[71] ;
void Prime()
{
    for(int i = 2 ; i <= 70 ; i++)
    {
        int j ;
        for( j = 2; j < i; j++){
            if(i % j == 0 ) break ;
        }
        if(j == i ) prime.pb(i) ;
    }

    pmod[0] = 1 ;
    for(int i = 1; i <= 100005; i++)
        pmod[i] = (pmod[i-1] * 2LL ) % mod ;

}
int main()
{


   Prime();

//   for(auto I : prime) {
//     cout << I << endl;
//   }
   int n, t ;
   cin >> n ;
   for(int i =0 ; i < n; i++)
        scanf("%d",&t) , cnt[t]++;

    for(int i = 1; i <= 70 ; i++)
    {
        //mask2[i] = 0;

        for(int j = 0 ; j < prime.size(); j++){
            int cnt = 0;
            int tmp = i ;
            while(tmp % prime[j] == 0){
                tmp /= prime[j] ;
                cnt++;
            }
            if(cnt & 1){
                mask1[i] |= (1<< j) ;
            }
//            else if(cnt){
//                mask2[i]  |= (1 << j ) ;
//            }
        }
        //mask2[i] ^= mask1[i] ;
    }
  //  cout << mask1[64] << ' ' << mask2[64] << endl;

    dp[0][0] = 1;
   // cout << mask1[1] << ' '  << mask2[1] << endl;
    for(int i = 1; i <= 70 ; i++){
        for(int j = 0 ; j <= (1<<19); j++){
            if(cnt[i])dp[i&1][j] = ((pmod[cnt[i]-1]) *(dp[(i-1)&1][j^mask1[i]] * 1LL + dp[(i-1)&1][j] ) ) % mod ;
            else
                dp[i&1][j] = dp[(i-1)&1][j] ;
        }
    }
    cout << (dp[70&1][0] - 1 + mod ) % mod  << endl;
    return 0;

}
