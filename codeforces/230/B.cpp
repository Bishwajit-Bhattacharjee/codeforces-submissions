#include <bits/stdc++.h>

using namespace std;
int mark[1000009];

void sieve(int n)
{
    for(int i = 0; i <= n ; i++)
        mark[i] = 0;

    int i  ,j , limit  =sqrt(n *1.0 );
   // mark[1] = 1;
    mark[0]  = 1;
    mark[1] = 1;
    for( i = 4; i<= n ; i +=2)
        mark[i] = 1;

    for(i = 3; i <= n; i += 2)
    {
        if(!mark[i])
        {
            if(i <= limit)
            {
                for(j = i * i; j <= n ; j += i*2)
                    mark[j] = 1;
                    //printf("debug ");
            }
        }
    }
}

int main() {
   sieve(1000003);
     int n, temp1;
     double temp;
    scanf("%d", &n);
    long long int ara[100008];
    for(int i =0; i < n; i++)
        scanf("%I64d", &ara[i]);
    for(int i = 0; i < n ; i++)
    {
        temp = sqrt(1.0 * ara[i]);
        if(ceil(temp) == floor(temp))
        {
            temp1 = (int) temp;
               // printf(" debug - > %d %lf\n",temp1, temp);
                if(!mark[temp1])
                    printf("YES\n");
                else
                    printf("NO\n");
        }
        else
            printf("NO\n");
    }
	return 0;
}
