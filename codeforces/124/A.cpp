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


   cout << n + 1 - max(a+1,n-b) << endl;
   return 0;
}
