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
    string s;
    int k;
    cin >> s >> k;
    map < char, char > pair;

    for(int i =0 ; i < k; i++)
    {
        string x;
        cin >> x;
        pair[x[0]] = x[1];
        pair[x[1]] = x[0] ;

        //pair[a-'a'][b-'a'] = pair[b-'a'][a-'a'] = 1;
    }
    int ans = 0;
    for(int i = 0; i < s.size(); )
    {
        int c1 , c2 ;
        c1 = 1;
        c2 = 0;
        int j = i + 1;
        char cur = s[i] ;
        //cout << cur << " " << s[j] << " " << j << endl;
        while(j < s.size() and (s[j] == cur or s[j] == pair[cur])){
            if(s[j] == cur) 
                c1++;
            else 
                c2++;
            j++;
            //cout << j << " " << c1 << " " << c2 << endl;
        }

        ans += min(c1,c2);
        i = j;
    }
        //while(i + 1 < s.size() && pair[s[i]-'a'][pair[s[i+1]]])
    cout << ans << endl;
    return 0 ;
}
