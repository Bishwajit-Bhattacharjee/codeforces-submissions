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
int const MX =   5 * 1e5 + 10;
int const mod = 10000007;
using namespace std;

ll zc(ll n)
{
    int i = 1;
    ll ans  =0;
    ll mul = 5;
    ll t = n;
    while((t /mul)!= 0)
    {
      ans += (n / mul) ;
      mul *= 5;
      i++;

    }
    return ans;
}

int main(){

int n, k =0;
cin >> n;

vi v;
for(int i = 1 ; i <MX; i++){
    if(zc(i) == n){
        v.pb(i);
    }
}
cout << v.size() << '\n';
for(int i = 0; i < v.size(); i++)
    cout << v[i] << ' ';
  return 0;
}
