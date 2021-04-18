#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()


void solve(){
    int n;
    cin >> n;
    vector<string> g(n);

    for (auto &x : g) cin >> x;
    vector<PLL> ids;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (g[i][j] == '*') ids.emplace_back(i, j);
        }
    }
    auto [x1, y1] = ids[0];
    auto [x2, y2] = ids[1];

    if (x1 == x2){
        ids.emplace_back((x1+1)%n, y1);
        ids.emplace_back((x1+1)%n, y2);
    }
    else if(y1 == y2){

        ids.emplace_back(x1, (y1+1)%n);
        ids.emplace_back(x2, (y1+1)%n);
    }
    else {
        ids.emplace_back(x1, y2);
        ids.emplace_back(x2, y1);
    }

    for (auto [x, y] : ids){
        g[x][y] = '*';
    }

    for (auto x : g){
        cout << x << '\n';
    }

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
