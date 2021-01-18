#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;

    vector <int> v(n);
    set < int > s;
    for (auto &x : v) cin >> x;

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++) {
            s.insert(abs(v[j] - v[i]));
        }
    }
    cout << s.size() << '\n';

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}