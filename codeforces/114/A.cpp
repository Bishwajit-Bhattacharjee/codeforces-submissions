#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e9;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;

int main()
{
    int k, l;
    cin >> k >> l;
    int ans = 0;
    while( l > 0 && (l % k == 0))
    {
        ans++;
        l /= k;

    }
    if(l == 1)
    {
        printf("YES\n%d\n", ans-1);
    }
    else
        printf("NO\n");
   return 0 ;
}
