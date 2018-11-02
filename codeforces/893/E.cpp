#include <bits/stdc++.h>
using namespace std;
int const MX = 2e6;
map < int, int > pf[MX];
bool mark[MX] ;
int const MOD = 1e9 + 7;
typedef long long int ll;
ll fact[MX] ;
void sieve()
{
    mark[1] = 1;
    for(int i = 2; i < MX; i++){
        if(!mark[i]){
            for(ll j = i; j < MX; j *= i){
                for(ll k = j ; k < MX; k += j)
                    pf[k][i]++, mark[k] = 1;
            }
        }
    }

    fact[0] = 1;

    for(int i = 1; i < MX; i++)
        fact[i] = (fact[i-1] * i) % MOD;

}
ll bigMod(ll a, ll b,ll mod = MOD)
{
    if(b == 0 ) return (1 % mod) ;

    ll ret = bigMod(a,b/2,mod);
    ret = (ret * ret) % mod;
    if(b & 1)
        ret = (ret * a ) % mod;

    return ret;
}

ll ncr(ll n, ll r)
{
    assert(n >= r);
    ll niche = (fact[r] * fact[n-r]) % MOD;
    niche = bigMod(niche, MOD - 2);
    return (fact[n] * niche ) % MOD;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    sieve();
    //cout << "hello" << endl;
    cin >> q;
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        ll ans = bigMod(2,y-1);

        for(auto pr : pf[x]){
            ans = (ans * ncr(pr.second + y - 1, y - 1) ) % MOD ;
        }
        cout << ans << '\n';
    }
    return 0;
}
