#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e5 +5;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;

int main()
{
   int n, m;
   scanf("%d %d ", &n, &m);
   char s[200][200];
   loop(i, 0, n-1)
    gets(s[i]);
    int ans = 0;
    for(int id = 0; id < n; id++)
    {
        bool wasbest = false;
        for(int k = 0; k < m; k++)
        {
            bool isbest = true;
            for(int l = 0; l < n; l++)
            {
                if(s[l][k] > s[id][k])
                    isbest = false;
            }
            if(isbest)
                wasbest = true;
        }
        if(wasbest)
            ans++;

    }
    cout << ans << endl;


   return 0;
}
