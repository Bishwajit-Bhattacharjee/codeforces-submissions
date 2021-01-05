#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    vector < int > v(n);
    int sum = 0;
    int cnt[3] = {0, 0, 0};
    for (auto &x : v) cin >> x, cnt[x]++, sum += x;

    if (sum & 1) {
        cout << "NO\n"; return;
    }
    
    for (int i = 0; i <= min(sum / 2, cnt[1]) ; i++){
        int two = sum / 2 - i;
        if ((two & 1) or (two/2) > cnt[2]) continue;
        
        int o_one = cnt[1] - i;
        int o_two = cnt[2] - two/2;

        if (o_one + 2 * o_two == sum/2 ) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}