#include <bits/stdc++.h>
using namespace std;
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

int const N = 5e5 + 5;
vector < int > g[N];
int st[N], en[N] ;
int tt;
int tid[N];
int lvl[N] ;
vector <char> ch[N];
int sub[N] ;
int ans[N];
int mask[N] ;
void dfs(int u,int p, int l = 0, int m = 0)
{
   // par[u] = p;
    st[u] = ++tt;
    tid[tt] = u;
    sub[u] = 1;
    lvl[u] = l;
    mask[u] = m;
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(v == p ) continue;
        dfs(v,u, l + 1, m ^(1<<(ch[u][i]-'a')));
        sub[u] += sub[v] ;
    }
    en[u] = tt;
}
int makhon[(1<<22)+10] ;

int solve(int node, int par)
{
    int ret = 0;
    for(int i = 0; i < 22; i++){
        int can = 0;
        int ind = mask[node] ^ (1<<i) ;
        if(makhon[ind] != -1){

            ret = max(ret,lvl[node] + makhon[ind] - 2 * lvl[par]);
        }
    }
    if(makhon[mask[node]] != -1){
        ret = max(ret,lvl[node] + makhon[mask[node]] - 2 * lvl[par]);
    }
    return ret;
}
void add(int u)
{
    makhon[mask[u]] = max(makhon[mask[u]], lvl[u] );
}
void dsu(int u,int p, bool keep)
{
    int big = -1, mx = -1;
    for(auto v: g[u]){
        if(v == p) continue;
        if(sub[v] > mx) mx = sub[v], big = v;
    }

    for(auto v : g[u]){
        if(v != big and v != p)
            dsu(v,u,0);
    }
    if(big != -1)
        dsu(big,u,1);

    int can = solve(u,u);
    if(big != -1)
        can = max(can,ans[big]);

    add(u);
    for(auto v : g[u]){
        if(v == p or v == big) continue;
        can = max(can,ans[v]);
        for(int ind = st[v]; ind <= en[v]; ind++){
            can = max(can, solve(tid[ind],u));
        }
        for(int ind = st[v]; ind <= en[v]; ind++){
            add(tid[ind]);
        }
    }

    ans[u] = can;

    if(!keep){
        for(int ind = st[u]; ind <= en[u]; ind++){
            int node = tid[ind];
            makhon[mask[node]] = -1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    memset(makhon,-1,sizeof makhon);

    for(int i = 1 ; i <= n - 1; i++){
        int a;
        char cc;
        cin >> a >> cc;
        g[a].push_back(i+1);
        g[i+1].push_back(a);
        ch[a].push_back(cc);
        ch[i+1].push_back(cc);
    }
    dfs(1,-1);
//
//    for(int i = 1; i <= n; i++)
//    {
//        cout << st[i] << " " << en[i] << " " << lvl[i] << " " << mask[i] << endl;
//    }
    dsu(1,-1,0);
    //cout << 'v'-'a' << endl;
    for(int i = 1; i <= n; i++)
        cout << ans[i] << '\n';


    return 0;
}
