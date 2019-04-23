#include <bits/stdc++.h>
using namespace std;
int const N = 1e6 + 10;
vector < int > g[N] ;
typedef long long int ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    //vector < int > ara(n);
    cin >> n;
    vector < int > ara(n);

    for(int i = 1; i < N; i++)
        g[i].push_back(0);
    for(int i = 0; i < n; i++)
        cin >> ara[i] , g[ara[i]].push_back(i+1);

    for(int i = 1; i < N; i++)
    {
        if(g[i].size() > 1)
            g[i].push_back(n+1);
    }
    ll ans = 0;

    for(int i = 1; i < N; i++)
    {
        if(g[i].size() == 1) continue;

        for(int j = 1; j + 1 < g[i].size(); j++)
        {
            ans += 1LL * (g[i][j]-g[i][j-1]) * (g[i].back() - g[i][j]) * 2 - 1;
        }
    }
    cout << fixed << setprecision(6) << 1.0 * ans / (n * 1.0 * n) << '\n';

    return 0;
}
