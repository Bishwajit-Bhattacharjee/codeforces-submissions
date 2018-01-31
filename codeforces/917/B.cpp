/// HK 108 Times
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std ;
#define ll long long
#define pb push_back
typedef pair <int,int>  PII ;
vector < PII > given ;
vector < pair < int , PII >  >  edge  ;
typedef pair < ll, ll > PLL ;
#define all(x) (x).begin() , (x).end()
#define F first
#define S second
#define READ freopen("in.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout)
#define FAST ios_base::sync_with_stdio(false)
#define ll long long
#define M 100007
#define MOD 1000000007
#define endl '\n'

// Order Statistic Tree

/* Special functions:

        find_by_order(k) --> returns iterator to the kth largest element counting from 0
        order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/

typedef tree<
int,					// type long long
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
const int MX = 110;

vector < PII > G[MX];
int dp[MX][MX][29][3];

int DP(int one ,int two ,int carry, int pl)
{

    int &ret = dp[one][two][carry][pl];
    if(ret != -1) return ret;

    if(!pl){
        int win = 0;
        for(auto p: G[one]){
            if(p.S >= carry){
                win |= DP(p.F, two,p.S, !pl);
            }
        }
        return ret = win;
    }
    else {
        int win = 1;
        for(auto p: G[two]){
            if(p.S >= carry){
                win &= DP(one,p.F,p.S, !pl);
            }
        }
        return ret = win;
    }
}

int main()
{
    int n, m ;
    cin >> n >> m ;

    memset(dp,-1,sizeof dp);

    for(int i = 0; i < m; i++){
        int u , v ;
        char c;
        cin >> u >> v >> c ;
        G[u].pb({v,c-'a'}) ;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%c",'A' + !DP(i,j,0,0));
        }
        printf("\n");
    }
    return 0;
}
