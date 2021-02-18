#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const N = 110;
int perm[N], revPerm[N];
int n;

int find_depth(int l, int r, int cur, int mx) {
    while (!(revPerm[mx] >= l and revPerm[mx] <= r)) mx--;
    if (mx == cur) return 0;
    // ll left = l, right = revPerm[mx];
    // if (left > right) swap(left, right);

    if (l <= revPerm[cur] and revPerm[cur] <= revPerm[mx]) {
        return 1 + find_depth(l, revPerm[mx] - 1, cur, mx);
    } else {
        return 1 + find_depth(revPerm[mx] + 1, r, cur, mx);
    }
}
void solve(){
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> perm[i];
        revPerm[perm[i]] = i;
    }

    for (int i = 1; i <= n; i++){
        cout << find_depth(1, n, perm[i], n) << " ";
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