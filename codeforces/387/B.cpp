#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef  long long ll;
typedef pair<int,int> PII;
const int up = 1e3;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;
//#define end return 0
int main()
{
    int n, m;
    cin >> n >> m;
    int a[4000], b[4000];
    loop(i, 0, n-1)
      scanf("%d", &a[i]);
    loop(i, 0, m - 1)
    {
        scanf("%d", &b[i]);
    }
    int cnt = 0;
    for(int j = n-1; j >= 0; j--)
    {
        bool f = true;
        for(int k = m-1; k >= 0; k--)
        {
            if(a[j] <= b[k])
            {
                b[k] = 0;
                f = false;
                break;
            }
        }
        if(f) cnt++;
    }
    cout << cnt << endl;
    return 0;
}

