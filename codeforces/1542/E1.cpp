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
ll mod;

inline void add(int &a, int b){
	a += b;
	if (a >= mod) a -= mod;
}

int const N = 52;
int const offset = 3000;
int const INV = N*N;
int f[N][INV], s[N][INV];
int lexSmlThis[N];
int n;


void solve(){
	cin >> n >> mod;

	f[1][0] = 1;

	for (int l = 2; l <= n; l++){
		for (int inv = 0; inv <= l*(l-1)/2; inv++){
			for (int k = 0; k < l; k++) {
				if (inv >= k) add(f[l][inv], f[l-1][inv-k]);
			}
		}
	}
	for (int l = 1; l <= n; l++){
		for (int inv = 0; inv <= l*(l-1)/2; inv++){
			add(s[l][inv], ((inv?s[l][inv-1]:0) + f[l][inv]) % mod);
		}
	}

	// for (int i = 1; i <= n; i++){
	// 	for (int inv = 0; inv <= i*(i-1)/2; inv++){
	// 		cout << i << " " << inv << " " << s[i][inv] << endl;
	// 	}
	// }

	for (int l = 1; l <= n; l++){
		int MX_INV = l*(l-1)/2;
		for (int i = 1; i <= l; i++){
			for (int j = i + 1; j <= l; j++){
				for (int p_inv = 0; p_inv <= (l-1)*(l-2)/2; p_inv++){
					if (p_inv + (i - j) >= 1){
						add(lexSmlThis[l], 
						1LL * s[l-1][p_inv+i-j-1] * f[l-1][p_inv] %mod);
					}
				}
			}
		}
	}
	vector<int> ans(n+1, 0);
	for (int i = 1; i <= n; i++){
		// cout << i << " " << lexSmlThis[i] << endl;
		ans[i] = (1LL* ans[i-1]*i + lexSmlThis[i]) % mod;
	}
	cout << ans[n] << "\n";
		
}
int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	int t = 1;
	while (t--) solve();
	
	return 0;
}
