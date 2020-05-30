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
ll h,c,t;

double can(ll itr)
{
	double cnt = (itr+1)/2 * h + (itr)/2 * c;
	ll diff = abs(cnt-itr*t);
	return fabs(cnt/itr - t);
	//return diff;
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
	
	int ts;
	cin >> ts;
	while(ts--){
		
		cin >> h >> c >> t;

		int itr = 1000;
		ll diff = 1e18;
		int st = -1;

		if(h+c >= 2 * t){
			cout << "2" << '\n';
			continue;
		}

		ll lo = (h-t)/(2*t-h-c);
		ll ans = lo;

		for(ll chk = max(lo-5,0LL); chk <= lo+5; chk++){
			if(can(2*chk+1) < can(ans*2+1)){
				ans = chk;
			}
		}

	
		//cout << diff << endl;
		cout << ans*2 + 1 << '\n';
		//cout << v << endl;
	}
	return 0;
}
// 973303 519683 866255
