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

int const N = 5e4 + 10; //;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



vector < int > primes;
bool mark[N] ;

void sieve()
{
    for(ll i = 2; i * i < N ; i++)
    {
        if(!mark[i]){
            for (ll j = 2*i; j < N ; j += i ) 
                mark[j] = 1;
        }
        
    }
    for(int i = 2; i < N ; i++){
        if(!mark[i]) {
            primes.push_back(i);
        }
    }
}

ll Count(ll n, ll pr)
{
    ll ret = 0;
    ll p = pr;
    while( p <= n)
    {
        ret += (n / p) ;
        p *= pr;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m,k ;
    cin >> n >> m >> k;    
    vector < ll > ara(n);

    for(int i = 0;i < n; i++)
        cin >> ara[i] ;

    sort(ara.begin(),ara.end(), greater<ll>());

    ll ans = 0;

    ans = (m/(k+1)) * (ara[0]*k+ ara[1]) + (m % (k+1)) * ara[0] ;
    cout << ans << '\n';
    return 0;
}
