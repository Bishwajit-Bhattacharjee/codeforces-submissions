#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;

void solve(){
    int n;
    cin >> n;
    vector<PLL> v(n);
    ll tot = 0;
    for (int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i + 1;
        tot += v[i].first;
    }
    sort(v.begin(), v.end());
    ll rgt = 0;
    vector<int> ans;

    for (int i = (int)v.size() - 1; i >= 0; ){
        int j = i;
        ll cur_sum = 0;
        vector<int> curPoses;
        while (j >= 0 and v[i].first == v[j].first) {
            curPoses.push_back(v[j].second);
            cur_sum += v[j].first;
            j--;
        }
        if (i + 1 == v.size() or (tot - rgt >= v[i+1].first)) {
            while (curPoses.size()) {
                ans.push_back(curPoses.back());curPoses.pop_back();
            }
            rgt += cur_sum;
            i = j;
        }
        else {
            break;
        }
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto x : ans) cout << x  << " ";
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}