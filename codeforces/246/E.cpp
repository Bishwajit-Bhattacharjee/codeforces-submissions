#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 5;
typedef pair<int,int> PII;
int n;
vector <int> g[N] ;
int sub[N] ;
int lvl[N] ;
string str[N];
vector <int> nq[N];
vector <int> q(N);
int ans[N];

void hdfs(int u,int l)
{
    lvl[u] = l;
    sub[u] = 1;
    for(auto v : g[u]){
        hdfs(v,l+1);
        sub[u] += sub[v];
    }
}
map <int,set<string> > *mp[N] ;

void dfs(int u)
{
    int big = -1, mx = -1;
    for(int v : g[u]){
        dfs(v);
        if(sub[v] > mx) mx = sub[v], big = v;
    }
    if(big != -1){
        mp[u] = mp[big] ;
    }
    else {
        mp[u] = new map <int, set <string> >();
    }
    (*mp[u])[lvl[u]].insert(str[u]);

    for(int v: g[u]){
        if(v != big){
            for(auto x : *mp[v]){
                for(auto y : x.second){
                    (*mp[u])[x.first].insert(y) ;
                }
            }
            (*mp[v]).clear();
        }
    }

    for(auto x : nq[u]){
        ans[x] = (*mp[u])[q[x]].size();
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n ;
    int tmp;
    for(int i = 1; i <= n; i++){
        cin >> str[i] >> tmp;
        g[tmp].push_back(i);
    }
    hdfs(0,0);

    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        q[i] = lvl[a] + b;
        nq[a].push_back(i);
    }
    dfs(0);

    for(int i = 0;i < m; i++)
        cout << ans[i] << '\n';
    return 0;
}
