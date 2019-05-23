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
PII,
null_type,
less<PII>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int const N = 3e5 + 100;
vector < pair<int,int> > g[N];
int sub[N] ;
int ans[N] ;
int lvl[N] ;
PLL nhash[N] ;
int big[N] ;

PLL base = {31,37};
PLL M = {999999937,999999929} ;
PLL expo[N] ;

void dfs(int u,int l, PLL H)
{
    sub[u] = 1;
    lvl[u] = l; // 1 based
    big[u] = -1;
    int mx = -1;
    nhash[u] = H;
    for(auto ed : g[u]){
        PLL tmp = H + expo[l] * (ed.second) ;
        tmp = tmp % M ;
        dfs(ed.first,l+1,tmp);
        int v = ed.first;
        sub[u] += sub[v] ;
        if(sub[v] > mx) {
            mx = sub[v] , big[u] = v;
        }
    }
}
map < PLL, int > *mp[N];
//int ans[N] ;

void add(int ind,int edgeVal)
{

}
void dsu(int u)
{

    ll bigVal = -1;

    for(auto v : g[u]){
        if(v.first == big[u])
            bigVal = v.second;
        dsu(v.first);
    }
    if(big[u] != -1){
        mp[u] = mp[big[u]];
    }
    else
        mp[u] = new map < PLL,int >();

    for(auto v : g[u]){
        if(v.first != big[u]){
            PLL modify = expo[lvl[u]] * ( bigVal-v.second) ;
            modify = ( modify + M) % M;
            for(auto x : *mp[v.first]){
                (*mp[u])[(x.first + modify)%M] += x.second;
            }
        }
    }
    (*mp[u])[nhash[u]]++;

    ans[lvl[u]] -= (sub[u] - (int)(*mp[u]).size() + (g[u].size() != 0)) ;

    for(auto v : g[u]){
        if(v.first != big[u]){
            PLL modify = expo[lvl[u]] * ( bigVal-v.second) ;
            modify = ( modify + M) % M;
            for(auto x : *mp[v.first]){
                (*mp[u])[(x.first + modify)%M] -= x.second;
                if(!(*mp[u])[(x.first + modify)%M]){
                    (*mp[u]).erase((x.first + modify)%M) ;
                }
            }
        }
    }

    for(auto v : g[u]){
        if(v.first != big[u]){
            for(auto x : *mp[v.first]){
                (*mp[u])[x.first] += x.second;
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    for(int i = 1;i < n; i++){
        int a,b;
        char ch;
        cin >> a >> b >> ch;
        g[a].push_back({b,ch-'a' + 1});
    }

    expo[0] = {1,1};
    for(int i = 1; i < N; i++)
        expo[i] = (expo[i-1] * base) % M;

    for(int i = 1; i <= n; i++)
        ans[i] = n;

    dfs(1,1,{0,0});

//    for(int i = 1; i <= n; i++)
//        cout << i << " " << nhash[i] << endl;
    dsu(1);
    int ret = n, ind = -1;
    for(int i = n; i >= 1; i--)
    {
        if(ret >= ans[i])
            ind = i, ret = ans[i] ;
    }
    cout << ret << "\n" << ind << endl;
    return 0;
}
