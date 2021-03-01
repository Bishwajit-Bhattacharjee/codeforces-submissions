#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){
    int n;
    cin >> n;

    vector<int> cnt(110, 0), a(n);
    for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;

    int last = 0, ans = 0;
    for (int i = 1; i <= 100; i++){
        if (!cnt[i]) continue;
        if (last) ans += cnt[i];
        last += cnt[i];
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
