#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

bool check_cube(ll num){
    if (num == 0) return false;
    ll cube_root = pow(num, 1.0/3);

    for (ll x = cube_root - 2; x <= cube_root + 2; x++) {
        if (x * x * x == num) return true;
 
    }
    return false;
}

void solve(){
    ll x;
    cin >> x;
    for (ll i = 1; i * i * i <= x; i++){
        if (check_cube(x - i * i * i)) {
            cout << "YES\n"; return;
        }
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}