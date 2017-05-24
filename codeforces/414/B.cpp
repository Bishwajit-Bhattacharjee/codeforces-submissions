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
int const MX =   2000 + 10;
int const mod = 1e9 + 7;
using namespace std;

vector < int > divi[MX];
void d()
{

    for(int i = 1; i < MX  ;i++){
        for(int j = 1; j * i < MX; j++){
            divi[i * j].pb(i);
        }
    }

}
ll dp[MX][MX];
ll f(int n, int k)
{
    if(n == 1)
        return 1;
    if(k == 1)
        return 1;
    ll &ret  = dp[n][k];
    if(ret != -1)
        return ret;
    ll ans = 0LL;
    for(int i = 0; i< divi[n].size(); i++){
        ans = (f(n  / divi[n][i] , k-1) % mod  + (ans % mod)) % mod;
    }
    return ret = ans;
}


int main()
{
    d();
   memset(dp, -1, sizeof dp);

   int n , k;
   cin >> n >> k;
   //cout << f(n, k );
   ll ans = 0LL;
   for(int i = 1; i<= n; i++)
    ans = (ans % mod + f(i,k) % mod) % mod;
   cout << ans;

    return 0;
}

