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
    ll a[110];
    vector < ll >  v;
    ll n;
    cin >> n;
    loop(i, 0, n-1)
      cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        if(a[i] == 1)
            v.pb(i);
    }
    ll ans = 1;
    ll len = v.size();
    if(len == 0)
    {
        cout << 0 << endl;
        return 0 ;
    }
    if(len == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for(ll i = len - 1; i > 0; i--)
    {
        ans *= (v[i] - v[i-1]);
    }

    cout << ans << endl;
    return 0;
}
