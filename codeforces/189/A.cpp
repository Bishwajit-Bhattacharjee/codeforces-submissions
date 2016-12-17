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
   int n, a, b ,c, d;
   cin >> n >>a >> b >> c;
   int ans = 0;
   for(int i =0 ; i*a <= n ; i++){
       for(int j = 0; i*a + j * b <= n; j++){
        int s = n - i* a - j * b;
        if(s % c == 0 )
            ans = max(ans , i+j+(s/c));
       }
   }
   cout << ans;

   return 0;
}
