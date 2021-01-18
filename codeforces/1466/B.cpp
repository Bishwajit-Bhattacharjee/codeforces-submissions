#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){

    int n;
    cin >> n;
    vector <int> v(n);

    for (auto &x : v) cin >> x;

    vector < int > cnt(3*n, 0);

    for (auto x : v) {
        if(cnt[x]) cnt[x+1]++;
        else 
            cnt[x]++;
    }

    int ans = 0;
    for (auto x : cnt) ans += (x > 0);
    cout << ans << '\n';
 
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}