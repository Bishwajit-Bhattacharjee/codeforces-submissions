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
using PCL = pair<char, ll>;
ll const M = 998244353;
ll const N = 502;
ll dp[N][N];

int n;
vector<PCL> ops;
ll ans, curPos;

ll DP(int pos, int sm){
	if (pos == n) return 1;	

	ll &r = dp[pos][sm];
	if (r != -1) return r;
	r = 0;
	
	if (pos == curPos){
		r = DP(pos+1, sm);
		return r;
	}

	r = DP(pos+1, sm);
	if (ops[pos].first == '+'){
		bool isSm = (ops[pos].second < ops[curPos].second || 
			(ops[pos].second == ops[curPos].second && pos < curPos)
		);
		r = (r + DP(pos+1, sm + isSm)) % M;
	}
	else {
		ll here = 0;
		if (sm <= 0) {
			if (pos < curPos) r = (r + DP(pos+1, 0)) % M;
		}
		else {
		    r = (r + DP(pos+1, sm-1)) % M;
		}
	}
	return r;
}

void solve(){
	cin >> n;
	for (int i = 0; i < n; i++){
		char ch;
		ll v;
		v = -1;
		cin >> ch;
		if (ch == '+') cin >> v;
		ops.push_back({ch, v});
	}
	// for (auto [c, v]: ops) cout << c << " " << v << endl;

	for (int i = 0; i < n; i++){
		if (ops[i].first == '-') continue;
		curPos = i;
		memset(dp, -1, sizeof dp);
		ll cnt = DP(0, 0);
		// cout << ops[curPos].second << " " << cnt << endl;
		ans = (ans + cnt * ops[curPos].second) % M;
	}
	cout << ans << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	while (t--) solve();
	
	return 0;
}
