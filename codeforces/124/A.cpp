#include <bits/stdc++.h>
using namespace std ;
const int MX = 1e5 + 10;
long long ara[MX] ;
long long csum[MX] ;
int main()
{
   int cnt =0 ;
   int n , a , b ;
   cin >> n >> a >> b ;

   for(int i = 1; i <= n; i++){
      if(i - 1 >= a and n - i <= b ) {
        cnt++;
      }
   }
   cout << cnt << endl;
   return 0;
}
