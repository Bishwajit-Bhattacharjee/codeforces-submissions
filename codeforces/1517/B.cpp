#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()


void solve(){
    int n, m;
    cin >> n >> m;
    multiset<PLL> ms;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int c;
            cin >> c;
            ms.insert({c,i});
        }
    }

    vector<vector<int>> b(m, vector<int> (n, -1));
    vector<set<int>> runtaken(n, set<int>());


    for (int i = 0; i < m; i++){
        auto [c, day] = *ms.begin();
        b[i][day] = c;
        runtaken[day].insert(i);
        ms.erase(ms.begin());
    }

    while(ms.size()){
        auto [c, day] = *ms.begin(); 
        for (int can = 0; can < m; can++){
            if (!runtaken[day].count(can)){
                b[can][day] = c;
                runtaken[day].insert(can);
                break;
            }
        }
        ms.erase(ms.begin());
    }


    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << b[j][i] << " ";
        }
        cout << "\n";
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
