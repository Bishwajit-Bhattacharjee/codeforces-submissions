#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

string s;
vector < vector<int> > vals;

void gen(int pos, vector<int> v) {
    if (pos == 3) {
        vals.push_back(v);
        return;
    }
    v.push_back(1);
    gen(pos+1,v);
    v.pop_back();
    v.push_back(-1);
    gen(pos+1, v);
    v.pop_back();
}

bool check(vector<int> v){
    int tot = 0;
    for (auto ch : s){
        if (ch == 'A') tot += v[0];
        else if(ch == 'B') tot += v[1];
        else tot += v[2];

        if (tot < 0) return 0;
    }
    return tot == 0;
}

void solve(){
    cin >> s;   

    for (auto x : vals){
        if(check(x)){
            cout << "YES\n"; return;
        }
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    gen(0, vector<int>());

    while(t--){
        solve();
    }
}
