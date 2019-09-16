#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <ll,ll> PLL;

ll const MOD = 1e9 + 7;
int const N = 5e5 + 100;
const ll BLOCK = 750 ;

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
ll ans[BLOCK+10][BLOCK+10] ;
ll ara[N] ;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n,l,r;
    cin >> n >> l >> r;

    vector < ll > mul;

    ll fact = 1;
    int cnt = 1;

    do{
        mul.push_back(fact);
        fact *= 2;
        cnt++;
    }while(cnt <= 20);
    assert(mul.size() == 20);

    ll mx = 0;

    cnt = r;
    for(int  i =0 ; i < r; i++){
        mx += mul[i] ; 
    }
    mx += (n-r)*mul[r-1];

    ll mn = 0;

    cnt = l;

    for(int i = 0; i < l; i++){
        mn += mul[i] ;
    }
    mn += (n - l)*mul[0] ;
    cout << mn << " " << mx << endl;

    return 0;
}