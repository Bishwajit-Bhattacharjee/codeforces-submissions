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
int const MX =   10010;
int const mod = 10000007;
using namespace std;
vi prime;
int mark[MX];
     /*
//memset(mark, )
void seive(){
   for(int i = 0;i < MX ; i++)
    mark[i] = 1;
  // prime.pb(2);
   mark[1] =  0;
   for(int i = 2 ; i < MX ; i++){
    if(mark[i]){
        prime.pb(i);
    for(int j = i * i ; j < MX ; j += i)
        mark[j] = 0;
    }
   }
}  */

ll f(ll a, ll b)
{
    if(a == 0 || b == 0){
          return 0;
    }
    if(a == b){
        return 1;
    }
    if(a > b){
        return (a/b) + f(a - b * (a/b), b);

    }
    if(a < b)
        return (b / a) + f(a, b - a * (b/a));
}
int main(){
 ll a, b;
 cin >> a >> b;
 cout << f(a, b);

  return 0;
}
