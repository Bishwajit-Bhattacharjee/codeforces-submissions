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

int const N = 3e5 + 10; //;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll dp[N] ;
ll n, m;
struct mat{
    ll mt[105+1][105+1];
    mat() {
        memset(mt,0,sizeof mt);
    }
    void identity()
    {
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= m; j++)
                mt[i][j] = (i == j) ;
        }
    }


};

mat mul(mat &a, mat &b)
{
    mat res;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                res.mt[i][j] += a.mt[i][k] * b.mt[k][j];
                res.mt[i][j] %= MOD;
            }
        }
    }
    return res;
}

mat matExpo(mat a, ll po)
{
    //cout << po << endl;
    if(po == 0) {
        mat tmp;
        tmp.identity();
        return tmp;
    }
    mat tmp = matExpo(a,po/2);
    tmp = mul(tmp,tmp);
    if(po % 2 ) {
        tmp = mul(tmp,a);
    }
    return tmp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    dp[1] = dp[0] = 1;
    for(int i = 2; i <= 50000; i++)
        dp[i] = (dp[i-1] + ((i >= m )?dp[i - m ] : 0)) % MOD;

    if(n < 5000) {
        cout << dp[n] << '\n';
        return 0;
    }
    mat maker;

    for(int i = 1; i <= m; i++)
    {

            if(i == 1){
                maker.mt[i][1] = maker.mt[i][m] = 1;
            }
            else {
                maker.mt[i][i-1] = 1;
            }

    }

    /* for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout  << maker.mt[i][j] << " ";
        }
        cout << endl;
    } */
    //cout << n << " " << m << endl;
    maker = matExpo(maker,n-m) ;
    //cout << n << " " << m << endl;
    //maker = mul(maker, maker);
 /*    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << maker.mt[i][j] << " ";
        }
        cout << endl;
    }
 */
    int x = 0;
    x++;

    ll ans = 0;
    for(int i = 1; i <= m ; i++)
    {
        ans = (ans + maker.mt[1][i]* dp[m+1-i]) % MOD;
    }

    cout << ans << endl;
    return 0;
}
