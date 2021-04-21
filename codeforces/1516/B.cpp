#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()


bool check2(vector<ll> v){
    ll x = 0;
    for (auto p: v) x ^= p;
    ll pref = 0;
    for (int i = 0; i + 1 < v.size(); i++){
        pref ^= v[i];
        if (pref == (x ^ pref)) return 1;
    }
    return 0;
}

bool check3(vector<ll> v){
    ll x = 0;
    for (auto p: v) x ^= p;
    int n = v.size();
    ll p1 = 0;
    for (int i = 0; i + i < n; i++){
        p1 ^= v[i];
        ll p2 = 0;
        for (int j = i + 1; j + 1 < n; j++){
            p2 ^= v[j];
            ll p3 = x ^ p1 ^ p2;

            if (p1 == p2 && p2 == p3) return 1;
        }
    }
    return 0;
}

bool check(vector<ll> v){
    ll p1 = 0;
    int n = v.size();
    for (int i = 0; i + 1 < n; i++){
        p1 ^= v[i];

        ll tmp = 0;
        for (int j = i + 1; j < n; j++){
            tmp ^= v[j];
            if (tmp == p1) {
                if (j + 1 == n) return 1;
                tmp = 0;
            }
        }
    }
    return 0;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);

    for (auto &x : v){
        cin >> x;
    }

    if (check2(v) or check3(v) or check(v)){
        cout << "YES\n";
    }
    else {
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
