#include <bits/stdc++.h>
using namespace std;

int range_xor(vector < int > &v, int l, int r) {
    int x_or = 0;
    for (int i = l; i <= r; i++) x_or ^= v[i] ;
    return x_or;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector < int > v(n);
    for (auto &x : v) cin >> x;
    if (n > 65) {
        cout << "1\n"; return 0;
    }
    int ans = n + 3;

    for (int mid = 0; mid < n; mid++){
        for (int l = mid; l >= 0; l--){
            for (int r = mid + 1; r < n; r++) {
                int xor1 = range_xor(v, l, mid);
                int xor2 = range_xor(v, mid + 1, r);
                if (xor1 > xor2 and r - l - 1 > 0) {
                    ans = min(ans, r - l - 1);
                }
            }
        }
    }
    if (ans > n) {
        cout << "-1\n";
    }
    else cout << ans << endl;
}