#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '#' + s;

    vector<int> L(n+2, 0), R(n+2, 0);
    for (int i = 1; i <= n; i++){
        if (s[i] == 'R') L[i] = i;
        else if (i > 1 && s[i] == 'L' && s[i-1] == 'R') L[i] = L[i-2];
        else if (s[i] == 'L') L[i] = i - 1;
    }
    R[n] = n;
    for (int i = n - 1; i >= 0; i--){
        if (s[i+1] == 'L') R[i] = i;
        else if (i + 2 <= n && s[i+1] == 'R' && s[i+2] == 'L') R[i] = R[i+2];
        else if(s[i+1] == 'R') R[i] = i + 1;
    }
    for (int i = 0; i <= n; i++){
        cout << R[i] - L[i] + 1 << " ";
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