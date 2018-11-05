#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> PII;
int const MX = 3e5 + 10;
#define all(x) (x).begin(), (x).end()
set < PII >* st[MX];
int sub[MX];
vector < int > g[MX];
int ans[MX] ;
void pre(int u,int p)
{
    sub[u] = 1;
    for(auto x : g[u])
    {
        if(x != p)
            pre(x,u),sub[u] += sub[x] ;
    }

}
void dfs(int u,int p)
{
    int big = -1,mx = -1;

    for(auto x : g[u])
    {
        if(x != p){
            dfs(x,u);
            if(sub[x] > mx)
                mx = sub[x] , big = x;
        }
    }
    if(big != -1){
        st[u] = st[big];
    }
    else
        st[u] = new set < PII > ();
    //cout << u << " hello" << endl;
    //cout << st[u]->size() << endl;
    (*st[u]).insert({sub[u],u});

    for(auto x : g[u])
    {
        if(x != p and x != big){
            for(auto tmp : (*st[x])){
                (*st[u]).insert(tmp);
            }
        }
    }

    ans[u] = ((*st[u]).lower_bound({(sub[u]+1)/2,-1}))->second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n , q;
    cin >> n >> q;

    for(int i = 2; i <= n; i++)
    {
        int a;
        cin >> a ;
        g[i].push_back(a);
        g[a].push_back(i);
        //cout << a << endl;
    }
    pre(1,-1);
    dfs(1,-1);

    for(int i = 1; i <= q; i++)
    {
        int v;
        cin >> v;
        //cout << v << endl;
        cout << ans[v] << '\n';
    }
    return 0;
}
