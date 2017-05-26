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

#define S second

int const up =   1e6 + 10 ;
int const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const MX =   1000 + 10;
int const mod = 1e9 + 7;
using namespace std;

ll dp[MX][MX];

ll C(ll n, ll r)
{
   if(n < r)
        return  0;
   if(n == r)
     return 1;
     if(r == 0)
     return 1;

   if(n == 1)
     return 1;

   ll &ret = dp[n][r];
   if(ret != -1)
      return ret;
   return ret =(C(n-1, r) + C(n-1, r-1)) % mod ;
}
int main()
{
    memset(dp, -1,sizeof dp);

    int k ;
    cin >> k;
    ll c[MX];
    F(i, 0, k)
    scanf("%I64d", &c[i]);
    ll ans = 1LL;
    ll total = c[0];
    for(int i = 1; i < k; i++){
        ans = ( ans * C(total + c[i] - 1, c[i]-1)) % mod;
        total += c[i];
    }
    cout << ans << endl;

}
