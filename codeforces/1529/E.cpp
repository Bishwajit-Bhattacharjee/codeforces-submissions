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


const int N = 3e5 + 10;
int n;
vector<vector<int>>g1, g2;
int timer = 0, in[N], out[N], mp[N];

void K(int u){
	in[u] = ++timer;
	mp[in[u]] = u;
	for (auto v : g2[u]) K(v);
	out[u] = timer;
}

int mx;

set<int> st;

bool is_ancestor(int u, int p){
	return in[p] <= in[u] && out[u] <= out[p];
}

void S(int u){
	// add u
	int undo = -1;

	auto it = st.lower_bound(in[u]);

	if (it == st.begin()) {
		st.insert(in[u]);
	}
	else {
		auto pit = prev(it);
		if (is_ancestor(u, mp[*pit])){
			undo = *pit;
			st.erase(pit);
			st.insert(in[u]);
		}
		else if (it == st.end() || !is_ancestor(mp[*it], u)){
			st.insert(in[u]);
		}
		else {
		}
	}

	mx = max(mx, (int)st.size());
	for (auto v: g1[u]) S(v);

	st.erase(in[u]);
	if (undo != -1) st.insert(undo);
}

void solve(){
	timer = mx = 0;
	assert(st.empty());
	cin >> n;
	g1.assign(n+1, vector<int>());
	g2.assign(n+1, vector<int>());

	for (int i = 2; i <= n; i++){
		int p;
		cin >> p;
		g1[p].push_back(i);
	}
	for (int i = 2; i <= n; i++){
		int p;
		cin >> p;
		g2[p].push_back(i);
	}

	K(1);
	S(1);
	cout << mx << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
