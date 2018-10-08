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
typedef pair < ll, ll > PLL ;
#define all(x) (x).begin() , (x).end()
#define F first
#define S second
#define READ freopen("in.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout)
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
PLL,					// type long long
null_type,
less<PLL>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
long long bigmod(long long p,long long e,long long M){
    if(e < 0 )
        return 0;
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
//int const MX = 3e5 + 10;

const int MX = 2e6 + 10;
vector < int > prime;
bool marking[MX] ;

void sieve()
{
    marking[1] = 1;
    marking[0] = 1;
    for(int i = 2; 1LL * i * i < MX; i++)
    {
        if(!marking[i]){
            //prime.pb(i);
            for(int j = 2 * i; j < MX; j += i )
            {
                marking[j] = 1;
            }

        }
    }
    for(int i = 2; i < MX; i++)
        if(!marking[i])
            prime.pb(i);
}


int main()
{
   #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       //freopen("out.txt","w",stdout);
       
   #endif
    FAST;
    sieve();
    int n;
    cin >> n;
    vector < ll > v(n+1);
    map < ll, ll> cnt, mp;
    map < ll , bool > done;

    ll tmp;
    for(int i = 1; i <= n;i++)
        cin >> tmp,cnt[tmp]++, done[tmp] = 0;

    for(auto x : prime)
    {
        ll four = 1LL*x * x * x * x;
        if(cnt.count(four)){
            mp[x] += (4 * cnt[four]);
            done[four] = 1;
        }
        ll three = 1LL*x * x * x;
        if(cnt.count(three)){
            mp[x] += (3 * cnt[three]);
            done[three] = 1;
        }
    }
    for(auto x : cnt){
        if(!done[x.F]){
            ll matha = sqrtl(x.F);
            for(ll dane = matha - 1; dane <= matha +1; dane++){
                if(dane * dane == x.F){
                    mp[dane] += (2*x.S);
                    done[x.F] = 1;
                    break;
                }
            }
        }
    }

    for(auto x : cnt){
        //cout << x.F << endl;
        if(done[x.F])
            continue;
        for(auto y : cnt){
            if(x.F == y.F) continue;

            ll matha = __gcd(x.F,y.F);
            

            if(matha != 1 and matha < min(x.F,y.F)){
                mp[matha] += (x.S);
                mp[x.F / matha] += (x.S);
                done[x.F] = 1;
                break;
            }
        }
    }

    ll ans = 1LL;
    ll md = 998244353;

    for(auto x : mp)
    {
        ans = (ans * (x.S + 1 )) % md;
        //cout << x.F << " " << x.S << endl;

    }
    //cout << mp.size() << endl;

    for(auto x: cnt){
        if(!done[x.F]){
            ans = (ans * (x.S + 1)) % md;
            ans = (ans * (x.S + 1)) % md;
        }
    }
    cout << ans << endl;

    return 0;
}