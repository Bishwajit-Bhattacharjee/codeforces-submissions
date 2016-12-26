#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef  long long ll;
typedef pair<int,int> PII;
const int up = 1e3;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;
//#define end return 0
int main()
{
    int n, k, tmp;
    vector <int >  a, b;
    cin >> n >> k;
    loop(i ,0, n -1)
      {
          cin >> tmp ;
          a.pb(tmp);
      }
    b = a;
    sort(a.begin(), a.end());
   if(a[n-1] >  a[0] + k)
   {
       puts("NO");
       return 0;
   }
   else
   {
       puts("YES");
       for( int i = 0; i  < b.size(); i++)
       {
           int x = 1;
         for(int j = 0; j < b[i]; j++)
         {
             printf("%d ", x);
            if(x % k == 0)
                x = 0;
            x++;
         }
         printf("\n");
       }
   }

    return 0;
}

