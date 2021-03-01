#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){
    int n, q;
    cin >> n >> q;
    set <int> s[2];
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++){
        int val;
        cin >> val;
        v[i] = val;
        s[val].insert(i);
    }
    while (q--){
        int t, x;
        cin >> t >> x;
        if (t == 1){
            s[v[x]].erase(x);
            v[x] ^= 1;
            s[v[x]].insert(x);
        } 
        else {
            if (x <= s[1].size()){
                cout << "1\n";
            } 
            else {
                cout << "0\n";
            }
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
