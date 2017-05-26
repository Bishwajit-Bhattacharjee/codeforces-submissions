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



ll two(ll n)
{
    if(n <= 1)
        return 0;
    return (n * (n-1))/2;
}

int main()
{
    vector < PII > fr, bc;
   // set < PII > s;
    ll off = 1e9 ;
    ll base = 1e9 + 10;
    int n, u, v;
    map  < PII, ll > m;
    cin >> n;
    for(int i = 0; i< n; i++)
    {
        scanf("%d %d",&u , &v);
        fr.pb({u , v});
        bc.pb({v, u});

        m[{u, v}]++;
      //  s.insert({u, v});

    }
    sort(fr.begin(), fr.end());
    sort(bc.begin(), bc.end());
    ll len = 1, ans = 0LL;
    FOR(i , 0, fr.size()-1)
    {
        if(fr[i].F == fr[i+1].F)
        {
            len++;
        }
        else
        {
            ans += two(len);
            len  = 1LL;
        }

    }
    ans += two(len);
    len = 1LL;
    FOR(i , 0 ,bc.size()-1)
    {
        if(bc[i].F == bc[i+1].F)
            len++;
        else {
            ans += two(len);
            len = 1LL;
        }
    }
    ans += two(len);
   // ans -= two(n - s.size() + 1);
   for(auto it : m)
   {
       //int temp = *it;
       ans -= two(it.S);
   }
    cout << ans ;
    return 0;
}
