#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;
typedef long long llong;
typedef pair<llong, llong> pll;
typedef unsigned long long ullong;
#define mp make_pair
#define sqr(x) ((x)*(x))
const double PI = 3.14159265359;
#define y1 Y1
#define y0 alalal1231

int n, m, k;
string f[505];
bool used[505][505];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

bool isValid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && f[x][y] == '.' && !used[x][y];
}

void dfs(int x, int y)
{
    used[x][y] = true;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny))
            dfs(nx, ny);
    }
    if (k)
        f[x][y] = 'X', k--;
}

int main()
{

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> f[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (isValid(i, j))
            {
                dfs(i, j);
                break;
            }
    for (int i = 0; i < n; ++i)
        cout << f[i] << '\n';
    return 0;
}