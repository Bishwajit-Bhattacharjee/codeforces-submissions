#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector < long long > a(n), b(m);

    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    sort(a.begin(), a.end(), [](long long a, long long b){
        return a > b;
    });

    long long diff_gcd = 0;

    for (int i = 0; i + 1 < a.size(); i++) {
        diff_gcd = __gcd(diff_gcd, a[i] - a[i+1]);
    }

    for (int i = 0; i < m; i++) {
        cout << __gcd(diff_gcd, b[i] + a.back()) << " " ;
    }

    cout << '\n';
    return 0;

}