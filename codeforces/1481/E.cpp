#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n+1), left(n+1, n+1), right(n+1, 0), suff_cnt(n+1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        left[a[i]] = min(left[a[i]], i);
        right[a[i]] = max(right[a[i]], i);
    }

    vector<int> dp(n+2, 0);

    for (int i = n; i > 0; i--) {
        dp[i] = dp[i+1];
        suff_cnt[a[i]]++;
        if (left[a[i]] != i) {
            dp[i] = max(dp[i], suff_cnt[a[i]]);
        } else {
            dp[i] = max(dp[i], suff_cnt[a[i]] + dp[right[a[i]] + 1]);   
        }
    }
    cout << n - dp[1] << "\n";

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    t = 1;
    while(t--){
        solve();
    }
}