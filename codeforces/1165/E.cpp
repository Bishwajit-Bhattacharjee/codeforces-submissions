#include <bits/stdc++.h>
using namespace std;
#define lc(l) 2(l)
#define rc(l) 2(l) + 1
typedef long long int ll;
int const N = 2e5 + 20;
typedef pair<ll,ll> PLL;

ll const MOD = 998244353;

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector < ll > a(n+1),b(n+1);

	for(int i = 1; i <= n; i++){
		cin >> a[i] ;
	}

	for(int i = 1; i <= n; i++) cin >> b[i] ;

	vector < PLL > cmp;

	for(int i = 1; i <= n; i++){
		cmp.push_back({a[i]*(i)*(n-i+1), i});
	}

	sort(cmp.begin(),cmp.end(), greater<PLL>());
	sort(b.begin()+1,b.end());

	vector < ll > nb(n+1);


	for(int i = 0; i < cmp.size(); i++){
		auto x = cmp[i] ;

		nb[x.second] = b[i+1] ;
	}

	ll ans = 0;


	for(ll i = 1; i <= n; i++){
		ans = (ans + a[i]*nb[i]%MOD*i%MOD*(n-i+1)%MOD) % MOD;
	}

	cout << ans << endl;
    return 0;
}
