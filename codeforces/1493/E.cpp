#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

string plus_one(string num){
    string ret;
    int carry = 1;
    for (int i = (int)num.size() - 1; i >= 0; i--){
        int val = (num[i] - '0' + carry) & 1;
        carry = (num[i] - '0' + carry) / 2;
        ret += '0' + val;
    }
    if (carry) ret += '1';
    reverse(all(ret));
    return ret;
}

void solve(){
    // cout << plus_one("1") << " "  << plus_one("10") << " " << plus_one("111111") << endl;

    int n;
    cin >> n;
    string l, r;
    cin >> l >> r;

    if (l == r){
        cout << r << '\n';
    }
    else if (l[0] != r[0]){
        cout << string(n, '1') << '\n';
    }
    else if (plus_one(l) == r || r.back() == '1'){
        cout << r << '\n';
    }
    else {
        cout << plus_one(r) << "\n";
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    t = 1;
    while(t--){
        solve();
    }
}
