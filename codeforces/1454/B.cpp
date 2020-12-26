#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    map < int, vector < int > > cnt;
    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        cnt[tmp].push_back(i+1);
    }

    for (auto &[val, vec] : cnt){
        if (vec.size() == 1) {
            cout << vec.back() << '\n'; return;
        }
    }
    cout << "-1\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}