#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()


int mex(set<int> &s){
    int m = 0;
    while (s.count(m)) m++;
    return m;
}

void solve(){
    int n, k;
    cin >> n >> k;
    set <int> s;
    for (int i = 0; i < n; i++){
        int tmp; 
        cin >> tmp;
        s.insert(tmp);
    }
    if (k == 0){
        cout << s.size() << "\n";
        return;
    }
    if (mex(s) == 1 + *s.rbegin()){
        cout << s.size() + k << '\n';
    } 
    else {
        s.insert((1 + mex(s) + *s.rbegin())/2);
        cout << s.size() << '\n';
    }

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
