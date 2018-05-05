#include<stdio.h>
int mapp[1005][1005];
int dis1[1005][1005];
int dis2[1005][1005];
int dis3[1005][1005];
int dis4[1005][1005];
int max(int x,int y)
{
    if(x>y)
        return x;
    return y;
}
int main()
{
    int n,m,i,j,sum=0;
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            scanf("%d",&mapp[i][j]);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            dis1[i][j]=mapp[i][j]+max(dis1[i-1][j],dis1[i][j-1]);
    for(i=n; i>=1; i--)
        for(j=m; j>=1; j--)
            dis2[i][j]=mapp[i][j]+max(dis2[i+1][j],dis2[i][j+1]);
    for(i=1; i<=n; i++)
        for(j=m; j>=1; j--)
            dis3[i][j]=mapp[i][j]+max(dis3[i-1][j],dis3[i][j+1]);
    for(i=n; i>=1; i--)
        for(j=1; j<=m; j++)
            dis4[i][j]=mapp[i][j]+max(dis4[i][j-1],dis4[i+1][j]);
    for(i=2; i<n; i++)
        for(j=2; j<m; j++)
            {sum=max(sum,dis1[i-1][j]+dis2[i+1][j]+dis3[i][j+1]+dis4[i][j-1]);
            sum=max(sum,dis1[i][j-1]+dis2[i][j+1]+dis3[i-1][j]+dis4[i+1][j]);}
    printf("%d",sum);
    return 0;
}

	