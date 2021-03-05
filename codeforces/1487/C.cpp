#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){
    int n;
    cin >> n;
    vector<int> draw_cnt(n+1, 0);
    int win = (n-1)/2;

    for (int i = 1; i <= n; i++){
        int need = win;
        for (int j = i + 1; j <= n; j++){
            int val = -1;
            if (need) val = 1, need--;
            else if ((n % 2 == 0) && !draw_cnt[i]){
                val = 0, draw_cnt[i] = 1;
            }
            cout << val << " ";
        }
    }
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
