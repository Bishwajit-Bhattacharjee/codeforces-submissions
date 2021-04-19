#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()


bool lastOne(vector<ll> &a, int n){
    multiset<ll> ms(a.begin(), a.begin() + n + 1);
    ll sum = accumulate(a.begin(), a.begin() + n + 1, 0LL);
    // cout << "sum " << sum << endl;
    ll dif = a.back() - sum;
    dif *= -1;

    if (ms.count(dif)) {
        ms.erase(ms.find(dif));
        for (auto x : ms) cout << x << " ";
        cout << '\n' ; return 1;
    }
    else {
        return 0;
    }
}

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n+2);
    
    for (auto &x :a) cin >> x;

    sort(all(a));

    if (lastOne(a, n)){

        return;
    }
    ll sum = accumulate(a.begin(), a.begin() + n, 0LL);
    if (sum == a[n]) {
        for (int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << "\n"; return;
    }
    cout << "-1\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
