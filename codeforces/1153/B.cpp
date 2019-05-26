
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    //sieve();

    int ara[110][110];
    int n,m,h;
    cin >> n >> m >> h;
    int f[110], l[110], top[110][110];

    for(int i = 0; i < m; i++)
    {
        cin >> f[i] ;
    }
    for(int i = 0; i < n; i++)
        cin >> l[i] ;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> top[i][j] ;

    for(int x = 0; x < n; x++)
    {
        for(int y = 0;y < m; y++)
        {
            if(top[x][y])
                ara[x][y] = min(f[y],l[x]);
            else
                ara[x][y] = 0;
            cout << ara[x][y] << ' ';

        }

        cout << '\n';
    }
    return 0;
}