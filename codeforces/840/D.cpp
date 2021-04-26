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
// to generate a uniform random integer over a range (l,r), use 
// int x = uniform_int_distribution<int>(l,r)(rng);

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

const int block_size = 320; 

struct Query
{
    ll l, r, id, k;
    Query(){}
    Query(int _l, int rr, int _id, ll _k):l(_l), r(rr), id(_id),k(_k) {

    }
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

int const N = 3e5 + 10;
vector<int> g[N];
int a[N];

// void solve(){
// 	int n, q;
// 	cin >> n >> q;

// 	for (int i = 0; i < n; i++) cin >> a[i], g[a[i]].push_back(i);

// 	while (q--){
// 		int l, r, k;
// 		cin >> l >> r >> k;
// 		l--, r--;

// 		int ans = 1e9;
// 		int cnt = 55;
// 		while (cnt--){
// 			int cur_ind = uniform_int_distribution<int>(l,r)(rng);
// 			int cur_val = a[cur_ind];
// 			if (ans < cur_val) continue;
// 			int cnt = upper_bound(all(g[cur_val]), r) - lower_bound(all(g[cur_val]), l);
// 			if (1LL * cnt * k > (r-l+1)) {
// 				ans = min(ans, cur_val);
// 			}
// 		}
// 		if (ans > n) {
// 			ans = -1;
// 		}
// 		cout << ans << '\n';
// 	}
// }
int cnt[N];


void add(int x){
	cnt[a[x]]++;
}

void remove(int x){
	cnt[a[x]]--;
}
int n, t;

ll get_ans(int l, int r, ll k){
	int itr = 100;
	int ans = 1e9;

	// cout << PLL(l, r) << " " << cnt[1] << " " << cnt[2] << endl; 

	while (itr--){
		int x = uniform_int_distribution<int>(l,r)(rng);
		if (cnt[a[x]] * k > (r - l + 1)) {
			ans = min(ans, a[x]);
		}
	}
	if (ans > n) ans = -1;
	return ans;
}


int l = 0, r = -1;

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> t;

	for (int i = 0; i < n; i++) cin >> a[i];

	vector<Query> Q(t);
	vector<ll> ans(t);

    for (int i = 0; i < t; i++){
        int l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        Q[i] = Query(l, r, i, k);
    }

    sort(Q.begin(), Q.end());


    for (auto q: Q)
    {
        while (l > q.l)
            add(--l);
        while (r < q.r)
            add(++r);
        while (l < q.l)
            remove(l++);
        while (r > q.r)
            remove(r--);
        ans[q.id] = get_ans(q.l, q.r, q.k);
    }

    for (auto x : ans) cout << x << "\n";
	return 0;
}
