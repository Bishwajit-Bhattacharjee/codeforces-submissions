#include <stdio.h>
int main()
{
    long long int a1[11],a2[11];
    int m,n;
    scanf("%d %d",&n,&m);

    for(int i=0;i<=10;i++)
        a1[i]=0;
    for(int i=0;i<=10;i++)
      a1[i]=a1[i]+n/10;
    for(int k=1;k<=(n%10);k++)
        a1[k]++;

     for(int i=0;i<=10;i++)
        a2[i]=0;
    for(int i=0;i<=10;i++)
      a2[i]=a2[i]+m/10;
    for(int k=1;k<=(m%10);k++)
        a2[k]++;


      long long int  sum=a1[0]*a2[0]+a1[0]*a2[5]+a1[1]*a2[4]+a1[1]*a2[9]+a1[2]*a2[3]+a1[2]*a2[8]+a1[3]*a2[2]+
a1[3]*a2[7]+a1[4]*a2[1]+a1[4]*a2[6]+a1[5]*a2[5]+a1[5]*a2[0]+
a1[6]*a2[4]+a1[6]*a2[9]+a1[7]*a2[8]+a1[7]*a2[3]+a1[8]*a2[2]+
a1[8]*a2[7]+a1[9]*a2[1]+a1[9]*a2[6];
printf("%I64d\n",sum);
    return 0;
}

