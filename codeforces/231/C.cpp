#include <bits/stdc++.h>

using namespace std;

typedef long long int ll ;

int main()
{
    ll n , k ;
    cin >>  n >> k;
    
    vector < ll > v (n + 1), cum(n + 1 , 0 );
    for(int i = 1 ; i <= n ;i++)
        scanf("%I64d", &v[i]);
    
    sort( v.begin() + 1 , v.end() );
    
    for(int i = 1; i <= n; i++)
        cum[i] = cum[i - 1 ] + v[i];
    ll ans = 0 , num = -1  ;    
    for(int i = 1; i <= n; i++){
        
        ll lo = 0  , hi = n ;
        while( lo < hi ){
            ll mid = (lo + hi + 1 )  / 2 ;
           // cout << mid << ' ' << lo << ' ' << hi << endl;
           // cout << "hk " << endl;
            ll tmp  = v[i] * mid - (cum[i] - ( (i >= mid) ? cum[i - mid]: (ll)1e17 ) ) ;
            
            if(tmp <= k){
                lo = mid ;
            }
            else 
                hi = mid - 1 ;
        }
        
    //    ans = max( ans , )
        if(lo > ans ){
            ans = lo ;
            num = v[i] ;
        } 
    }
    
    cout << ans << ' ' << num << endl;
    return 0;
    
}