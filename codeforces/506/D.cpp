#include <bits/stdc++.h>
using namespace std;
typedef pair < int, int > PII;

int const MX = 1e5 + 10;

int p[4*MX];

unordered_map <int, unordered_map < int, int > > par, seen;


int deg[MX];

int Find(int node)
{
    return p[node] = (p[node] == node)? node : Find(p[node]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int id = -1;
    int n,m;
    cin >> n >> m;

    for(int i = 0; i < 4 * MX ; i++)
        p[i] = i;

    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        deg[a]++, deg[b]++;
//        g[a].insert(c);
//        g[b].insert(c);
        if(!par[a].count(c))
            par[a][c] = ++id;

        if(!par[b].count(c))
            par[b][c] = ++id;

        int A = Find(par[a][c]);
        int B = Find(par[b][c]);
        if(A != B)
            p[A] = B;
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int u,v;
        cin >> u >> v;
        int mn = min(u,v);
        int mx = max(u,v);

        if(seen.count(mn) and seen[mn].count(mx)){
            cout << seen[mn][mx] << '\n';
            continue;
        }

        if(deg[u] > deg[v]) swap(u,v);
        int cnt = 0;

        for(auto x : par[u]){

            if(par[v].count(x.first))
                 cnt += ( Find(x.second) == Find(par[v][x.first]));
        }
        cout << cnt << '\n';
        seen[mn][mx] = cnt;
    }
    return 0;
}

