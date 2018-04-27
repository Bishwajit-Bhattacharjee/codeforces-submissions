#include <bits/stdc++.h>
using namespace std;

map <  pair < int, int  > , int > hasEdge;

int color[100*100*10 + 5] ;
int n, m ;
vector < int > adj[(int)1e5 + 10 ];


int ans= 1;
int maxi ;
int has[(int)1e5 + 10];

int vis[(int)1e5 + 10];

void dfs(int node)
{
        vis[node] = 1;
        int cur = adj[node].size() ;
        if(cur > maxi)
        {
                maxi = cur;
                ans = node;
        }
        else if(cur == maxi)
        {
                ans = min(ans ,node) ;

        }
      //  cout << node << " " << ans << endl;

        for(auto x : adj[node])
        {
                if(!vis[x])
                        dfs(x) ;

        }

}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0) ;
        cout.tie(0);
        maxi = INT_MIN;

//        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n ; i++)
                cin >> color[i+1] , has[color[i+1] ] = 1;

        for(int i = 0; i < m;i++)
        {
                int u ,v ;
                cin >> u >> v;

                if(color[u] > color[v] ) swap(u,v) ;

                if(color[u] != color[v] && !hasEdge.count({color[u],color[v]}))
                {
                        hasEdge[{color[u],color[v]}] = 1;
                        adj[color[u]].push_back(color[v]);
                        adj[color[v]].push_back(color[u]);

                }
                else
                {
                        continue;
                }
        }

        for(int i = 1; i <= 100000; i++)
                if(!vis[i] && has[i])
                        dfs(i);

        cout << ans << endl;
}
