#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e5 +5;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;

int main()
{
   int n, m, temp1, temp2;
   cin >> n >> m;
   vi(ac);
   vi(wa);
   loop(i, 0, n-1)
   {
       cin >> temp1;
       ac.pb(temp1);
   }
   int mini = *std::max_element(ac.begin(), ac.end());//the lower limit
   loop(i, 0, m-1)
   {
       cin >> temp1;
       wa.pb(temp1);
   }
   int maxi = *std::min_element(wa.begin(), wa.end());// the upper limit

   bool extra = false, flag = false ;
   bool pass = true;

   for(int i = mini; i < maxi; i++)
   {
      for(int j = 0; j < n ; j++)
      {
          if( 2 * ac[j] <= i)
            extra = true;
          if(ac[j] > i)
            pass = false;
      }
      if(extra && pass)
      {
       cout << i << endl;
       flag = true;
        break;
      }
   }
   if(!flag)
    printf("-1\n");

   return 0;
}
