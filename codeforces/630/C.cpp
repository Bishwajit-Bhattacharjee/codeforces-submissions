#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const up =   1e6 + 10 ;
int  const up1 = 5 * 1e4 + 10  ;
int const eps = 1e-9;
int const mod = 10000007;
using namespace std;

ll power(ll n)
{
    ll ans= 1;
    for(ll i = 1; i <=n ;i++)
        ans *= 2;
    return ans;
}

int main()
{
    ll m;
    cin >> m;
    cout << 2 * (power(m) - 1) << endl;
    return 0;
}

