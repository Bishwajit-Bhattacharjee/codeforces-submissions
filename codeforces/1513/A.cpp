#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> ans(n+1, -1);
    int r = n, cnt = 0;
    for (int i = 2; i < n; i += 2){
        if (cnt < k){
            ans[i] = r; r--;
            cnt++;
        }
    }
    if (cnt < k) {
        cout << "-1\n"; return;
    }

    for (int i = 1; i <= n; i++){
        if (ans[i] == -1) ans[i] = r--;
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << '\n';

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
