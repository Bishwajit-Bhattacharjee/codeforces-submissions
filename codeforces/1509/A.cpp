#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){
    ll n;
    cin >> n;
    vector<vector<int> > x(2, vector<int> ());

    for (int i = 0;i < n; i++){
        int tmp;
        cin >> tmp;
        x[tmp&1].push_back(tmp);
    }
    for (auto a : x){
        for (auto b : a) {
            cout << b << " ";
        }
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
