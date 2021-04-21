#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){
    ll n, k;
    cin >> n >> k;
    vector <int> v(n);

    for (auto &x: v) cin >> x;

    for (int i = 0; i + 1 < n; i++){
        while (v[i] > 0 && k){
            v[i]--;
            k--;
            v[n-1]++;
        }
    }

    for (auto x : v) cout << x << " ";
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
