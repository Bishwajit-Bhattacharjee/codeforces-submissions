#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){
    int n, m;
    cin >> n >> m;
    vector<ll> cnt(m+10, 0);

    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp; cnt[tmp%m]++;
    }
    ll ans = 0;
    ans += (cnt[0] > 0);
    for (int i = 1; i < m; i++){
        if (i > m - i) break;
        if (i + i == m) {
            ans += (cnt[i] > 0);
            cnt[i] = 0;
            continue;
        }
        ll mn = min(cnt[i], cnt[(m-i)]);
        if (mn) ans++;
        cnt[i] -= mn;
        cnt[m-i] -= mn;
        if (cnt[i] && mn) cnt[i]--;
        else if(cnt[m-i] && mn) cnt[m-i]--;
    }

    for (int i = 1; i < m; i++) ans += cnt[i];

    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
