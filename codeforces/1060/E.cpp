#include <bits/stdc++.h>
using namespace std;
int const MX = 2e5 + 10;
typedef long long int ll;
vector < int > g[MX];
ll sub[MX];
ll path[MX][2];
ll ans;
ll odd;
ll n ;
void dfs(int u,int p,int lvl)
{
    sub[u] = 1;
    int f = lvl & 1;
    path[u][lvl&1] = 1;
    ll totOdd  = 0, totEven = 1;
    for(auto v : g[u])
    {
        if(v == p ) continue;
        //cout << v << endl;
        dfs(v,u,lvl+1);
        sub[u] += sub[v] ;
        //cout << path[v][1^f] << endl;
        odd += totEven * path[v][1^f] ;
        odd += totOdd * path[v][0^f] ;


        //odd +=
        ans += sub[v] * (n - sub[v]) ;
        path[u][0] += path[v][0] ;
        path[u][1] += path[v][1] ;
        totOdd += path[v][1^f];
        totEven += path[v][0^f];
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1,0);
    //cout << odd << endl;
    assert((ans + odd) % 2 == 0);

    ans = (ans + odd) / 2;
    cout << ans << endl;

    return 0;
}
