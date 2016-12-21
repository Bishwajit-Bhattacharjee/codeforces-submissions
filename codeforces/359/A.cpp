#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e9;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;
#define end return 0
int main()
{
   int n,m;
   int a[70][70];
   cin >> n >> m;
   loop(i, 1, n)
   {
       loop(j, 1, m)
          cin >> a[i][j];
   }
   bool f = true;
   loop(i, 1, n)
   {
      if(a[i][1] == 1)
        f = false;
      if(a[i][m] == 1)
        f = false;
   }
   loop(i, 1, m)
   {
       if(a[1][i] == 1)
        f = false;
       if(a[n][i]== 1)
        f = false;
   }
   if(f)
    puts("4");
   else
    puts("2");

   end ;
}


