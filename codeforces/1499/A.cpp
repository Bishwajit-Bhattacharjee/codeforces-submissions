#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int w, b;
    cin >> w >> b;
    if (k1 > k2) swap(k1, k2);

    int ww = (k1 + (k2-k1)/2);
    int bb = n - k2 + (k2 - k1)/2;
    cout << ((ww >= w && bb >= b)? "YES": "NO") << "\n";

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
