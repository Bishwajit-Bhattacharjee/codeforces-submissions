#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
using PII = pair<int,int>;
#define all(x) (x).begin(), (x).end()

vector <PII> vals{
    PII(0, 3), PII(2, 3), PII(2, 1), PII(0, 1)
};

vector<vector<int> > lists;

void gen(int pos, vector<int> v) {
    if (pos == 4) {
        lists.push_back(v); return;
    }
    gen(pos + 1, v);
    v.push_back(pos);
    gen(pos + 1, v);
}
int n;

bool check(vector <int> tkn, vector<int> v) {

    for (auto x : tkn){
        int p = vals[x].first, q = vals[x].second;
        if (v[p] && v[q]) v[p]--, v[q]--;
    }

    for (int i = 0; i < 4; i++) v[i] = max(0, v[i] - (n-2));

    for (int i = 0; i < 4; i++){
        if (v[i]) return 0;
    }
    return 1;
}
void solve(){
    
    vector<int> v(4);
    cin >> n;

    gen(0, vector<int>());

    for (int i = 0; i < 4; i++) {
        cin >> v[i];
    }

    for (auto x : lists){
        if (check(x, v)) {
            cout << "YES\n"; return;
        }
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
