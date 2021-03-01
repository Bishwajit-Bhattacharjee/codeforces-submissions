#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){
    ll n, u, v;
    cin >> n >> u >> v;
    vector <int> a(n+1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 2; i <= n; i++){
        if (abs(a[i] - a[i-1]) > 1){
            cout << "0\n"; return;
        }
    }
    bool all_zero = true;
    for (int i = 2; i <= n; i++){
        if (a[i] != a[i-1]) all_zero = false;
    }

    cout << min(u, v) + all_zero * v << "\n";
    
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
