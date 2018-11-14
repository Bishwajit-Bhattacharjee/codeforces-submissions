#include <bits/stdc++.h>
using namespace std;
int const MX = 3e5 + 10;
typedef long long int ll;
typedef pair < int , int > PII ;
ll t[MX] ;
void update(int id, ll val)
{
    while(id < MX)
        t[id] += val, id += (id & -id);
}
ll qr(int id)
{
    ll sum = 0;
    while(id > 0)
    {
        sum += t[id], id -= (id & -id);
    }
    return sum ;
}
vector < int > g[MX] ;
vector < PII > up[MX] ;
ll ans[MX];
void dfs(int n,int p, int h)
{

    for(auto x : up[n])
    {
        update(h,x.second);
        //cout << n << endl;
        if(h + x.first + 1< MX)
            update(h+x.first + 1, -x.second);
    }
    ans[n] = qr(h);
    for(auto x : g[n])
    {
        if(x != p){
            dfs(x,n,h+1);
        }
    }
    for(auto x : up[n])
    {
        update(h,-x.second);
        if(h + x.first + 1< MX)
            update(h+x.first + 1, x.second);
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int m;
    cin >> m;
    while(m--)
    {
        int v,d,x;
        cin >> v >> d >> x;
        up[v].push_back({d,x});
    }
    dfs(1,-1,1);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;

    return 0;
}
