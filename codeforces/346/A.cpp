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
#define f first
#define S second

int const up =   1e6 + 10 ;
int const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const MX =   1e5 + 10;
int const mod = 10000007;
using namespace std;

ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}


int main(){
ll n, a[110];
cin >> n;

F(i, 0, n)
{
    cin >> a[i];

}
ll mx= *max_element(a, a + n);
ll g = a[0];
F(i , 1 , n)
{
    g = gcd(g, a[i]);
}
ll p = (mx/g)-1-(n-2);
if(p % 2 == 0)
    puts("Alice");
else
    puts("Bob");

  return 0;
}
