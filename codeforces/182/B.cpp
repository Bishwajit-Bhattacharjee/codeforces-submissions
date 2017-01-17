#include <bits/stdc++.h>
#define PII pair < int , int >
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
int const up =  5 * 1e7 + 10 ;
int const up1 = 1e3 + 10;
using namespace std;

  int main()
  {
   int d, n, t;
      scanf("%d %d", &d, &n);

        int ans = 0;
   for(int  i = 1; i <= n; i++)
   {
       scanf("%d", &t);
        if(i != n)ans += (d-t);
   }

    cout << ans ;

   return 0;
 }
