#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int const N = 2e5 + 10;
int const M = 1<<22;
vector<vector<int>> g;
int n, k, sub[N];
ll ans[N], cnt[M], sum = 0;
bool deleted[N];

string s;

void check(bool b){
    if (!b){
        while(true);
    }
}

int get_mask(int pos){
    return 1<<(s[pos] - 'a');
}

void calc_sub(int u, int p){
    sub[u] = 1;
    for (auto v : g[u]){
        if (v == p || deleted[v]) continue;
        calc_sub(v, u);
        sub[u] += sub[v];
    }
}


int centroid(int u, int p, int sz){
    for (auto v : g[u]){
        if (v != p && !deleted[v] && sub[v] > sz/2) 
            return centroid(v, u, sz);
    }
    return u;
}

void add(int u, int p, int mask, int val){
    mask ^= get_mask(u);

    // cout << "node " << u << " " << p << " " << mask << endl;

    cnt[mask] += val;
    for (auto v : g[u]){
        if (v == p || deleted[v]) continue;
        add(v, u, mask, val);
    }
}

ll query(int u, int p, int mask){
    mask ^= get_mask(u);

    // cout << "       Query for " << u << endl;

    // for (int i = 0; i < 8; i++){
    //     cout << "            cnt " << i << " " << cnt[i] << endl;
    // }

    ll tot = 0;
    for (auto v: g[u]){
        if (v == p || deleted[v]) continue;
        tot += query(v, u, mask);
    }
    
    for (int pos = 0; pos < 21; pos++){
        int tmp_msk = mask ^ (1<<pos);
        check(tmp_msk < M);
        tot += cnt[tmp_msk];
    }
    tot += cnt[mask];
    ans[u] += tot;
    return tot;
}


ll single(int u, int p, int mask){
    ll tot = 0;
    mask ^= get_mask(u);

    for (auto v : g[u]){
        if (v == p || deleted[v]) continue;
        tot += single(v, u, mask);
    }

    tot += (__builtin_popcount(mask) <= 1);
    ans[u] += tot;
    return tot;
}

void complete_this_centroid(int cen){
    sum = 0;
    single(cen, cen, 0);

    // cout << "Centroid update " << cen << " : " << endl;

    for (auto v : g[cen]){
        if (deleted[v]) continue;
        add(v, cen, 0, +1);
    }

    // for (int i = 0; i < 10; i++) cout << " cen up  " << i << " " << cnt[i] << endl;

    for (auto v : g[cen]){
        if (deleted[v]) continue;
        add(v, cen, 0, -1);
        ll tmp = query(v, cen, get_mask(cen));
        // cout << "cen " << cen << " " << "v " << v << " " << tmp << endl;
        sum += tmp;
        add(v, cen, 0, +1);
    }

    // cout << cen << " " << sum << endl;

    assert(sum % 2 == 0);

    ans[cen] += sum/2;

    for (auto v : g[cen]){
        if (deleted[v]) continue;
        add(v, cen, 0, -1);
    }


    // for (int i = 0; i < 10 ; i++){
    //     assert(cnt[i] == 0);
    // }
}

void decompose(int u, int p){
    calc_sub(u, p);
    int cen = centroid(u, p, sub[u]);

    complete_this_centroid(cen);
    deleted[cen] = 1;

    for (auto v : g[cen]){
        if(!deleted[v])
            decompose(v, v);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n ; 
    g.assign(n+1, vector<int>());

    for (int i = 1; i <= n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }    
    cin >> s;
    
    decompose(0, -1);


    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}