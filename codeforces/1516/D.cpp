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

vector < ll > primes;
vector < bool > marks;
int const N = 2e5;
vector<int> pd[N];

void sieve(int n)
{
    marks.resize(n+10,0);
	marks[1] = 1;
	
	for(int i = 2; i < n; i++){
		if(!marks[i]){
			for (int j = i; j < n; j += i){
				pd[j].push_back(i);
				if (i != j) marks[j] = 1;
			}

		}
	}
}

int go[N];
int const LOG = 18;
int dp[LOG][N];
vector<int> g[N];


int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	sieve(N);

	int n, q;
	cin >> n >> q;

	vector<int> v(n+1);

	for (int i = 0; i < n; i++){
		cin >> v[i+1];
	}
	go[n+1] = n+1;

	for (int i = n; i >= 1; i--){
		go[i] = n + 1;
		if (i != n){
			for (auto p : pd[v[i]]){
				if (g[p].size()){
					go[i] = min(go[i], g[p].back());
				}
			}
		}
		go[i] = min(go[i], go[i+1]);

		for (auto p : pd[v[i]]) g[p].push_back(i);
	}	

	for (int i = 0; i < LOG; i++){
		for (int j = 1; j <= n+1; j++){
			if (i == 0) dp[i][j] = go[j];
			else {
				dp[i][j] = dp[i-1][dp[i-1][j]];
			}
		}
	}

	while (q--){
		int l, r;
		cin >> l >> r;

		int ans = 0;
		int cur = l;
		for (int i = LOG - 1 ; i >= 0; i--){
			if (dp[i][cur] <= r) {
				ans += (1LL<<i);
				cur = dp[i][cur];
			}
		}

		cout << ans + 1 << '\n';
	}

	return 0;
}
