#include <bits/stdc++.h>
#define PII pair < int , int >
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define pb push_back
int const up = 1e3 + 10 ;
int const up1 = 1e8 + 10;
using namespace std;
//vector < int > divi[100007];
int main()
{

  int n, x_0,y_0;
  int x[up] , y[up];
 // int t1 ,t2
  cin >> n >> x_0 >> y_0;
  loop(i, 0, n)
  {
      scanf("%d %d", &x[i], &y[i]);

  }
  int cnt = 0;
  bool  f[up] ;
  loop(i, 0, n)
     f[i] = true;
  for(int i = 0; i < n; i++)
  {
      if(f[i])
      {
           cnt++ ;
          for(int j = i; j < n; j++)
          {
            if((y[i]-y_0)*(x[j]-x[i]) == (x[i]-x_0)*(y[j]-y[i]) && f[j])
            {
            f[j] = false;
            }
          }
      }
  }
  cout << cnt << endl;
  return 0;
}
