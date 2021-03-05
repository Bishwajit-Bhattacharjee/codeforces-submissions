#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()
int const N = 2e5 + 10;
PLL a[5][N];
ll cost[5][N];
int n[5];
set <int> st[4][N];
ll const INF = 1e17;

void solve(){
    for (int i = 0; i < 4; i++) cin >> n[i];

    for (int i = 0; i < 4; i++){
        for (int j = 1; j <= n[i]; j++){
            cin >> cost[i][j];
            a[i][j] = {cost[i][j], j};
        }
    }    

    for (int i = 0; i < 3; i++){
        int m;
        cin >> m;
        for (int j = 1; j <= m; j++){
            int a, b;
            cin >> a >> b;
            st[i][a].insert(b);
        }
    }


    for (int i = 2; i >= 0; i--){
        sort(a[i+1] + 1, a[i+1] + n[i+1] + 1);

        for (int j = 1; j <= n[i]; j++){
            int compat = 1;
            a[i][j].first = INF;
            while (compat <= n[i+1] && st[i][j].count(a[i+1][compat].second)) {
                compat++;
            }
            if (compat <= n[i+1]){
                a[i][j].first = cost[i][j] + a[i+1][compat].first;
            }
        }
    }
    ll mn = INF;
    for (int i = 1; i <= n[0]; i++){
        mn = min(mn, a[0][i].first);
    }
    cout << ((mn >= INF)? -1 : mn) << "\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    t = 1;
    while(t--){
        solve();
    }
}
