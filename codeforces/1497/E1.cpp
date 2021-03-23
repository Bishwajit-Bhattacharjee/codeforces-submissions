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


int const MX = 1e7 + 10;
vector < ll > primes;

vector < bool > marks;
int virtual_value[MX];

void sieve(){

    for (int i = 1; i < MX; i++) virtual_value[i] = i;

    marks.resize(1e5 + 10, 0);

    for (ll i = 2; 1LL*i*i < MX; i++){
        if (!marks[i]){

            for (int j = i; j < MX; j += i){
                if (j != i && 1LL * j * j < MX) marks[j] = 1;
                while (virtual_value[j] % (i*i) == 0) 
                    virtual_value[j] /= (i*i);
            }
        }
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 1; i <= n; i++){
        cin >> a[i-1];
        // cout << "map " << a[i-1];
        a[i-1] = virtual_value[a[i-1]];
        // cout << " " << a[i-1] << endl;
    }
    int ans = 1;
    map <int, bool> has;

    for (int i = 0; i < n; i++){
        // cout << a[i] << " : " << endl;
        // for (auto x : msk) cout << x << " ";
        // cout << endl;
        int msk = a[i];
        if (has.count(msk)){
            ans++;
            has.clear();
        }
        has[msk] = 1;
    }
    cout << ans << '\n';
}

int main(){    
	ios::sync_with_stdio(false); cin.tie(0);
    sieve();

    // cout << "here" << endl;
    int t;
    cin >> t;
    while(t--) solve();
    // vector<int> tmp = factoring(18);
    // for (auto x : tmp) cout << x << " ";

	return 0;
}
