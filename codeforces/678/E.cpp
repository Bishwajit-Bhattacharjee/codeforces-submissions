//HK HK HK HK HK 108 times
#include <bits/stdc++.h>
#define PII pair < int , int >
#define PLL pair < ll, ll >
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
int const N =  1e6 + 12;
bool mark[N] ;
vector < ll > primes;
void sieve()
{
    for(int i = 2; i < N ; i++)
    {
        if(!mark[i])
        {
            for(int j = 2 * i ; j < N ; j += i )
                mark[j] = 1; //pf[j].pb(i);
        }
    }
    for(int i = 2; i < N ; i++)
        if(!mark[i])
            primes.pb(i);
}
int const MX = 18;

//bool vis[18][(1<<18) + 5];
double dp[18][(1<<18) + 5] ;
double p[20][20];
int n;
double DP(int pos, ll mask)
{
//    if(mask & (1<<0))
//        return 0;

    if( (mask | (1LL<<pos)) == ((1LL<<n) - 1))
        return (pos == 0);

    if(dp[pos][mask] > -0.5)
        return dp[pos][mask] ;

    dp[pos][mask] = 0;

    //vis[pos][mask] = 1;

    for(int i = 0; i < n; i++)
    {
        if( i != pos and !(mask & (1LL<< i)))
        {
            dp[pos][mask] = max(dp[pos][mask],  p[pos][i] * DP(pos,mask | (1LL<<i)) + p[i][pos] * DP(i,mask |(1<<pos)) )  ;
        }
    }
    return dp[pos][mask] ;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> p[i][j] ;

    double ans = 0;
    //fill(dp,dp + 18 *(1<<18 + 5) , -1);
    memset(dp,-1,sizeof dp);
    for(int i = 0; i < n; i++)
    {
        ans = max(ans, DP(i,0));
    }
    cout << fixed << setprecision(9) << ans << endl;
    return 0;
}
