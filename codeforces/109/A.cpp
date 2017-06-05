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
int const MX =   1e2 + 10;
int const mod = 1e9 + 7;

using namespace std;

map  < ll, ll > m;
/*
int last(ll a, ll b)
{
    for(int i = 63; i >= 0 ; i--){
        ll mask = 1LL << i;
        if((a & mask) != (b & mask))
            return i;
    }
}

void update(ll v, ll u, ll w)
{
   int idx = last(v, u);
   m[v] += w;
   for(int i = 0 ; i <= idx; i++){
      v >>= 1;
      m[v] += w;
   }
   for(int i = 0 ; i <= idx; i++){
    v <<= 1;
    if((u & (1LL << (idx - i))) != 0LL){
        m[v + 1] += w;
    }
    else
        m[v] += w;
   }

}

ll solv(ll v, ll u)
{
    int idx = last(v, u);
    ll ans = 0LL;
    ans += m[v];
    for(int i = 0; i <= idx; i++){
        v >>= 1;
        ans += m[v];
    }
    for(int i =0; i <= idx; i++){
        v <<= 1;
        if((u & (1LL << (idx - i))) != 0LL) {
          ans += m[v+1];
        }
        else
            ans += m[v];
    }
    return ans;

}

  */
bool cmp (PII a, PII b)
{
    if(a.F + a.S != b.F + b.S){
        if(a.F == b.F)
            return (a.S < b.S);
        else
            return a.F < b.F;
    }
    else
      return (a.F + a.S < b.F + b.S);

}
int main( )
{
   int f = -1 , s = -1;
   vector < PII > v;

   int n;
   cin >> n;
   for(int i  = 0 ; i <= 1e6 ; i++){
      if( n >= 4 * i && (n - 4 * i) %  7 == 0){
         f = i, s = (n - 4 * i) / 7;
       v.pb({f, s});
      }
   }
   if(v.size() == 0){
    puts("-1");
    return 0;

   }
   sort(v.begin(), v.end(), cmp);
   for(int i = 1 ; i<= v[0].F; i++)
    cout << '4';
   for(int i = 1; i <= v[0].S; i++)
    cout << '7';

   return 0;
}
