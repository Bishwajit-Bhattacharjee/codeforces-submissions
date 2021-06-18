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

vector < ll > primes;
vector < bool > marks;

void sieve(int n)
{
    marks.resize(n+10,0);
	marks[1] = 1;
	for(int i = 2; i < n; i++){
		if(!marks[i]){
			for(int j = 2*i; j < n; j += i){
				marks[j] = 1;
			}
			primes.push_back(i);
		}
	}
}
int const N = 3e5 + 10, LOG = 20;
int A[N], C[N], par[LOG][N];


void solve(){
	int q, a0, c0;

	memset(par, -1, sizeof par);

	cin >> q >> A[0] >> C[0];

	for (int i = 1; i <= q; i++){
		int t;
		cin >> t;
		if (t == 1){
			int p, a, c;
			cin >> p >> A[i] >> C[i];
			par[0][i] = p;
			for (int lg = 1; lg < LOG; lg++){
				if (par[lg-1][i] != -1){
					par[lg][i] = par[lg-1][par[lg-1][i]];
				}
			}
		}
		else {
			int v, w;
			cin >> v >> w;
			int non_zero = v, par_cnt = 0;

			for (int lg = LOG-1; lg >= 0; lg--){
				if (A[par[lg][non_zero]] > 0){
					par_cnt += (1<<lg);
					non_zero = par[lg][non_zero];
				}
			}
			ll cost = 0, taken_amount = 0;
			int cur_h = par_cnt;
			while (w > 0 && cur_h >= 0){
				int node = v;
				for (int lg = LOG-1; lg >= 0; lg--){
					if (cur_h & (1<<lg)){
						node = par[lg][node];
					}
				}
				ll can_take = min(w, A[node]);
				A[node] -= can_take;
				w -= can_take;
				taken_amount += can_take;
				cost += can_take * C[node];
				cur_h--;
			}
			cout << taken_amount << " " << cost << endl;
		}
	}
	
}

int main(){

	// ios::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	while (t--) solve();
	
	return 0;
}
