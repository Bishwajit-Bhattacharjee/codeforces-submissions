#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e5;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;
#define end return 0
int main()
{
    int d,y,  k, n;
    cin >> y >> k >> n;
    bool f = false;
  /*  if( n <= y || n < k)
    {
        puts("-1");
        end;
    } */


        for(int m = 1 ;m * k <= n ;m++){
          if(m * k - y >= 1)
         {
             f = true;
          printf("%d ", m*k - y);
        }


    }
   if(!f)
    puts("-1");
   end ;
}


