#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
char str[120];
int dp[120][3000];
void init(){
	memset(dp,0,sizeof dp);
	dp[0][0]=1;	
	for(int i=1;i<=100;++i)
		for(int j=i*1;j<=i*26;++j)
			for(int k=1;k<=26;++k)
			if (j>=k)
				dp[i][j]=(dp[i][j]+dp[i-1][j-k])%mod;
}
int main(){
	int T,n,m;
	scanf("%d",&T);
	init();
	while (T--){
		scanf("%s",str);
		n=strlen(str); m=0;
		for(int i=0;i<n;++i)
			m+=str[i]-'a'+1;
		printf("%d\n",dp[n][m]-1);
	}
}