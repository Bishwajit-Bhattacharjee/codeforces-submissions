#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

int const N = 1e7 + 5;

ll ds[N];
ll ans[N];

void solve(){
    ll c;
    cin >> c;

    if (ans[c] == 0){
        cout << "-1\n";
    }
    else {
        cout << ans[c] << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;

    ll cnt = 0; 
    for (int i = 1; i < N; i++){
        for (int j = i; j < N; j += i) ds[j] += i, cnt++;
    }

    // for (int i = 1; i <= 12; i++){
    //     cout << i << " " << ds[i] << endl;
        // }




    for (int i = N - 1; i > 0; i--){
        if (ds[i] < N) ans[ds[i]] = i;
    }


    while(t--){
        solve();
    }
}
