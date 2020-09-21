#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

ll nxt(ll a){
    ll _a = a;
    vector<int> dig;
    while(_a){
        dig.push_back(_a % 10);
        _a /= 10;
    }
    sort(dig.begin(), dig.end());
    return a + dig.back() * dig.front();
}
void solve(){
    ll a, k;
    cin >> a >> k;
    int cnt = 1;

    while( nxt(a) != a and cnt < k){
        cnt++;
        a = nxt(a);
    }
    cout << a << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
}