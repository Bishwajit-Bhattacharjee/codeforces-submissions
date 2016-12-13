#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = -1e9 -1;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)

#define vi(x) vector<int> x;

int main()
{
   int n, k, l, c, d, p, nl, np;
   cin >> n>> k>> l>> c>> d>> p>> nl>> np;
   int ans = min((k*l)/nl, min((c*d), p/np));
   ans /= n;
   cout << ans << endl;
    return 0;

}
