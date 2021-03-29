#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

ll dig_sum(ll n){
    ll s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

void solve(){
    ll n;
    cin >> n;
    while (gcd(n, dig_sum(n)) == 1){
        n++;
    }
    cout << n << "\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
