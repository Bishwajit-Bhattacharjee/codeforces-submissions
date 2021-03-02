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
less<ll>,
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

ll ans(vector <ll> &a, vector<ll> &b){

	// cout << "a : ";
	// for (auto x : a) cout << x << " ";
	// cout << endl;
	// cout << "b : ";
	// for (auto x : b) cout << x << " ";
	// cout << endl;
	ordered_set ost, eql;
	ll cnt = 0;

	map<ll, int> a_has;
	for (auto x : a) a_has[x] = 1;

	for (auto x : b) {
		if (a_has[x] > 0) eql.insert(x);
	}


	for (int i = 0; i < b.size(); i++){
		ost.insert(b[i]);
		ll choto = upper_bound(all(a), b[i]) - a.begin();
		ll can = 0;
		if (choto > 0){
			can = (int)ost.size() - (int)ost.order_of_key(b[i] - choto + 1)
				+ (int)eql.size() - (int)eql.order_of_key(b[i] + 1);
		}
		cnt = max(cnt, can);
	}

	// cout << "ret " << cnt << endl;
	return cnt;
} 

void solve(){

	int n, m;
	cin >> n >> m;
	vector <ll> a(n), b(m);

	vector<ll> x[2], y[2];

	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	for (auto val : a){
		x[val > 0].push_back(abs(val));
	}
	for (auto val : b){
		y[val > 0].push_back(abs(val));
	}
	reverse(all(x[0]));
	reverse(all(y[0]));

	cout << ans(x[0], y[0]) + ans(x[1], y[1]) << "\n";

}
int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
