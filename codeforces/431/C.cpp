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

int n, k, d;
int dp[110][3];

int way(int i , int t){
   if(i > n )
     return 0;
   if(i == n)
    return (t == 1);
   if(dp[i][t] != -1)
    return dp[i][t];
   int ans = 0;
   for(int x = 1; x <= k ; x++){
    ans = ((ans % MOD ) + (way(i + x, (x >= d || t == 1)?1: 0)) % MOD) % MOD;

   }
   return dp[i][t] = ans;
}





int main(){

    cin >> n >> k >> d;
    memset(dp, -1 , sizeof dp);
    cout << way(0, 0);

	return 0;
}
