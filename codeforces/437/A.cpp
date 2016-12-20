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
  string s;
  int a[9];
  loop(i ,0, 3)
  {
      cin >> s;
      a[i] = s.size()-2;
  }
  int c1= 0, c2 = 0, id1, id2;
  loop(i, 0, 3)
  {
      int cc1 = 0;
      loop(j, 0, 3)
      {

          if(i != j)
          {
              if(a[i] * 2 <=  a[j])
                cc1++;
          }
      }
      if(cc1 == 3)
       {
         c1++; id1 = i;
       }
  }
  loop(i, 0, 3)
  {
      int cc2 = 0;
      loop(j, 0, 3)
      {

          if(i != j)
          {
              if(a[i] >= 2 * a[j])
                cc2++;
          }
      }
      if(cc2 == 3)
       {
          c2++;id2 = i;
       }
  }
  if(c1 == 1 && c2 == 0)
    printf("%c\n" ,'A' + id1);
  else if(c1 == 0 && c2 == 1)
    printf("%c\n", 'A' + id2);
  else
    printf("C\n");
   end ;
}


