#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()


void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> l, r;
    int cnt = 0;
    int k = n / 3;

    for (int i = 0; i < n; i++){
        if (s[i] == 'T'){
            cnt++;
            if (cnt > k) r.push_back(i);
            else l.push_back(i);
        } 
    }
    reverse(all(r));
    reverse(all(l));
    for (int i = 0; i < s.size(); i++){
        char x = s[i];
        if (x == 'M'){
            if(l.empty() or r.empty() or l.back() > i or r.back() < i){
                cout << "NO\n"; return;
            }
            l.pop_back(), r.pop_back();
        }
    }

    if (l.empty() and r.empty()) {
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
