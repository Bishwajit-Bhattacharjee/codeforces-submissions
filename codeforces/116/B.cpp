#include <bits/stdc++.h>

using namespace std;
char a[15][15];
int n , m;
bool yes( int i , int j)
{
    if(i+1 < n && a[i+1][j] =='P')
        return true;
    if(j+1 < m && a[i][j+1] == 'P')
        return true;
    if(i-1 >= 0 && a[i-1][j] =='P')
        return true;
    if(j-1 >=0 && a[i][j-1] == 'P')
        return true;
  return false;
}

int main() {
  /* code */
//

  cin >> n >> m;
  char buf[10];
  gets(buf);
  for(int i =0 ; i < n ; i++)
    gets(a[i]);
  bool eat[15][15];
  int cnt = 0;
  for(int i =0 ; i < n; i++)
  {
      for(int j = 0; j < m; j++)
      {
          if(a[i][j] == 'W' &&  yes(i, j))
            cnt++;
      }
  }
  cout << cnt;

  return 0;
}
