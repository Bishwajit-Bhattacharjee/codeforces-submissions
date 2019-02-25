#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define pb push_back
//#all(x) (x).begin(),(x).end()
#include <chrono>

int const MOD = 1e9 + 7;

ll bigmod(ll a, ll b)
{
    if (b == 0)
        return 1 % MOD;
    ll x = bigmod(a, b / 2);
    x = (x * x) % MOD;
    if (b % 2)
        x = (x * a) % MOD;
    return x;
}

int const N = 2e6 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll cnt[N] ;
bool mark[N];
int pdc[N] ;
bool wont[N] ;
void seive()
{
    for(ll i = 2; i < N; i++){
        if(!mark[i]){
            for(ll j = i ; j < N ; j += i ){
                if(j != i )mark[j] = 1;
                pdc[j]++;
            }
        }
        if(!mark[i])
        {
            for(ll j = i*i; j < N ; j += i * i )
                wont[j] = 1;
        }
    }
}

//ll fact[N] ;
ll n, k;
ll comCount(ll num)
{
    return (bigmod(num, n ))  ;
}

ll ara[N] ;

ll addMOD(ll a,ll b)
{
    return ( a + b >= MOD ) ? (a+b-MOD) : (a + b);
}
void update(int pos, ll val)
{
    ara[pos] = (ara[pos] + val) % MOD ;
}

ll Q(int pos)
{

    return ara[pos];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    seive();
    cin >> n >> k ;
    ll ans = 0;
    vector < ll > bigp(k+1);

    for(int i = 0; i <= k; i++)
        bigp[i] = bigmod(i,n);

    for(ll x = 2; x <= k; x++)
    {

        if(wont[x]) continue;

        for(ll i = x, here = 1; i <= k; i += x, here++)
        {
            ll val = bigp[here];


            //cout << x << " range " << i << " " << min(k+1,i+x) - 1 << "val " << here <<  endl;
            if(pdc[x] % 2 == 0) val *= -1;
            update(i,val);
            update(min(k+1,i+x),-val);
        }
//        ll tmp = comCount(cnt[i]);
//        if(pdc[i] % 2 == 0 ) tmp *= -1;
//        ans = (ans + tmp + MOD ) % MOD ;
    }

    for(int i = 1; i <= k; i++)
        ara[i] = (ara[i] + ara[i-1]) % MOD;

    vector < ll > b(k+1,0);

    for(int i = 1; i <= k; i++)
    {
        //cout << i << " " << Q(i) << endl;
        b[i] = (comCount(i) - Q(i) + MOD ) % MOD;
        //cout << i << " " << b[i] << endl;
        ans = (ans + (b[i] ^ i)) % MOD ;
    }

    //ans = (comCount(n) - ans + MOD ) % MOD ;
    cout << ans << endl;
    return 0;
}
