#include <bits/stdc++.h>
#define PII pair < int , int >
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define pb push_back
int const up = 1e5 + 10 ;
using namespace std;
vector < int > divi[100007];
void d(int n)
{
    int i , j;
    for(int i = 2; i <= n; i++)
    {
        for(int j = i; j <= n; j+=i)
            divi[j].pb(i);
    }
}
int main()
{
    d(100007);
    int n, g, ans = 1, t;
    int a[100007]={0};

    cin >> n ;
     for(int i = 0; i < n; i++)
     {
         scanf("%d", &t);
         int len = divi[t].size();
         for(int x = 0; x < len; x++)
         {
             a[divi[t][x]]++;
         }

     }
     int maxi = 1;
      for(int i = 2; i < 100001; i++)
      {
        maxi = max(a[i], maxi);
      }
      cout << maxi << endl;
  return 0;
}
