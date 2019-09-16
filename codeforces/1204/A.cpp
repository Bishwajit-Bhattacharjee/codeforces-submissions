#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <ll,ll> PLL;

ll const MOD = 1e9 + 7;
int const N = 5e5 + 100;
const ll BLOCK = 750 ;

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
ll ans[BLOCK+10][BLOCK+10] ;
ll ara[N] ;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int one = 0;
    for(auto ch : s){
        one += (ch == '1');
    }
    int ans = 0;

    for(int i = (int)s.size() - 1; i >= 0; i -= 2){
        if(i == 0){
            ans += (one > 1);
        }
        else 
            ans++;
    }
    cout << ans << endl;
    return 0;
}