#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef pair<int,int> PII;
typedef long long int ll;
typedef pair< ll,ll> PLL;
typedef unsigned long long int ULL;
typedef pair<ULL,int> PUI;
#define S second
#define F first
typedef tree<
PLL,
null_type,
less<PLL>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


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

ostream& operator<<(ostream &out,PUI a)
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


int const MOD = 1e9 + 7;
int const N = 2e5 + 10;
ll ans[N] ;
ll sub[N] ;
ll niche[N] ;
vector < int > g[N] ;

void dfs(int u,int p)
{
    sub[u] = 1;
    
    for(int v : g[u]){
        if(v != p ){
            dfs(v,u);
            sub[u] += sub[v];

        }
    }
    niche[u] = sub[u] ;
    for(int v : g[u]){
        if(v != p){
            niche[u] += niche[v];
        }
    }
}

void dfs1(int u,int p)
{
    if(u == 1){
        ans[u] = niche[u];
    }
    if(u != 1){
        ans[u] = ans[p] + sub[1] - 2 * sub[u] ;
        //cout << u << " "<< ans[p] << " "  << ans[u] << endl;
    }
    for(int v : g[u]){
        if(v != p) 
            dfs1(v,u);
    }
    
    
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;

    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1,-1);
    dfs1(1,-1);
    
    cout << *max_element(ans,ans+n+1) << endl;
    return 0;
}
