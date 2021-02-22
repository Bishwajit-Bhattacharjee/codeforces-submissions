#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll n;
    cin >> n;
    vector <ll> v(n);
    ll extra = 0;

    for (auto &x : v) 
        cin >> x;
    extra += v[0];
    v[0] = 0;

    for (int i = 1; i < n; i++){
        if (extra + v[i] <= v[i-1]) {
            cout << "NO\n"; return;
        }
        extra = extra + v[i] - i ;
        v[i] = i;
    }
    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}