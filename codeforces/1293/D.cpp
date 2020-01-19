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

ll lim = 4e16 + 100;

vector < PLL > pts;

ll x0,_y0,ax,bx,ay,by;

void gen()
{
	pts.push_back({x0,_y0});

	for(int i = 1; ;i++){
		PLL last = pts.back();
		ll x = last.F*ax + bx;
		ll y = last.S*ay + by;

		if(x >= lim or y >= lim){
			return ;
		}
		pts.push_back({x,y});
	}
}


int main(){

	ios::sync_with_stdio(false); cin.tie(0);

	cin >> x0 >> _y0 >> ax >> ay >> bx >> by;

	gen();

	ll x,y,_t;
	cin >> x >> y >> _t;

	ll ans = 0;


	for(int i = (int)pts.size() - 1; i >= 0; i--){
		ll can = 0;
		ll rt = abs(x - pts[i].F) + abs(y-pts[i].S);
		ll t = _t;
		vector < PLL > npts;

		for(int x = i ; x >= 0; x--)
			npts.push_back(pts[x]);
		
		for(int x = i  + 1; x < pts.size(); x++) 
			npts.push_back(pts[x]);
		

		if(rt <= t){
			can++;
			t -= rt;
			int j = 0;	
			while(j + 1 < npts.size()){
				rt = abs(npts[j].F - npts[j+1].F) + abs(npts[j].S - npts[j+1].S);

				//cout <<i << " " <<  can << " " << j << " " << rt <<  endl;

				if(rt > t){
					break;
				}
				j++;
				t -= rt;
				can++;
			}

			//cout << can << " " << i << " " << pts[i].F << " " << pts[i].S <<  endl;
			ans = max(ans,can);


		}
		else 
			continue;
	}

	cout << ans << endl;

	return 0;
}
