
#include <bits/stdc++.h>
#define PII pair < int , int >
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define pb push_back
int const up = 1e5 + 3 ;
using namespace std;

//map < char , string > m;

int main()
{
   int clr[up] = {0};

   int n, m, t1, t2, t3 ;
   cin >> n >> m;
   scanf("%d %d %d", &t1, &t2, &t3);
   clr[t1] = 1; clr[t2] = 2 ; clr[t3] = 3;
   for(int i = 2; i <= m ;i++)
   {
       scanf("%d %d %d", &t1, &t2, &t3);
       if(!clr[t1])
       {
           if(!clr[t2]  && !clr[t3])
           {
               clr[t1] = 1; clr[t2] = 2 ; clr[t3] = 3;

               continue;
           }
           else if(clr[t2]  && clr[t3])
           {
              clr[t1] = 6 - clr[t2] - clr[t3];
              continue;
           }
           else if(clr[t2])
           {
               clr[t1] = (clr[t2] % 3) + 1;
               clr[t3] = (clr[t1] %  3) + 1;
               continue;
           }
           else if(clr[t3])
           {   clr[t1] = (clr[t3] % 3) + 1;
               clr[t2] = (clr[t1] %  3) + 1;
               continue;

           }
       }
       if(!clr[t2])
       {
           clr[t2] = (clr[t1] % 3)  + 1;
           clr[t3] = (clr[t2] % 3) + 1;
           continue;
       }
       if(!clr[t3])
        clr[t3] = 6 - clr[t1] - clr[t2];
   }
   for(int i = 1; i <= n; i++)
     printf("%d ", clr[i]);

   return 0;
}
