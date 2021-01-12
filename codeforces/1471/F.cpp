#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const N = 3e5 + 10;
vector<int> g[N];

int comp(int u, vector <int> &col) {
    int sz = 1;
    col[u] = 1;
    for (auto v : g[u]){
        if (col[v] == -1) sz += comp(v, col);
    }
    return sz;
}

void coloring(int u, vector <int> &col) {
    col[u] = 1;

    for (auto v : g[u]) {
        assert(col[v] == -1 or col[v] == 2);
        col[v] = 2;
    }
    for (auto v : g[u]) {
        for (auto w : g[v]) {
            if (col[w] == -1) coloring(w, col);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) g[i].clear();

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector < int > col(n + 1, -1);

    if (comp(1, col) != n) {
        cout << "NO\n"; return;
    }
    fill(col.begin(), col.begin() + n + 1, -1);

    // for (int i = 1; i <= n; i++) {
    //     if (col[i] == -1) {
    //         col[i] = 1;
    //         for (auto v : g[i]) {
    //             assert(col[v] == -1 or col[v] == 2);
    //             col[v] = 2;
    //         }
    //     }
    // }

    coloring(1, col);
    cout << "YES\n";
    cout << count(col.begin() + 1, col.end(), 1) << "\n";

    for (int i = 1; i <= n; i++){
        if (col[i] == 1)  cout << i << " "; 
    }
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