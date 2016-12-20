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
    char s[10][10], buf[10];
    int k;
    cin >> k;
    gets(buf);
    loop(i, 0, 3)
        gets(s[i]);
    int sum[19]={0};
    loop(i, 0, 3)
    {
        loop(j, 0, 3)
        {
            if(s[i][j] != '.')
                sum[s[i][j]-'0']++;
        }
    }

    loop(i, 1, 9)
    {
        if (sum[i] > 2* k )
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");

    return 0;
}


