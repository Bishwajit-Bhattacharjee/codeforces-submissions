#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

int const N = 1050;
int const MOD = 1e9 + 7;
ll dp[2][N][N];
ll n, k;

ll DP(bool dir, int pos, int l){
    if (l == 0) return 0;
    if (pos == 0) return 1;
    if (pos == n + 1) return 1;
    ll &ret = dp[dir][pos][l];
    if (ret != -1) return ret;

    ret = 0;
    int mul = (dir)?-1: 1;

    ret = DP(dir, pos + mul, l);
    ret += DP(dir^1, pos - mul, l-1);

    if (ret >= MOD) ret -= MOD;
    return ret;
}


void solve(){

    cin >> n >> k;
    for (int d = 0; d < 2; d++){
        for (int _n = 0; _n <= n + 10; _n++){
            for (int _k = 0; _k <= k + 10; _k++) dp[d][_n][_k] = -1;
        }
    }
    cout << DP(0, 1, k) << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
