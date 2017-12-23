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
#define M 100007
#define MOD 1000000007

// Order Statistic Tree

/* Special functions:

        find_by_order(k) --> returns iterator to the kth largest element counting from 0
        order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/

typedef tree<
int,					// type long long
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
const int MX = 1e5 + 10;
int cnt[MX];
int p[MX] ;
int main()
{
    FAST ;
    int n ;
    cin >> n ;
    ordered_set ost;
    for(int i = 1;i <= n; i++){
        cin >> p[i] ;
        int bame = ost.order_of_key(p[i]) ;
        if(bame == i - 1) {
            cnt[p[i]] --;
        }
        else if(bame == i - 2){
            int id = *ost.find_by_order(i-2) ;
            //cout << id << ' ' << i << endl;
            cnt[id]++;
        }
        ost.insert(p[i]) ;
    }
//    for(int i = 1; i <= n ;i++)
//        cout << cnt[i] <<endl;
    cout << max_element(cnt + 1, cnt+ n+1) - cnt << endl;
}
