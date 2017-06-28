#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAXN = 1 * 1000 + 10;

int ans[MAXN][MAXN];

int main ()
{
    //ios::sync_with_stdio(false);

    int n, d, k;
    cin >> n >> k >> d;

    ll tmp = 1;
    bool check = false;
    for (int i = 0; i < d; i ++)
    {
        tmp *= k;
        if (tmp >= n)
        {
            check = true;
            break;
        }
    }

    if (!check) 
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i < n; i ++) 
    {
        for (int j = 0; j < d; j ++) ans[i][j] = ans[i - 1][j];
        for (int j = d - 1; j >= 0; j --)
        {
            ans[i][j] = (ans[i][j] + 1) % k;
            if (ans[i][j]) break;
        }
    }

    for (int i = 0; i < d; i ++, cout << endl)
        for (int j = 0; j < n; j ++)
            cout << ans[j][i] + 1 << ' ';
    return 0;
}