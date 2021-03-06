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
int const N = 3e5 + 10;

ll bigmod(ll a, ll b){
	if(!b) return 1;
	ll x  = bigmod(a,b/2);

	x = (x * x)%MOD;
	if(b&1)
		x = (x * a) %MOD;
	return x;
}
vector < bool > marks;
vector<int> pd[N];

void sieve(int n)
{
    marks.resize(n+10,0);
	marks[1] = 1;
	for(int i = 2; i < n; i++){
		if(!marks[i]){
			for (int j = i; j < n; j += i){
				pd[j].push_back(i);
				if (j != i) marks[j] = 1;				
			}
		}
	}
}
multiset <int> st[N];
map<PLL, int> how_much;

vector<PII> factor(int n){
	int _n = n;
	vector<PII> ret;
	for (auto x : pd[_n]){
		int cnt = 0;
		while (n % x == 0) n /= x, cnt++;
		ret.emplace_back(x, cnt);
	}
	return ret;
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	sieve(N);

	int n, q;
	cin >> n >> q;

	vector <int> a(n);
	for (auto &x : a) cin >> x;

	for (int i = 0; i < n; i++){
		vector<PII> tmp = factor(a[i]);

		for (auto [x, cnt] : tmp){
			st[x].insert(cnt);
			how_much[{i+1,x}] = cnt;
		}
	}

	ll g = 1;
	for (int i = 2; i < N; i++){
		if (st[i].size() == n){
			g = (g * bigmod(i, *st[i].begin())) % MOD;
		}
	}

	while(q--){
		int i, x;
		cin >> i >> x;
		vector <PII> tmp = factor(x);

		for(auto [p, cnt] : tmp){
			int mn = 0;
			if (st[p].size() == n){
				mn = *st[p].begin();
				// ll mul = bigmod(p, *st[p].begin());

				// mul = bigmod(mul, MOD - 2);
				// g = (g * mul) % MOD;
			}
			if (how_much.count({i,p})){
				int val = how_much[{i,p}];
				st[p].erase(st[p].find(val));
			}

			how_much[{i, p}] += cnt;
			st[p].insert(how_much[{i, p}]);
			
			if (st[p].size() == n){
				g = (g * bigmod(p, *st[p].begin() - mn)) % MOD;
			}
		}

		cout << g << '\n';
	}

	return 0;
}
