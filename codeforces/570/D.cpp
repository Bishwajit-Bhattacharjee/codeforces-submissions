#include <bits/stdc++.h>
using namespace std;
int const N = 5e5 + 10;
typedef pair<int,int> PII;
map < int, int > *mask[N] ;
vector < int > nq[N];
vector < int > g[N];
char ch[N] ;
int sub[N] ;
vector <int> ans(N);
vector < PII > q(N);
int lvl[N] ;
void dfs(int u, int l)
{
    int big = -1, mx = -1;
    sub[u] = 1;
    lvl[u] = l;
    for(auto v : g[u])
    {
        dfs(v,l+1);
        sub[u] += sub[v];
        if(sub[v] > mx) mx = sub[v], big = v;
    }
    if(big == -1){
        mask[u] = new map < int,int>();
    }
    else{
        mask[u] = mask[big];
    }
    int can = (1<<(ch[u] -'a'));
    (*mask[u])[l] ^= can;

    for(auto v : g[u]){
        if(v != big){
            for(auto x : *mask[v]){
                (*mask[u])[x.first] ^= x.second;
            }
        }
    }
    for(auto ind : nq[u]){
        if(!(*mask[u]).count(q[ind].second)){
            ans[ind] = 1;
        }
        else
            ans[ind] = ( (__builtin_popcount((*mask[u])[q[ind].second])) <= 1);
    }

}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m ;
    cin >> n >> m ;

    for(int i = 1; i <= n - 1; i++){
        int tmp;
        cin >> tmp;
        g[tmp].push_back(i+1);
    }
    for(int i = 1; i <= n; i++)
        cin >> ch[i] ;

    for(int i = 0; i < m; i++)
        cin >> q[i].first >> q[i].second, nq[q[i].first].push_back(i);

    dfs(1,1);

    for(int i = 0; i < m; i++)
    {
        cout << ((ans[i])?"Yes":"No") << '\n';
    }

    return 0;
}
