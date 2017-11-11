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
vector<ll>vec;

void lucky(int id , ll carry)
{
    if(id < 0 ) return ;
    if(carry)vec.pb(carry);
    lucky(id-1,carry*10 + 4) ;
    lucky(id-1, carry*10 + 7) ;
}
int main()
{
    ll r, l;
    lucky(10, 0);
    sort(all(vec)) ;
    while(cin >> l >> r)
    {
        ll ans =0LL ;
        ll last = 0LL;
        ll cnt = 0LL;
        int i;
        for( i = 0 ; i < vec.size() && vec[i] <= r;i++)
        {
            ans += (vec[i]-last) *(vec[i]);
            last = vec[i];
        }
        ans += (r-last)*vec[i] ;

        last = 0;
        for( i = 0 ; i < vec.size() && vec[i]< l;i++)
        {
            ans -= (vec[i] - last) *(vec[i]);
            last = vec[i] ;
        }
        ans -= (l-1-last) *vec[i];
        cout << ans << endl;
    }
    return 0 ;
}
