//HK HK HK HK HK 108 times


#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define FOR(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a %b == 0)?(a/b):(a/b)+1
#define F first
#define S second

int const up =   1e6 + 10 ;
int const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const MX =   5 * 1e5 + 10;
int const mod = 10000007;
using namespace std;
// ************************************************************** GLOBAL VARIABLES *******************************************
int dp[30005][700];
bool vis[30005][700];
int a[30001];
int n, d;
int call(int i, int j)
{
    if(i > 30000 or j == 0)
        return 0;

    int jj = j - (d - 350);
    if(vis[i][jj])
        return dp[i][jj];
    vis[i][jj] = 1;
    if(j == 1){
      dp[i][jj] = a[i] + max(call(i + j + 1, j + 1), call(i + j, j ));
    }
    else {
      dp[i][jj] = a[i] + max(call(i + j + 1 , j + 1) , max(call(i + j , j), call(i + j - 1, j - 1)));
    }
    return dp[i][jj];
}


 //***************************************************************** GB ENDS HERE ********************************************
 //*******************************************************FUNCTIONS **********************************

 //*******************************************************FUNCTIONS END HERE *************************
 int main()
{
   //int d;
  while( cin >> n >> d){
   memset(dp, -1, sizeof dp) ;
   memset(a, 0 , sizeof a);
   memset(vis, 0 , sizeof vis);
   for(int i = 0; i < n; ++i){
    int t;
     scanf("%d",&t);
     a[t]++;
   }
    cout << ' ' << call(d, d) << endl;
  }


   return 0;
}



