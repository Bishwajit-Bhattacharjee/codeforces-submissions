#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

PLL order(PLL p){
    return PLL(min(p.first, p.second), max(p.first, p.second));
}
void solve(){
    int n, m;
    cin >> n >> m;
    map<PLL, int> has;

    set <PLL> same, diff;

    while (m--){
        char ch;
        cin >> ch;
        // cout << ch << endl;
        if (ch == '+'){
            int a, b;
            char label;
            cin >> a >> b >> label;
            // cout << a << " " << b << " " << label << endl;
            if (has.count({b, a})) {
                if (has[{b, a}] == label){
                    same.insert(order({a, b}));
                }
                else {
                    diff.insert(order({a, b}));
                } 
            }
            has[{a, b}] = label;
        }
        else if (ch == '-'){
            int a, b; char label;
            cin >> a >> b;

            if (has.count({b, a})) {
                if (has[{b, a}] == has[{a, b}]) same.erase(order({a, b}));
                else diff.erase(order({a,b}));
            }
            has.erase({a, b});
        }
        else {
            int k;
            cin >> k;
            
            if (k & 1){
                cout <<  ((same.size() or diff.size())? "YES\n" : "NO\n");
            } 
            else {
                cout << ((same.size())? "YES\n": "NO\n");
            }
        }
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
