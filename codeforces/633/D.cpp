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
long long bigmod(long long p,long long e,long long M){
    long long ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
 ll modinverse(ll a,ll M){return bigmod(a,M-2,M);}
ll bigmod(ll base, ll pow)
{
    if(pow == 0) return (1 % mod);
    ll x = bigmod(base, pow/2 );
    x = ( x * x ) % mod;
    if(pow % 2 == 1)
         x = (x * base) % mod;
    return x;
}
const int MX = 2e5 + 10 ;
//vector < ll > cnt;
//
//ll count(ll num)
//{
//    ll c1 = upper_bound(all(cnt), num) - cnt.begin() ;
//    ll c2 = lower_bound(all(cnt), num) - cnt.begin() ;
//    return c1 - c2;
//
//}

int main()
{
    int n;
    cin >> n ;
    vector < ll > ara(n);
    map < ll, int > cnt;

    for(int i = 0; i < n;i++)
        cin >> ara[i] ,cnt[ara[i]]++;

    int ans = 2;
    vector < ll > so_far;
    //sort(all(cnt)) ;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(i == j ) continue;
            if(!ara[i] and !ara[j] )
            {
                ans = max( ans, cnt[0] ) ;
                continue;
            }
            so_far.clear();
            so_far.pb(ara[i]), so_far.pb(ara[j]);

            ll can = 2;
            ll first = ara[i] , second = ara[j] ;
            cnt[ara[i]]--;
            cnt[ara[j]]--;
            ll tmp = ara[i] + ara[j] ;

           // cout << tmp << " " << to_cmp << endl;
            while(cnt[tmp] > 0 )
            {
                cnt[tmp]--;
                so_far.pb(tmp) ;
                first = second;
                second = tmp ;
                tmp = first + second;
                can++;
                //to_cmp = count(tmp) ;
            }
            ans = max(1LL * ans, can) ;
            for(auto x : so_far)
                cnt[x]++;
        }

    }
    cout << ans << endl;
    return 0;
}
