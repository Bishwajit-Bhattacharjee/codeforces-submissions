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

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    
    vector < PLL > v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i].first, v[i].second = i+1;
    
    sort(v.begin(), v.end(), greater<PLL>());

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += (v[i].first * i + 1) ;
    }
    cout << ans << endl;

    for(auto x : v){
        cout << x.second << " " ;
    }

    return 0;   
}