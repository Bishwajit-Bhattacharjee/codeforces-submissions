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
int const MX =   1e5 + 10;
int const mod = 1e9 + 7;

using namespace std;


int main()
{
   int n;
   cin >> n;
   vector < PII > v;
   int t1, t2;
   for(int i = 1; i <= n ; i++){
    scanf("%d", &t1);
    v.pb({t1, i});
   }

   sort(v.begin(), v.end());
   for(int i = 0; i<(n/2); i++){
    printf("%d %d\n", v[i].S, v[n-1-i].S);
   }
   return 0;
}
