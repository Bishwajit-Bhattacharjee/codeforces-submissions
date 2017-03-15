#include <bits/stdc++.h>
#define PII pair < int , int >
#define  PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
ll const inf =  1LL << 59 ;
int  const MX = 5  * 1e5 + 8  ;
int const EPS = 1e-9;
int  const MOD = 1e9 + 7;
using namespace std;


int main()
{
     vi l1, l2, r1, r2;
     int n, m;
     cin >> n ;
     int a, b;
     for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        l1.pb(a);
        r1.pb(b);
     }
     cin >> m;
     for(int i= 0; i < m; i++){
        scanf("%d %d", &a, &b);
        l2.pb(a);r2.pb(b);
     }
     int mx1 = *max_element(l1.begin(), l1.end());
     int mn1 = *min_element(r1.begin(), r1.end());
     int mx2 = *max_element(l2.begin(), l2.end());
     int mn2 = *min_element(r2.begin(), r2.end());
     int ans = 0;
    // printf("%d %d %d %d\n", mx1, mn1, mx2 , mn2);
     if(mn1 < mx2 )
        ans = max(ans, mx2 - mn1);
     if(mn2  < mx1)
          ans = max(ans, mx1 - mn2);

     cout << ans << endl;
    return 0;
}
