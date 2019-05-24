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
vector < int > g[N];
int st[N] , en[N], tid[N] ;
int tt, state[N] , t[4*N], lz[4*N] ;
void dfs(int u)
{
    st[u] = (++tt);
    tid[tt] = u;
    for(int v : g[u]){
        dfs(v);
    }
    en[u] = tt;
}
void build(int p,int l,int r)
{
    if(l == r) {
        t[p] = state[tid[l]] ;
        lz[p] = 0;
        return ;
    }
    int mid = (l+r) / 2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    t[p] = t[p*2] + t[2*p+1] ;
}
void push(int p,int l,int r)
{
    if(lz[p]){
        t[p] = (r-l+1) - t[p] ;
        if(l != r){
            lz[p*2] ^= 1;
            lz[p*2+1] ^= 1;
        }
        lz[p] = 0;
    }
}
void update(int p,int l,int r,int ul,int ur,int val)
{
    push(p,l,r);
    if(ul <= l and r <= ur){
        lz[p] = 1;
        push(p,l,r);
        return ;
    }
    if(ul > r or ur < l ) return;
    int mid = (l+r)/ 2;
    update(p*2,l,mid,ul,ur,val);
    update(p*2+1,mid+1,r,ul,ur,val);
    t[p] = t[2*p] + t[2*p+1] ;
}
int Q(int p,int l,int r,int ul,int ur)
{
    push(p,l,r);
    if(ul <= l and r <= ur){
        return t[p];
    }
    if(ul > r or ur < l ) return 0 ;
    int mid = (l+r)/ 2;
    return Q(p*2,l,mid,ul,ur) + Q(2*p+1,mid+1,r,ul,ur);
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        g[p].push_back(i+1);
    }
    for(int i = 1; i <= n; i++)
        cin >> state[i] ;

    dfs(1);
    build(1,1,n);
    int q;
    cin >> q;
    assert(tt >= n);
//    for(int i = 1; i <= n; i++)
//        cout << i << " " << st[i] << " " << en[i] << endl;
    while(q--){
        string s;
        int node;
        cin >> s >> node;
        if(s != "get"){
            update(1,1,n,st[node],en[node],1);
        }
        else {
            cout << Q(1,1,n,st[node],en[node]) << '\n';
        }
    }
    return 0;
}
