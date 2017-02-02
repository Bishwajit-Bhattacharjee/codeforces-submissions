#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const up =   1e6 + 10 ;
int  const up1 = 1e7  ;
using namespace std;

//global variables
//vector < int > point;
//ll ncr[35][35];

 // global variables

 // functions



 // functions end
 int main()
 {
    int a[60] , b[60], c[60], d[50];
    int n, l ;
    cin >> n >> l;
    loop(i, 0, n-1)
    scanf("%d", &a[i]);
    loop(j,0, n-1)
    {
       scanf("%d", &b[j]);
       c[j] = b[j];
    }

    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < n; j++)
        {
            c[j] =(b[j] + i) % l;
           // printf("%d %d\n", b[j], c[j]);
        }
        for(int m = 0; m < n;m++)
        {


         for(int k = 0; k < n ; k++)
         {
            d[(k + m) % n] = c[k];
           // printf("d %d c %d\n", d[k], c[k]);
         }
         int cnt = 0;
         for(int x = 0; x < n; x++)
           {
            if(a[x] == d[x])
                cnt++;
           }
           if(cnt == n)
          {
            puts("YES");
            return 0;
          }
        }
    }
    puts("NO");

    return 0;
}
