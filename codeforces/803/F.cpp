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

int const N = 1e5 + 10;
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

ll comCount(ll num)
{
    return (bigmod(2LL, num) - 1 + MOD ) % MOD ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    seive();

    int n;
    cin >> n;

    for(int i = 0; i < n ; i++)
    {
        ll tmp;
        cin >> tmp;
        cnt[tmp]++;
    }

    for(ll i = 2; i < N; i++)
    {
        for(ll j = 2*i; j < N ; j+= i)
            cnt[i] += cnt[j] ;
    }
    ll ans = 0;

    for(ll i = 2; i < N; i++)
    {
        //if(i < 100 )cout << i << " " << pdc[i] << endl;
        if(wont[i]) continue;
        ll tmp = comCount(cnt[i]);
        if(pdc[i] % 2 == 0 ) tmp *= -1;
        ans = (ans + tmp + MOD ) % MOD ;
    }
    ans = (comCount(n) - ans + MOD ) % MOD ;
    cout << ans << endl;
    return 0;
}
