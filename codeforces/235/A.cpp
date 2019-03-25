#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll lcm(ll a, ll b)
{
    return (a /__gcd(a,b)) * b;
}
int main()
{
    ll n;
    cin >> n;

    ll ans = 0;

    for(ll i = n ; i >= max(n-100, 1LL); i--)
    {
        for(ll j = n; j >= max(n-100,1LL); j--)
        {
            for(ll k = n; k >= max(n-100,1LL) ; k--)
            {
                ll tmp = lcm(i,lcm(j,k)) ;
                ans = max(ans, tmp);
            }
        }
    }
    cout << ans << endl;
}
