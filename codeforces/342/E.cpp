#include <bits/stdc++.h>
using namespace std;
int const BLOCK = 320;
int const MAX = 1e5 +10;
typedef pair < int,int > PII;
int table[MAX][20] , t , par[MAX] , lvl[MAX] , n ,q, tst;
vector<int>edg[MAX];

void dfs(int node ,int parent ,int level) {
    lvl[node] = level;
    for(int i =0 ; i < edg[node].size() ; i++ ) {
        int x = edg[node][i];
        if( x != parent) {
            par[x] = node;
            dfs(x , node , level+1);
        }
    }
}

void build() {

    memset( table , -1 ,sizeof table);
    for(int i =1 ; i <=n ; i++ ) {
        table[i][0] = par[i];
    }

    for(int j =1 ; (1 << j) < n ; j++ ) {
        for(int i =1 ; i <= n ;i++ ) {
            if( table[i][j-1] != -1) {
                table[i][j] = table[table[i][j-1]][j-1];
            }
        }
    }
}

int lca(int u , int v) {

    if( lvl[u] < lvl[v] ) swap(u,v);
    while( lvl[u] > lvl[v] ) {
        int logDist = log2(lvl[u] - lvl[v]);
        u = table[u][logDist];
    }

    if( u == v) return u;

    int logVal = log2(lvl[u]);
    for(; logVal >=0 ; logVal--) {
        if( table[u][logVal] !=-1 && table[u][logVal] != table[v][logVal]) {
            u = table[u][logVal];
            v = table[v][logVal];
        }
    }
    return par[u];
}


int D(int a,int b)
{
    int L = lca(a,b);
    return lvl[a] + lvl[b] - 2 * lvl[L] ;
}
vector < int > ans;
vector < int > red;
int dist[MAX];
int mark[MAX] ;
int vis[MAX];
int tmp_dist[MAX];
void block_bfs()
{
    queue < int > q;
    fill(tmp_dist, tmp_dist + MAX , 1e9);
    memset(vis,0,sizeof vis);
    for(auto x : red)
        tmp_dist[x] = 0, q.push(x), vis[x] = 1;///;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        //vis[u] = 1;

        for(auto v : edg[u])
        {
            if(vis[v]) continue;
            tmp_dist[v] = tmp_dist[u] + 1;
            vis[v] = 1;
            q.push(v);
        }
    }

    for(int i = 1; i <= n; i++)
            dist[i] = min(dist[i], tmp_dist[i]);

}
void blockQ(vector < PII >& Q)
{
    block_bfs();
    vector < int > block_red;
    for(auto  x : Q)
    {
        if(x.first == 1)
        {
            block_red.push_back(x.second);
            //red.push_back(x.second);
        }
        else
        {
            for(auto y : block_red){
//                cout << y << " " << x.second << " " << D(y,x.second) << endl;
//                cout << "LCA :" << lca(y,x.second) << endl;
                dist[x.second] = min(dist[x.second], D(y,x.second));

            }
            //cout << endl;
            ans.push_back(dist[x.second]);
        }
    }
    for(auto x : block_red)
        red.push_back(x);
    //red.clear();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> n >> m;


	for(int i =0 ; i < n -1 ; i++ ) {
            int u , v;
            cin >> u >> v;
            //scanf("%d %d %d",&u,&v,&w);
            edg[u].push_back(v);
            edg[v].push_back(u);
    }
    dfs(1 ,-1 , 0);
    build();
    fill(dist, dist + MAX , 1e9);

	//lca_init();

    vector < PII > Q;
    Q.push_back({1,1});
    red.push_back(1);
    //mark[1] = 1;
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        Q.push_back({a,b});

        if(Q.size() == BLOCK)
        {
            blockQ(Q);
            Q.clear();
        }
    }

    if(Q.size()){
        blockQ(Q);
    }

////    for(int i = 1; i <= n; i++)
////        cout << par[i] << endl;
//    cout << lca(1,2) << endl;
    for(auto x : ans)
        cout << x << '\n';

    return 0;
}
