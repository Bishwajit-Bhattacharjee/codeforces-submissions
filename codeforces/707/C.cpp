#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
ll const inf =  1LL << 59 ;
int  const MX  = 1e5 + 10;
int const EPS = 1e-9;
int  const MOD = 1e9 + 7;
using namespace std;


int main(){
    ll n, m , k ;
    cin >> n;
    if(n == 1 || n == 2)
    {
        puts("-1");
        return 0;
    }
    if(n % 2 == 0){
        cout << (n*n)/4 - 1 <<' '<< (n*n)/4 + 1;
        return 0;
    }
    if(n % 2 == 1 ){
        cout << (n*n + 1)/ 2 << ' ' << (n*n - 1)/2;
    }

    return 0;
}
