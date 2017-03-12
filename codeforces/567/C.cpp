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
   map < ll , ll > fw;
   map < ll , ll > bc;
   set < ll > s;
   ll a[MX];
   ll n, k;
   cin >> n >> k;
   for(int i = 0; i < n; i++){
    scanf("%I64d", &a[i]);
    bc[a[i]]++;
    s.insert(a[i]);
   }

   if(k == 1){
    set < ll >::iterator it;
    it = s.begin();
    ll ans = 0;
    while(it != s.end()){
        ll x =(ll) bc[*it];
        ans += (x * (x - 1)*(x-2))/ 6;
        it++;
    }
    cout << ans ;
    return 0;
   }
   ll ans = 0;
   for(int i = 0; i < n; i++){
    fw[a[i]]++;
    if(a[i] % k == 0){
        ans += (long long int)(!(a[i] / k == a[i] || a[i] * k == a[i]))?(fw[a[i]/ k] * (bc[a[i] * k] - fw[a[i] * k])):
                            (((fw[a[i]/ k] - 1) * (bc[a[i] * k] - fw[a[i] * k] )));
    }
   }

   cout << ans << endl;
    return 0;
}