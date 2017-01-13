#include <bits/stdc++.h>
#define PII pair < int , int >
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define pb push_back
int const up = 1e5 + 10 ;
int const up1 = 1e8 + 10;
using namespace std;
//vector < int > divi[100007];
int main()
{

  int n, k;
  cin >> n;
  int i  = 2;
  cout << n << ' ';
  while(n != 1)
  {
      while(n % i == 0)
      {
          n /= i;
          cout << n << ' ';
      }
      i++;
  }
  //cout << 1 ;
  return 0;
}
