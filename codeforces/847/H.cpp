#include <bits/stdc++.h>
#define lli     long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e17
#define EPS		1e-8
#define MAX		1000006
using namespace std;

int n;
lli  ara[MAX], linc[MAX], rinc[MAX], lsum[MAX] ,rsum[MAX];
lli sum, cnt,ans=INF;

int main()
{
	scanf("%d",&n);

	for( int i =1; i<=n; i++ ) {

		scanf("%lld",&ara[i]);
	}

	for( int i =1; i<=n; i++ ) {

		linc[i] = max( ara[i], linc[i-1] +1);
		lsum[i] = (lsum[i-1] + linc[i] - ara[i]);
	}

	for( int i =n; i>=0; i-- ) {

		rinc[i] = max( ara[i], rinc[i+1] +1);
		rsum[i] = rsum[i+1] + rinc[i]- ara[i];
	}
//
//	for( int i = 1; i <=n ;i++) {
//
//		cout<<linc[i]<<" ";
//	}
//	cout<<endl;
//	for( int i = 1; i <=n ;i++) {
//
//		cout<<lsum[i]<<" ";
//	}
//	cout<<endl;
//	for( int i = 1; i <=n ;i++) {
//
//		cout<<rinc[i]<<" ";
//	}
//	cout<<endl;
//	for( int i = 1; i <=n ;i++) {
//
//		cout<<rsum[i]<<" ";
//	}

    for( int i = 1; i<=n ;i++ ) {

        if( linc[i] > rinc[i] ) sum = lsum[i]+ rsum[i+1];
        else  sum= rsum[i] + lsum[i-1];

        ans= min(sum,ans);
    }

    printf("%lld\n",ans);
	return 0;
}

