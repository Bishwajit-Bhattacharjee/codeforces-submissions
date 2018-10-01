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
/*const int MX = 2e5 + 10;
vector < int > prime;
bool mark[MX] ;

void sieve()
{
    mark[1] = 1;
    mark[0] = 1;
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
}*/


int const MX = 2e5 + 10;

int matha[MX*32][2] ;
int root;
int cnt[MX*32][2];
int nnode;

void init()
{
    root = nnode = 0;

    
    matha[root][0] = matha[root][1] = -1;
    
}   


void insert(string num)
{
    int now = root;

    for(int i = 0; i < num.size(); i++)
    {
        if(matha[now][num[i] - '0'] == -1)
        {
            matha[now][num[i] - '0'] = ++nnode;
            memset(matha[nnode], -1,sizeof matha[nnode]);    
        }
        cnt[now][num[i]- '0']++;
        now = matha[now][num[i] - '0'];
    
    }

}
int query(string num)
{
    int now = root;
    int ans = 0;

    for(int i = 0; i < num.size(); i++){

        if(num[i] - '0')
        {
            if(matha[now][0] != -1 and cnt[now][0] > 0 )
            {
                ans ^= (1<<(30-i));
                now = matha[now][0] ;
            }
            else {
                now = matha[now][1] ;
            }
        }
        else {
            if(matha[now][1] != -1 and cnt[now][1] > 0 )
            {
                ans ^= (1<<(30-i));
                now = matha[now][1] ;
            }
            else {
                now = matha[now][0] ;
            }
        }
        //cout << ans << " " << i << endl;

    }
    return ans;

}

void del(string s)
{
    //int root = 0;
    int now = root;

    for(int i = 0; i < s.size(); i++){
        cnt[now][s[i]-'0']--;
        now = matha[now][s[i]-'0'];        
    }

}
string toBin(int num)
{
    string tmp = "";

    if(num == 0)
    {
        tmp = "0";
    }

    while(num)
    {
        tmp += ('0' + num % 2);
        num /= 2;
    }
    while(tmp.size() < 31) 
        tmp += '0';

    reverse(all(tmp));

    return tmp;

}
int main()
{
   #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
//       freopen("out.txt","w",stdout);
       
   #endif

    FAST;
    int q;
    cin >> q;
    init();
    //cout << toBin(0).size() << endl << toBin(0) << endl;//;

    insert(toBin(0));

    while(q--)
    {
        char ch;
        int x;
        cin >> ch >> x;

        //cout << ch << " " << x << endl;

        if(ch == '+'){
            //cout << toBin(x) << endl;
            insert(toBin(x));
        }
        else if(ch == '?'){
            //cout << toBin(x) << endl;
            cout << query(toBin(x)) << endl;
        } 
        else {
            del(toBin(x));
        }       
    }

    return 0 ;
}
