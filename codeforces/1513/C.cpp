#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

int const N = 3e5;
ll const M = 1e9 + 7;
ll dp[15][N];


void solve(){

    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    while (n) {
        ans += dp[n%10][m];
        ans %= M;
        n /= 10;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    for (int i = 0; i <= 9; i++) dp[i][0] = 1;
    for (int i = 0; i <= 9; i++){
        for (int m = 10 - i - 1; m >= 0; m--) dp[i][m] = 1;
    }


    for (int m = 1; m < N; m++){
        for (int i = 0; i < 10; i++){
            if (m - 10 + i >= 0) {
                dp[i][m] = (dp[0][m-10+i] + dp[1][m-10+i]) % M;
            }
            // else {
            //     dp[i][m] = dp[i][m-1];
            // }

            // if(m < 10) cout << i << " " << m << " " << dp[i][m] << endl;
        }
    }

    // cout << dp[5][6] << '\n';


    while(t--){
        solve();
    }
}
