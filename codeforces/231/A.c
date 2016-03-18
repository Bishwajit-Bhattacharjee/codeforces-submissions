#include <stdio.h>
int main()
{
    int i, j,n, sum = 0;
    scanf("%d", &n);
    int ara[n][3];
    for(i = 0; i < n;i++)
    {
        for(j= 0 ; j < 3; j++)
            scanf("%d",&ara[i][j]);
    }
    for(i = 0; i < n; i++)
    {
        //for(j = 0; j < 3; j++)

            if(ara[i][0] + ara[i][1] + ara[i][2] >= 2)
                sum++;

    }
    printf("%d\n", sum);
    return 0;
}
