#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PII = pair<int,int>;
int const N = 2e5;

vector <int> diff[N], same[N];

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        same[i].clear(), diff[i].clear();
    }
    vector<int> a(n+1), b(n+1);
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++){
        if (a[i] == b[i]) same[b[i]].emplace_back(i);
        else diff[b[i]].emplace_back(i);
    }
    vector <int> paint(m), ans(m);
    for (auto &x : paint) cin >> x;
    vector <int> done;

    for (int i = m - 1; i >= 0; i--){
        if (diff[paint[i]].size()) {
            ans[i] = diff[paint[i]].back();
            diff[paint[i]].pop_back();
            done.push_back(ans[i]);
        } 
        else if (same[paint[i]].size()) {
            ans[i] = same[paint[i]].back();
            same[paint[i]].pop_back();
            done.push_back(ans[i]);
        }
        else if(done.size()){
            ans[i] = done.back();
        } 
        else {
            cout << "NO\n"; return;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (diff[i].size()) {
            cout << "NO\n"; 
            return;
        }
    }
    cout << "YES\n"; 
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