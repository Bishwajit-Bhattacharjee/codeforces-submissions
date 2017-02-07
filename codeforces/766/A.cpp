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
   string s1 , s2;
   cin >> s1 >> s2;
   int len1 = s1.size();
   int len2 = s2.size();
   if(len1 == len2)
   {
         if(s1 == s2)
         {
             puts("-1");return 0;
         }
         else
            printf("%d", len1);
   }
   else
   {
       printf("%d", max(len1, len2));
   }
   return 0;
}
