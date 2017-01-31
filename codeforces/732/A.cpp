#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const up =   1e6 + 10 ;
int  const up1 = 1e7  ;
using namespace std;

//global variables
//vector < int > point;
//ll ncr[35][35];

 // global variables

 // functions



 // functions end
 int main()
 {
    int k, r, ans;
    cin >> k >> r;
    for(int i = 1; i <= 10 ; i++)
    {
        ans = k * i;
        if(ans % 10 == r || ans % 10 == 0)
        {
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}
