#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){

    ll n;
    cin >> n;
    if (n % 2050 != 0) {
        cout << "-1\n"; return;
    }

    n /= 2050;
    ll ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
