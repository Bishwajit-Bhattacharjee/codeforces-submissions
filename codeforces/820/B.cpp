#include <bits/stdc++.h>

using namespace std;

int main() {
   double  n, ans ;
   double a, can = 1e9;
   cin >> n ;
   cin >> a;
   for(int i =0 ; i <= n-3 ; i++){
   	  double ang = 0.5 * ((n-i-2)* 180  - ((n-i-2)* 180 * (n-2) * 1.0)/ n )  ;
   	 // ang  *= 0.5;
   	  if(fabs(ang - a) < can){
   	  	can = fabs(ang - a);  ans = n - i ;
   	  }
   }
  //cout << "2 1"<< ' ' << ans ;
 printf("2 1 %0.lf", ans); 
	return 0;
}