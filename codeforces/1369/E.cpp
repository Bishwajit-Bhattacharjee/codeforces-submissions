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

#define F first
#define S second


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
set < int > g[N];

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector< int > w(n+1);
	for(int i = 1; i <= n; i++) cin >> w[i];
	vector< PII > choice(m+1);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		choice[i+1] = {a,b};
		g[a].insert(i+1);
		g[b].insert(i+1);
	}
	set < int > left, good_items;
	for(int i = 1; i <= m; i++) left.insert(i);
	for(int i = 1 ; i <= n; i++)
		if(g[i].size() <= w[i]) good_items.insert(i);
	stack < int > order;
	vector < bool > taken(n + 1, 0);
	
	while(good_items.size() and left.size()){
		int u = *good_items.begin();
		// cout << "good items " << u << endl;
		taken[u] = 1;
		for(auto v : g[u]){
			order.push(v);
			left.erase(v);
			int er = ( choice[v].first == u ? choice[v].second : choice[v].first );
			g[er].erase(v);
			if(g[er].size() <= w[er] and !taken[er]) good_items.insert(er);
		}
		good_items.erase(u);
		g[u].clear();
		// cout << "left : ";
		// for(auto x : left) cout << x << " ";
		// cout << endl;
	}
	if(left.size()){
		cout << "DEAD\n";
	}
	else {
		cout << "ALIVE\n";
		while(order.size()) cout << order.top() << " ", order.pop();
		cout << '\n';
	}
	return 0;
}