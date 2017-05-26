// HK  HK HK HK HK HK   JSN  JRR

#include <bits/stdc++.h>
#define PII pair < int , int >
#define PIB pair < int , bool >
#define PI 2.0*acos(0.0)
#define ll long long int
#define F(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a %b == 0)?(a/b):(a/b)+1

#define S second

int const up =   1e6 + 10 ;
int const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const MX =   5 * 1e5 + 10;
int const mod = 10000007;
using namespace std;

ll f(ll n){
  ll r = 1LL;
  while(n)
    r*= (n--);
  return r;
}



int main()
{
    int a[11], b[11];
    int n, m , b1, b2;
    cin >> n >> b1;
    for(int i = 0; i < n ; i++)
    {
        scanf("%d", &a[i]) ;
    }
    cin >> m >> b2;
    for(int i = 0; i< m; i++)
        scanf("%d", &b[i]);

    ll v1 =0LL, v2 = 0LL;
    ll t = 1LL;
    for(int i =  n-1; i >= 0 ; i--)
    {
        v1 += (a[i] * t);
        t *= b1;
    }
     t = 1LL;
    for(int i = m-1; i >= 0 ; i--)
    {
        v2 += (b[i] * t);
        t *= b2 ;
    }
    if(v1 == v2)
        puts("=");
    else if(v1 < v2)
    {
        puts("<") ;
    }
    else
        puts(">");
    return 0;
}
