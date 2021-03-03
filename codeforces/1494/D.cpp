#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()
int const N = 1000;
int a[N][N];
int par[N], sal[N];
int cur;

int find_root(vector<int> &leaves) {
    if (leaves.size() == 1) {
        sal[leaves.back()] = a[leaves.back()][leaves.back()];
        return leaves.back();
    }
    int root = (++cur);

    int mx = 0;

    for (int i = 0; i < leaves.size(); i++){
        for (int j = i + 1; j < leaves.size(); j++){
            mx = max(mx, a[leaves[i]][leaves[j]]);
        }
    }

    sal[root] = mx;

    vector <vector<int>> groups;
    for (auto leave : leaves){
        bool done = false;
        for (auto &v : groups){
            if (a[v.back()][leave] < mx){
                v.push_back(leave);
                done = true;
                break;
            }
        }
        if (!done){
            groups.push_back(vector<int>{leave});
        }
    }

    for (auto &x : groups) {
        int leaf = find_root(x);
        par[leaf] = root;
    }

    return root;
}

void solve(){
    int n;
    cin >> n;

    memset(par, -1, sizeof par);
   
    cur = n;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) 
            cin >> a[i][j];
    }
    vector <int> leaves;
    for (int i = 1; i <= n; i++) leaves.push_back(i);

    int root = find_root(leaves);

    cout << cur << "\n";
    for (int i = 1; i <= cur; i++) cout << sal[i] << " ";
    cout << "\n";
    cout << root << "\n";
    for (int i = 1; i <= cur; i++){
        if (i == root) continue;
        cout << i << " " << par[i] << "\n";
    }

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    t = 1;
    while(t--){
        solve();
    }
}
