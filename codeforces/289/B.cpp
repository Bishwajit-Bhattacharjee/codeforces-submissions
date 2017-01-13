#include <bits/stdc++.h>
#define PII pair < int , int >
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define pb push_back
int const up = 1e5 + 10 ;
using namespace std;
vector < int > divi[100007];
int main()
{
  int n, m , d;
  int a[up];
  cin >> n >> m >> d;
  loop(i, 0, n * m )
  {
    scanf("%d", &a[i]);

  }
  int r = a[0] % d;
  loop(i, 1, n*m)
  {
      if(r != a[i] % d)
      {
          puts("-1");
          return 0;
      }
  }
  sort(a , a + (n*m));
  int mid = (n*m)/2;
  int sum = 0;
  for( int i = 0; i < n*m ; i++)
  {
      if(i != mid)
        {
            sum += abs(a[i] - a[mid]);
        }
  }
   cout << sum / d << endl;

  return 0;
}
