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

int n;
map<PII,bool> has;
int cnt;

vector<int> Q(int cur){
	cout << "? " << cur << endl;
	vector<int> dist(n+1,0);
	cnt++;
	assert(cnt <= (n+1)/2);
	for (int i = 1; i <= n; i++) cin >> dist[i];
	return dist;
}
void solve(){
	cin >> n;
	vector<int> dr = Q(1);	
	int mx = *max_element(all(dr));
	vector<vector<int>> layers(n+3);

	int cnt[2] = {0,0};
	for (int i = 1; i <= n; i++){
		layers[dr[i]].push_back(i);
		if (dr[i] == 1){
			has[{1,i}] = 1;
		}
	}
	for (int i = 1; i <= n; i++){
		cnt[i&1] += layers[i].size();
	}
	int st = 1;
	if (cnt[0] < cnt[1]) st = 2;
	for (int i = st; i <= n; i += 2){
		if (has.size() >= n-1) break;

		for (auto v : layers[i]){
			vector<int> d = Q(v);
			for (int i = 1; i <= n; i++){
				if (d[i] == 1){
					int x = i, y = v;
					if (x > y) swap(x, y);
					if (!has.count({x,y})){
						has[{x,y}] = 1;
					}
				}
			}
		}
	}

	assert(has.size() + 1 == n);

	cout << "!" << endl;

	for (auto [k, v] : has){
		cout << k.first << " " << k.second << endl;
	}
}
int main(){

	int t = 1;
	while (t--) solve();
	
	return 0;
}
