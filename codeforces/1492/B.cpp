#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    vector<int> p(n+1), rp(n+1);

    for (int i = 1; i <= n; i++) cin >> p[i], rp[p[i]] = i;

    vector <int> ans;

    int now = n;
    int cut_ind = n + 1;
    while (now >= 1) {
        while (now >= 1 and rp[now] >= cut_ind) now--;
        if (now < 1) break;

        int cur_ind = rp[now];
        for (int i = cur_ind; i < cut_ind; i++) ans.push_back(p[i]);
        cut_ind = cur_ind;
    }
    assert(ans.size() == n) ;
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}