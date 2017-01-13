#include <bits/stdc++.h>
#define PII pair < int , int >
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define pb push_back
int const up = 1e5 + 10 ;
int const up1 = 1e8 + 10;
using namespace std;
//vector < int > divi[100007];
int main()
{

  int n, k;
  cin >> n >> k;
  int a[up]; bool f[up];
  for(int i = 0 ;i  < up ; i++)
  {
      f[i] = true;
  }
  loop(i, 0, n)
  {
      scanf("%d", &a[i]);
  }
  int cnt[up];
  for(int i = 0; i < up ; i++)
     cnt[i] = 0;

  for(int i = 0; i < n; i++)
  {
    if(f[i])
    {
     for(int j = i; j < n; j+= k)
     {
         cnt[i] += a[j];
         //printf(" debug -> %d %d\n",i,  cnt[i]);
         f[j] = false;
     }
    }


  }
  int ans = up1;
  int ai = 0;
  for(int i = 0; i < n; i++)
  {

       if(cnt[i] < ans  && cnt[i])
        {
            ai = i; ans = cnt[i];
            //printf(" debug -> %d %d\n",i,  cnt[i]);
        }
  }
  //for(int )
  cout << ai + 1<< endl;
  return 0;
}
