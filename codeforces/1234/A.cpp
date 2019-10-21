#include <bits/stdc++.h>
using namespace std;
#define lc(l) 2(l)
#define rc(l) 2(l) + 1
typedef long long int ll;
int const N = 2e5 + 20;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll tot = 0;

		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			tot += x;
		}
		cout << (tot + n - 1) / n << endl;

	}
	
    return 0;
}
