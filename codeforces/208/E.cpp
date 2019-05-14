#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 5;
int const LOG = 18;
int sp[N][LOG+1];
typedef pair<int,int> PII;
int n;
vector <int> g[N] ;
int sub[N] ;
int lvl[N] ;
int ind[N], st[N], en[N];
int t;

void dfs(int u, int l)
{
    //vis[u] = 1;
    sub[u] = 1;
    lvl[u] = l;
    st[u] = ++t;
    ind[t] = u;
    for(auto v : g[u]){
        sub[u] += sub[v] ;
        dfs(v, l+1);
        sp[v][0] = u;
    }
    en[u] = t;
}

int kth_parent(int nn,int k)
{
    int par = nn;
    for(int lg = LOG; lg >= 0; lg--)
        if((k & (1<<lg)) ){
            if(sp[par][lg] == -1)
                return -1;
            par = sp[par][lg] ;
        }

    if(par == nn) return -1;
    return par;
}
int ans[N];
vector < int > q(N);
vector < int > nq[N];
//vector < int > *mp[N] ;
int cnt[N] ;

void dsu(int u,bool keep)
{
    //vis[u] = 1;
    int big = -1, sz = -1;

    for(auto v : g[u]){
        //dsu(v);
        if(sub[v] > sz) sz = sub[v], big = v;
        //dfs()
    }

    for(auto v : g[u]){
        if(v != big)
            dsu(v,0);
    }
    //if(big != -1)

    if(big == -1){
        //mp[u] = new vector<int>();
    }
    else {
        dsu(big,1);
        //mp[u] = mp[big] ;
    }
    //(*mp[u]).push_back(u);
    cnt[lvl[u]]++;

    for(auto v: g[u]){
        if(v != big){
            for(int tt = st[v]; tt <= en[v]; tt++){
                cnt[lvl[ind[tt]]]++;
            }
            //(*mp[v]).clear();
        }
    }

    for(auto x : nq[u]){
        ans[x] = cnt[q[x]];
    }
    if(keep)
        return;
    for(int tt = st[u]; tt <= en[u]; tt++){
        cnt[lvl[ind[tt]]]--;
    }

}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n ;
    memset(sp,-1,sizeof sp);
    //vector < int > pr(n+1);
    for(int i = 1; i <= n;i++){
        int tmp;
        cin >> tmp;
        //pr[i] = tmp;
        g[tmp].push_back(i);
    }
    dfs(0,0);
//    for(int i = 1; i <= n;i++){
//        if(!pr[i]) dfs(i,0);
//    }

    for(int lg = 1; lg <= LOG; lg++){
        for(int i = 0; i <= n; i++)
        {
            if(sp[i][lg-1] != -1)
                sp[i][lg] = sp[sp[i][lg-1]][lg-1];
        }
    }

    int m;
    cin >> m;

    for(int i = 0; i < m;i++){
        int v,p;
        cin >> v >> p ;
        //cout << v << " " << kth_parent(v,p) << " " << lvl[v] << " " << lvl[6] << endl;
        int parent = kth_parent(v,p);
        if(parent > 0){
            q[i] = lvl[parent] + p;
            nq[parent].push_back(i);
        }
    }
    //memset(vis,0,sizeof vis);

    dsu(0,0);

    for(int i =0 ;i < m; i++)
        cout << ( (ans[i]) ? (ans[i] - 1 ) : 0 )<< '\n';
    return 0;
}
