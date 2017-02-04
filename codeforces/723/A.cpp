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
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    int mini = mod;
    for(int i = 1; i <= 100; i++)
    {
        mini = min(mini, abs(i-x1)+abs(i-x2) + abs(i-x3));
    }

    cout << mini ;
    return 0;
}
