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
    
    for(int i = 0 ; i < n; i++ ){
        long long int  tmp = (long long int)( upper_bound(v.begin() + i , v.end(), v[i] + d ) -( v.begin() + i)  ) - 1;
        ans +=  cnt(tmp) ;
        
    }
    cout << ans << endl;
    

    return 0;
}