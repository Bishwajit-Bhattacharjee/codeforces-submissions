#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long int ll;

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

int const N = 1e6 + 100;
vector < int > g[N];
int sub[N] ;
int ans[N] ;
int lvl[N] ;
//int cnt[N] ;
set < PII > *st[N] ;
map < int,int > *cnt[N] ;
void pre(int u, int p,int l)
{
    sub[u] = 1;
    lvl[u] = l;
    for(auto v : g[u]){
        if(v != p){
            pre(v,u,l+1);
            sub[u] += sub[v] ;
        }
    }
}

void add(int ind, int L,int val)
{
    if(!cnt[ind]->count(L)){
        (*cnt[ind])[L] += val;
        st[ind]->insert({-val,L});
        return ;
    }

    st[ind]->erase(st[ind]->find({-(*cnt[ind])[L],L}));
    (*cnt[ind])[L] += val;
    st[ind]->insert({-(*cnt[ind])[L], L});
}
void dfs(int u,int p)
{
    int big = -1, mx = -1;
    for(auto v : g[u]){
        if(v != p){
            if(sub[v] > mx) {
                mx = sub[v], big = v;
            }
        }
    }

    for(auto v : g[u]){
        if(v != p and v != big)
            dfs(v,u);
    }
    if(big != -1){
        dfs(big,u);
        st[u] = st[big] ;
        cnt[u] = cnt[big] ;
    }
    else {
        st[u] = new set < PII > ();
        cnt[u] = new map <int,int> ();
    }

    add(u,lvl[u],1);

//    vec[u]->push_back(u);
//    cnt[lvl[u]]++;
//    if(cnt[lvl[u]] > ansCnt[u]){
//        ansCnt[u] = cnt[lvl[u]] ;
//        ans[u] = lvl[u] ;
//        //ansh[u] = lvl
//    }
//    else if(cnt[lvl[u]] == ansCnt[u]){
//        ans[u] = min(lvl[u],ans[u]);
//    }

    for(auto v : g[u]){
        if( v != p and v != big){
            for(auto x : *cnt[v]){
                add(u,x.first,x.second);
            }
        }
    }

    ans[u] = (*(st[u]->begin())).second ;
//    if(!keep){
//        for(auto x : *vec[u]){
//            cnt[lvl[x]]--;
//        }
//    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n - 1; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    pre(1,-1,0);
    dfs(1,-1);

    for(int i = 1; i <= n; i++){
        cout << ans[i] - lvl[i] << '\n';
    }

    return 0;
}
