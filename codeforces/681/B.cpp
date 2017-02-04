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
    ll a, b ,c ,n, t;
    cin >> n;
    for(ll a = 0; a <= 811; a++)
    {
        for(ll b = 0; b <= 8101; b++)
        {
           t = n - a * 1234567 - b * 123456 ;
           if(t >= 0 && ( t % 1234 == 0))
                 { puts("YES");return 0;}
        }
    }

        puts("NO");

    return 0;
}
