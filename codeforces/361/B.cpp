#include <bits/stdc++.h>
#define PII pair < int , int >
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
int const up =  5 * 1e7 + 10 ;
int const up1 = 1e3 + 10;
using namespace std;

  int main()
  {
   int n, k; cin >> n >> k;
    int a[n+1];
   if(k == n)
   {

    puts("-1");
    return 0;
   }
   else
   {

       for(int i = 1; i <= n ; i++)
        a[i]= i;

   }
   for(int j = k + 2;j < n; j++)
   {
      a[j] = j + 1;
   }
   if(k != n-1 ) a[n] = k + 2;
   if(k  != n -1)swap(a[1], a[n]);
   for(int i = 1 ; i <= n; i++)
      cout << a[i] << ' ';
   return 0;
 }
