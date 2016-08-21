#include <stdio.h>
int main()
{
    long long int a[25]={0};
    long long int ans=0;
    int n,i;
    scanf("%d",&n);
    for(int j=0;j<n;j++)
    {
        scanf("%d",&i);
        a[10+i]++;
    }
    for(i=1;i<=10;i++)
        ans+=a[10+i]*a[10-i];
    printf("%I64d\n",ans+(a[10]*(a[10]-1)/2));
  return 0;
}
