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

int const MOD = 1e9 + 7;
int const N = (1<<15) + 10;
int n, T;
int len[20], g[20] ;
ll dp[N][250][4];

ll DP(int mask,int time,int lt)
{
    if(time == 0) return 1;
    if(time < 0) return 0;
    if(mask == 0) {
        return (time == 0);
    }
    ll &ret = dp[mask][time][lt];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < n;i++){
        if(mask & (1<<i) and g[i] != lt){
            ret += DP(mask^(1<<i),time - len[i],g[i]);
            if(ret >= MOD)
                ret -= MOD;
        }
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> T;

    for(int i = 0; i < n; i++){
        cin >> len[i] >> g[i] ;
    }
    memset(dp,-1,sizeof dp);

    cout << DP((1<<n)-1,T,0) << endl;

    return 0;
}
