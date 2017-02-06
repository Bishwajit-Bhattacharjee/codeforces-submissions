#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const up =   1e6 + 10 ;
int  const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const mod = 10000007;
using namespace std;

//global variables



 // global variables  end here

 // functions begin here


 // functions end
 int main()
 {
    int  n, a[up1];
    cin >> n;
    for(int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    sort(a, a + n);
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans +=( (i+1 > a[i]))? (i+1 - a[i]):(a[i]-(i+1));
    }
    cout << ans << endl;
    return 0;
}
