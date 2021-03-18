#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){
    int n, k;
    cin >> n >> k;
    n -= max(0, k - 3);
    k = max(0, k - 3);

    if (n & 1){
        cout << n/2 << " " << n/2 << " " << "1 ";
    }
    else if(n % 4 == 0){
        cout << n/2 << " " << n/4 << " " << n/4 << " ";
    }   
    else {
        cout << (n/2 - 1) << " " << (n/2 - 1) << " 2 ";
    }

    while (k){
        cout << "1 ";
        k--;
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
