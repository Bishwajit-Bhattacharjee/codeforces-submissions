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


//int level[MX];


int main(){
    int n, m ;
    cin >> n >> m;
    int ans = min(m, n)+ 1;
    cout << ans << endl;
    ans--;
    for(int i = ans; i >= 0; i--){
        cout << i << ' '<< ans - i << endl;
    }
	return 0;
}
