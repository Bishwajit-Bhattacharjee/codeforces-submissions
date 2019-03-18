//HK HK HK HK HK 108 times
#include <bits/stdc++.h>
#define PII pair < int , int >
#define PLL pair < ll, ll >
#define PI 2.0*acos(0.0)
#define ll long long int
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define FOR(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a %b == 0)?(a/b):(a/b)+1
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7 ;
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
int const N =  1e6 + 12;
bool mark[N] ;

vector < int > pf[N] ;

void sieve()
{
    for(int i = 2; i < N ; i++)
    {
        if(!mark[i])
        {
            for(int j =  i ; j < N ; j += i )
                mark[j] = 1, pf[j].pb(i);
        }
    }
}

ll mask_cnt[N] ;
ll ara[N] ;

ll cnt;

void rec(ll pos, ll koyta,int id, ll mul, bool del)
{

    if(pos == pf[ara[id]].size())
    {
        if(mul != 1)
        {
            ll tmp = mask_cnt[mul];
            if(del) tmp--;
            if(koyta & 1 ) {
                cnt += tmp;
            }
            else
                cnt -= tmp;

            if(del){
                mask_cnt[mul]--;
            }
            else {
                mask_cnt[mul]++;
            }
            //mask_cnt[]

        }
        return ;
    }
    rec(pos+1,koyta+1,id,mul * pf[ara[id]][pos], del);
    rec(pos+1,koyta,id,mul,del);
}
ll solve(ll num, bool del)
{
    cnt = 0;
    rec(0,0,num,1,del);
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    sieve();

    int n, q;
    cin >> n >> q;

    vector < int > has(N+1,0);

    for(int i = 0; i < n; i++)
    {
        cin >> ara[i+1] ;
    }

    ll ans = 0;
    ll tot = 0;
    while(q--)
    {
        int x;
        cin >> x;
        if(has[x]){
            tot--;
            ll collide = solve(x,1);
            ans -= tot - collide;
            has[x] = 0;
        }
        else {
            //tot++;
            ll collide = solve(x,0);
            //cout << "coolide : " << collide << endl;
            ans += tot - collide;
            tot++;
            has[x] = 1;
        }
        cout << ans << endl;
    }

    return 0;
}
