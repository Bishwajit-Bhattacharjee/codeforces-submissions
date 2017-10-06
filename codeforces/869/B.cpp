#include <bits/stdc++.h>
using namespace std ;

int main()
{
    long long a , b ;
    cin >> a >> b ;
    long long ans ;
    if(b == 0 and a == 0){
        ans = 1 ;
    }
    else if(a == 0  ) {
        if( b >= 5)ans = 0 ;
        else {
                ans = 1 ;
           for(int i = 1  ; i <= b ; i++ )
                ans *= i ;
            ans %= 10 ;
        }
    }
    else {
            ans = 1;
        for(long long i = a + 1  ; i <= b && (ans % 10 != 0) ; i++) {
            ans = (ans * i ) % 10  ;
           // cout << ans << endl;
        }
        //cout << ans << endl;
       // ans %= 10 ;
        //cout << ans << endl ;
    }
    cout << ans ;
}
