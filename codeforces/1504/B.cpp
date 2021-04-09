#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    vector<bool> need_toggle(n, 0), can_toggle(n, 0);
    int cnt[] = {0, 0};
    for (int i = 0; i < n; i++){
        cnt[a[i]-'0']++;
        if (a[i] != b[i]) need_toggle[i] = 1;
        if (cnt[0] == cnt[1]) can_toggle[i] = 1;
    }
    bool flip = 0;
    for (int i = n - 1; i >= 0; i--){
        a[i] = '0' + (a[i] - '0') ^ flip;

        if (a[i] == b[i]) continue;
        else if (can_toggle[i]){
            flip ^= 1;
        }
        else {
            cout << "NO\n"; return;
        }
    }

    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
