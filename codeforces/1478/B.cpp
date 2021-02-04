#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    ll q, d;
    cin >> q >> d;

    vector<ll> can;
    can.push_back(d);
    for(int i = 1; i <= 10; i++)
        can.push_back(d + 10*i), can.push_back(i + 10*d);
    
    sort(can.begin(), can.end());

    vector<int> dp(129, 0);
    dp[0] = 1;

    // for (auto x : can) cout << x << " ";
    // cout << endl;

    for (int i = 1; i < dp.size(); i++){
        for (auto x : can) {
            if (i >= x) 
                dp[i] |= dp[i-x];
        }
    }


    while(q--){
        int a;
        cin >> a;
        ll count = 10*d + 9;

        cout << ((a > count or dp[a])? "YES" : "NO") << "\n";
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