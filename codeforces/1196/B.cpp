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
bool isNotPrime[N] ;

void sieve()
{
    for(int i = 2; i < N; i++){
        if(!isNotPrime[i]){
            for(int j = 2 * i ; j < N; j += i) 
                isNotPrime[j] = 1;
        }
    }
}
vector < PII > ans;

void generate(int n,int off)
{
    if(!isNotPrime[n]){
        for(int i = 1; i <= n; i++){
            ans.push_back({off + i,off + i%n + 1 });
        }
        return ;
    }
    if(n == 4){
        ans.push_back({off + 1, off + 2});
        ans.push_back({off + 1, off + 3});
        ans.push_back({off + 2, off + 3});
        ans.push_back({off + 2, off + 4});
        ans.push_back({off + 3, off + 4});
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    //sieve();
    int q;
    cin >> q;
    while(q--){
        int n,k;
        cin >> n >> k;
        vector < int > v(n);
        for(int i = 0;i < n; i++) cin >> v[i] ;
        vector < int > ans ;
        ll tot = 0, cnt = 0;
        for(int i = 0;i < n;i++){
            tot += v[i] ;
            if( (tot & 1) and cnt + 1 < k){
                ans.push_back(i+1);
                tot = 0;
                cnt++;
                //cout << i + 1 << " " << tot << endl;
            }
        }
        if(tot & 1 and cnt + 1 == k){
            ans.push_back(n);
            cout << "YES\n";
           // cout << ans.size() << '\n';
            for(auto x : ans) {
                cout << x << " " ;
                
            }
            cout << '\n';

        }
        else {
            cout << "NO\n";
        }
    }
    return 0;

}
