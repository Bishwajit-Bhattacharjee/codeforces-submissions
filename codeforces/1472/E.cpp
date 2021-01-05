#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

struct dat {
    int h, w, i;
    dat(int _h, int _w, int _i){
        h = _h;
        w = _w;
        i = _i;
    }
    dat(){}
};

void solve(){
    int n;
    cin >> n;

    vector < dat > v;

    map < int, vector < dat > > mp;

    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        v.emplace_back(l, r, i);
        v.emplace_back(r, l, i);
        mp[l].emplace_back(l, r, i);
        mp[r].emplace_back(r, l, i);
    }
    auto h_choto = [](dat a, dat b) {
        if (a.h == b.h) {
            if (a.w == b.w) return a.i < b.i;
            return a.w < b.w;
        }
        return a.h < b.h;
    };

    sort (v.begin(), v.end(), h_choto);
    auto w_choto = [](dat a, dat b) {
        if (a.w == b.w) {
            if (a.h == b.h) return a.i < b.i;
            return a.h < b.h;
        }
        return a.w < b.w;
    };

    set < dat, decltype(w_choto)> s(w_choto);

    vector < int > ans (n+1, -1);

    for (auto &[x, vec]: mp) {
        
        for (auto &cur : vec) {
            if (!s.empty()) {
                auto val = *s.begin();
                if ( val.w < cur.w) ans[cur.i] = val.i;
            }
        }

        for (auto &cur : vec) s.insert(cur);
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
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