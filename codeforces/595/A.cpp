// HK  HK HK HK HK HK   JSN  JRR

#include <bits/stdc++.h>
#define PII pair < int , int >
#define PIB pair < int , bool >
#define PI 2.0*acos(0.0)
#define ll long long int
#define FOR(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a %b == 0)?(a/b):(a/b)+1
#define F first
#define S second
#define lu unsigned long long int
int const up =   1e6 + 10 ;
int const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const MX =   1000 + 10;
int const mod = 1e9 + 7;
using namespace std;


int main()
{
  //  int a[1010];
   int n, m;
   cin >> n >> m;
   int ans = 0;
   for(int i = 1; i <= n; i++){
    for(int j = 1;j  <= m; j++){
        int u, v;
        scanf("%d%d", &u, &v);
        ans += (u | v);
    }
   }
   cout << ans;



    return 0;
}
