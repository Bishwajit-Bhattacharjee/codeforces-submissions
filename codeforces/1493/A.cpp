#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){
    int n, k;
    cin >> n >> k;

    set <int> tkn;

    int ans = 0;
    for (int i = n; i >= 1; i--){
        if (i != k && !tkn.count(k-i)){
            tkn.insert(i);
            ans++;
        }
    }
    cout << tkn.size() << "\n";
    for (auto x : tkn){
        cout << x << " ";
    }
    cout << '\n';

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
