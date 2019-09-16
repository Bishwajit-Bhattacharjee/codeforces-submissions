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
    int q;
    cin >> q;
    
    while(q--){
        int t,x,y;
        cin >> t >> x >> y;
        if(t == 1){
            ara[x] += y;
            for(int i = 1; i < BLOCK; i++){
                    ans[i][x%i] += y;
            }
        }
        else {
            if(x >= BLOCK) {
                ll cur = 0;
                for(int xx = 0; xx + y < N ; xx += x){
                    cur += ara[xx+y]; 
                }
                cout << cur << '\n';
            }
            else {
                cout << ans[x][y] << '\n';
            }
        }
    }
    return 0;
}