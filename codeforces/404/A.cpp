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
    int n ;
    char ch;
    scanf("%d", &n);
    set < char > m;
    set < char > x;
    char a[301][301];
    char buf[10];
    gets(buf);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            scanf("%c", &a[i][j]);
        gets(buf);
    }

    loop(i, 0, n-1)
    {
        ch = a[i][i];
       m.insert(ch);
      // a[i][i] =' ';
    }
    loop(j, 0, n-1)
    {
        ch = a[j][n-j-1];
      m.insert(ch);
      //a[j][n-j-1]=' ';
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j && j != (n-i-1))
                x.insert(a[i][j]);
        }
    }
    set < char > :: iterator it = m.begin();

    set < char > :: iterator it1 = x.begin();
    //cout << *it <<' ' << *it1;
    if((int)m.size() == 1 && (int)x.size() == 1 && *it != *it1)
        printf("YES\n");
    else
        printf("NO\n");

   return 0;

}
