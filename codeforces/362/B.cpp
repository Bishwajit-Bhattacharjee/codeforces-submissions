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
int main()
{
    int n, m, tmp, bad[up];
    cin >> n >> m;
    //bool f = false;
    loop(i, 0, m-1)
    {
       scanf("%d", &bad[i]);
       if(bad[i] == 1 || bad[i] == n)
       {
        //f = true;
           puts("NO");
           return 0 ;
       }
    }
    sort(bad , bad + m);
  // if(!f)
   //{
       loop(i, 1, m-2)
    {
        if(((bad[i]-bad[i-1]) == 1) && ((bad[i] -bad[i-1]) == 1) && ((bad[i+1]-bad[i]) == 1))
         {
             puts("NO");
             return 0 ;
         }
    }
   //}
   puts("YES");
    return 0;
}



   //end ;



