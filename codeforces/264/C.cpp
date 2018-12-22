#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int,int > PII;
typedef pair < ll,ll > PLL;
#define F first
#define S second
#define FAST ios::sync_with_stdio(0);cin.tie(0)
ostream& operator<<(ostream & os, PLL h)
{
	return os << "( " << h.F << ", " << h.S << " )" << endl;

}
PLL operator+ (PLL a, ll x)     {return {a.F + x, a.S + x} ;}
PLL operator- (PLL a, ll x)     {return {a.F - x, a.S - x} ;}
PLL operator* (PLL a, ll x)     {return {a.F * x, a.S * x} ;}
PLL operator+(PLL x, PLL y) { return {x.F + y.F,x.S + y.S} ;}
PLL operator-(PLL x,PLL y) { return {x.F - y.F, x.S - y.S} ;}
PLL operator*(PLL x,PLL y) { return {x.F * y.F , x.S * y.S} ;}
PLL operator%(PLL x,PLL y) { return {x.F % y.F, x.S % y.S} ;}
bool operator==(PLL x,PLL y) { return x.F == y.F and x.S == y.S ;}
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace __gnu_pbds;

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

ll const INF = 1e13;
ordered_set ost;

int const N = 1e5 + 10;

int color[N] ;
ll dp[N+2];
ll val[N] ;
int a,b,n;
bool vis[N] ;

PLL mora_set[2];

ll rectify(ll val)
{
    return max(0LL, val);
}
ll solve()
{
    int p = 0, q = -1;
    for(int i = 1; i <= n; i++)
        dp[i] = -INF;
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        ll &r = dp[color[i]];
        if(r != -INF)
            r = max(r,r + a * val[i]);
        if(p != color[i])
            r = max(r, dp[p] + b * val[i]);
        else if( q != color[i])
            r = max(r, dp[q] + b * val[i]);

        if(color[i] != p and (q == -1 or dp[q] < r))
            q = color[i] ;
        if(dp[q] > dp[p])
            swap(p,q);
    }
    return dp[p];
}
int main()
{
    FAST;
    int q;
    cin >> n >> q;
//    vector < ll > dp(n + 2, 0);
    for(int i = 1; i <= n; i++)
        cin >> val[i] ;
    for(int i = 1; i <= n; i++)
        cin >> color[i] ;
    //ost.clear();
    while(q--)
    {
        cin >> a >> b;
        mora_set[0] = {-INF,-INF};
        mora_set[1] = {-INF,-INF};
        memset(dp,0,sizeof dp);
        memset(vis,0,sizeof vis);
        cout << max(0LL,solve()) << '\n';
    }
    return 0;
}
