#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){   
    int n;
    cin >> n;

    vector<ll> v(n);
    for (auto &x : v) cin >> x;

    multiset<ll> ms[2];
    vector<ll> sum(2, 0);
    ll ans = 1e17;

    for (int i = 0; i < n; i++){
        ms[i&1].insert(v[i]);
        sum[i&1] += v[i];
        if (i < 1) continue;
        ll can = 0;
        can += sum[0] + 1LL*(n - ms[0].size()) * (*ms[0].begin());
        can += sum[1] + 1LL*(n - ms[1].size()) * (*ms[1].begin());

        ans = min(ans, can);
    }
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
