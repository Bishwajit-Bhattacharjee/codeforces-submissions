
#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const inf =  1 << 28 ;
int  const array_size = 5 * 1e5 + 10  ;
int const eps = 1e-9;
ll const MOD = 1e8;
using namespace std;

//global variables
int i , j , k;
int k1 , k2 ;
int dp[101][101][11][11];
int way(int n1, int n2, int m1, int m2){
    //puts("why");
    if(n1 == 0 && n2 == 0)
        return 1;
    if(n1 < 0 || n2 < 0)
        return 0;
    if(m1 == k1 && m2 == k2 && (n1 + n2) > 0)
       return 0;
    if(n1 == 0  && n2 == (k2 - m2))
        return 1;
    if(n2 == 0 && n1 == (k1 - m1))
        return 1;
    if(dp[n1][n2][m1][m2] != -1)
        return dp[n1][n2][m1][m2];

    int ret1 =0 , ret2 = 0;
    if(m1 + 1 <= k1 && n1)
        ret1 = way(n1-1, n2, m1 + 1,0);
    if(m2 + 1 <= k2 && n2)
        ret2 = way(n1, n2-1 , 0, m2 + 1);
    return dp[n1][n2][m1][m2] = (ret1 % MOD + ret2 % MOD) % MOD;
 }

int main(){
    int n1, n2 ;
    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp , -1, sizeof dp);

    cout << way(n1, n2 ,0, 0);
    return 0;
}
