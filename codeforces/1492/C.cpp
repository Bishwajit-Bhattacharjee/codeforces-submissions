#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int n, m;
int const N = 30;
vector<int> g[N];

int Find(int ch, int pos) {
    vector<int> &v = g[ch];
    int ret = upper_bound(v.begin() , v.end(), pos) - v.begin();
    if (ret == v.size()) return -1;
    return v[ret];
}

int Find2(int ch, int pos) {
    vector<int> &v = g[ch];
    int ret = lower_bound(v.begin() , v.end(), pos) - v.begin();
    return v[ret - 1];
}

void solve(){
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    for (int i = 0; i < n; i++) g[s[i] - 'a'].push_back(i);

    vector < int > ans;
    int last = -1;
    for (int i = 0; i < m; i++){
        ans.push_back(Find(t[i] - 'a', last));    
        last = ans.back();
        // cout << i << " " << last << endl;
    }
    int mx = 0;
    for (int i = 1; i < m; i++) mx = max(mx, ans[i] - ans[i-1]);

    int cur = n + 1;
    for (int i = m - 1; i > 0; i--) {
        int can_go = Find2(t[i] - 'a', cur);
        ans[i] = can_go;
        mx = max(mx, ans[i] - ans[i-1]);
        cur = ans[i];
    }
    cout << mx << "\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    t = 1;
    while(t--){
        solve();
    }
}