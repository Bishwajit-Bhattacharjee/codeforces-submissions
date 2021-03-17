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

int LIM = 1e5 + 10;
int const MX = 1e7 + 10;
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
vector<int> factoring(int n){
    vector<int> ret;
    for (auto prime : primes){

        if (prime*1LL*prime > n) break;
        if (n % prime == 0) {
            int cnt = 0;
            while (n % prime == 0) cnt++, n /= prime;
            if (cnt & 1) ret.push_back(prime);
        }
    //     cout << "prime : " << prime << endl;
    }
    if (n != 1) ret.push_back(n);
    return ret;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 1; i <= n; i++){
        cin >> a[i-1];
    }
    int ans = 1;
    map <vector<int>, bool> has;

    for (int i = 0; i < n; i++){
        vector<int> msk = factoring(a[i]);
        // cout << a[i] << " : " << endl;
        // for (auto x : msk) cout << x << " ";
        // cout << endl;
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
    sieve(LIM);
    // cout << "here" << endl;
    int t;
    cin >> t;
    while(t--) solve();
    // vector<int> tmp = factoring(18);
    // for (auto x : tmp) cout << x << " ";

	return 0;
}
