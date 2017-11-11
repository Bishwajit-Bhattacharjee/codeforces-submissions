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
int m[4050*4050];
int main()
{
    ll a;
    int csum[5010] ;
    while(cin >> a)
    {
        map < ll , ll > m ;
        string s ;
        cin >> s ;
        //cout << s ;
        int sz = s.size();

        for(int i = 0 ;i < sz ; i++)
        {
            csum[i] = ( (i)?(csum[i-1]): 0) + (s[i]-'0')  ;
        }
        ll sum  = 0LL;
        for(int i = 0; i< sz ;i++)
        {
            for(int j =i; j< sz; j++)
            {
                ll tmp ;
                tmp = csum[j] - ( (i)?csum[i-1]:0 );
                m[tmp]++; sum++;
            }
        }

        ll ans = 0LL;
        //cout << sum << endl;
        if(a==0)
        {
            ans += 2LL * sum * m[0] ;
            ans -= m[0] * m[0] ;
        }
        else
        {
           for(int i = 1; i <= (int)sqrt(a); i++)
           {
               if(a % i ==0 and i == (a/i) ){
                    if(i <= 4000*4000 and a/i <= 4000*4000)
                        ans += 1LL* m[i] * m[a/i] ;
               }
               else if(a % i == 0){
                    if(i <= 4000*4000 and a/i <= 4000*4000)
                        ans += 2LL* m[i] * m[a/i] ;
               }
           }
        }
        cout << ans << endl;
    }
    return 0 ;
}
