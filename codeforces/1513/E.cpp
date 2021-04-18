#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()
ll const M = 1e9 + 7;
int const N = 2e5 +10;
ll f[N];

ll bigmod(ll a, ll b){
    if (!b) return 1;
    ll x = bigmod(a, b/2);
    x = (x * x) % M;
    if (b & 1) x = (x * a) % M;
    return x;
}

void pre(){
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = (f[i-1] * i) % M;
}

ll ncr(ll n, ll r){
    if (n < r || r < 0 || n < 0) return 0;

    return (f[n] * bigmod(f[r] * f[n-r] % M, M - 2)) % M;
}

ll calc(map<ll,ll> &m, ll cnt){
    ll ans = f[cnt];
    for (auto [x,y] : m){
        ans = (ans * bigmod(f[y], M - 2)) % M;
    }
    return ans;
}


ll all_perm(vector<ll> &a){
    map<ll,ll>cnt;
    for (auto x : a) cnt[x]++;
    ll ans = f[a.size()];

    for (auto [x, y]: cnt){
        ans = ans * bigmod(f[y], M-2) % M;
    }
    return ans;
}

void solve(){
    pre();

    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (auto &x : a) cin >> x, sum += x;
    if (sum % n != 0) {
        cout << "0\n"; return;
    }

    ll each = sum/n;
    map<ll,ll> source, sink, zero;
    ll src_c = 0, sink_c = 0, z = 0;
    
    for (auto x: a){
        if (x > each) source[x]++, src_c++;
        else if (x < each) sink[x]++, sink_c++;
        else zero[x]++, z++;
    }

    // cout << source.size() << " " << sink.size() << " " << each << endl;

    if (src_c <= 1 || sink_c <= 1){
        cout << all_perm(a) << '\n'; return;
    }

    cout << (2 * calc(source, src_c) * calc(sink, sink_c) % M * ncr(n, src_c + sink_c)) % M << '\n';

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    t = 1;
    while(t--){
        solve();
    }
}
