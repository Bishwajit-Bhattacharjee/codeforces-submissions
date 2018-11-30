#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int,int > PII;
typedef pair < ull,ll > PLL;
#define F first
#define S second
ostream& operator<<(ostream & os, PLL h)
{
	return os << "( " << h.F << ", " << h.S << " )" << endl;

}
PLL operator+ (PLL a, ll x)     {return {a.F + x, a.S + x} ;}
PLL operator- (PLL a, ll x)     {return {a.F - x, a.S - x} ;}
PLL operator* (PLL a, ll x)     {return {a.F * x, a.S * x} ;}
PLL operator+(PLL x, PLL y) { return {x.F + y.F,x.S + y.S} ;}
PLL operator-(PLL x,PLL y) { return {x.F - y.F, x.S - y.S} ;}
PLL operator*(PLL x,PLL y) { return {x.F * y.F , x.S * y.S} ;}
PLL operator%(PLL x,PLL y) { return {x.F % y.F, x.S % y.S} ;}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace __gnu_pbds;

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
int const MX = 1000;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector < int > deg(n+1), one, deg_so_far(n+1,0);
    vector < PII > need;


    for(int i = 0; i < n; i++){
        cin >> deg[i+1] ;
        if(deg[i+1] == 1)
            one.pb(i+1);
        else
            need.pb({deg[i+1], i+1});
    }

    sort(need.begin(), need.end(),greater<PII>());
    vector < PII > edge;

    for(int i = 1; i < need.size(); i++)
    {
        deg_so_far[need[i].S]++;
        deg_so_far[need[i-1].S]++;
        edge.pb({need[i].S, need[i-1].S});
    }


    if(one.size() >= 3 and need.size() == 0)
    {
        return cout << "NO", 0;
    }

    int cur = 0;

    if(one.size() >= 1 )
    {
         deg_so_far[need[0].second]++;
         edge.push_back({need[0].S, one[0]});
    }
    if(one.size() >= 2)
    {
         deg_so_far[need.back().second]++;
         edge.push_back({need.back().S, one[1]});
    }

    for(int i = 2; i < one.size(); )
    {
        if(cur == need.size())
            return cout << "NO" , 0;

        while( i < one.size() and deg_so_far[need[cur].S] < need[cur].F)
        {
            deg_so_far[need[cur].S]++;
            edge.push_back({need[cur].S, one[i]});
            i++;
        }
        cur++;
    }

    cout << "YES" << endl;
    int dim =  need.size() - 1;
    dim += (one.size() >= 1);
    dim += (one.size() >= 2);

    cout << dim << endl;
    cout << edge.size() << endl;

    for(auto x : edge)
        cout << x.F << " " << x.S  << '\n';

    return 0;
}
