#include <bits/stdc++.h>
using namespace std;
using ll = long long int;


void rectify(int pos, string &s) {
    set <char> left, right;

    for (int i = 0; i < 26; i++) {
        if (s[pos] - 'a' == i) continue;
        bool can = 1;
        for (int l = max(0, pos -2); l < pos; l++){
            if (s[l] - 'a' == i) can = 0;
        }

        for (int r = pos+1; r < min(pos+3, (int)s.size()); r++){
            if (s[r] - 'a' == i) can = 0;
        }

        if(can) {
            s[pos] = 'a' + i;
            return;
        }
    }

    assert(false);
}

void solve(){
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < s.size(); i++){
        for (int j = max(0, i - 2); j < i; j++) {
            if (s[i] == s[j]) {
                rectify(i, s);
                ans++;
            }
        }
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}