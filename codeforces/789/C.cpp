#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
ll const inf =  1LL << 59 ;
int  const MX  = 2 *1e5 + 10;
int const EPS = 1e-9;
int  const MOD = 1e9 + 7;
using namespace std;


//int level[MX];
//int color[MX];


int main(){
    int n;
    int a[MX];
    vi dif1(MX);

    cin >> n;
    for(int i = 0; i < n ; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n-1; i++){
        dif1[i] = abs(a[i] - a[i+1]);
    }
    //dif2
    vi dif2 = dif1;
    vi dif3 = dif1;
    for(int i = 2; i < n-1; i += 2)
        dif2[i] = -dif1[i];
    for(int i = 1; i < n-1; i += 2)
        dif3[i] = -dif1[i];
    ll ans = 0, mxans = 0;

  /*  for(int i = 0; i< n-1; i++){
        cout << dif1[i] << ' ';

    }
    cout << endl;
    for(int i = 0 ;i < n-1 ; i++){
        cout << dif2[i] << ' ';

    }
    cout << endl;
    */
    for(int i = 1 ; i < n-1 ; i++){
        ans += dif2[i];
        mxans = max(ans, mxans);
        if(ans < 0)
            ans = 0;

    }
    ll mxans1 = 0, ans1 = 0;
    for(int i = 0 ; i < n-1; i++){
          ans1 += dif3[i];
          mxans1 = max(ans1 , mxans1);
          if(ans1 < 0)
            ans1 = 0;
    }
    cout << max(mxans1, mxans); //<< //mxans <<  ' ' << mxans1;
    return 0;
}
