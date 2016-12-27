#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef  long long ll;
typedef pair<int,int> PII;
const int up = 1e5;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;
//#define end return 0
int main()
{
    int n, m;
    cin >> n;
    int a[up];
    loop(i, 0, n-1)
    {
        scanf("%d", &a[i]);
    }
    if(n == 1 || n == 2)
    {
        printf("%d\n", n);
        return 0;
    }
        //puts("1");
    else
    {
        int maxlen = 2, len = 2 ;
        for(int i = 2; i < n; i++)
        {
            if(a[i] == a[i-1] + a[i-2])
               len++;
            else
            {
                maxlen = max(maxlen, len);
                len = 2;
            }
        }
        printf("%d\n", max(maxlen, len));
    }

    return 0;
}

