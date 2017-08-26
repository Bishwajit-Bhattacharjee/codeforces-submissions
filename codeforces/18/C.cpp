#include <bits/stdc++.h>
typedef long long int ll ;

using namespace std;

ll a[(int)1e5 + 10 ] ;
ll sum[(int)1e5 + 10 ] ;

int main()
{
   int n ;
   cin >> n;
   
   for(int i = 1; i <= n ; i++){
       scanf("%I64d", &a[i]);
       sum[i] = sum[i-1] + a[i] ;
    }
    
    int ans = 0;
    
    for(int i = 1; i < n ; i++){
        if(sum[i] == (sum[n] - sum[i]))
        ans++;
    }
    cout << ans << endl;
    
    
    
    return 0;
}