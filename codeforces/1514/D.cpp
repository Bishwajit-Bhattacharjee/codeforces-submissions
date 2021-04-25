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

vector<int> g[N];

vector<int> v;

int many(int l, int r, int val){
    return upper_bound(all(g[val]), r) - upper_bound(all(g[val]), l-1);
}

int Q(int l, int r){
    int cnt = 30;
    bool sad = 0;
    ll cc = 0;
    while(cnt--){
        int x = uniform_int_distribution<int>(l,r)(rng);
        int val = v[x];
        cc = many(l, r, val);
        // cout << "DBD " <<  val << " " << cc << endl;
        if ( (r - l + 2) / 2 < cc) {
            sad = 1; break;
        }
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
    v.resize(n + 1);

    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v[i+1] = tmp;
        g[tmp].push_back(i+1);
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << Q(l, r) << '\n';
    }
	return 0;
}
