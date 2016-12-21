#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e6;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;
#define end return 0
int main()
{
   int n, m,tmp, n1= 0, n_1 = 0, l , r;
     scanf("%d %d", &n ,&m);
   loop(i, 1, n)
    {
         scanf("%d", &tmp);
         (tmp == 1)?n1++:n_1++;
    }
  // cout << n1 << ' ' << n_1;
    loop(i, 1 ,m)
    {
        scanf("%d %d", &l, &r);
        int m = (r-l+1);
       // printf("\n %d ", m);
        //cout <<'\n' << (r-l+1);
        if((  m % 2 == 0) && (m/2 <= n1) && (m/2 <= n_1))
            puts("1");
        else
            puts("0");

    }

   end ;
}


