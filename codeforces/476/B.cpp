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
    string s1, s2;
    cin >>s1 >> s2;
    ll p1 = 0LL, p2= 0LL , m1 =0LL ,  m2 = 0LL, c = 0;

    F(i, 0 , s1.size()){
      if(s1[i] == '+')
        p1++;
      if(s1[i]== '-'){
            m1++;
      }
      if(s2[i] == '+')
        p2++;
      if(s2[i] == '-')
        m2++;
      if(s2[i] == '?')
        c++;
    }
    if(p1 < p2 || m1 < m2)
    {
        puts("0.0000000");
        return 0;
    }
    p1 -= p2, m1 -= m2;
    ll x = f(p1 + m1);
    x /= f(m1);
    x /= f(p1);
    ll y = 1LL;
    for(int i = 1; i<= c; i++)
        y *= 2;
    printf("%0.9lf", (double)x/y);
    return 0;
}
