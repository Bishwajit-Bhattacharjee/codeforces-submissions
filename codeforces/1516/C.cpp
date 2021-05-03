#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

int const N = 2010;
bool dp[3][N * 105];

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    int tot = 0;

    for (auto &x : v) cin >> x, tot += x;

    dp[1][0] = 1;

    for (int i = 0; i < n; i++){
        for (int sum = 0; sum <= tot; sum++){
            dp[i&1][sum] = dp[(i+1)&1][sum];
            if (sum >= v[i])
                dp[i&1][sum] |= dp[(i+1)&1][sum-v[i]];
        }
    }

    if (tot & 1) {
        cout << "0\n"; return;
    }

    if (!dp[(n-1)&1][tot/2]){
        cout << "0\n"; return;
    }

    while(true){
        for (int i = 0; i < n; i++){
            if (v[i] & 1){
                cout << "1\n" << i + 1 << '\n';
                return;
            }
            v[i] /= 2;
        }
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
