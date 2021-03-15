#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){
    int n;
    cin >> n;
    vector<ll> xx, yy;

    for (int i = 0; i < 2 * n; i++){
        ll x, y;
        cin >> x >> y;
        if (!x) xx.push_back(abs(y));
        else yy.push_back(abs(x));
    }

    sort(all(xx));
    sort(all(yy));

    assert(xx.size() == n && yy.size() == n);

    double ans = 0.0;
    for (int i = 0; i < n; i++){
        double val =  sqrt(1.0* xx[i] *xx[i] + 1.0 * yy[i] * yy[i]);
        //cout << val << endl;
        ans += val;
    }

    cout <<fixed << setprecision(9) << ans << '\n';

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
