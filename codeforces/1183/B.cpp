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
int const N = 1e6 + 10;

bool val(ll n)
{
    ll s = 0;
    while(n){
        s += n % 10;
        n /= 10;
    }
    return s  % 4 == 0;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    ll ans1 = -1e12, ans2 = 1e12;
    int n, k;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        ans1 = -1e12, ans2 = 1e12;
        for(int i = 0; i< n;i++){
            ll a;
            cin >> a;
            ll c1, c2;
            c1 = a - k, c2 = a + k;
            if(c1 > c2) swap(c1,c2);
                ans1 = max(ans1,c1);
                ans2 = min(ans2,c2);
           // cout << c1 << " c2 " << c2 << endl;
           // cout << ans1 << " hum " << ans2 << endl;
        }//ll ans1 = -1e12, ans2 = 1e12;
        if(ans1 > ans2) {
            cout << "-1" << endl;
        }
        else {
            cout << max(ans1,ans2) << endl;
        }


    }

    //assert(0);
    return 0;
}
