#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    map<string,int> pos_map;
    map<int,string> pat_map;

    for (int i = 1; i <= n; i++){
        string tmp;
        cin >> tmp;
        pos_map[tmp] = i;
        pat_map[i] = tmp;
    }
    vector<string> v(m+1);
    vector<int> target_pos(m+1);

    for (int i = 1; i <= m; i++){
        string tmp;
        int pos;
        cin >> v[i] >> target_pos[i];
    }

    map< string, vector<string> > g;
    map<string, int> deg;


    for (int i = 1; i <= m; i++){
        string str = v[i];
        int pos = target_pos[i];
        
        bool done = false;
        vector<string> matches;
        for (int mask = 0; mask < (1<<k); mask++){
            string cur = str;
            for (int i = 0; i < k; i++){
                if (mask & (1<<i)) cur[i] = '_';
            }
            if (pat_map[pos] == cur) done = true;
            matches.push_back(cur);
        }
        if (!done) {
            cout << "NO\n"; return;
        }

        // cout << "......." << str << endl;
        // for (auto x : matches) cout << x << " " ;
        // cout << endl;

        string up = pat_map[pos];

        for (auto x : matches){
            if (x != up && pos_map.count(x)){
                g[up].push_back(x);
                deg[x]++;
            }
        }        
    }
    vector <string> zero;

    // for (auto [str, pos] : pos_map){
    //     cout << str << ": ";
    //     for (auto x : g[str]){
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

    for (auto [str, pos] : pos_map){
        if (deg[str] == 0) zero.push_back(str);
    }
    vector <string> top_sort;

    while (zero.size()){
        string cur = zero.back(); zero.pop_back();
        top_sort.push_back(cur);

        for (auto adj : g[cur]){
            deg[adj]--;
            if (deg[adj] == 0) zero.push_back(adj);
        }
    }

    // cout << "HELLO\n";

    if (top_sort.size() != n) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        for (auto x : top_sort){
            cout << pos_map[x] << " ";
        }
        cout << "\n";
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