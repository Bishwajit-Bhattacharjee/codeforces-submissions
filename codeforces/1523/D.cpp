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

int const N = 17;

ll F[(1<<N) + 10], a[(1<<N)+10];
int n, m, p;
ll get_ans(vector<string> &st, vector<int> &mp){
	memset(F, 0, sizeof F);
	int M = st[0].size();

	for (int i = 0; i < n; i++){
		int msk = 0;
		for (int j = 0; j < M; j++){
			if (st[i][j]=='1'){
				msk ^= (1<<j);
			}
		}
		F[msk]++;
	}

	for(int i = 0;i < M; ++i) {
		for(int mask = (1<<M) - 1; mask >= 0; --mask){
			if(!(mask & (1<<i)))
				F[mask] += F[mask^(1<<i)];
		}
	}

	ll msk = 0;

	for (int i = 0; i < (1 << M); i++){
		if (F[i] >= (n+1)/2){
			if (__builtin_popcount(i) > __builtin_popcount(msk)){
				msk = i;
			}	
		}
	}

	// cout << "here " << bitset<5>(msk) << endl;
	
	ll actual = 0;
	for (int i = 0; i < M; i++){
		if (msk & (1<<i)) actual ^= (1LL<<mp[i]);
	}
	return actual;
}

void solve(){
	cin >> n >> m >> p;
	vector<string> v(n);
	

	for (int i = 0; i < n; i++){
		cin >> v[i];
	}

	int trial = 60;
	ll ans = 0;
	while (trial--){
		int ind = uniform_int_distribution<int>(0, n-1)(rng);	
		vector<int> pos;
		for (int i = 0; i < m; i++){
			if(v[ind][i] == '1') {
				pos.push_back(i);
			}
		}
		vector<string> tmp(n, "");
		for (int i = 0; i < n; i++){
			for (auto x : pos){
				tmp[i] += v[i][x];
			}
		}

		// cout << endl;
		// for (int i = 0; i < n; i++){
		// 	cout << tmp[i] << endl;
		// }

		// cout << endl;

		// for (auto x : pos) cout << x << " ";
		// cout << endl;

		ll msk = get_ans(tmp, pos);

		if (__builtin_popcountll(msk) > __builtin_popcountll(ans)){
			// cout << ind << " " << msk << endl;
			ans = msk;
		}
	}

	for (int i = 0; i < m; i++){
		if (ans & (1LL<<i)){
			cout << "1";
		}
		else cout << "0";
	}
	cout << "\n";

}
int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	while (t--) solve();
	
	return 0;
}
