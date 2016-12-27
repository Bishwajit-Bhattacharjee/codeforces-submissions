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
bool cmp(int i , int j)
{
    return ( i > j);
}
int main()
{
    int n, m;
    cin >> n;
    int a[110];
    loop(i, 0, n-1)
      cin >> a[i];
    sort (a, a + n, cmp);
    //loop(i, 0, n-1)
      //cout <<  a[i] << ' ' ;
    ll sum  = 0;
    int mul = 1;
    for( int i = 0; i < n; i++)
    {
        sum +=(mul)* sq(a[i]);
        mul *= -1;
    }
    double ans = pi * ((double)sum);
    printf("%0.10lf\n", ans);
    return 0;
}

