#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

bool const DEBUG = 0;
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
vector<PII> g[N] ;
int outdeg[N] ;

PLL B = {1e9 + 7,43};
PLL M = {1e9 + 21, 1e9 + 9};

PLL mat[20][20] ;
vector < PLL > P(N);
PLL target;
int n, m, k;
int ans;

void recur(int pos, vector<int> &perm){
    if(pos == k + 1){
        PLL tmp = {0,0};
        assert(perm.size() == k);
        for(int i = 0; i < perm.size(); i++){
            tmp = (tmp + mat[i+1][perm[i]]) % M;
        }
        if(tmp == target) ans++;
        return;
    }

    for(int i = 1; i <= pos; i++){
        perm.push_back(i);
        recur(pos+1,perm);
        perm.pop_back();
    }

}

int main(){

	ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m >> k;

    P[0] = {1,1};

    for(int i = 1; i <= n + 1; i++) P[i] = (P[i-1] * B) % M;

    for(int i = 0; i < m; i++){
        int a,b,e;
        cin >> a >> b >> e;
        g[a].push_back({b,e});
        outdeg[a]++;
    }

    for(int i = 0; i <= n; i++) {
        sort(g[i].begin(), g[i].end(),
            [&](PII a, PII b)->bool {
                if(a.second == b.second){
                    return a.first < b.first;
                }
                else
                    return a.second < b.second;
             });
    }

    for(int i = 0; i < 20 ; i++){
        for(int j = 0; j < 20; j++){
            mat[i][j] = {0,0};
        }
    }

    for(int i = 1; i <= n; i++){
        int out = outdeg[i] ;
        for(int j = 1; j <= out; j++){
            mat[out][j] = (mat[out][j] + P[g[i][j-1].first]) % M;
        }
    }

    target = {0,0} ;

    for(int i = 1; i <= n; i++){
        target = (target + P[i]) % M;
    }
    vector<int> p;
    recur(1,p);

    cout << ans << endl;

	return 0;
}

