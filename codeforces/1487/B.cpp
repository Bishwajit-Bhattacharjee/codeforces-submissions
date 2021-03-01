#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){
    int n, k;
    cin >> n >> k;
    k--;
    int cyc = (k) / (n/2);
    cout << (k + (n & 1) * cyc) % n + 1 << "\n";
    // cout << (k + (n & 1)) % n + 1 << "\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
