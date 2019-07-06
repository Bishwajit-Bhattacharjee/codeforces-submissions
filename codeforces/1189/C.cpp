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
int const LOG = 20;
PLL dp[N][LOG+1];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i = 0;i <= LOG; i++){
        for(int j = 0; j < N ; j++)
            dp[i][j] = PII(-1,-1);
    }
    int n;
    cin >> n;
    vector < ll > v(n);
    for(int i = 0; i< n; i++){
        cin >> v[i] ;
        dp[i][0] = PII(0,v[i]);
    }
    for(int lg = 1; (1<<lg) <= n; lg++){
        for(int i = 0; i < n; i++){
            if(dp[i][lg-1].first != -1){
                int nxt = i + (1LL<< (lg-1)) ;
                dp[i][lg].first = (dp[i][lg-1].first + dp[nxt][lg-1].first ) ;
                dp[i][lg].second = (dp[i][lg-1].second + dp[nxt][lg-1].second ) % 10;
                dp[i][lg].first += (dp[i][lg-1].second + dp[nxt][lg-1].second) >= 10 ;
            }
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        ll l,r;
        cin >> l >> r;
        l--,r--;
        int cnt = 0;
        ll val = r - l + 1;
        while(val != 1){
            val /= 2;
            cnt++;
        }
        cout << dp[l][cnt].first << '\n';
    }
    return 0;
}
