#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;

    vector < int > v[2] ;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v[tmp&1].push_back(tmp);
    }

    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());

    bool is_alice = 1;
    ll bs = 0, as = 0;

    while (v[0].size() + v[1].size()) {

        if (is_alice) {
            if (v[0].size() && v[1].size()) {
                if (v[0].back() >= v[1].back()) {
                    as += v[0].back();
                    v[0].pop_back();
                }
                else {
                    v[1].pop_back();
                }
            }
            else if(v[0].size()) as += v[0].back(), v[0].pop_back();
            else v[1].pop_back();
        }
        else {

            if (v[0].size() && v[1].size()) {
                if (v[1].back() >= v[0].back()) {
                    bs += v[1].back();
                    v[1].pop_back();
                }
                else {
                    v[0].pop_back();
                }
            }
            else if(v[1].size()) bs += v[1].back(), v[1].pop_back();
            else v[0].pop_back();
        }

        is_alice ^= 1;
    }

    if (as == bs) {
        cout << "Tie\n";
    }
    else if (as > bs) cout << "Alice\n";
    else cout << "Bob\n";

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}