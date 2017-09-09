#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
ll const mod = 1e9 + 9 ;

ll bigmod(ll a, ll b  ){
    if(b == 1 )
        return (a % mod) ;
    ll ret = 1LL ;
    ll x = (bigmod(a, b / 2)) ;
    if(b % 2 ) {
            ret = ( (x * x ) % mod ) * (a % mod) ;
            ret %= mod ;
    }
    else {
        ret = (x * x ) % mod ;
        ret %= mod ;
    }
    return ret ;

}

int main()
{
    ll n, m, k ;
    while(cin >> n >> m >> k){
      ll x = m - (n / k ) * (k - 1 ) - (n % k )  ;
      x = max((ll)0 , x ) ;
   //   cout << "x" << x << endl;
      ll ans ;
      ans = bigmod(2 , x + 1 ) * k ;
      ans %= mod ;
      ans += m ;
    //  cout << ans << endl;
      ans = ( (ans - (x + 2 ) * k ) % mod + mod ) % mod  ;
      cout << ans << endl;

    }

}
