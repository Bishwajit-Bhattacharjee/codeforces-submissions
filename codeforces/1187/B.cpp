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

int cnt1[N][30], cnt2[30];
string s;

bool can(int val)
{
    for(int i = 0; i < 26; i++){
        if(cnt1[val][i] < cnt2[i]) return 0;
    }
    return 1;
}
ll solve(string &st)
{
    memset(cnt2,0,sizeof cnt2);

    for(auto x : st) cnt2[x-'a']++;
    int lo = 1,hi = s.size();
    int ans = hi;
    while(lo <= hi){
        int mid = (lo + hi)/ 2;

        if(can(mid)){
            ans = min(ans,mid);
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    cin >> s;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 26;j++){
            if(s[i-1] - 'a' == j) cnt1[i][j] = cnt1[i-1][j] + 1;
            else cnt1[i][j] = cnt1[i-1][j] ;
        }
    }

    int q;
    cin >> q;
    while(q--){
        string st;
        cin >> st;
        cout << solve(st) << '\n';
    }
    return 0;
}
