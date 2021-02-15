#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int ask(int pos) {
    cout << "? " << pos << endl;
    int ret;
    cin >> ret;
    return ret;
}
void solve(){
    int n;
    cin >> n;
    int lo = 1, hi = n;

    while (hi - lo > 20){
        int mid = (lo + hi) / 2;
        int m1 = ask(mid);
        int m2 = ask(mid - 1);

        if (m1 > m2) hi = mid;
        else lo = mid - 1;
    }
    int ans = n + 100, ans_ind = -1;
    for (int x = lo; x <= hi; x++) {
        int val = ask(x);
        if (val < ans) {
            ans = val;
            ans_ind = x;
        }
    }
    cout << "! " << ans_ind << endl;
}
int main(){
    int t;
    t = 1;
    while(t--){
        solve();
    }
}