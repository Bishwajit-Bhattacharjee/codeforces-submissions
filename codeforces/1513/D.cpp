#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()
ll const INF = 1e17;
int const N = 2e5 + 10;
int par[N];

int Find(int u){
    return par[u] = u == par[u] ? u: Find(par[u]);
}

void Union(int u, int v){
    int U = Find(u);
    int V = Find(v);
    assert(U != V);
    if (rand() % 2) swap(U, V);
    par[U] = V;
}

void solve(){
    ll n, p;
    cin >> n >> p;

    for (int i = 0; i < n; i++) par[i] = i;
    vector<PLL> a(n);
    vector<ll> b(n);

    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        b[i] = a[i].first;
        a[i].second = i;
    }

    sort(all(a));
    ll ans = 0;

    for (auto [x, ind] : a) {
        if (x > p) break;
        ll g = x;
        for (int l = ind - 1; l >= 0; l--){
            if (gcd(g, b[l]) != x or Find(ind) == Find(l)) break;
            ans += x;
            Union(ind, l);
        }
        g = x;
        for (int r = ind + 1; r < n; r++){
            if (gcd(g, b[r]) != x or Find(ind) == Find(r)) break;

            ans += x;
            Union(ind, r);
        }
    }

    for (int i = 0; i + 1 < n; i++){
        if (Find(i) != Find(i+1)){
            ans += p;
            Union(i, i+1);
        } 
    }

    cout << ans << '\n';

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    srand(time(0));
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
