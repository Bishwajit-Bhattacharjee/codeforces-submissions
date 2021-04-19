#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()


ll isS(ll n){
    for (ll i = 1; i * i <= n; i++){
        if (i * i == n) return 1;
    }
    return 0;
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    bool y = 0;
    for (auto &x: v){
        cin >> x;
        if (!isS(x)) y = 1;
    }
    cout << ((y)?"YES":"NO") << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
