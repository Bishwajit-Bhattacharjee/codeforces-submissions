#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX 1030

int N, k;
long long dp[MAX][MAX];
long long comb[100002];
map <int, int> cnt;
vector <int> lucky;

bool isLucky(int num)
{
   while(num)
   {
      if((num%10) != 4 && (num%10) != 7)
         return false;
      num /= 10;
   }
   return true;
}

long long bigMod(int base, int pow)
{
   if(pow == 0)
      return 1LL;
   long long x = bigMod(base, pow/2);
   x = (x*x)%MOD;
   if(pow&1)
      x = (x*base)%MOD;
   return x;
}

void Comb(int n)
{
   comb[0] = 1LL;
   for(int i=1; i<=n; i++)
   {
      comb[i] = (comb[i-1]*(n-i+1))%MOD;
      comb[i] = (comb[i] * bigMod(i, MOD-2))%MOD;
   }
   for(int i=n+1; i<100002; i++)
      comb[i] = 0;
}

long long ways(int pos, int taken)
{
   if(dp[pos][taken] != -1)
      return dp[pos][taken];
   /*if(taken == 0)
      return 1;*/
   if(pos == lucky.size()){
       if( taken > k) return 0;

       return comb[k-taken];

   }

   dp[pos][taken] = (ways(pos+1, taken) + (ways(pos+1, taken+1)*cnt[lucky[pos]])%MOD )%MOD;
   return dp[pos][taken];
}

int main()
{
   //ios_base::sync_with_stdio(false);

   int a, unlucky = 0;
   cin>>N>>k;

   for(int i=0; i<N; i++)
   {
      cin>>a;

      if(isLucky(a))
      {
         if(cnt.find(a) == cnt.end())
         {
            lucky.push_back(a);
            cnt[a] = 1;
         }
         else
            cnt[a]++;
      }
      else
         unlucky++;
   }

   Comb(unlucky);
   assert(lucky.size() <= MAX) ;

   memset(dp, -1, sizeof(dp));

   long long ans = 0;

   /*for(int i=max((int)lucky.size(), k); i>=0; i--)
   {
      ans = ( ans + ( ways(0,i)*comb[k-i] )%MOD )%MOD;
      //cout<<ways(0,i)<<endl;
   }*/

   cout<<ways(0,0)<<endl;

   return 0;
}
