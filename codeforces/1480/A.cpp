#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    string s;
    cin >> s;
    bool alice = true;

    for (auto &ch : s) {
        if (alice) {
            if (ch == 'a') ch = 'b';
            else ch = 'a';
        } else {
            if (ch == 'z') ch = 'y';
            else ch = 'z';
        }
        alice ^= 1;
    }
    cout << s << "\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}