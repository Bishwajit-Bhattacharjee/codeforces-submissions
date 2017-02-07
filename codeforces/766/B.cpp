#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const up =   1e6 + 10 ;
int  const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const mod = 10000007;
using namespace std;

//global variables



 // global variables  end here

 // functions begin here


 // functions end
 int main()
 {
   int n, t;
   //int a[up1];
   vi v;
   cin >>n;
   //for(int i = 0;i < )
   for(int i = 1; i<= n;i++)
   {

    scanf("%d", &t);
    v.pb(t);
   }
   sort(v.begin(), v.end(), greater<int> ());
   bool f = false;
   for(int i = 2; i < n; i++)
   {
       if(v[i] + v[i-1] > v[i-2])
       {
           puts("YES");
           return 0;
       }

   }
   puts("NO");

   return 0;
}
