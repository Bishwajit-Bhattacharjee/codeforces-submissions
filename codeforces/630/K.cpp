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
   ll n, ans1, ans2 , ans3, ans4;
   cin >> n;
   ans1 = (n/2) + (n/3) + (n/5) + (n/7);
   ans2 = (n/6) + (n/10) + (n/14) + (n/15) + (n/21) + (n/35);
   ans3 = n/30 + n/42 + n/70 + n/105;
   ans4 = n/210;
   ll ans = ans1 - ans2 + ans3 - ans4;
   cout << n - ans << endl;
   return 0;
}
