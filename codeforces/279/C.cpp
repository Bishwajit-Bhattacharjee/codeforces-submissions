#include <bits/stdc++.h>
const int	maxn = 100005;
int a[maxn],l[maxn],r[maxn];
int main()
{
	int n,m,i,x,y;
	scanf("%d%d", &n, &m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),l[i]=r[i]=i;
	for(i=n;i>1;i--)
		if(a[i-1]<=a[i])
			r[i-1]=r[i];
	for(i=1;i<n;i++)
		if(a[i]>=a[i+1])
			l[i+1]=l[i];
	while(m--)
	{
		scanf("%d%d",&x,&y);
		if(r[x]>=l[y])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}