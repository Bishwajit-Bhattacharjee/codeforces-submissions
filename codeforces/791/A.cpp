#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
ll const inf =  1LL << 59 ;
int  const MX = 1e7 + 8  ;
int const EPS = 1e-9;
int  const MOD = 1e9 + 7;
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int ans = 0;
    while(a <= b){
        a = 3 * a;
        b = 2 * b;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
