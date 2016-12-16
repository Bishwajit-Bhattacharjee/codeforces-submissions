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
   long long int n, x, a, b;
    cin >> n >> x;
    vector < pair < ll,ll > > m;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a >> b;
        m.push_back(make_pair(a, b));
    }
   long long int ans = 0;
    loop(i, 0, n - 1)
    {
        ans += (m[i].second - m[i].first + 1);
    }

    ans += (m[0].first - 1) % x;
    loop(i,1, n-1)
      ans += (m[i].first - m[i-1].second - 1) % x;

    cout << ans;

   return 0;
}
