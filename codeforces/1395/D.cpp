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
int main(){

	ios::sync_with_stdio(false); cin.tie(0);
    ll n, m , d;
    cin >> n >> d >> m;
    vector<ll> beshi, kom;
    beshi.push_back(0);

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if(tmp > m ) beshi.push_back(tmp);
        else kom.push_back(tmp);
    }

    sort(beshi.begin()+1,beshi.end(), greater<ll>());
    sort(kom.begin(), kom.end());

    if(DEBUG)cout << beshi.size() << " " << kom.size() << endl;

    vector<ll>pref_kom(kom.size()+1,0), pref_beshi(beshi.size(),0);

    for(int i = 1; i < pref_kom.size(); i++){
        pref_kom[i] = pref_kom[i-1] + kom[i-1];
    }

    for(int i = 0; i < pref_beshi.size(); i++){
        if(i)
            pref_beshi[i] = pref_beshi[i-1] + beshi[i];
    }

    ll ans = 0, can;

    for(int beshi_taken = 0; beshi_taken < beshi.size(); beshi_taken++){
        can = 0;
        ll waste_count = max(0LL,(beshi_taken-1)*d);
        waste_count -= ((ll)beshi.size() - 1 - beshi_taken);
        if(waste_count < 0) waste_count = 0;
        if(waste_count > kom.size()) continue;

        can = pref_beshi[beshi_taken] + pref_kom.back() - pref_kom[waste_count];
        if(DEBUG){
            cout << pref_beshi[beshi_taken] << endl;
            if(can > ans ) {
                cout << "beshi_taken " << beshi_taken << " " << can << " " << ans << endl;
            }
        }

        ans = max(ans, can);
    }
    cout << ans << endl;
	return 0;
}
