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
int const N = 2e5 + 10;

vector<ll> g[N], cum[N];


void solve(){
	int n;
	cin >> n;
	for (int i = 0; i <= n + 5; i++) g[i].clear(), cum[i].clear();

	vector<ll> u(n), s(n);

	for (auto &x : u) cin >> x;
	for (auto &x : s) cin >> x;

	for (int i = 0; i < n; i++) g[u[i]].push_back(s[i]);

	for (int i = 0; i < N; i++){
		if (g[i].size()) {
			cum[i].push_back(0);

			sort(all(g[i]), greater<ll>());
			for (int j = 0; j < g[i].size(); j++){
				cum[i].push_back(cum[i].back() + g[i][j]);
			}

			// cout << i << ": " << endl;
			// for (int j = 0; j < g[i].size(); j++){
			// 	cout << "(" << g[i][j] << " ," << cum[i][j+1] << "), ";
			// }
			// cout << endl;
		}
	}



	vector<ll> ans(n+1, 0);

	for (int i = 0; i <= n; i++){
		if (g[i].size()){
			for (int j = 1; j <= g[i].size(); j++){
				int sz = g[i].size();
				ans[j] += cum[i][sz/j* j];
			}
		}
	}

	for (int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
	cout << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
