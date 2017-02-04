#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const up =   1e6 + 10 ;
int  const up1 = 5 * 1e4 + 10  ;
int const eps = 1e-9;
int const mod = 10000007;
using namespace std;

//global variables



 // global variables  end here

 // functions begin here


 // functions end
 int main()
 {
    int n;
    int a[100];
    cin >> n;

    loop(i, 1, n)
    cin >> a[i];
    if(n == 1)
     {

       if(a[n] == 0)puts("UP");
      else if(a[n] == 15)
        puts("DOWN");
        else puts("-1");
       return 0;
     }
    if(a[n] > a[n-1])
       (a[n] == 15)?puts("DOWN"):puts("UP");
    else
    {
         (a[n] == 0)?puts("UP"):puts("DOWN");
    }
    return 0;
}
