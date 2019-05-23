#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef pair<int,int> PII;
typedef long long int ll;
typedef pair< ll,ll> PLL;

PLL operator+(PLL a,PLL b){ return {a.first + b.first, a.second + b.second}; }
PLL operator-(PLL a,PLL b){ return {a.first - b.first, a.second - b.second}; }
PLL operator*(PLL a,PLL b){ return {a.first * b.first, a.second * b.second}; }
PLL operator/(PLL a,PLL b){ return {a.first / b.first, a.second / b.second}; }
PLL operator%(PLL a,PLL b){ return {( b.first + a.first) % b.first, (b.second + a.second) % b.second}; }
PLL operator%(PLL a,ll b){ return {a.first % b, a.second % b} ;}
PLL operator+(PLL a,ll b){ return {a.first + b, a.second + b} ;}
PLL operator-(PLL a,ll b){ return {a.first - b, a.second - b} ;}
PLL operator*(PLL a,ll b){ return {a.first * b, a.second * b} ;}

ostream& operator<<(ostream &out,PLL a)
{
    out << "( " << a.first << ", " << a.second << " )" ;
    return out;
}

/*
	Order Statistics Tree ( OST )

	find_by_order()
		takes an integer k and returns an iterator to the k'th largest element counting from zero
	order_of_key()
		takes an element, here an integer and returns the number of elements strictly smaller than input
*/

typedef tree<
PLL,
null_type,
less<PLL>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int const N = 2e5 + 100;
vector < PLL > g[N];
ll sub[N] ;
ll ans[N] ;
ll lvl[N] ;
ll a[N] ;
//ll cost[]
ordered_set* ost[N] ;

void dfs(int u,ll l)
{
    int big = -1, mx = -1;
    sub[u] = 1, lvl[u] = l;
    for(auto v : g[u]){
        dfs(v.first,l+v.second);
        sub[u] += sub[v.first] ;
        if(sub[v.first] > mx) mx = sub[v.first] , big = v.first;
    }
    if(big != -1){
        ost[u] = ost[big] ;
    }
    else
        ost[u] = new ordered_set;

    ans[u] = (*ost[u]).order_of_key({lvl[u],(ll)1e9});

    for(auto ed: g[u]){
        int v = ed.first;
        if(v != big){
            for(auto x : *ost[v]){
                if(x.first <= lvl[u]) ans[u]++;
                (*ost[u]).insert(x);
            }
        }
    }

    (*ost[u]).insert({lvl[u]-a[u],u});
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    for(int i = 1; i <= n;i++) cin >> a[i] ;

    for(int i = 1;i < n; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back({i+1, b});
    }

    dfs(1,0);

    for(int i = 1; i <= n;i++)
        cout << ans[i] << " ";
    return 0;
}
