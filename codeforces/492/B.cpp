//#inlcude <stdio.h>
#include <bits/stdc++.h>

using namespace std;



int main()
{
   int n ,l,ara[1009];
   scanf("%d %d", &n, &l);

   for(int i  = 0; i < n; i++)
    scanf("%d", &ara[i]);

   sort(ara, ara + n);

    int rag = 2 *(max(ara[0], l - ara[n-1]));

    for(int i = 1; i < n; i++)
        rag = max(rag, ara[i] - ara[i-1]);
    double ans = (rag * 1.0) / 2;
    //cout >> rag;
    printf("%.10lf\n", ans);

    return 0;

}
