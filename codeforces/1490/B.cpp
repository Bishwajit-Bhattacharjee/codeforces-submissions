#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    vector<int> cnt(3, 0);
    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        cnt[val % 3]++;
    }
    int ans = 0;
    while (true) {
        for (int i = 0; i < 3; i++) {
            if (cnt[i] > n / 3) {
                cnt[(i + 1) %3] += (cnt[i] - n/3);
                ans += cnt[i] - n/3;
                cnt[i] = n/3;
            }
        }
        bool done = true;
        for (int i = 0; i < 3; i++) {
            if (cnt[i] != n/3) done = false;
        }
        if (done) break;
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