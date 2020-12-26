#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const N = 3e5;
vector < int > g[N];

int calc (int p, int n) {
    int st = 0, cnt = 0;
    g[p].push_back(n + 1);

    for (auto x : g[p]) {
        if (x - st > 1) cnt++;
        st = x;
    }
    return cnt;
}

void solve(){
    int n;
    cin >> n;
    set < int > s;

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        g[tmp].push_back(i+1);
        s.insert(tmp);
    }
    int ans = n;
    for (auto x : s) {
        ans = min(ans, calc(x, n));
    }

    cout << ans << '\n';

    for (auto x : s) g[x].clear();
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}