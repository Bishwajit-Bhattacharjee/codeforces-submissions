#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PII = pair <int,int>;
int const N = 3e5 + 10;

void solve(){
    int n, m;
    cin >> n >> m;

    vector < PII > v(m);

    for (int i = 0; i < m; i++){
        int r, c;
        cin >> r >> c;
        v[i] = {c, r};
    }

    sort(v.begin(), v.end());
    vector < PII > obs;
    for (int i = 0; i < m; ){
        int j = i, sum = 0;
        while (j < m and v[j].first == v[i].first){

            sum += v[j].second;
            j++;
        }
        obs.emplace_back(v[i].first, sum);
        i = j;
    }

    bool can = true;
    int i = 0;

    while (i < obs.size() and obs[i].second == 3)
        i++;

    for ( ; i < obs.size(); ){
        if (obs[i].second == 3) {
            i++; continue;
        }
        if (i + 1 >= obs.size()) {
            can = false; break;
        }

        assert(obs[i+1].first > obs[i].first);

        if (obs[i+1].first - obs[i].first & 1) {
            if (obs[i].second != obs[i+1].second) {
                can = false; break;
            }
        }
        else {
            if (obs[i].second + obs[i+1].second != 3){
                can = false; break;
            }
        }
        i += 2;
    }

    cout << (can? "YES\n" : "NO\n") ;

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}