// HK  HK HK HK HK HK   JSN  JRR

#include <bits/stdc++.h>
#define PII pair < int , int >
#define PIB pair < int , bool >
#define PI 2.0*acos(0.0)
#define ll long long int
#define FOR(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a %b == 0)?(a/b):(a/b)+1
#define F first
#define S second
#define lu unsigned long long int
int const up =   1e6 + 10 ;
int const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const MX =   1e5 + 10;
int const mod = 1e9 + 7;

using namespace std;
 vector <ll> v1, v2;
 int n, m ;

 bool can(ll r)
 {
    for(int i = 0; i < n ; i++)
    {
        auto  t = lower_bound(v2.begin(), v2.end(), v1[i] - r);
        if(t == v2.end() || *t > (v1[i] + r))
            return false;
    }
    return true;
 }




int main()
{

  // int n;
   cin >> n >> m;
   ll tmp;
   for(int i = 0; i < n ; i++)
   {
    scanf("%I64d", &tmp);
    v1.pb(tmp);
   }
   for(int j = 0 ; j < m; j++)
    {
        scanf("%I64d", &tmp);
         v2.pb(tmp);
    }
   ll lo = 0 , hi = 2 * 1e9;
   ll  ans = 1LL<<60;
   while(abs(lo - hi) > 5){
    ll mid = (lo + hi)/2;
    if(can(mid)) {
        ans = min(ans , mid);
        hi = mid;
    }
    else {
        lo = mid + 1;
    }

   }
    for(ll i = min(lo , hi); i <= max(lo , hi); i++){
        if(can(i)){
            ans = min(ans, i);
        }
    }
   cout << ans;

   return 0;
}
