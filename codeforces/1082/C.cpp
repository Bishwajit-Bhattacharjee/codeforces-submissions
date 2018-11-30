#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int,int > PII;
typedef pair < ull,ll > PLL;
#define F first
#define S second
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
int const MX = 2e5 ;

ll n, m;

vector < ll > s[MX];
vector < ll > cum[MX] ;
ll ans[MX];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        s[a].pb(b);

    }

    for(int i = 1; i <= m; i++){
        sort(s[i].begin(),s[i].end(), greater < ll > ());
        ll ss = 0;
        for(int j = 0; j < s[i].size(); j++)
        {
            cum[i].pb(ss += s[i][j]);
            if(ss >= 0)
                ans[j+1] += ss;
        }
    }

    cout << *max_element(ans, ans + MX) << endl;


    return 0;
}
