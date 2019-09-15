#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <ll,ll> PLL;

ll const MOD = 998244353LL;

int const N = 3e5 + 100;
ll fact[N]; //]

ll bigmod(ll a,ll b)
{
    if(b == 0) return 1;

    ll x = bigmod(a,b/2);
    x = (x * x) % MOD;
    
    if(b & 1) {
        x = (x * a) % MOD;
    }
    return x;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    fact[0] = 1;
    for(int i = 1; i < N ; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }

    int n;
    cin >> n ;

    map < ll,ll > first, second;
    map < PLL,ll> cnt;
    vector < int > one(n),two(n);
    vector < PLL > pairs(n);

    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        first[a]++, second[b]++;
        cnt[{a,b}]++;
        one[i] = a;
        two[i] = b;
        pairs[i] = {a,b};
    }

    
    
    ll ans = 1;

    for(auto x : first){
        ans = (ans * fact[x.second]) % MOD;
    }
    ll ans1 = 1;
    for(auto x : second){
        ans1 = (ans1 * fact[x.second]) % MOD;
    }

    ans = (ans + ans1) % MOD;
    //cout << ans << endl;
    ll minus = 1;
    
    sort(pairs.begin(), pairs.end());

    bool f = 1;
    for(int i = 0; i + 1< pairs.size(); i++){
        if(pairs[i].second > pairs[i+1].second){
            f = 0;
            break;
        }
    }

    if(!f){
        minus = 0;
    }
    else {
        for(auto x : cnt){
            minus = (minus * fact[x.second]) % MOD;
        }
    }
    cout <<(fact[n] - ans + minus + 2 * MOD) % MOD << endl;
    return 0;
}