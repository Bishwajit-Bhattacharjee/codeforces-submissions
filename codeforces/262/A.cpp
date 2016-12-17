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
   int n, k;
   cin >> n >> k;
   int temp, cnt = 0, cnt1 = 0;
   loop(i, 0, n-1)
   {
       cnt1 = 0;
       cin >> temp;
       while(temp)
       {
        if(temp % 10 == 4 || temp % 10 == 7)
           cnt1++;
           temp /= 10;
       }
        if(cnt1 <= k)
          cnt++;
    }
    cout << cnt << endl;
   return 0;
}
