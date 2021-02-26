#include <bits/stdc++.h>
using namespace std;
using ll = long long int;


void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> g(n);
    for (int i = 0; i < n; i++){
        cin >> g[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++) {
            if (g[i][j] == g[j][i]) {
                cout << "YES\n";
                vector<int> ans;
                while(ans.size() <= m) {
                    if (ans.size() & 1) ans.push_back(i+1);
                    else ans.push_back(j + 1);
                }
                for (auto x : ans) cout << x << " ";
                return;
            }
        }
    }

    if (m & 1) {
        cout << "YES\n";
        vector<int> ans;

        while(ans.size() <= m) {
            if (ans.size() & 1) ans.push_back(1);
            else ans.push_back(2);
        }
        for (auto x : ans) cout << x << " ";
        return;
    }

    if (n == 2 and m % 2 == 0) {
        cout << "NO";
        return;
    }
    vector<int> perm{0, 1, 2};

    do {
        int a = perm[0], b = perm[1], c = perm[2];
        if (g[a][b] == g[b][c]) break;
    }while(next_permutation(perm.begin(), perm.end()));

    int x = perm[0] + 1, y = perm[1] + 1, z = perm[2] + 1;

    if (m / 2 % 2 == 1){
        cout <<  "YES\n";
        while (m >= 4) {
            cout << x << " " << y << " " << z << " " << y << " " ;
            m -= 4;
        }
        assert(m == 2);
        cout << x << " " << y << " " << z ;
        return;
    } else {
        cout << "YES\n";
        cout << y << " ";
        while (m >= 4) {
            cout << z << " " << y << " " << x << " " << y << " ";            
            m -= 4;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << '\n';
    }
}