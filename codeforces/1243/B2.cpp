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

int const N = 2e6 + 5;
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

int main(){

	ios::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s,t;
		cin >> s >> t;

		vector < PII > ans;

		bool nai = 0;
		for(int i = 0; i < n; i++){
			
			int nxt = next_pos(t,i,s[i]);
			if(nxt == -1) {
				nxt = next_pos(s,i+1,s[i]);
				if(nxt == -1){
					nai = 1;
					continue;
				}
				else {
					swap(t[i],s[nxt]);
					ans.push_back({nxt+1,i+1});
					
					//t[] = s[]
				}
			}
			else{
				t[nxt] = t[i] ;
				ans.push_back({i+1,i+1});
				ans.push_back({i+1,nxt+1});
			}
			
		}
		if(nai) {
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		cout << ans.size() << '\n';

		for(auto x : ans){
			cout << x.first << " " << x.second << '\n';
		}
	}

	return 0;
}
