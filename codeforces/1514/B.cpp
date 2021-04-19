#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

ll const M = 1e9 + 7;

void solve(){
    ll n, k;
    cin >> n >> k;

    ll ans = 1;

    for (int i = 1; i <= k; i++){
        ans = (ans * n) % M;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
