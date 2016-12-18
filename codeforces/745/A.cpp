#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e-9 ;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;

int main()
{
   string s;
   cin >> s;
   set < string > m;
   int len = s.size();
   s += s;
   loop(i, 0, len - 1)
   {
       m.insert(s.substr(i, len));

   }

   cout << m.size() << endl;
   return 0;
}
