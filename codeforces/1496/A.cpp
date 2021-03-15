#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

void solve(){
    int n, k;
    cin >> n >> k;
    deque<char> ch(n);

    for (auto &x : ch) cin >> x;
    int cnt = 0;
    while (cnt < k && ch.size() > 1 && ch.front() == ch.back()){
        cnt++;
        ch.pop_back();
        ch.pop_front();
        //cout << cnt << endl;
    }
    cout << ((ch.size() && cnt >= k)? "YES": "NO") << "\n";

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
