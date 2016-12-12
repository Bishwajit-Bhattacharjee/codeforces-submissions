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
   int n,m, a[52];
   cin >> n >> m;
   loop(i, 0, m-1)
       cin >> a[i];
    sort(a, a+m);
   int best = 1e6;
   for(int k = 0;  k <= m-n; k++)
    best = min(best, a[k+n-1]-a[k]);
   printf("%d\n", best);
  return 0;

}
