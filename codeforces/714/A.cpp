//#inlcude <stdio.h>
#include <bits/stdc++.h>

using namespace std;



int main()
{
    long long int l1, l2, r1, r2, k, maxi, mini, ans = 0;
    scanf("%I64d %I64d %I64d%I64d %I64d", &l1, &r1, &l2, &r2, &k);

    maxi = max(l1, l2);
    mini = min(r1 , r2);
    if((mini - maxi) >=0)
    {
        ans = mini - maxi + 1;
        if(mini >= k && maxi <= k)
            ans--;


    }
    printf("%I64d\n", ans);
    return 0;
   // else
      //  printf("0\n");

}
