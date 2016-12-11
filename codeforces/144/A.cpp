#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;

#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)

#define vi(x) vector<int> x;

int main()
{
  int n, ara[110];
  int i_min=0, i_max=0;
  scanf("%d", &n);
  loop(i, 0, n-1)
  {
      scanf("%d", &ara[i]);
  }
  //loop()
  int l = ara[0], s = ara[0];
  loop(i, 0, n-1)
  {
      if(ara[i]>l)
      {
          l = ara[i];
          i_max = i;
      }
      if(ara[i] <= s)
      {
          s = ara[i];
          i_min = i;
      }
  }
  int ans ;
  if(i_max == i_min)
    ans = 0;
  else if(i_max > i_min)
    ans = i_max + (n - 1-i_min) - 1;
  else
    ans = i_max + n -1- i_min;
  printf("%d\n", ans);
  return 0;
}
