#include <bits/stdc++.h>
#define PII pair < int , int >
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define pb push_back
int const up = 1e8 + 10 ;
using namespace std;

int main()
{
  char str[1000000];  int a[100] = {0};
  char  bul[8] = "Bulbasr";
   gets(str);
   int len = strlen(str);
   for(int i =0 ; i < len ; i++)
   {
       for(int j =0; j < 7; j++)
       {
           if(str[i] == bul[j])
           {
               a[j]++;
               break;
           }
       }
   }
   a[4] /= 2;  a[1] /= 2;

   int mini = 100000000;
   for(int i =0 ; i< 7; i++)
   {
       //cout << a[i] << endl;
       mini = min(a[i], mini);
   }
   cout << mini << endl;
  return 0;
}
