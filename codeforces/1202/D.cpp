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

int const N = 1e5 + 10;
bool mark[N] ;

void sieve()
{
    for(int i = 2; i < N; i++){
        if(!mark[i]){
            for(int j = 2 * i ; j < N; j += i) 
                mark[j] = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    vector < ll > com;
    map < ll, ll > mp;
    for(ll i = 1; i*(i-1)/2 <= 1e9; i++){
        com.push_back(i*(i-1)/2) ;
        mp[i*(i-1)/2] = i;
    }

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;

        auto it = upper_bound(com.begin(), com.end(), n);
        it--;
        ll up = *it;
       // cout << up << endl;

        
        int left = n - up;
        up = mp[up] ;

        up -= 2;
        string s = "";
        s += "733";

        for(int i = 0; i < left; i++)
            s += '1';
        for(int i = 0; i < up; i++)
            s += '3';
        s += '1';

        reverse(s.begin(), s.end());

        assert(s.size() <= 1e5);
        cout << s << endl;

    }

    return 0;

}