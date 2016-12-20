#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e5;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;
#define end return 0
int main()
{

 char soroban[][15] ={"O-|-OOOO","O-|O-OOO", "O-|OO-OO", "O-|OOO-O","O-|OOOO-", "-O|-OOOO", "-O|O-OOO","-O|OO-OO","-O|OOO-O","-O|OOOO-"};
   int n,t, i ;
   cin >> n;
   if (n == 0)
  {

    puts(soroban[0]);
    end;
  }

   while(n != 0)
   {
       t = n % 10;
       puts(soroban[t]);
       n /= 10;
   }

   end ;
}


