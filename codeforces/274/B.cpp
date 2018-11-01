#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const MX = 1e5 + 10;
ll ara[MX] ;
vector < int > g[MX] ;
ll Plus[MX], Minus[MX] ;

void dfs(int u,int p)
{
    ll pos = -1, neg = -1;

    for(auto x : g[u]){
        if(x == p ) continue;
        dfs(x,u);
        pos = max(pos,Plus[x]);
        neg = max(neg,Minus[x]);
    }

    if(pos < 0 and neg < 0){
        if(ara[u] > 0 )
            Minus[u] = ara[u], Plus[u] = 0;
        else
            Plus[u] = -ara[u], Minus[u] = 0 ;

    }
    else {
        ara[u] = ara[u] + pos + (-neg);
        if(ara[u] > 0 )
            Minus[u] = ara[u] + neg, Plus[u] = pos;
        else
            Plus[u] = pos - ara[u], Minus[u] = neg;

    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n - 1; i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
        cin >> ara[i] ;
    dfs(1,-1);
    cout << Plus[1] + Minus[1] << endl;
    return 0;
}
