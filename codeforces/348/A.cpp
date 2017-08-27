#include <bits/stdc++.h>
typedef long long int ll ;

using namespace std;
ll a[(int)1e5 + 10 ] ;
int n ;

bool can(ll mid ){
    ll tmp = 0LL;
    for(int i = 0; i < n ; i++){
        if(a[i] > mid) return 0;
        tmp += (mid - a[i] );
        
    }
   // cout << mid << ' ' << tmp  << endl;
    return !(tmp < mid ) ;
}

int main()
{
    cin >> n ;
    
    for(int i = 0 ; i < n; i++){
        scanf("%lld", &a[i]) ;
    }
    
   ll lo = 0 , hi = 1e12 ;
   while(lo < hi ){
       
        ll mid = (lo + hi ) / 2 ;
     //   cout << mid << ' '<< can(mid) << endl;
        if(can(mid)) hi = mid ;
        else 
            lo = mid + 1 ;
   }
   
   cout << lo << endl;
    
   return 0;
}