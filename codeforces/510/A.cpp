#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e2 + 1;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)

#define vi(x) vector<int> x;

int main()
{
    int n,m, j;
    cin >> n >> m;
    loop(i, 1, n)
    {
        if(i % 2 == 1)
        {
            loop(j,1,m)
                printf("#");
        }
        else if(i % 4 == 0)
        {
            printf("#");
            loop(j,1, m-1)
              printf(".");
        }
        else
        {
            loop(j, 1 , m-1)
             printf(".");
             printf("#");
        }
        printf("\n");
    }
   return 0;

}
