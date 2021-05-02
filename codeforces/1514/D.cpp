#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

double INF = 1e100;
double EPS = 1e-12;
typedef long long int ll;

typedef pair < int,int > PII;
typedef pair < ll,ll > PLL;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define F first
#define S second
#define all(v) (v).begin(),(v).end()

ostream& operator<<(ostream & os, PLL h){
	return os << "( " << h.F << ", " << h.S << " )" << endl;

}
PLL operator+ (PLL a, ll x)     {return {a.F + x, a.S + x} ;}
PLL operator- (PLL a, ll x)     {return {a.F - x, a.S - x} ;}
PLL operator* (PLL a, ll x)     {return {a.F * x, a.S * x} ;}
PLL operator+(PLL x, PLL y) { return {x.F + y.F,x.S + y.S} ;}
PLL operator-(PLL x,PLL y) { return {x.F - y.F, x.S - y.S} ;}
PLL operator*(PLL x,PLL y) { return {x.F * y.F , x.S * y.S} ;}
PLL operator%(PLL x,PLL y) { return {x.F % y.F, x.S % y.S} ;}


ll const MOD = 1e9 + 7;

ll bigmod(ll a, ll b){
	if(!b) return 1;
	ll x  = bigmod(a,b/2);

	x = (x * x)%MOD;
	if(b&1)
		x = (x * a) %MOD;
	return x;
}
int const N = 4e5;
const int BLOCK = 320;


vector<int> g[N];

vector<int> v;


struct Query{
    int l, r, id;
    Query(int _l, int _r, int _id): l(_l), r(_r), id(_id){}
    Query(){}

    bool operator<(const Query& rhs) const {
        return PII(l/BLOCK, r) < PII(rhs.l/BLOCK, rhs.r);
    }
};

vector<Query> Q;
int f[N], ff[N];
int l = 0, r = -1;
int maxi = 0;

void add(int x){
    int val = v[x];
    if (ff[f[val]]) ff[f[val]]--;
    f[val]++;
    ff[f[val]]++;

    maxi = max(maxi, f[v[x]]);
}

void remove(int x){
    if (ff[f[v[x]]]) ff[f[v[x]]]--;
    f[v[x]]--;
    ff[f[v[x]]]++;
    
    while (maxi && !ff[maxi]) maxi--;

}

int get_ans(int l, int r){
    int cnt = 30;
    ll cc = maxi;
    bool sad = 0;

    // cout << l << " " << r << " " << maxi << endl;

    // cout << "DBD " <<  val << " " << cc << endl;
    if ( (r - l + 2) / 2 < cc) {
        sad = 1; 
    }
    if (!sad) return 1;
    // cout << "sad " << endl;
 
    ll good = r - l + 1 - cc;
 
    ll ans = max(cc - good, 1LL);
 
    return ans;

}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);

    int n, q;
    cin >> n >> q;
    v.resize(n);

    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v[i] = tmp;
        g[tmp].push_back(i);
    }

    Q.resize(q);

    for (int i = 0; i < q; i++){
        cin >> Q[i].l >> Q[i].r;
        Q[i].l--, Q[i].r--;
        Q[i].id = i;
    }
    sort(all(Q));
    vector<int> ans(q);

    for (auto q: Q){
        while (l > q.l) add(--l);
        while (r < q.r) add(++r);
        while (l < q.l) remove(l++);
        while (r > q.r) remove(r--);
        ans[q.id] = get_ans(l,r);
    }

    for (auto x : ans) cout << x << "\n";

	return 0;
}
