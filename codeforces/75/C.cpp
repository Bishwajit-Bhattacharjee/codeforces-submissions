// HK  HK HK HK HK HK   JSN  JRR

#include <bits/stdc++.h>
#define PII pair < int , int >
#define PIB pair < int , bool >
#define PI 2.0*acos(0.0)
#define ll long long int
#define F(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a %b == 0)?(a/b):(a/b)+1
#define f first
#define S second

int const up =   1e6 + 10 ;
int const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const MX =   5 * 1e5 + 10;
int const mod = 10000007;
using namespace std;

vi divi;
void fact(ll a , ll b)
{
    ll n =  __gcd(a, b);
    for(ll x = 1; x * x <= n ; x++){
        if(n % x == 0){
            divi.pb(x);
            divi.pb(n/x);
        }

    }
   sort(divi.begin() , divi.end()) ;
}

ll bs(ll l, ll h)
{
    ll lo = 0 , hi = divi.size()-1;
    ll mid;
    ll ans = -1;
    while(abs(hi-lo) > 5){
        mid = (lo + hi)/ 2;
        ll t = divi[mid];
        if( t >= l && t <= h){
            ans = t;
            lo = mid ;
        }
        else if(t < l){
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    for(ll x = min(lo , hi) ; x <= max(lo , hi); x++){
         ll t = divi[x];
        if( t >= l && t <= h){
            ans = t;
           // lo = mid ;
        }
    }
    return ans ;
}
int main()
{
    ll a, b ;
    cin >> a >> b;
    fact(a, b);
    ll n, l, h;
    cin >> n;
    F(i, 0, n)
    {
        scanf("%I64d %I64d", &l, &h);
        printf("%I64d\n", bs(l , h));
    }
    return 0;
}
