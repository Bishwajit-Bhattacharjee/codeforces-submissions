
#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
ll const inf =  1LL << 59 ;
int  const MX = 1e5 + 5  ;
int const EPS = 1e-9;
int  const MOD = 1e9 + 7;
using namespace std;

//global variables

int   k;
int dp[MX];
int cumsum[MX];
int way(int i)
{
    if(i == 0)
        return 1;
    if(dp[i] != -1)
        return dp[i];
    int ret1 = 0, ret2;
    if(i - k + 1 >= 0)
        ret1 = way(i - k);
    ret2 = way(i - 1);

    return dp[i] = (ret1 % MOD + ret2 % MOD) % MOD;
}


int main(){
    // int n, k;
    int t,a,b;
    scanf("%d%d", &t, &k) ;
    memset(dp, -1  , sizeof dp);
    cumsum[0] = 0;
    for(int i = 1; i < MX; i++)
        cumsum[i] = (cumsum[i-1] + way(i)) % MOD;



    // cin >> n >> k;
    for(int i = 1; i <= t; i++)
    {
        int ans;
        scanf("%d %d", &a, &b);
        ans = cumsum[b] - cumsum[a-1];
        if(ans < 0) ans = ( ans + MOD) % MOD;
        cout << ans << endl;
    }
     //
     //cout << way(1);
    return 0;
}
