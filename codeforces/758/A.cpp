#include <bits/stdc++.h>
#define PII pair < int , int >
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
int const up =  5 * 1e7 + 10 ;
int const up1 = 1e3 + 10;
using namespace std;
  ll gcd ( ll a, ll b)
  {
      ll t;
      while(b != 0)
      {
          t = b;
          b  = a % b;
          a = t;
      }
      return a;
  }


int main()
{
       int n;
       int a[110];
       cin >> n;
       for(int i  = 0; i < n; i++)
       {
           scanf("%d", &a[i]);
       }
       int maxi = *max_element(a, a + n);
       int cnt = 0;
       for(int i = 0; i < n; i++)
        cnt += (maxi - a[i]);

       cout << cnt;
  return 0;
}
