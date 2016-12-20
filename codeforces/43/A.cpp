#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e-9;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;


int main()
{
 // map < string , int > a;
   string s, x;
   int n;
   char buf[10];
  // char a[110][19];
  vector < string > a;
   cin >> n;
   gets(buf);
   loop(i, 0 , n - 1)
   {
       cin >> s;
       a.pb(s);
   }

    sort(a.begin(), a.end());
   cout << a[n/2] << endl;

   return 0;
}
