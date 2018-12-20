#include <bits/stdc++.h>
using namespace std;
int const N = 3e5 + 10;
int par[N] ;
vector < int > g[N];
bool vis[N] ;
int dist[N];
vector < int > comp;
int cost[N];

void dfs(int node, int pr, int dst)
{
    dist[node] = dst;
    vis[node] = 1;
    comp.push_back(node);

    for(auto x : g[node])
    {
        if(x == pr) continue;
        dfs(x,node, dst+1);
    }

}
int Find(int node)
{
    return par[node] = ((par[node] == node)? node : Find(par[node]) );
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;

    for(int i = 1; i <= m; i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            comp.clear();
            dfs(i,-1,0);
            int mx = -1, node = -1;
            for(auto x : comp)
            {
                if(mx < dist[x]){
                    mx = dist[x] ;
                    node = x;
                }
                //dist[x] = 0;
            }
            comp.clear();
            dfs(node,-1,0);
            int dim = 0;
            for(auto x : comp)
            {
                par[x] = i;
                dim = max(dim,dist[x]);
            }
            cost[i] = dim;
        }
    }

    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int node;
            cin >> node;
            int boss = Find(node);
            cout << cost[boss] << '\n';
        }
        else
        {
            int a,b;
            cin >> a >> b;
            int A = Find(a);
            int B = Find(b);
            if(A != B)
            {
                par[A] = B;
                cost[B] = max(cost[A],max(cost[B], 1 + (cost[B]+1)/ 2 + (cost[A] + 1) / 2 ) );

            }
        }
    }

    return 0;
}
