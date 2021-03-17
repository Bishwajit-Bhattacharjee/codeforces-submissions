#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){
    int n;
    cin >> n;
    vector<int> cnt(110);
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        cnt[tmp]++;
    }
    for (int i = 0; i < 101; i++){
        if (cnt[i]) {
            cout << i << " ";
            cnt[i]--;
        }
    }
    for (int i = 0; i < 101; i++){
        while (cnt[i]){
            cout << i << " "; 
            cnt[i]--;
        }
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
