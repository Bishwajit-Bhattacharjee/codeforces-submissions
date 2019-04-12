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

int const N = 50;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector < int > primes;
bool mark[N] ;

void sieve()
{
    for(ll i = 2; i < N ; i++)
    {
        if(!mark[i])
        {
            for(int j = i * 2; j < N; j += i )
                 mark[j] = 1;
        }
    }
    for(int i = 2; i < N ; i++)
        if(!mark[i])
            primes.pb(i);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    sieve();
    vector < int > divi;
    //cout << primes.size() << endl;
    for(auto x : primes)
    {
        cout << x << endl;
        string ret;
        cin >> ret;

        if(ret == "yes"){
            divi.pb(x);
        }

    }
    if(divi.size() >= 2){
        cout << "composite" << endl;
    }
    else if(divi.size() == 1 and divi.back() * divi.back() <= 100){
        cout << divi.back() * divi.back() << endl;
        string inp;
        cin >> inp;
        if(inp == "yes"){
            cout << "composite" << endl;
        }
        else {
            cout << "prime" << endl ;
        }
    }
    else
        cout << "prime" << endl;
    return 0;
}
