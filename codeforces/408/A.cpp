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
   int n, k[110],t, sum[110] = {0};
   cin >> n;
   loop(i,1, n)
   {
       cin >> k[i];
   }
   int ans = up;
   loop(i, 1, n)
   {
       sum[i] += k[i]*15;
       loop(j, 1, k[i])
       {
         cin >> t;
         sum[i]+=(t * 5);
       }
       ans = min(ans,  sum[i]);
   }
   cout << ans<< endl;


   end ;
}


