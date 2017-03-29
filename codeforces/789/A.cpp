#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a % b == 0)?(a/b):(a/b)+1
ll const inf =  1LL << 59 ;
int  const MX  = 2 *1e5 + 10;
int const EPS = 1e-9;
int  const MOD = 1e9 + 7;
using namespace std;


int main()
{
      int n, k;
      int w[MX];
      cin >> n >> k;
      for(int i = 0 ;i < n; i++)
        scanf("%d", &w[i]);
      ll ans = 0;
      for(int i = 0 ;i < n; i++){
        ans += (ll)ceiling(w[i], k);
      //  cout << ans;
      }
       ll x = (ll)ceiling(ans , 2);
    cout <<  x;
}
