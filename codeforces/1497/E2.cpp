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
int virtual_value[MX], cnt[MX];

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
    vector<int> a(n+1);

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = virtual_value[a[i]];
    }


    vector<vector<int>> left(k+1, vector<int> (n+1, n+1));
    vector<vector<int>> dp(k+1, vector<int> (n+1, n+1));

    for (int j = 0; j <= k; j++){
        for (int i = 1; i <= n; i++) cnt[a[i]] = 0;
        int conf = 0, l = 1;

        // cout << j << " : " << endl;
        for (int i = 1; i <= n; i++){
            left[j][i] = i;
            cnt[a[i]]++;
            if (cnt[a[i]] > 1) conf++;

            while (l < i && conf > j){
                if(l){
                    cnt[a[l]]--;
                    if (cnt[a[l]] > 0) conf--;
                }
                l++;
            }
            left[j][i] = l;

            // cout << "(" << i << ", " << left[j][i] << "), "; 
        }
        // cout << endl;
    }

    for (int i = 0; i <= k; i++) dp[i][0] = 0;

    for (int j = 0; j <= k; j++){


        for (int i = 1; i <= n; i++){
            for (int bame = 0; bame <= j; bame++){
                int l = left[j-bame][i];
                dp[j][i] = min(dp[j][i], 1 + dp[bame][l-1]);
            }
        }
    }

    cout << dp[k][n] << "\n";
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
