#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef  long long ll;
typedef pair<int,int> PII;
const int up = 1e5;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;
#define sq(x) x*x
#define pi  2 * acos(0.0)
//#define end return 0

int main()
{
    int n, m;
    cin >> n >> m;
    int a[110];
    loop(i ,0, n-1)
      cin >> a[i];
    sort(a, a + n);
    int sum = 0;
    for(int i = 0; i < m; i++)
      {
          if(a[i]  > 0 )
            break;
          sum += a[i];

      }
    cout << (-1)*sum << endl;
    return 0;
}
