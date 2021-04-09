#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()


bool isPalin(string s){
    
    for (int i = 0; i < s.size()/2; i++){
        if (s[i] != s[s.size() - 1 - i]) return 0;
    }
    return 1;
}

void solve(){
    string s;
    cin >> s;
    int lc = 0;
    int tc = 0;
    for (auto c: s) tc += c == 'a';
    string ans;

    if (tc == s.size()){
        cout << "NO\n";
        return;
    }

    if (s[0] != 'a'){
        ans = s + 'a';
    }
    else if(s.back() != 'a')
        ans += 'a' + s;

    if (!isPalin('a' + s)) {
        ans = 'a' + s;
    }    
    else ans = s + 'a';
    cout << "YES\n";

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
