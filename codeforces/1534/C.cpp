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

int const N = 8e5 + 10;
int par[3*N];

int Find(int u){
	return par[u] = (u == par[u])? u : Find(par[u]);
}

void Union(int u, int v){
	int U = Find(u), V = Find(v);
	if (U != V) par[U] = V;
}
int perm[2][N], pos[2][N];

void solve(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> perm[0][i];
		pos[0][perm[0][i]] = i;
	}	

	for (int i = 1; i <= n; i++){
		cin >> perm[1][i];
		pos[1][perm[1][i]] = i;
	}	

	for (int i = 1; i <= n; i++){
		par[i] = i;
		par[n+i] = i;
	}

	for (int i = 1; i <= n; i++){
		int c1 = perm[0][i];
		int c2 = perm[1][i] + n;
		Union(c1, c2);
	}
	set <int> s;
	for (int i = 1; i <= n; i++){
		s.insert(Find(i));
		s.insert(Find(n+i));
	}
	ll ans = 1LL;
	for (int i = 1; i <= s.size(); i++){
		ans = (ans * 2LL) % MOD;
	}
	cout << ans << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
