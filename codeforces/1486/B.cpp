#include <bits/stdc++.h>
using namespace std;
using ll = long long int;


ll each_dim(vector <ll> &v) {
    if (v.size() == 1) return 1LL;
    int mid = (int)v.size() / 2;
    if (v.size() & 1){
        return 1;
    }    
    else {
        return 1LL * abs(v[mid] - v[mid-1]) + 1;
    }
}

void solve(){
    int n;
    cin >> n;
    vector <ll> x(n), y(n);

    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    cout << each_dim(x) * each_dim(y) << "\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}