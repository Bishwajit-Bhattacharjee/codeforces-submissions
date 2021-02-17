#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    map <ll,int> cnt;
    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        cnt[tmp]++;
    }
    vector<ll>occurs;
    for (auto [val, key] : cnt) occurs.push_back(key);
    sort(occurs.begin(), occurs.end());

    ll ans = 1e18;
    ll left_sum = 0;
    for (int i = 0; i < occurs.size(); i++) {
        ll can = left_sum + (n - left_sum) - (occurs.size() - i) * occurs[i];
        ans = min(ans, can);
        left_sum += occurs[i];
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