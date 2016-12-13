#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = -1e9 -1;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)

#define vi(x) vector<int> x;

int main()
{
   int ans, temp1, temp2;
   int n ;
  vector< PII > p1;
  vector< PII > p2;
   cin >> n;
  while(n--)
  {
      cin >> temp1 >> temp2;
      p1.push_back(make_pair(temp1, temp2));
      p2.push_back(make_pair(temp2, temp1));
  }

  sort(p1.begin(), p1.end());
  sort(p2.begin(), p2.end());
  bool flag = true;
  for(int i = 0 ; i < (int)SZ(p1); i++)
  {
    //  printf(" debug -> %d %d\n",p1[i].first, p2[i].second);
      if(p1[i].first != p2[i].second)
        flag = false;
  }
  if(flag)
     printf("Poor Alex\n");
  else
    printf("Happy Alex\n");

    return 0;

}
