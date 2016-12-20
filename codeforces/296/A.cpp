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

int main()
{
   int a[up]={0},n, tmp;
   set < int > x;
   cin  >> n;
   int m;
   (n % 2 == 0)? m = n-2:m = n;
   loop(i, 0, n-1)
   {
     cin >> tmp;
     a[tmp]++;
     x.insert(tmp);
   }
   if(n == 1)
   {
       puts("YES");
       return 0;
   }
   else if(n == 2)
   {
       if(x.size() == 2)
        puts("YES");
       else
        puts("NO");
       return 0;
   }
   else{
   bool f = true;
   if(x.size() < 2)
     f = false;
   else
   {
       loop(i, 1, 1000)
       {
           if( a[i] > (m/2 + 1))
            f = false;
       }
   }
   if(f)
     puts("YES");
   else
    puts("NO");
   }
    return 0;
}


