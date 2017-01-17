#include <bits/stdc++.h>
#define PII pair < int , int >
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
int const up =  5 * 1e7 + 10 ;
int const up1 = 1e3 + 10;
using namespace std;
  bool cmp ( PII a, PII b)
  {
      if(a.first == b.first)
         return (a.second > b.second);
      return (a.first > b.first);
  }
int main()
{
   vector < PII > v;

   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int n, k, t;
   cin >> n >>k;
   for(int i = 1; i <= n; i++)
   {
       scanf("%d", &t);
       v.pb(make_pair(t, i));
   }
   sort(v.begin(), v.end(), cmp);
   printf("%d\n", v[k-1].first);
  // for(int i = 0; i < v.size(); i++)
    // printf(" %d -> %d\n", v[i].first, v[i].second);
   for(int i = 0; i < k; i++)
    printf("%d ", v[i].second);

  return 0;
}
