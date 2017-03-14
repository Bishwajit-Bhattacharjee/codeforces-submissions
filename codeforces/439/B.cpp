#include <bits/stdc++.h>
#define PII pair < int , int >
#define  PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
ll const inf =  1LL << 59 ;
int  const MX = 5  * 1e5 + 8  ;
int const EPS = 1e-9;
int  const MOD = 1e9 + 7;
using namespace std;

int main()
{
    ll c[MX];
    ll n, x;
    cin >> n >> x;
    for(int i = 0;i < n; i++)
     cin >> c[i];
    sort(c,c + n);
    ll ans = 0;
    for(int i = 0; i  < n ; i++){
        ans += c[i] * x;
        if(x != 1) x--;
    }
    cout << ans ;  
    return 0;
}