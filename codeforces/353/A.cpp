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
   vector < PII > x;
   int t1, t2, n;
   int o_e = 0, sum1 =0 , sum2 = 0;
   cin >> n;
   loop(i, 0, n-1)
   {
       cin >> t1 >> t2;
       if((t1 % 2 == 0 && t2 % 2 == 1) || (t1 % 2 == 1 && t2 % 2 == 0))
       o_e++;
       sum1+= t1;
       sum2 += t2;
       //x.pb(make_pair(t1, t2));
    }
    int ans ;
    if(sum1 % 2 == 0 && sum2 %  2 == 0)
        ans = 0;
    else if((sum1 % 2 == 1 &&sum2 % 2 == 1) || (sum1 % 2 == 1 &&sum2 % 2 == 1) )
    {
      if(o_e > 1)
            ans = 1;
      else
        ans = -1;
    }
    else
        ans = -1;
    cout << ans << endl;




   return 0;
}
