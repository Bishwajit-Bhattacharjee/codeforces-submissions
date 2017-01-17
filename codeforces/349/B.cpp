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
    int v; cin >> v;
    int a[10];
    int mini  = up;
    int index;
    for(int i = 1; i < 10  ; i++)
    {

         cin >> a[i];
         if(a[i] < mini)
         {
             mini = a[i];
             index = i;
         }
    }
    int ans = (v / mini);
    v -= (ans * mini);
    string res;
    for(int i = 1 ; i <= ans; i++)
    {
       res += (i + '0');
    }
     for(int i = 0; i < ans; i++)
     {
         for(int j = 9 ; j > 0; j--)
         {
            if(v + mini - a[j] >= 0 )
            {
                res[i] = j + '0';
                v -= (a[j] - mini);
                break;
            }
         }
     }
     if(ans == 0)
        puts("-1");
     else
        cout << res << endl;
   return 0;
 }
