
#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const up =   1e6 + 10 ;
int  const array_size = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const mod = 10000007;
using namespace std;

//global variables



 // global variables  end here

 // functions begin here


 // functions end
int cnt[5];

int main()
{

	int n ,a , i;
	//sc(n);
	cin >> n;
	for(int i = 0 ; i < n ; i++) {
		//sc(a);
		cin >> a;
		cnt[a]++;
	}

	int ans = cnt[4];
	ans += cnt[3];
	cnt[1] = max(cnt[1] - cnt[3] , 0 );
	ans += cnt[2]/2;
	int r = cnt[2]%2;
	if( r ) {
		ans ++;
		cnt[1] = max(0,cnt[1] - 2);
	}

	if( cnt[1] ) {
		if( cnt[1]%4 == 0) ans += cnt[1] / 4;
		else ans += cnt[1] / 4 + 1;
	}

	printf("%d\n" ,ans );

	return 0;
}
