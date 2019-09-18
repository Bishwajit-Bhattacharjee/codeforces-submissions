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
int const N = 110;
ll adj[N][N], way[N][N] ;
string edge[N];
int const INF = 1e9;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    ll a1,a2,k1,k2,n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;

    if(k1 > k2) {
        swap(a1,a2);
        swap(k1,k2);
    }
    ll mn ;
    ll mx = min(n/k1,a1) + min((n - min(n/k1,a1)* k1)/k2,a2) ;
    n = n - (k1-1)*a1 - (k2-1)*a2;
    n = max(n,0LL);
    if(n > 0) {
        mn = min(n,a1+a2);
    }
    else {
        mn = 0;
    }
    cout << mn << "  " << mx << endl;
    return 0;
}       