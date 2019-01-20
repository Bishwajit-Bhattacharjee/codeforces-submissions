#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair < int,int > PII;
typedef pair < ll,ll > PLL;
#define pb push_back
//#all(x) (x).begin(),(x).end()

//int const N = 1;
int const MOD = 1e9 + 7;

ll bigmod(ll a, ll b)
{
    if(b==0)
        return 1 % MOD;
    ll x = bigmod(a,b/2);
    x = (x * x) % MOD;
    if(b%2)
        x = (x * a) % MOD;
    return x;
}

int const N = 2e5 + 10;//;
//vector  < int > g[30];
ll dp[N][4];

ll cnt(ll n, ll mod)
{
    if(n - mod < 0 ) return 0;
    return (n - mod) / 3 + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, l,r;
    cin >> n >> l >> r;
    ll mod[4];
    memset(mod,0,sizeof mod);
    for(int i = 0; i < 3; i++)
        mod[i] = cnt(r,i) - cnt(l-1,i);

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int now = 0; now < 3; now++)
            {
                dp[i][j] += mod[now] * dp[i-1][(j - now + 3)%3] ;
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}


