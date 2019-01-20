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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector < int > v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i] ;

                     //)
    int t = 0, ans = INT_MAX;

    for(int tmp = 1; tmp <= 110; tmp++)
    {

        int can = 0;
        for(int i = 0; i < n; i++)
        {
            can += (max(0, abs(v[i] - tmp) - 1));
        }
        if(ans > can)
        {
            t = tmp;
            ans = can;
        }
    }
    cout << t << " " << ans << endl;
    return 0;
}


