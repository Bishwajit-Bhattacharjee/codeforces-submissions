#include <bits/stdc++.h>
using namespace std;

int const N = 5e5 + 10;
int const MOD = 1e8 + 7;
int const INF = 1e9;

typedef long long ll;
typedef pair<int,int> PII;

vector <int> g[N] ;
vector < PII > q[N] ;
int val[N] , sub[N], lvl[N];
int ans[N] ;
int st[N], en[N], id[N] ;
int cur;
int cnt[N] ;

void pre(int u, int l = 1){

    st[u] = ++cur;
    id[cur] = u;
    sub[u] = 1;
    lvl[u] = l;

    for(auto x : g[u]){
        pre(x,l+1);
        sub[u] += sub[x];
    }
    en[u] = cur;
}
void dfs(int u,int l, bool keep )
{
    //cout << "here " << u << " " << l << endl;

    int big = -1, mx = -1;

    for(auto v : g[u]){
        if(sub[v] > mx){
            mx = sub[v] ;
            big = v;
        }
    }

    for(auto v : g[u]){
        if(v != big){
            dfs(v,l+1,0);
        }
    }
    
    if(big != -1)
        dfs(big,l+1,1);

    cnt[lvl[u]] ^= (1<<val[u]);

    for(auto v : g[u]){
        if(v == big) continue;
        for(int tt = st[v]; tt <= en[v]; tt++){
            cnt[lvl[id[tt]]] ^= (1<<val[id[tt]]);
        }
    }
    for(auto x : q[u]){
        ans[x.second] = (__builtin_popcount((cnt[x.first])) <= 1);
    }

    if(!keep){
        for(int tt = st[u]; tt <= en[u]; tt++){
            cnt[lvl[id[tt]]] ^= (1<<val[id[tt]]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m ;
    cin >> n >> m;

    for(int i = 2; i <= n; i++){
        int t;
        cin >> t;
        g[t].push_back(i);
        //g[i].push_back(t);
    }
    pre(1);

    string s;
    cin >> s;
    //cout << s << endl;

    for(int i = 0; i < s.size(); i++)
        val[i+1] = (s[i]-'a');

    for(int i = 1; i <= m; i++){
        int v,h;
        cin >> v >> h;
        //cout << v << " " << h << endl;
        q[v].push_back({h,i});
        
    }    
    //pre(1,1);
    dfs(1,1,0);

    for(int i = 1; i <= m; i++){
        if(ans[i]){
            cout << "Yes\n";
        }
        else 
            cout << "No\n";
    }


    return 0;
}