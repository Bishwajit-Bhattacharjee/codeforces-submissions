#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const inf =   1 << 28 ;
int  const up = 2 * 1e5 + 10  ;
int const eps = 1e-9;
ll const MOD = 1e5 + 7;
using namespace std;

int main()
{
   vector< PII > p;
    int now[up], then[up];
    int  mark[up] = {0};
    int n, k;
    cin  >> n >> k;
    for(int i = 1; i <= n; i++ )
     scanf("%d", &now[i]);
     for(int j = 1; j <= n; j++)
        scanf("%d", &then[j]);
    for(int i = 1; i <= n; i++)
    {
       p.pb(make_pair(now[i] - then[i], i));

    }
     sort(p.begin(), p.end());
    ll ans = 0;
    for(int i = 0; i < k ; i++)
    {
        ans += now[p[i].second];
        mark[p[i].second] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!mark[i])
            ans += min(now[i], then[i]);
    }
    cout << ans ;
    return 0;
}
