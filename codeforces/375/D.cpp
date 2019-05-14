#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 5;
typedef pair<int,int> PII;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

/*
	Order Statistics Tree ( OST )

	find_by_order()
		takes an integer k and returns an iterator to the k'th largest element counting from zero
	order_of_key()
		takes an element, here an integer and returns the number of elements strictly smaller than input
*/

typedef tree<
PII,
null_type,
less<PII>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int n;
vector <int> g[N] ;
int sub[N] ;
int lvl[N] ;
int st[N], en[N];
int tt;
vector <int> nq[N];
vector <int> q(N);
int ans[N];
int tid[N] ;
ordered_set *ost[N];
map < int,int> *colcnt[N];

void hdfs(int u,int l, int p)
{
    st[u] = ++tt;
    tid[tt] = u;
    lvl[u] = l;
    sub[u] = 1;
    for(auto v : g[u]){
        if(v == p) continue;
        hdfs(v,l+1,u);
        sub[u] += sub[v];
    }
    en[u] = tt;
}
int col[N];

void add(int ind, int color)
{
    if(!(*colcnt[ind]).count(color)){
        (*colcnt[ind])[color]++;
        ost[ind]->insert({(*colcnt[ind])[color],color});
        return ;
    }
    (*ost[ind]).erase((*ost[ind]).find({(*colcnt[ind])[color],color}));
    (*colcnt[ind])[color]++;
    ost[ind]->insert({(*colcnt[ind])[color],color});

}
void dfs(int u, int p)
{
    int big = -1, mx = -1;

    for(int v : g[u]){
        if(v == p)continue;
        dfs(v,u);
        if(sub[v] > mx ) mx = sub[v], big = v;
    }
    if(big == -1){
        ost[u] = new ordered_set;
        colcnt[u] = new map <int,int>();
    }
    else {
        ost[u] = ost[big] ;
        colcnt[u] = colcnt[big];
    }
    add(u,col[u]);

    for(int v : g[u]){
        if(v != big and v != p){
            for(int _ = st[v]; _ <= en[v]; _++){
                add(u,col[tid[_]]);
            }
        }
    }

    for(int x : nq[u]){
        ans[x] = ost[u]->size() - (ost[u]->order_of_key({q[x],-1}));
    }

}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int m;
    cin >> n  >> m;
    for(int i = 1; i <= n; i++) cin >> col[i] ;
    for(int i = 0;i < n - 1; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //
    hdfs(1,0,-1);


    for(int i = 0; i < m; i++)
    {
        int v,k;
        cin >> v >> k;
        q[i] = k;
        nq[v].push_back(i);
    }
    dfs(1,-1);

    for(int i = 0; i < m; i++)
        cout << ans[i] << '\n';

    return 0;
}
