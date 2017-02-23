
#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const up =   1e6 + 10 ;
int  const array_size = 5 * 1e5 + 10  ;
int const eps = 1e-9;
ll const MOD = 1e9 + 7;
using namespace std;

//global variables

ll bigmod(ll a, ll b)
{
    if(b == 0) return (1 % MOD);
    ll x = bigmod(a, b/2);
    x = ( x * x) % MOD;
    if(b % 2 == 1)
     x = (x * a) % MOD;
    return x;

}


int main()
{
    ll a , b;
    cin >> a >> b;
    ll nom = ( (a % MOD) * (b % MOD)) % MOD;
    nom = (nom * (b-1)) % MOD;
    ll nom2 = (2 + ((b % MOD) * (a+1) % MOD) % MOD) % MOD;
    ll nom3 = (nom * nom2) % MOD;
    ll denom = bigmod(4, MOD - 2);
    cout << (nom3 * denom) % MOD << endl;
    return 0;
}
