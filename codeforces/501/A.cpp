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
   int a, b ,c, d;
   cin >> a >> b >> c >> d;
   int m , v;
   m = max(a/10 * 3, a - (a/250)*c);
   v = max(b/10 * 3, b - (b/250)*d);
   if(m > v)
     puts("Misha");
   else if(m < v)
      puts("Vasya");
   else
    puts("Tie");
   return 0;
}
