#include <bits/stdc++.h>

using namespace std;

long long int cnt(long long int n){
    
    if(n <= 1){
        return 0 ;
    }
    
    return n * ( n - 1 ) / 2;

}

int main() {
    int n, d;
    cin >> n >> d;
    vector < int > v(n);
    
    for(int i = 0 ; i < n; i++){
        scanf("%d", &v[i]);
    }
    
    long long int ans = 0LL;
    int i , j ;
    for( i = 0, j = 0 ; i < n && j <= n ; i++ ){
            
        while( v[j] - v[i] <= d  && j < n  ) j++ ;
        // while(v[j] - v[i] )
        ans += cnt((long long int)(j - i - 1) ) ;
        
    }
    cout << ans << endl;

    return 0;
}