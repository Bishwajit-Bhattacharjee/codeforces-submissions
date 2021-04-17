#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

int n;

bool major(string s){
    vector<int> cnt(2, 0);
    for (auto x : s) cnt[x-'0']++;
    return cnt[1] >= cnt[0];
}

void do_it(vector<string> v, int pos){
    char ch = '0' + pos;
    string s1 = v[0], s2 = v[1];

    vector<int> ind1;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == ch && ind1.size() < n){
            ind1.push_back(i);
        }
    }

    vector<int> ind2;
    for (int i = 0; i < s2.size(); i++){
        if (s2[i] == ch && ind2.size() < n) ind2.push_back(i);
    }


    string ans = "";
    int l = 0, r = 0;
    for (int i = 0; i < n; i++){
        while (l < s1.size() && l < ind1[i]) {
            ans += s1[l]; l++;
        }
        while (r < s2.size() && r < ind2[i]) {
            ans += s2[r]; r++;
        }
        ans += ch;
        l++, r++;
    }

    while (l < s1.size()) ans += s1[l++];
    while (r < s2.size()) ans += s2[r++];

    cout << ans << '\n';
    // assert(ans.size() <= 3 * n);


}

void solve(){
    cin >> n;

    string s[3];
    vector<string>v[2];

    for (int i = 0; i < 3; i++) {
        cin >> s[i];
        v[major(s[i])].push_back(s[i]);
    }
    if (v[0].size() >= 2){
        do_it(v[0], 0);
    } else {
        do_it(v[1], 1);
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
