#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
ll const inf =  1LL << 59 ;
int  const MX = 1e5 + 5  ;
int const EPS = 1e-9;
int  const MOD = 1e9 + 7;
using namespace std;

//global variables


int main(){
    int x[MX], h[MX];
    int n;
    cin >> n;
    int ans = 0;

    for(int i = 1; i <= n;i++)
        cin >> x[i] >> h[i];
   // for(int i = 1; i <= n;i++)
     //   cin >> h[i];
    ans = 1;
    int last = x[1];
    for(int i = 2 ;i <= n - 1; i++)
    {
        if(x[i] - h[i] > last)
        {
            ans++, last = x[i];
            //continue;
        }
        else if(x[i] + h[i] < x[i+1])
            ans++, last = x[i] + h[i];
       // cout << ans << ' ';
       else 
         last = x[i];
    }
    if(n != 1) ans++;
    cout << ans ;
    return 0;
}