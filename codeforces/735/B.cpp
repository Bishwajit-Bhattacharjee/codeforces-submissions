//#inlcude <stdio.h>
#include <bits/stdc++.h>

using namespace std;

long long int a[100009];

int main()
{
    int n, n1, n2;
    scanf("%d %d %d", &n, &n1 ,&n2);
    int mini = min(n1,n2);
    int maxi = max(n1, n2);
   long long  int s1 = 0, s2 = 0, s3 = 0, s4 =0;
    for(int i = 0; i<n; i++)
        scanf("%I64d", &a[i]);
    sort(a, a + n);
    reverse(a, a +n);

  //  int j;
   // int c1 = 0, c2 = 0;

    for(int i = 0 ; i < maxi; i++)
        s1+=a[i];
    for(int i = 0; i < mini; i++)
        s2 += a[maxi + i];
    for(int i = 0; i <mini; i++)
        s3 += a[i];
    for(int i = 0; i < maxi; i++)
       {

        s4 += a[mini + i];
        // printf(" debug %d\n", s4);
       }

    double ans1 , ans2;
    ans1 = (1.0*s1)/(1.0 * maxi) +(1.0*s2) / (1.0 * mini);
    ans2 = (1.0 *s3) /(1.0 * mini) + ((double) s4) /(1.0 * maxi);
    double ans = max(ans1, ans2);
          //  printf( " debug - %d %d\n", s3, s4);
    printf("%.10lf\n", ans);
    return 0;

}
