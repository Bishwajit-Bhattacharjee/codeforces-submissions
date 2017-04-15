#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a % b == 0)?(a/b):(a/b)+1
ll const inf =  1LL << 59 ;
int  const MX  = 1e3 + 1;
int const EPS = 1e-9;
int  const MOD = 10056;

using namespace std;

int main()
{
   int t, n, c = 0, x , k;

   vi v;
   cin >> n >> k ;
   if(k == 1){
    cout << n ;
    return 0;
   }
   for(int i = 2 ; i <= n ; i++){
      if(n % i == 0){
        while(n % i == 0){
            n /= i;
            v.pb(i);
        }
      }
   }
    if(k > v.size()){
        puts("-1");
        return 0;
    }
    for(int i = 0; i < k - 1; i++){
        cout << v[i] << ' ';
    }
    int ans = 1;
    for(int i = k - 1; i < v.size(); i++){
        ans *= v[i];
    }
    cout << ans ;


   return 0;
}
