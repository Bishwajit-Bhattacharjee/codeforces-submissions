#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int n, k;

bool can(vector<int> &v, int x) {
    bool pos = 0;
    int pref_sum = 0;
    vector<int> pref_min(n + 2, 0);

    for (int i = 1; i <= n; i++) {
        pref_sum += (v[i] >= x)? 1 : -1;
        pref_min[i] = min(pref_min[i-1], pref_sum);
        if (i < k) continue;
        if (pref_sum - pref_min[i - k] > 0) return true;
    }
    // for (int i = 0; i < n; i++){
    //     pref_sum += (v[i] >= x)? 1 : -1;
    //     pref_min[i] = min(pref_min[i], pref_sum);
    //     if (i) pref_min[i] = min(pref_min[i], pref_min[i-1]);
    //     if (i + 1 < k) continue;
    //     if (pref_sum - (i-k >= 0? pref_min[i-k] : 0) > 0) return true;
    // }
    return false;
}
void solve(){
    cin >> n >> k;

    vector<int> v(n + 1);

    for (int i = 1 ; i <= n; i++) cin >> v[i];

    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = (lo + hi + 1)/2;
        if (can(v, mid)) lo = mid;
        else hi = mid - 1;
    } 
    cout << lo << "\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    t = 1;
    while(t--){
        solve();
    }
}