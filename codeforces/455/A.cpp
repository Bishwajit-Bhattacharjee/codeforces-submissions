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
//int color[MX];
ll dp[MX];
ll cnt[MX] = {0};

ll num(int n){
   if(n == 0)
      return 0;
   if(n == 1)
     return cnt[1];
    if(dp[n] != - 1)
        return dp[n];
   dp[n] = max(num(n - 1),num(n-2) + (ll)n * (ll)cnt[n]);
   return dp[n];
}

int main(){
    int n, a;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        cnt[a]++;
    }
    memset(dp, -1 , sizeof dp);
    cout << num(MX - 10);



    return 0;
}
