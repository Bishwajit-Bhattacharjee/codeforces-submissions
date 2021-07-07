#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

double INF = 1e100;
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

int const N = 100;
int const offset = 100;

const double EPS = 1e-9;
double dp[5*N+offset][5*N+offset];
double c, m, p, v;
double dp1[5*N+offset];


double e(double pr){
	double other = 1 - pr;
	if (other < v + EPS){
		return 1 + other;
	}
	return 1 + other * e(pr + v);
}

double DP(int oc, int mc){
	
	double tc = c + v/2 * oc;
	double tm = m + v/2 * mc;
	double tp = 1 - tc - tm;

	// cout << tc << " " << tm << " " << tp << endl;

	assert(oc + offset >= 0 && oc < N && mc < N && mc + offset >= 0);

	double &r = dp[oc+offset][mc+offset];
	if (r > -0.5) return r;

	r = 1;

	if (tc < v + EPS){
		r +=  tc * e(tp + tc/2);
	}
	else {
		r +=  tc * DP(oc - 2, mc + 1);
	}
	if (tm < v + EPS){
		r +=  tm * e(tp + tm/2);
	}
	else {
		r += tm * DP(oc + 1, mc - 2);
	}

	// cout << "again " << tc << " " << tm << " " << tp << " " << r << endl;

	
	return r;
}

void solve(){
	cin >> c >> m >> p >> v;
	for (int i = 0; i < 5*N+offset; i++){
		for (int j = 0; j < 5*N+offset; j++){
			dp[i][j] = -1.0;
		}
	}
	// cout << dp[0][0] << endl;
	cout << fixed << setprecision(9) <<  DP(0, 0) << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	
	return 0;
}
