#include <bits/stdc++.h>
using namespace std;

double INF = 1e100;
double EPS = 1e-12;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		ll a, b, n;
		cin >> a >> b >> n;

		if(n % 3 == 0) {
			cout << a << "\n";
		}
		else if(n % 3 == 1){
			cout << b << "\n";
		}
		else 
			cout << (a ^ b) << "\n";
	}
    return 0;
}