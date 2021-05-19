#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PII = pair<int,int>;

int const N = 1e5 + 10;
ll M;
vector<vector<PII>> g;
int n, sub[N];
ll ans, sum = 0;
bool deleted[N];
ll mod[N], inv[N];
map<ll,ll> cnt;


ll bigmod(ll a, ll b){
    if (!b) return 1LL;
    ll x = bigmod(a, b/2);
    x = x * x % M;
    if (b & 1) x = (x * a) % M;
    return x;
}

void calc_sub(int u, int p){
    sub[u] = 1;
    for (auto [v,w] : g[u]){
        if (v == p || deleted[v]) continue;
        calc_sub(v, u);
        sub[u] += sub[v];
    }
}


int centroid(int u, int p, int sz){
    for (auto [v,w] : g[u]){
        if (v != p && !deleted[v] && sub[v] > sz/2) 
            return centroid(v, u, sz);
    }
    return u;
}

void printState(){
    cout << "Current state" << endl;
    for (auto [k, v]: cnt){
        cout << "     " << k << " " << v << endl;
    }
}

void add(int u, int p, ll mask, int val, int dep){
    cnt[mask] += val;
    for (auto [v,w] : g[u]){
        if (v == p || deleted[v]) continue;
        add(v, u, (mask + w * mod[dep]) % M, val, dep+1);
    }
}

void query(int u, int p, ll mask, int dep){

    ll tot = 0;
    ll qm = (M -(mask * inv[dep] % M)) % M;

    // cout << "Qeury " << u << "  val " << qm << endl;
    // printState();

    sum += cnt[qm];

    for (auto [v,w] : g[u]){
        if (v == p || deleted[v]) continue;
        query(v, u, (mask * 10 + w) % M, dep+1);
    }
}

void single(int u, int p, ll mask, int dep){
    ans += (mask == 0 && dep != 0);
    for (auto [v,w] : g[u]){
        if (v == p || deleted[v]) continue;
        single(v, u, (mask + mod[dep]* w) % M, dep+1);
    }
}

void complete_this_centroid(int cen){
    cnt.clear();
    cnt[0] = 1;
    sum = 0;

    single(cen, cen, 0, 0);

    for (auto [v,w] : g[cen]){
        if (deleted[v]) continue;
        add(v, cen, w, +1, 1);
    }

    // cout << "Current cen " << cen << " :" << endl;
    // printState();

    for (auto [v,w] : g[cen]){
        if (deleted[v]) continue;
        add(v, cen, w, -1, 1);
        query(v, cen, w, 1);
        add(v, cen, w, +1, 1);
    }

    // cout << "Cen " << cen << " " << sum << endl;

    ans += sum;
}



void decompose(int u, int p){
    calc_sub(u, p);
    int cen = centroid(u, p, sub[u]);

    complete_this_centroid(cen);
    deleted[cen] = 1;

    for (auto [v,w] : g[cen]){
        if(!deleted[v])
            decompose(v, v);
    }
}

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll modINV(ll a, ll m){
    ll x, y;
    ll g = gcd(a, m, x, y);
    assert(g == 1);
    x = (x % m + m) % m;
    return x;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> M; 


    g.assign(n+1, vector<PII>());

    for (int i = 1; i <= n - 1; i++){
        int a, b, dig;
        cin >> a >> b >> dig;
        dig %= M;
        g[a].push_back({b, dig});
        g[b].push_back({a, dig});
    }    


    mod[0] = inv[0] = 1;
    inv[1] = modINV(10, M);

    // cout << "modinv here " << inv[1] << endl;

    for (int i = 1; i < N; i++) mod[i] = (mod[i-1] * 10) % M;
    for (int i = 2; i < N; i++) inv[i] = (inv[i-1] * inv[1]) % M;


    // cout << "INV " << inv[1] << endl;
    
    decompose(0, -1);

    cout << ans << endl;
    return 0;
}