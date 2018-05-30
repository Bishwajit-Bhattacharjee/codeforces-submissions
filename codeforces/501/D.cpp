/// HK 108 Times
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std ;
#define ll long long
#define pb push_back
typedef pair <int,int>  PII ;
vector < PII > given ;
vector < pair < int , PII >  >  edge  ;
typedef pair < ll, ll > PLL ;
#define all(x) (x).begin() , (x).end()
#define F first
#define S second
#define READ freopen("in.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout)
#define FAST ios_base::sync_with_stdio(false)
#define ll long long
#define MOD 1000000007
#define endl '\n'

// Order Statistic Tree

/* Special functions:

        find_by_order(k) --> returns iterator to the kth largest element counting from 0
        order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/
const int mod = 1e9 + 7 ;
typedef tree<
int,					// type long long
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

vector<int> converter(vector < int > P)
{
    vector<int> factorad(P.size()) ;
    ordered_set ost;
    for(auto x : P )
        ost.insert(x) ;

    for(int i = 0; i < P.size() ; i++)
    {
        factorad[i] = ost.order_of_key(P[i]) ;
        ost.erase(P[i]);
    }
    return factorad;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(0) ;

    int n;
    cin >> n;

    vector < int > p1(n) , p2(n) ;

    for(int i = 0 ; i < n; i++)
        cin >> p1[i] ;

    for(int i = 0 ; i < n; i++)
        cin >> p2[i] ;

    vector <int> r1 = converter(p1) ;
    vector <int> r2 = converter(p2) ;
    vector <int> nv(n) ;
    int carry = 0;

    for(int i = n-1; i >= 0 ; i--)
    {
        int tmp = r1[i] + r2[i] + carry;
        nv[i] = tmp % (n-i) ;
        carry = tmp / (n-i) ;

    }
    vector < int > ans(n);

    ordered_set again;
    for(int i = 0; i < n ; i++)
        again.insert(i) ;

    for(int i = 0; i < n;i++)
    {
        ans[i] = *again.find_by_order(nv[i]);
        again.erase(again.find_by_order(nv[i]));

    }

    for(auto x : ans)
        cout << x << " " ;

    return 0;
}
