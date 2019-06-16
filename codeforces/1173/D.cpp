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
int const N = 3e5 + 10;

ll dp[N] ;
int const MOD = 998244353;
vector < int > g[N];
ll sub[N] ;
ll fact[N];
int degree[N];

void dfs(int u, int p = 0)
{
    sub[u] = 1;
    dp[u] = 1;
    int deg = (g[u].size());
    dp[u] *= fact[deg];
    dp[u] %= MOD;

    for(int v : g[u]){
        if(v != p){
            dfs(v,u);
            dp[u] *= dp[v] ;
            dp[u] %= MOD;
            sub[u] += sub[v] ;
        }
    }
    dp[u] = (dp[u] ) % MOD;

}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        //degree[a]++, degree[b]++;
        g[b].push_back(a);
    }
    fact[0] = fact[1] = 1;
    for(int i = 2; i < N; i++)
        fact[i] = ( fact[i-1] * i ) % MOD;

    //fill(dp+1,dp+n+1,1);

    dfs(1);
    ll ans = 1;
    for(int i = 1; i <= n; i++){
        //ans = (ans *  * fact[degree[i]]) % MOD;
    }
    //assert(dp[1] <)
    cout << ( dp[1] * n) % MOD << endl;
    return 0;
}
