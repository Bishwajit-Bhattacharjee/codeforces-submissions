#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){
    string s;
    cin >> s;
    vector<PLL> v;

    for (int i = 0; i < s.size(); ){
        int j = i;
        while (j < s.size() && s[j] == s[i]) j++;
        v.push_back({s[i]-'0', j - i});
        i = j;
    }

    // for (auto [x, y] : v){
    //     cout << x << ", " << y << endl;
    // }

    for (int i = v.size() - 1; i >= 0; i--){
        if (!v[i].first && v[i].second > 1){
            int j = i - 1;
            while (j >= 0){
                if (v[j].first && v[j].second > 1) {
                    cout << "NO\n"; return;
                }
                j--;
            }
            i = j;
        }
    }
    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
