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
#define endl '\n'

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
const ll inf = 3000000000000000000LL;
string s0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s1 = "What are you doing while sending \"";
string s2 = "\"? Are you busy? Will you send \"" ;
ll cnt[MX] ;

char solve(ll n, ll k)
{
   if(cnt[n] < k ) return '.';
   if(n == 0 && k <= cnt[n]) return s0[k-1] ;
   if(s1.size() >= k ) return s1[k-1] ;
   if(s1.size() + cnt[n-1] >= k ) return solve(n-1,k-s1.size()) ;
   if(s1.size() + cnt[n-1] + s2.size() >= k)
        return s2[k-s1.size() - cnt[n-1] - 1] ;
   if(s1.size() + cnt[n-1] + s2.size() + cnt[n-1] >= k)
        return solve(n-1,k - s1.size() - cnt[n-1] - s2.size()) ;
   if(s1.size() + cnt[n-1] + s2.size() + cnt[n-1] + 1 == k)
        return '\"' ;
   return '?' ;
}
int main()
{
    FAST ;
    cnt[0] = s0.size();
    //cout << s1.size() + s2.size() + 2 << endl;
    for(int i = 1 ; i < MX; i++)
        cnt[i] = min(inf,cnt[i-1] * 2LL + s1.size() + s2.size() + 2 );
    ll n ,k , q ;
    cin >> q ;
   // cout << cnt[1] << endl;
    string ans = "";
    while(q--){
        cin >> n >> k ;

        ans += solve(n, k) ;
        //cout << solve(n,k) << endl;
    }
    cout << ans << endl;
    return 0;
}
