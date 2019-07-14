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
int row[N], col[N];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s,t,p;
        cin >> s >> t >> p;
        int cnt[3][30];
        memset(cnt,0,sizeof cnt);

        for(auto x : s)
            cnt[0][x-'a']++;

        for(auto x : p)
            cnt[1][x-'a']++;

        for(auto x : t)
            cnt[2][x-'a']++;
        bool f = 1;

        int idt = 0, ids = 0;
        s += '#';
        while(f and idt < t.size() and ids < s.size()){
            if(t[idt] != s[ids]){
                if(cnt[1][t[idt]-'a'] > 0){
                    cnt[1][t[idt]-'a']--;
                    idt++;
                }
                else {
                    //cout << "NO" << '\n';
                    f = 0;
                }
            }
            else {
                idt++, ids++;
            }
        }
        if(ids + 1 == s.size() and idt == t.size() and f){
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
        //cout << ((f) ? "NO":"YES") << '\n';
    }
    return 0;
}
