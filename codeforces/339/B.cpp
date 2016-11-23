//#inlcude <stdio.h>
#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n, t,m , i;
   long long  int ara[100005];
    scanf("%d %d" ,&n, &m);
    for(int i = 1; i <= m; i++)
        scanf("%I64d",&ara[i]);
    long long int ans =  ara[1] - 1;

    if( m > 1)
    {
        for(int i = 2; i <= m ; i++)
        {
            if(ara[i-1] <= ara[i])
                ans += ara[i] - ara[i-1];
            else
            {
                ans += (n - ara[i-1]) + ara[i];
            }
        }
    }
    printf("%I64d\n", ans);

    return 0;

}
