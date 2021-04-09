#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()
int const N = 210, D = 100000;
ll t[N], xp[N], y[N];
ll const INF = 1e12;

void solve(){
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        cin >> t[i] >> xp[i] >> y[i];
    }
    vector<ll> done(m+1, -1), req(m+1, INF);
    done[0] = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if (done[j] != -1) req[j] = 0;
        }
        if (t[i] == 1){
            ll x = (xp[i] - 1) / D + 1;
            for (int j = 1; j <= m; j++){
                if (j >= x and done[j-x] != -1 and req[j-x] < y[i]){
                    if (done[j] != -1) continue;
                    done[j] = i;
                    req[j] = req[j-x] + 1;
                }
            }
        }
        else {
            for (int j = 1; j <= m; j++){
                ll x = (xp[i]*j + D - 1) / D;
                if (x <= m && done[j] != -1 and req[j] < y[i]){
                    if (done[x] == -1) {
                        done[x] = i; req[x] = req[j] + 1;
                    }
                }
            }
        }
    }


    for (int i = 1; i <= m; i++){
        cout << done[i] << " ";
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    t = 1;
    while(t--){
        solve();
    }
}
