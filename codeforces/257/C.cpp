#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;

int main() {
	// your code goes here
	vector < double > a;
	int n;
	cin >> n;
	for(int i = 0 ; i < n; i++){
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		double tmp = atan2(t2, t1) * 180 / PI;tmp = (tmp < 0)?tmp + 360: tmp; 
	 // 	cout << tmp << endl;
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	double ans = a[n-1] - a[0];
	for(int i  = 0 ; i < n - 1 ; i++){
		ans = min(ans , 360 - a[i+1] + a[i]);
	}
	cout << setprecision(10) <<ans << endl;
	return 0;
}