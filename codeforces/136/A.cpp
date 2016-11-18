//#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, ara[110];
    scanf("%d", &n);
    for(int i = 0 ; i < n; i++)
    {
        scanf("%d", &ara[i]);
    }
    for(int i = 1;i <= n; i++)
    {
        for(int k = 0; k < n; k++)
        {
            if(ara[k] == i)
                printf("%d ", k + 1);
        }
    }
    printf("\n");
    return 0;
}
