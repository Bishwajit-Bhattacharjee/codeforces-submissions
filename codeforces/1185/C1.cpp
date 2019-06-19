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


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, t;
    cin >> n >> t;

    priority_queue < ll > pq;

    vector < int > v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
    }
    int ans = 0;
    ll tot = 0;
    vector < int > a;

    for(int i = 0; i < n; i++){
        ans = 0;
        while(tot + v[i] > t){
            tot -= pq.top();
            a.push_back(pq.top());
            pq.pop();
            ans++;
        }
        tot += v[i] ;
        pq.push(v[i]);
        while(!a.empty()){
            pq.push(a.back());
            tot += a.back();
            a.pop_back();
        }
        cout << ans << '\n';
    }
    return 0;
}

