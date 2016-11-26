//#inlcude <stdio.h>
#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n,m, l, r,ara[110];
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < n; i++)
        scanf("%d", &ara[i]);
    int ans = 0;
    for(int i =0 ;i < m ; i++)
    {
        scanf("%d %d", &l, &r);
        int ans2 = 0;
        for(int j = l-1; j < r; j++)
            ans2 += ara[j];
        //ans = max(ans2, ans);
        if(ans2 > 0) ans += ans2;
    }
    printf("%d\n", ans);
    return 0;

}
