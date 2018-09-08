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
//const int MX = 2e5 + 10;
/*vector < int > prime;
bool mark[MX] ;

void sieve()
{
    for(int i = 2; 1LL * i * i < MX; i++)
    {
        if(!mark[i]){
            //prime.pb(i);
            for(int j = 2 * i; j < MX; j += i )
            {
                mark[j] = 1;
            }

        }
    }
    for(int i = 2; i < MX; i++)
        if(!mark[i])
            prime.pb(i);
}
*/
int const MX = 3e5 + 10;
vector < string > per;

void pre()
{
    string temp = "1689";
    do{
        per.pb(temp);
    }while(next_permutation(all(temp)));
} 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    FAST;
    cin.tie(0);
    cout.tie(0);
    pre();


    /*cout << "100" << endl;

    for(int i = 1; i <= 100; i++)
    {
        cout << "1000" << endl;
    }*/

    string s;
    cin >> s;
    string bam, dan;
    int cnt[12];
    memset(cnt,0,sizeof cnt);

    for(auto x: s)
    {
        if(x == '0') dan += x;
        else if(x == '1' or x == '6' or x == '8' or x == '9'){
            cnt[x-'0']++;
            if(cnt[x-'0']>=2 )
            {
                bam += x;
            }
        }
        else 
            bam += x;
    }

    for(int i = 0; i < per.size(); i++)
    {
        int mod = 0;
        int pow = 1;
        string tmp = "";
        tmp += dan;
        tmp += per[i] ;
        tmp += bam;

        for(auto x : tmp){
            mod += (pow * (x-'0'));
            mod %= 7;
            pow = (pow * 10 ) % 7;
        }
        
        if(mod == 0 ) {
            reverse(all(tmp));
            return cout << tmp << endl, 0;
        }
    }
    return 0 ;
}
