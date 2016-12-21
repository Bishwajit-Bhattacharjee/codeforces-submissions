#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e6;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;
#define end return 0
int main()
{
    set < int > x;
   int r1,  r2, c1, c2, d1 ,d2, a1, a2, b1, b2;
   cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
   bool f = ((c2+r1-d1)%2==0 &&(c1+r1-d2)%2==0 &&  (c1+r2-d1)%2==0  && (c2+r2-d2)%2==0);
   bool f2 = false;
   if(f)
   {
       a2 = (c2+r1-d1) / 2;
       a1 = (c1+r1-d2) / 2;
       b1 = (c1+r2-d1) / 2;
       b2 = (c2+r2-d2) / 2;
       if(a1 > 0 && a1 < 10 && a2 > 0 && a2 < 10  && b1 > 0 && b1 <10 && b2 > 0 && b2 < 10)
        f2 = true;
       x.insert(a1);
       x.insert(a2);
       x.insert(b1);
       x.insert(b2);
   }
   if(x.size() == 4 && f && f2)
    cout << a1<<' ' <<a2<<'\n' << b1 << ' ' << b2;
   else
    puts("-1");
   end ;
}


