#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int calc(vector<int> &h){
    for (int i = 0; i + 1 < h.size(); i++){
        if (h[i] < h[i+1]) {
            h[i]++;
            return i + 1;
        }
    }
    return -1;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (auto &x : h) cin >> x;
    if (1LL * 100 * 100 + 100 < k) {
        cout << "-1\n";
        return;
    }
    while (k > 1) {
        calc(h);
        k--;
    }
    cout << calc(h) << "\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}