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

vector < ll > primes;
vector < bool > marks;
int const N = 1e6 + 10;
vector <int> pds[N];

void sieve(int n)
{
    marks.resize(n+10,0);
	marks[1] = 1;
	for(int i = 2; i < n; i++){
		if(!marks[i]){
			for(int j = 2*i; j < n; j += i){
				marks[j] = 1;
                pds[j].push_back(i);
			}
            pds[i].push_back(i);
			primes.push_back(i);
		}
	}
}
vector <PII> mask(int n) {
    vector <PII> ret;

    for (auto p : pds[n]) {
        int cnt = 0;
        while(n % p == 0) cnt++, n /= p;
        if (cnt & 1) ret.push_back({p, 1});
    }
    return ret;
}
void solve(){
    int n;
    cin >> n;
    vector <int> v(n);
    vector < int > ans;

    for(auto &x : v) {
        cin >> x;
    }

    map < vector<PII>, int > cnt;

    for (auto &x : v){
        vector <PII> ret = mask(x);
        cnt[ret]++;
    }
   
    int res = 0;
    for (auto &[x, y]: cnt) {
        res = max(res, y);
    }
    ans.push_back(res);

    while (true){

        map < vector<PII>, int > t_cnt;

        bool change = 0;

        for (auto it = cnt.begin(); it != cnt.end();) {
            if (it->first.size() and it->second % 2 == 0) {
                change = 1;
                cnt[vector<PII>()] += it->second;
                it = cnt.erase(it);
            }
            else it++;
        }

        // for (auto [vec, c] : cnt) {
        //     if (vec.size() and c % 2 == 0) {
        //         t_cnt[ vector<PII>()] += c;
        //         change = 1;
        //     }
        //     else t_cnt[vec] += c;
        // }

        // cnt = t_cnt;

        int res = 0;
        for (auto &[x, y]: cnt) {
            res = max(res, y);
        }
        ans.push_back(res);

        if (!change) break;

    }

    int q;
    cin >> q;
    while (q--) {
        ll w;
        cin >> w;
        if (ans.size() == 0) cout << "-1\n";

        if (w >= ans.size()) cout << ans.back() << "\n";
        else cout << ans[w] << "\n";

    }    
}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);
    sieve(N);

    int t;
    cin >> t;
    while(t--)
        solve();
	return 0;
}
