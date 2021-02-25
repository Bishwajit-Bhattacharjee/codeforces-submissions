#include <bits/stdc++.h>
using namespace std;
using ll = long long int;


void solve(){
    int a, b, k;   
    cin >> a >> b >> k;
    if (k == 0){
        cout << "YES\n";
        cout << string(b, '1') + string(a, '0') << "\n";
        cout << string(b, '1') + string(a, '0') << "\n";
    } else if (k > a + b - 2 or (k > 0 and (b == 1 or a == 0))) {
        cout << "No\n";
    } else {
        string x = string(b, '1') + string(a, '0');
        string y = x;
        swap(y[b-1], y[b + min(a, k) - 1]);
        k -= min(a, k);
        for (int pos = b - 2; pos >= 1 and k > 0; pos--){
            swap(y[pos], y[pos+1]);
            k--;
        } 
        cout << "YES\n";
        cout << x << "\n";
        cout << y << "\n";
    }

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    t = 1;
    while(t--){
        solve();
    }
}