#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <ll,ll> PLL;

ll const MOD = 1e9 + 7;

ll bigmod(ll a,ll b)
{
    if(b == 0) return 1;

    ll x = bigmod(a,b/2);
    x = (x * x) % MOD;
    
    if(b & 1) {
        x = (x * a) % MOD;
    }
    return x;
}
int const N = 2e5 + 100;
int const INF = 1e9;

ll gcd(ll a,ll b)
{
    if(a == 0 or b == 0) return a + b;
    return __gcd(a,b);
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector < ll > v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
    }
    ll mx = *max_element(v.begin(),v.end());

    ll z = 0;
    for(auto x : v){
        z = __gcd(z,mx - x);
    }
    ll y = 0;

    for(int i = 0; i < n; i++){
        y += (mx - v[i])/z;
    }
    cout << y << " " << z << endl;
    return 0;   
}