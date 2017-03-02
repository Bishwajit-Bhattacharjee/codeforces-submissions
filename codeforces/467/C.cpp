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
ll a[asize], sum[asize] = {0};
int n, m, k,num;
ll dp[asize][asize];
ll max_sum(int id, int rem)
{
   if(rem < 0)
        return  (-1 *inf);

   if (id >= num)
   {
       if(rem == 0)
          return 0LL;
       else
        return (-1 * inf);
   }
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

    cin >> n >> m >> k;
    loop(i , 0 ,n-1)
    {
        scanf("%I64d", &a[i]);
    }
    loop(i, 0, n-m+1)
    {
        for(int j = 0; j < m ; j++)
            sum[i] += a[i + j];
    }
     num  = n-m+1;
     memset(dp, -1, sizeof dp);
    cout << max_sum(0, k);
    return 0;
}