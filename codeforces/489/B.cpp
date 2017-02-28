
#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const inf =  1 << 28 ;
int  const array_size = 5 * 1e5 + 10  ;
int const eps = 1e-9;
ll const MOD = 1e8;
using namespace std;

//global variables




int main(){
    //int n1, n2 ;
    int n, m ;
    vi boy, girl;
    int  mark_g[110]={0}, t;
    cin >> n ;
    //for(int i )
    //loop(i, 0, n-1)
    for(int i = 0; i < n; i++)
       scanf("%d",&t), boy.pb(t);
    cin >> m;
    for(int i = 0; i < m ; i++)
    scanf("%d", &t), girl.pb(t);
    sort(boy.begin(), boy.end()) ;
    sort(girl.begin(), girl.end());

   // sort(boy.begin(), boys.end());
   //sort(girls.begin(), girls.end());
    int result = 0;
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++)
          if (abs(boy[i] - girl[j]) <= 1)
          {
            girl[j] = 1000;
            result++;
            break;
          }
    cout << result << endl;
    return 0;
}
