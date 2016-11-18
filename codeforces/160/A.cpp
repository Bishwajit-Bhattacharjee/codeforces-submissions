//#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i = 0 ;
    int ara[110];
    scanf("%d", &n);
    int sum = 0;
    for(int i = 0 ; i < n; i++)
    {
        scanf("%d", &ara[i]);
        sum += ara[i];
    }
    sort(ara, ara + n);
    int max_sum = 0, c_count = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        max_sum += ara[i];
        c_count++;
        if(max_sum > (sum - max_sum))
            break;
    }
    printf("%d\n", c_count);

    return 0;
}
