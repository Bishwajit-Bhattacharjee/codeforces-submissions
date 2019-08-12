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


int const MOD = 1e8 + 7;

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

ll bigmod(ll a, ll b, ll mod = MOD){

    if(b == 0) return 1LL;
    ll x = bigmod(a,b/2);
    x = (x * x ) % mod;
    if(b & 1) x = (x * a) % mod;
    return x;
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m,k;
    cin >> n >> m >> k;
    
    
    vector < ll > a(n+1);

    for(int i = 1; i<= n; i++){
        cin >> a[i] ;
    }

    vector < ll > c1(max(n,m)+10,0), c2(max(n,m)+10,0);

    vector < pair < PLL,ll > > q(m+1);
    
    for(int i = 1; i <= m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        q[i] = {{a,b},c};

    }  

    for(int i = 0; i < k; i++){
        int x,y;
        cin >> x >> y;
        c2[y+1]--, c2[x]++;
    }
    for(int i = 1; i <= m; i++){
        c2[i] += c2[i-1] ;
    }

    for(int i = 1; i <= m; i++){
        auto tup = q[i] ;
        c1[tup.first.first] += c2[i] * tup.second;
        c1[tup.first.second+1] -= c2[i] * tup.second;
    }

    for(int i = 1; i <= n; i++){
        c1[i] += c1[i-1] ;
    }

    for(int i = 1; i <= n; i++)
        cout << a[i] + c1[i] << ' ';
    return 0;
}