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
    int a[505];
    int n, k,ans = 0;
    cin >> n >> k;


    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(n == 1)
    {

        printf("0\n%d", a[0]);
        return 0;
    }
    for(int i = 1; i < n; i++)
    {
        if(a[i] + a[i-1] < k)
           {

             int x = k - a[i]-a[i-1];
              a[i] += x;
              ans += x;
           }
    }
    printf("%d\n", ans);
    for(int i = 0 ; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
