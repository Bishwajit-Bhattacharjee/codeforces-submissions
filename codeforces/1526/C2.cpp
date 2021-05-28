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

ll bit[N];

void update(int l, ll val){
	for (l ; l < N; l += (l & (-l))) {
		bit[l] += val;
	}
}

ll Q(int l){
	ll ret = 0;
	for (l ; l > 0; l -= (l & (-l))){
		ret += bit[l];
	}
	return ret;
}



void solve(){
	int n;
	cin >> n;
	vector<ll> v(n+1);
	vector<PLL> neg;
	set<int> pos;

	ll ans = 0;

	for (int i = 1; i <= n; i++){
		cin >> v[i];
		if (v[i] >= 0) {
			pos.insert(i);
			update(i, v[i]);
			ans++;
		}
		else {
			neg.emplace_back(v[i], i);
		}
	}

	sort(all(neg), [](PLL a, PLL b)-> bool {
		if (a.first == b.first) return a.second > b.second;
		return a.first > b.first;
	});


	// cout << "hello" << endl;

	for (auto [val, in] : neg){
		ll req = -val;
		if (Q(in) < req) continue;

		bool found = 0;
		int cur = in;

		while (req > 0){
			auto it = pos.lower_bound(cur);
			if (it == pos.begin()) break;
			it = prev(it);			
			ll komao = min(v[*it], req);
			v[*it] -= komao;
			update(*it, -komao);
			req -= komao;
			if (v[*it] == 0) {
				cur = *it;
				pos.erase(it);
			}
		}
		if (req > 0) break;
		else ans++;
	}

	cout << ans << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	while (t--) solve();
	
	return 0;
}
