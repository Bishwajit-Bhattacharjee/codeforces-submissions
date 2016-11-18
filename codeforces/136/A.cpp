//#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    //ara[110];
    scanf("%d", &n);
    int ara[n + 5];
    for(int i = 0 ; i < n; i++)
    {
        //scanf("%d", &ara[i]);
        scanf("%d", &x);
        ara[x] = i + 1;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        printf("%d ", ara[i]);
    }

    return 0;
}
