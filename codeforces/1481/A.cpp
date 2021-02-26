#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int px, py;
    cin >> px >> py;
    map < char, int > cnt;
    string s;
    cin >> s;
    for (auto ch : s) cnt[ch]++;
    bool can_x = (px == 0 or px > 0 && cnt['R'] >= px) or (px < 0 && cnt['L'] >= -px);
    bool can_y = (py == 0 or py > 0 && cnt['U'] >= py) or (py < 0 && cnt['D'] >= -py);
    if (can_x and can_y) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}