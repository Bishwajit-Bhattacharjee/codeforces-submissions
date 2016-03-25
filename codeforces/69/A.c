#include <stdio.h>
int main()
{
    int  n,i,j;
    scanf("%d", &n);
    int ara[n][3];int sum[3]={0, 0, 0};
    for(i = 0; i <n ;i++)
    {
      for(j = 0; j < 3; j++)
        scanf("%d", &ara[i][j]);
    }
    for(j = 0; j < 3; j++){
        for(i = 0; i < n; i++)
            sum[j]+= ara[i][j];
    }
    if( !sum[0] && !sum[1] && !sum[2])
        printf("YES\n");
    else
        printf("NO");
 return 0;
}
