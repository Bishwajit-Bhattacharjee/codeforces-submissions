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

ll lcm(ll a, ll b)
{
    ll t, x, y;
    x = a;y = b;
    while(b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return ((x/a)* y);
}

int main()
{
    ll m;
    cin >> m;
    ll ans = (m * (12 + (m-1) * 6)) / 2 ;
    cout <<  ans+ 1 << endl;
    return 0;
}

