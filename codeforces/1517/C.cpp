#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int> (n, -1));


    for(int i = 0; i < n; i++) cin >> g[i][i];

    for (int i = 0; i < n; i++){
        int col = g[i][i];
        int cnt = g[i][i] - 1;

        int x = i, y = i;

        // cout << cnt << " " << i << endl;
        // cout << "debug " << endl;
        // for (int x = 0; x < n; x++){
        //     for (int j = 0; j <= x; j++) cout << g[x][j] << " ";
        //     cout << endl;
        // }

        while (cnt > 0){
            int nx = x, ny = y - 1;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && g[nx][ny] == -1){
                x = nx, y = ny;
                g[x][y] = col;
                cnt--;
                continue;
            } 
            nx = x + 1, ny = y;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && g[nx][ny] == -1){
                x = nx, y = ny;
                g[x][y] = col;
                cnt--;
                continue;
            } 
            // assert(false);
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++) cout << g[i][j] << " ";
        cout << "\n";
    }

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    t = 1;
    while(t--){
        // cout << "hello" << endl;
        solve();
    }
}
