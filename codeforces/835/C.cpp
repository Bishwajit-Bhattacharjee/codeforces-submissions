#include <bits/stdc++.h>
using namespace std;
int star[11][110][110];

int main()
{
   int n, q, c;
   cin >> n >> q >> c;
   for(int i = 1; i <= n; i++){
       int x, y, s;
       scanf("%d %d %d", &x, &y, &s);
       star[s][x][y]++;
   }
   for(int s = 0; s <= 10 ; s++){
       for(int x1 = 1; x1 <= 100; x1++){
           for(int y1 = 1; y1 <= 100; y1++){
               star[s][x1][y1] += star[s][x1-1][y1] + star[s][x1][y1-1] - star[s][x1-1][y1-1];
               
           }
       }
   }
   for(int i = 1; i <= q; i++){
       int t, x1, y1, x2, y2;
       scanf("%d %d%d %d %d", &t, &x1, &y1, &x2, &y2);
       int ans = 0;
       for(int br = 0 ; br <= 10 ; br++){
           int nowpower = (br + t) % (c + 1);
           int tmp = star[br][x2][y2] - star[br][x1-1][y2] - star[br][x2][y1-1] + star[br][x1-1][y1-1];
           ans += tmp * nowpower;
       }
       printf("%d\n", ans);
       
       
   }
   
   return 0;
}