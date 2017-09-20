#include <bits/stdc++.h>
#define lli     long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e9
#define EPS		1e-8
#define MAX		1000006
using namespace std;

string str[10000];
int n ,ans, m, tmp,cnt;
int main()
{
	scanf("%d",&n);

	for( int i =0; i < n; i++ ){
		cin>>str[i];
	}

	for( int  i= 0 ;i < 7; i++) {

		cnt=0;
		for( int j=0 ;j<n ; j++) {

			if( str[j][i]=='1') cnt++;
		}
		ans=max( ans, cnt);
	}

	printf("%d\n",ans);
	return 0;
}
