#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int cnt = 0;
int ask(int l, int r) {
    if (l == r) return l;
    cnt++;
    assert(cnt <= 40);
    cout << "? " << l << " " << r << endl;
    int ret;
    cin >> ret;
    return ret;
}
int main(){
    int n;
    cin >> n;
    int delim = ask(1, n);
    int c1 = ask(1, delim);
    int lo, hi;
    if (delim == 1) {
        lo = 2, hi = n;
    }
    else if (c1 == delim) {
        lo = 1, hi = delim - 1;
    } else {
        lo = delim + 1, hi = n;
    }
    int ans = n + 1;
    if (delim < hi) {
        while (lo < hi) {
            // cout << "small right now " << lo << " " << hi << endl;
            int mid = (lo + hi) / 2;
            int val = ask(delim, mid);
            if (val != delim) lo = mid + 1;
            else {
                hi = mid;
            }
        }
        cout << "! " << hi << endl;
    }
    else {
        
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            int val = ask(mid, delim);
            if (val != delim) hi = mid - 1;
            else {
                lo = mid;
            }
        }
        cout << "! " << hi << endl;
        
    }
}