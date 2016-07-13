#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int ara[n+1][2];
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<2;k++)
            scanf("%d",&ara[i][k]);
    }
    int count =0 ;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                if(ara[i][0]==ara[j][1])
                    count++;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}
