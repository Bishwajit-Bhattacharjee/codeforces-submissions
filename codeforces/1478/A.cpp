#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    int ans = 0;

    map<int, int> cnt;

    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
        ans = max(ans, cnt[tmp]);
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