#include <bits/stdc++.h>
using namespace std;
#define  ll  long long int
int main(){
	ll b, m  ;
	cin >> m >> b;
	ll ans = 0LL;
	for(ll x = 0; x <= b *m ; x++){
		if(x % m  == 0){
			ll tmp = x *(-1) / m;
			if(tmp + b >= 0){
			  ll y = tmp + b;
			  ll t1 , t2;
			  t1 = x * (x + 1); t1 /= 2; t1 *= y + 1; t2 = y * (y + 1); t2 /= 2; t2 *= x + 1;
			  ans = max(ans , t1 + t2);
			}
		}
	}
	cout << ans ;
}