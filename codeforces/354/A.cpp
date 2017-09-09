#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll;

ll ls[(int)1e5 + 10] , rs[(int)1e5 + 10];


int main()
{
    int  n,l,r,q1,q2 ;
    cin >> n >> l >> r >> q1 >> q2 ;
    int w[(int)1e5 + 10] ;
    for(int i  = 1 ; i<= n; i++)
        scanf("%d", &w[i]) ;

    for(int i = 1 ; i <= n ; i++)
        ls[i] = ls[i-1] + w[i] ;// cout << ls[i] << endl;

    for(int i = n; i >=  0 ; i--)
        rs[i] = rs[i+ 1] + w[i] ;
    ll ans = 1e16;
   // cout << ls[0] << endl;
    for(ll i  = 0  ; i <= n; i++){
        ll cur = ls[i] * l + rs[i + 1 ]  * r ;
        //cout <<cur << ' ' << rs[i] << endl;
        if(i > n- i ){
            cur += (2 * i - n - 1) * q1 ;

        }
        else if(i < n - i)
            cur += (n - 2 * i - 1) * q2  ;
       // cout << "ans " << ans << ' ' << "cur " << cur << endl;
        ans = min(ans , cur) ;
    }
    cout << ans << endl;

}
