#include <bits/stdc++.h>

using namespace std;

int main() {
   int n;
//   cin >> n;
   int c, v0, v1, a ,  l;
   cin >> c >> v0 >> v1 >> a >> l;
   int cnt = 0;
   while(c > 0){
   	c -= v0 ;
   	v0 = min(v0 + a, v1);
   	cnt++;
   if(c <= 0) break;
   else 
   c += l;
   //	cnt++;
   //	cout << v0 << ' ' << c <<  endl;
   }
   cout << cnt ;
	// your code goes here
	return 0;
}