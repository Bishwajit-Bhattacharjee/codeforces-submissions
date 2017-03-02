#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
ll const inf =  1LL << 59 ;
int  const asize = 5005 ;
int const eps = 1e-9;
ll const MOD = 1e8;
using namespace std;

//global variables
ll a[asize], sum[asize];
int n, m, k,num;
ll dp[asize][asize];

ll max_sum(int id, int rem)
{
    if(id >= n)
        return 0;
    if(rem == 0)
    return 0;
   
   
   
   if(dp[id][rem] != -1)
    return dp[id][rem];
   ll ret1, ret2 ;
   ret1 = sum[id] + max_sum(id + m, rem-1);
   ret2 = max_sum(id + 1, rem);
   
   return dp[id][rem]  = max(ret1, ret2);
}



int main(){
    //cout << -1 * inf;
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> k;
    ll tmp = 0;
    for(int i = 0;i < n;i++)
    {
        
        cin >> a[i];
        tmp += a[i];
        if(i >= m - 1)
           {
               sum[i-m+1] = tmp;
               tmp -= a[i-m+1];
    }
    }
    
    
     memset(dp, -1, sizeof dp);
     
    cout << max_sum(0, k) << endl;;
    return 0;
}