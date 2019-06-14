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


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll two, three, five;

    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector < ll > md(3,0);
        for(int i = 0; i < n; i++){
            int tmp;
            cin >> tmp;
            md[tmp%3]++;
        }
        ll ans = 0;
        ans += md[0] ;
        ll mn = min(md[1],md[2]);
        ans += min(md[1],md[2]);
        md[1] -= mn;
        md[2] -= mn;
        mn = min(md[1]/2,md[2]/2);
        ans += mn;
        md[1] -= 2 * mn;
        md[2] -= 2 * mn;

        ans += (md[1] / 3) ;
        ans += (md[2] / 3);
        cout << ans << endl;
    }
    return 0;
}
