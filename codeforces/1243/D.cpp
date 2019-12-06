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


ostream& operator<<(ostream & os, PLL h)
{
	return os << "( " << h.F << ", " << h.S << " )" << endl;

}
PLL operator+ (PLL a, ll x)     {return {a.F + x, a.S + x} ;}
PLL operator- (PLL a, ll x)     {return {a.F - x, a.S - x} ;}
PLL operator* (PLL a, ll x)     {return {a.F * x, a.S * x} ;}
PLL operator+(PLL x, PLL y) { return {x.F + y.F,x.S + y.S} ;}
PLL operator-(PLL x,PLL y) { return {x.F - y.F, x.S - y.S} ;}
PLL operator*(PLL x,PLL y) { return {x.F * y.F , x.S * y.S} ;}
PLL operator%(PLL x,PLL y) { return {x.F % y.F, x.S % y.S} ;}

//PLL base = {37,41};
PLL M = {1e9+21, 1e9+9};

int const N = 2e5 + 5;
int const LOG = 31;
ll const MOD = 998244353;

ll bigmod(ll a, ll b)
{
	if(!b) return 1;
	ll x  = bigmod(a,b/2);

	x = (x * x)%MOD;
	if(b&1)
		x = (x * a) %MOD;
	return x;
}

ll inv(ll x)
{
	return bigmod(x%MOD,MOD-2);
}
vector < ll > primes;
vector < bool > marks(N+1,0);

void sieve()
{
	marks[1] = 1;
	for(int i = 2; i < N; i++){
		if(!marks[i]){
			for(int j = 2*i; j < N; j += i){
				marks[j] = 1;
			}
			primes.push_back(i);
		}
	}
}

int next_pos(string &str, int st, char ch)
{
	if(st >= str.size()) return -1;

	for(int i = st; i < str.size(); i++){
		if(str[i] == ch) return i;
	}
	return -1;
}

set < int > g[N];

int main(){

	ios::sync_with_stdio(false); cin.tie(0);

	int n,m;
	cin >> n >> m;

	for(int i = 1; i <= m; i++){
		int a,b;
		cin >> a >> b;
		g[a].insert(b);
		g[b].insert(a);
	}

	set < int > alive;

	for(int i = 2; i <= n; i++) alive.insert(i);

	queue < int > q;
	//q.push(1);
	vector < bool > vis(n+1,0);

	int cnt = 0;

	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		q.push(i);
		alive.erase(i);

		while(!q.empty()){
			int f = q.front();
			vis[f] = 1;
			q.pop();
			for(auto it = alive.begin(); it != alive.end(); ){

				if((*it) != f and g[f].find(*it) == g[f].end()){
					q.push(*it);
					it = alive.erase(it);
					cnt++;
				}
				else it++;
			}
		}
	}
	cout << n - 1 - cnt << endl;

	return 0;
}
