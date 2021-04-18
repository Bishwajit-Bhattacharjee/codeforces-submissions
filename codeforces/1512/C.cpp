#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){
    vector<int> cnt(2, 0);
    cin >> cnt[0] >> cnt[1];
    
    int n = cnt[0] + cnt[1];

    string s;
    cin >> s;

    for (int i = 0; i < n / 2; i++){
        auto l = s[i] , r = s[n-i-1];
        if (l == '?' && r == '?') continue;
        if (l != '?' && r != '?') cnt[l-'0']--, cnt[r-'0']--;
        else {
            if (l == '?'){
                cnt[r - '0'] -= 2;
                s[i] = r;
            }
            else {
                cnt[l-'0'] -= 2;
                s[n-i-1] = l;
            }
        }
    }
    if ((n&1) && s[n/2] != '?') {
        cnt[s[n/2] - '0']--;
    }

    if (cnt[0] < 0 or cnt[1] < 0) {
        cout << "-1\n"; return;
    }

     
    // cout << cnt[0] << " " << cnt[1] << endl;


    if (n & 1) {
        if (s[n/2] != '?'){

        }
        else if (cnt[0] % 2 == 1) {
            s[n/2] = '0';
            cnt[0]--;
        }
        else {
            cnt[1]--;
            s[n/2] = '1';
        }
    }

    for (int i = 0; i < n/2 ; i++){
        if (s[i] == '?' && s[n-i-1] == '?') {
            if (cnt[0] >= 2) {
                s[i] = s[n-i-1] = '0'; cnt[0] -= 2;
            }
            else {
                s[i] = s[n-i-1] = '1'; cnt[1] -= 2;
            }
        }
    }

    if (cnt[0] < 0 || cnt[1] < 0) {
        cout << "-1\n"; return;
    }

    for (int i = 0; i < n/2; i++){
        if (s[i] != s[n-i-1] || s[i] == '?') {
            cout << "-1\n"; return;
        }
    }

    cout << s << '\n';

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
