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
int const N = 1e5 + 10;

bool check(ll a,ll b)
{
    double aa = a;
    return aa * b < (double)8e18;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);    
    ll n,k;
    cin >> n >> k;
    vector < ll > v(n+1,0),ran(n+1);

    for(int i = 1; i <= n; i++){
        cin >> v[i] ;
        ran[i] = i;
        if(v[i] == 1){
            if(v[i-1] == 1){
                ran[i] = ran[i-1];
            }
        }
    }
    
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll pp = 1, sum = 0;
        for(int j = i; j > 0; ){
            if(v[j] == 1) {
                int len = (j-ran[j]+1);
                if(pp % k == 0 and (pp / k - sum > 0) and (pp/k - sum) <= len)
                    ans++;
                pp *= 1;
                sum += len;
                j = ran[j] - 1;
                continue;
            }
            if(!check(pp,v[j])){
                break;
            }
            pp *= v[j] , sum += v[j] ;
            if(pp % sum == 0 and pp / sum == k) ans++;
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}
