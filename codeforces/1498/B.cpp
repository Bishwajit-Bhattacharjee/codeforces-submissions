#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()
ll n, W;

bool can(ll h, vector<ll> &w){
    ll cnt = 1, ww = 0;

    for (auto x : w){
        if (ww + x <= W){
            ww += x;
            continue;
        }
        else {
            cnt++;
            ww = x;
        }
    }
    return cnt <= h;
}

void solve(){
    
    cin >> n >> W;

    vector <ll> w(n);
    multiset<ll> ms;

    for (auto &x : w) cin >> x, ms.insert(x);
    ll ans = 1;
    ll cur = W;
    while (ms.size()){
        auto it = ms.upper_bound(cur);
        it = prev(it);
        
        if (*it > cur){
            ans++;
            cur = W;
            continue;
        }
        cur -= *it;
        ms.erase(it);
        
    }

    cout << ans << '\n';

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
