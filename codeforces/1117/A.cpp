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
    int n;
    cin >> n;    
    vector < ll > ara(n);

    for(int i = 0;i < n; i++)
        cin >> ara[i] ;

    ll mx = *max_element(ara.begin(),ara.end());

    ll cnt = 0;
    ll so_far = (ara[0] == mx);

    for(int i = 1; i < ara.size(); )
    {
        if(ara[i-1] == mx and ara[i] == mx){
            so_far++;
        }
        else if(ara[i] == mx ){
            cnt = max(cnt, so_far);
            so_far = 1;
        }
        else {
            cnt = max(cnt,so_far);
            so_far = 0;
        }
        i++;
    }
    cout << max(cnt,so_far) << endl;
    return 0;
}
