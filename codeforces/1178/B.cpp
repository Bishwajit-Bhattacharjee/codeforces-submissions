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
int const N = 2e6 + 10;
ll pref[N], suff[N] ;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    string sn;
    cin >> sn;
    sn += '#';
    string s = sn;
    int cnt = 0;
    for(int i = 0; i < sn.size(); ){
        if(sn[i] == 'v'){
            cnt++; i++;
        }
        else {
            pref[i] = max(0,cnt - 1);
            cnt = 0;
            i++;
        }
    }
    cnt = 0;
    int i;
    for( i = sn.size() - 2 ; i >= 0; ){
        if(sn[i] == 'v') {
            cnt++, i--;
        }
        else {
            suff[i] = max(0,cnt - 1);
            cnt = 0;
            i--;
        }
    }
    if(i < 0 and cnt != 0 ) {
        suff[i] = cnt - 1;
    } 
    for(int i = 0; i < s.size(); i++)
    {
        if(i)
            pref[i] += pref[i-1]  ;
        
    }
    for(int i = (int)s.size() -1; i >= 0; i--){
        suff[i] += suff[i+1] ;//+ (s[i] == 'v');
    }
    ll ans = 0;
    for(int i = 1; i + 1 < s.size(); i++){
        if(s[i] == 'o') 
            ans += 1LL*pref[i] * suff[i] ;
    }
    cout << ans << endl;
    return 0;

}
