#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()
ll const LIM = 2e9;

vector<ll> pre;

void solve(){
    int n;
    cin >> n;
    cout << upper_bound(all(pre), n) - pre.begin() << '\n';

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    for (ll i = 2; i * i <= LIM; i++){
        if (i & 1) pre.push_back((i*i)/2 + 1);
    }

    while(t--){
        solve();
    }
}
