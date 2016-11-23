//#inlcude <stdio.h>
#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n, t,m , i;
   long long  int temp1, temp2; //ara[100005];
    scanf("%d %d" ,&n, &m);
    scanf("%I64d",&temp1);
    long long int ans = temp1 - 1;
  if(m > 1)
    {
        for(int i = 1; i < m; i++){
            scanf("%I64d",&temp2);
            if(temp1 <= temp2)
                ans += (temp2 - temp1);
            else
                ans += (n - temp1) + temp2;

            temp1 = temp2;
        }
    }
    //long long int ans =  ara[1] - 1;


    printf("%I64d\n", ans);

    return 0;

}
