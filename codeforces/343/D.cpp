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
int t[4*N], lz[4*N];
vector < int > g[N];
int st[N], en[N] ;
int tt;
int tid[N];
int par[N] ;
void push(int p,int l,int r)
{
    if(lz[p] != -1){
        t[p] = (r-l+1) * lz[p];
        if(l != r){
            lz[p*2] = lz[p] ;
            lz[p*2 + 1] = lz[p] ;
        }
        lz[p] = -1;
    }
}

void update(int p,int l,int r,int ul,int ur,int val)
{
    push(p,l,r);
    if(ul <= l and r <= ur) {
        lz[p] = val;
        push(p,l,r);
        return;
    }
    if(l > ur or r < ul) return;
    int mid = (l + r) / 2;
    update(p*2,l,mid,ul,ur,val);
    update(p*2+1,mid+1,r,ul,ur,val);

    t[p] = t[p*2] + t[p*2 + 1] ;
}

int Q(int p,int l, int r,int ul, int ur)
{
    push(p,l,r);
    if(ul <= l and r <= ur) {
        return t[p] ;
    }
    if(l > ur or r < ul) return 0;
    int mid = (l + r) / 2;
    return Q(p*2,l,mid,ul,ur) +
    Q(p*2+1,mid+1,r,ul,ur);

    //t[p] = t[p*2] + t[p*2 + 1] ;
}
void dfs(int u,int p)
{
    par[u] = p;
    st[u] = ++tt;
    tid[tt] = u;

    for(auto v: g[u]){
        if(v == p ) continue;
        dfs(v,u);
    }
    en[u] = tt;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    memset(t,0,sizeof t);
    memset(lz,-1,sizeof lz);
    for(int i = 1 ; i <= n - 1; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1);
    int q;
    cin >> q;
    while(q--){
        int type, node;
        cin >> type >> node ;
        if(type == 1){
            int q = Q(1,1,n,st[node],en[node]);
            if(q == (en[node] - st[node] + 1)){

            }
            else {
                if(par[node] != -1)
                    update(1,1,n,st[par[node]],st[par[node]],0);
                update(1,1,n,st[node], en[node],1);
            }
        }
        else if(type == 2){
            update(1,1,n,st[node],st[node],0);
        }
        else{
            int q = Q(1,1,n,st[node],en[node]);
            cout << (q == (en[node] - st[node] + 1)) << '\n';
        }
    }
    return 0;
}
