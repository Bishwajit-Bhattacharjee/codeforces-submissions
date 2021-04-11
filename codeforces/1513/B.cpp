#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()
ll const M = 1e9 + 7;
int const N = 3e5;

ll f[N];

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> cnt;

    ll a = (1LL << 32) - 1;

    for (int i = 0; i < n; i++){
        ll val;
        cin >> val;
        cnt[val]++;
        a &= val;

    }


    if (cnt[a] < 1) {
        cout << "0\n";
        return ;
    }
    ll ans = 0;
    ll val = cnt[a];
    
    ll cur = 1LL * val * (val - 1);
    cur = (cur % M * f[n-2]) % M;
    ans = (ans + cur) % M;

    cout << ans << '\n';

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = (f[i-1] * i) % M;

    while(t--){
        solve();
    }
}
