
#include <bits/stdc++.h>
#define PII pair < int , int >
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define pb push_back
int const up = 1e6 + 3 ;
using namespace std;

//map < char , string > m;

int main()
{
   int a[27]={0}, b[27]={0};
   char in[10000], out[10000];
   gets(in);
   gets(out);
   int leni = strlen(in);
   int leno = strlen(out);
   loop(i, 0, leni)
   {
       a[in[i]-'a']++;
   }
   loop(i, 0, leno)
   {
       b[out[i] -'a']++;
   }
   int ans = 0;
   loop(i, 0, 26)
   {
       if(!a[i] && b[i])
       {
           puts("-1");
           return 0;
       }
       if(b[i] <= a[i])
        ans+= b[i];
       else if(b[i] > a[i])
         ans += (a[i]);


   }
    cout << ans << endl;
   return 0;
}
